/*
 * ASIX AX8817X based USB 2.0 Ethernet Devices
 * Copyright (C) 2003-2005 David Hollis <dhollis@davehollis.com>
 * Copyright (C) 2005 Phil Chang <pchang23@sbcglobal.net>
 * Copyright (c) 2002-2003 TiVo Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// #define	DEBUG			// error path messages, extra info
// #define	VERBOSE			// more; success messages

#define BRCM_FIX

#include <linux/module.h>
#include <linux/kmod.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/ethtool.h>
#include <linux/workqueue.h>
#include <linux/mii.h>
#include <linux/usb.h>
#include <linux/crc32.h>

#include "usbnet.h"

/* ASIX AX8817X based USB 2.0 Ethernet Devices */

#define AX_CMD_SET_SW_MII		0x06
#define AX_CMD_READ_MII_REG		0x07
#define AX_CMD_WRITE_MII_REG		0x08
#define AX_CMD_SET_HW_MII		0x0a
#define AX_CMD_READ_EEPROM		0x0b
#define AX_CMD_WRITE_EEPROM		0x0c
#define AX_CMD_WRITE_ENABLE		0x0d
#define AX_CMD_WRITE_DISABLE		0x0e
#define AX_CMD_WRITE_RX_CTL		0x10
#define AX_CMD_READ_IPG012		0x11
#define AX_CMD_WRITE_IPG0		0x12
#define AX_CMD_WRITE_IPG1		0x13
#define AX_CMD_WRITE_IPG2		0x14
#define AX_CMD_WRITE_MULTI_FILTER	0x16
#define AX_CMD_READ_NODE_ID		0x17
#define AX_CMD_READ_PHY_ID		0x19
#define AX_CMD_READ_MEDIUM_STATUS	0x1a
#define AX_CMD_WRITE_MEDIUM_MODE	0x1b
#define AX_CMD_READ_MONITOR_MODE	0x1c
#define AX_CMD_WRITE_MONITOR_MODE	0x1d
#define AX_CMD_WRITE_GPIOS		0x1f
#define AX_CMD_SW_RESET			0x20
#define AX_CMD_SW_PHY_STATUS		0x21
#define AX_CMD_SW_PHY_SELECT		0x22
#define AX88772_CMD_READ_NODE_ID	0x13

#define AX_MONITOR_MODE			0x01
#define AX_MONITOR_LINK			0x02
#define AX_MONITOR_MAGIC		0x04
#define AX_MONITOR_HSFS			0x10

/* AX88172 Medium Status Register values */
#define AX_MEDIUM_FULL_DUPLEX		0x02
#define AX_MEDIUM_TX_ABORT_ALLOW	0x04
#define AX_MEDIUM_FLOW_CONTROL_EN	0x10

#define AX_MCAST_FILTER_SIZE		8
#define AX_MAX_MCAST			64

#define AX_EEPROM_LEN			0x40

#define AX_SWRESET_CLEAR		0x00
#define AX_SWRESET_RR			0x01
#define AX_SWRESET_RT			0x02
#define AX_SWRESET_PRTE			0x04
#define AX_SWRESET_PRL			0x08
#define AX_SWRESET_BZ			0x10
#define AX_SWRESET_IPRL			0x20
#define AX_SWRESET_IPPD			0x40

#define AX88772_IPG0_DEFAULT		0x15
#define AX88772_IPG1_DEFAULT		0x0c
#define AX88772_IPG2_DEFAULT		0x12

#define AX88772_MEDIUM_FULL_DUPLEX	0x0002
#define AX88772_MEDIUM_RESERVED		0x0004
#define AX88772_MEDIUM_RX_FC_ENABLE	0x0010
#define AX88772_MEDIUM_TX_FC_ENABLE	0x0020
#define AX88772_MEDIUM_PAUSE_FORMAT	0x0080
#define AX88772_MEDIUM_RX_ENABLE	0x0100
#define AX88772_MEDIUM_100MB		0x0200
#define AX88772_MEDIUM_DEFAULT	\
	(AX88772_MEDIUM_FULL_DUPLEX | AX88772_MEDIUM_RX_FC_ENABLE | \
	 AX88772_MEDIUM_TX_FC_ENABLE | AX88772_MEDIUM_100MB | \
	 AX88772_MEDIUM_RESERVED | AX88772_MEDIUM_RX_ENABLE )

#define AX_EEPROM_MAGIC			0xdeadbeef

/* This structure cannot exceed sizeof(unsigned long [5]) AKA 20 bytes */
struct asix_data {
	u8 multi_filter[AX_MCAST_FILTER_SIZE];
};

struct ax88172_int_data {
	u16 res1;
	u8 link;
	u16 res2;
	u8 status;
	u16 res3;
} __attribute__ ((packed));

static int asix_read_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
			    u16 size, void *data)
{
	return usb_control_msg(
		dev->udev,
		usb_rcvctrlpipe(dev->udev, 0),
		cmd,
		USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
		value,
		index,
		data,
		size,
		USB_CTRL_GET_TIMEOUT);
}

static int asix_write_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
			     u16 size, void *data)
{
	return usb_control_msg(
		dev->udev,
		usb_sndctrlpipe(dev->udev, 0),
		cmd,
		USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
		value,
		index,
		data,
		size,
		USB_CTRL_SET_TIMEOUT);
}

static void asix_async_cmd_callback(struct urb *urb, struct pt_regs *regs)
{
	struct usb_ctrlrequest *req = (struct usb_ctrlrequest *)urb->context;

	if (urb->status < 0)
		printk(KERN_DEBUG "asix_async_cmd_callback() failed with %d",
			urb->status);

	kfree(req);
	usb_free_urb(urb);
}

static inline int asix_set_sw_mii(struct usbnet *dev)
{
	int ret;
	ret = asix_write_cmd(dev, AX_CMD_SET_SW_MII, 0x0000, 0, 0, NULL);
	if (ret < 0)
		devdbg(dev, "Failed to enable software MII access");
	return ret;
}

static inline int asix_set_hw_mii(struct usbnet *dev)
{
	int ret;
	ret = asix_write_cmd(dev, AX_CMD_SET_HW_MII, 0x0000, 0, 0, NULL);
	if (ret < 0)
		devdbg(dev, "Failed to enable hardware MII access");
	return ret;
}

static inline int asix_get_phyid(struct usbnet *dev)
{
	int ret = 0;
	void *buf;

	buf = kmalloc(2, GFP_KERNEL);
	if (!buf)
		goto out1;

	if ((ret = asix_read_cmd(dev, AX_CMD_READ_PHY_ID,
				    0, 0, 2, buf)) < 2) {
		devdbg(dev, "Error reading PHYID register: %02x", ret);
		goto out2;
	}
	ret = *((u8 *)buf + 1);
out2:
	kfree(buf);
out1:
	return ret;
}

static int asix_sw_reset(struct usbnet *dev, u8 flags)
{
	int ret;

        ret = asix_write_cmd(dev, AX_CMD_SW_RESET, flags, 0, 0, NULL);
	if (ret < 0)
		devdbg(dev,"Failed to send software reset: %02x", ret);

	return ret;
}

static int asix_write_rx_ctl(struct usbnet *dev, u16 mode)
{
	int ret;

	ret = asix_write_cmd(dev, AX_CMD_WRITE_RX_CTL, mode, 0, 0, NULL);
	if (ret < 0)
                devdbg(dev, "Failed to write RX_CTL mode: %02x", ret);

	return ret;
}

static void asix_status(struct usbnet *dev, struct urb *urb)
{
	struct ax88172_int_data *event;
	int link;

	if (urb->actual_length < 8)
		return;

	event = urb->transfer_buffer;
	link = event->link & 0x01;
	if (netif_carrier_ok(dev->net) != link) {
		if (link) {
			netif_carrier_on(dev->net);
			usbnet_defer_kevent (dev, EVENT_LINK_RESET );
		} else
			netif_carrier_off(dev->net);
		devdbg(dev, "Link Status is: %d", link);
	}
}

static void
asix_write_cmd_async(struct usbnet *dev, u8 cmd, u16 value, u16 index,
				    u16 size, void *data)
{
	struct usb_ctrlrequest *req;
	int status;
	struct urb *urb;

	if ((urb = usb_alloc_urb(0, GFP_ATOMIC)) == NULL) {
		devdbg(dev, "Error allocating URB in write_cmd_async!");
		return;
	}

	if ((req = kmalloc(sizeof(struct usb_ctrlrequest), GFP_ATOMIC)) == NULL) {
		deverr(dev, "Failed to allocate memory for control request");
		usb_free_urb(urb);
		return;
	}

	req->bRequestType = USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
	req->bRequest = cmd;
	req->wValue = cpu_to_le16(value);
	req->wIndex = cpu_to_le16(index);
	req->wLength = cpu_to_le16(size);

	usb_fill_control_urb(urb, dev->udev,
			     usb_sndctrlpipe(dev->udev, 0),
			     (void *)req, data, size,
			     asix_async_cmd_callback, req);

	if((status = usb_submit_urb(urb, GFP_ATOMIC)) < 0) {
		deverr(dev, "Error submitting the control message: status=%d",
				status);
		kfree(req);
		usb_free_urb(urb);
	}
}

static void asix_set_multicast(struct net_device *net)
{
	struct usbnet *dev = netdev_priv(net);
	struct asix_data *data = (struct asix_data *)&dev->data;
	u8 rx_ctl = 0x8c;

	if (net->flags & IFF_PROMISC) {
		rx_ctl |= 0x01;
	} else if (net->flags & IFF_ALLMULTI
		   || net->mc_count > AX_MAX_MCAST) {
		rx_ctl |= 0x02;
	} else if (net->mc_count == 0) {
		/* just broadcast and directed */
	} else {
		/* We use the 20 byte dev->data
		 * for our 8 byte filter buffer
		 * to avoid allocating memory that
		 * is tricky to free later */
		struct dev_mc_list *mc_list = net->mc_list;
		u32 crc_bits;
		int i;

		memset(data->multi_filter, 0, AX_MCAST_FILTER_SIZE);

		/* Build the multicast hash filter. */
		for (i = 0; i < net->mc_count; i++) {
			crc_bits =
			    ether_crc(ETH_ALEN,
				      mc_list->dmi_addr) >> 26;
			data->multi_filter[crc_bits >> 3] |=
			    1 << (crc_bits & 7);
			mc_list = mc_list->next;
		}

		asix_write_cmd_async(dev, AX_CMD_WRITE_MULTI_FILTER, 0, 0,
				   AX_MCAST_FILTER_SIZE, data->multi_filter);

		rx_ctl |= 0x10;
	}

	asix_write_cmd_async(dev, AX_CMD_WRITE_RX_CTL, rx_ctl, 0, 0, NULL);
}

static int asix_mdio_read(struct net_device *netdev, int phy_id, int loc)
{
	struct usbnet *dev = netdev_priv(netdev);
	u16 res;

	asix_set_sw_mii(dev);
	asix_read_cmd(dev, AX_CMD_READ_MII_REG, phy_id,
				(__u16)loc, 2, (u16 *)&res);
	asix_set_hw_mii(dev);

	return res & 0xffff;
}

/* same as above, but converts resulting value to cpu byte order */
static int asix_mdio_read_le(struct net_device *netdev, int phy_id, int loc)
{
	return le16_to_cpu(asix_mdio_read(netdev,phy_id, loc));
}

static void
asix_mdio_write(struct net_device *netdev, int phy_id, int loc, int val)
{
	struct usbnet *dev = netdev_priv(netdev);
	u16 res = val;

	asix_set_sw_mii(dev);
	asix_write_cmd(dev, AX_CMD_WRITE_MII_REG, phy_id,
				(__u16)loc, 2, (u16 *)&res);
	asix_set_hw_mii(dev);
}

/* same as above, but converts new value to le16 byte order before writing */
static void
asix_mdio_write_le(struct net_device *netdev, int phy_id, int loc, int val)
{
	asix_mdio_write( netdev, phy_id, loc, cpu_to_le16(val) );
}

static int ax88172_link_reset(struct usbnet *dev)
{
	u16 lpa;
	u16 adv;
	u16 res;
	u8 mode;

	mode = AX_MEDIUM_TX_ABORT_ALLOW | AX_MEDIUM_FLOW_CONTROL_EN;
	lpa = asix_mdio_read_le(dev->net, dev->mii.phy_id, MII_LPA);
	adv = asix_mdio_read_le(dev->net, dev->mii.phy_id, MII_ADVERTISE);
	res = mii_nway_result(lpa|adv);
	if (res & LPA_DUPLEX)
		mode |= AX_MEDIUM_FULL_DUPLEX;
	asix_write_cmd(dev, AX_CMD_WRITE_MEDIUM_MODE, mode, 0, 0, NULL);

	return 0;
}

static void
asix_get_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
	struct usbnet *dev = netdev_priv(net);
	u8 opt;

	if (asix_read_cmd(dev, AX_CMD_READ_MONITOR_MODE, 0, 0, 1, &opt) < 0) {
		wolinfo->supported = 0;
		wolinfo->wolopts = 0;
		return;
	}
	wolinfo->supported = WAKE_PHY | WAKE_MAGIC;
	wolinfo->wolopts = 0;
	if (opt & AX_MONITOR_MODE) {
		if (opt & AX_MONITOR_LINK)
			wolinfo->wolopts |= WAKE_PHY;
		if (opt & AX_MONITOR_MAGIC)
			wolinfo->wolopts |= WAKE_MAGIC;
	}
}

static int
asix_set_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
	struct usbnet *dev = netdev_priv(net);
	u8 opt = 0;
	u8 buf[1];

	if (wolinfo->wolopts & WAKE_PHY)
		opt |= AX_MONITOR_LINK;
	if (wolinfo->wolopts & WAKE_MAGIC)
		opt |= AX_MONITOR_MAGIC;
	if (opt != 0)
		opt |= AX_MONITOR_MODE;

	if (asix_write_cmd(dev, AX_CMD_WRITE_MONITOR_MODE,
			      opt, 0, 0, &buf) < 0)
		return -EINVAL;

	return 0;
}

static int asix_get_eeprom_len(struct net_device *net)
{
	return AX_EEPROM_LEN;
}

static int asix_get_eeprom(struct net_device *net,
			      struct ethtool_eeprom *eeprom, u8 *data)
{
	struct usbnet *dev = netdev_priv(net);
	u16 *ebuf = (u16 *)data;
	int i;

	/* Crude hack to ensure that we don't overwrite memory
	 * if an odd length is supplied
	 */
	if (eeprom->len % 2)
		return -EINVAL;

	eeprom->magic = AX_EEPROM_MAGIC;

	/* ax8817x returns 2 bytes from eeprom on read */
	for (i=0; i < eeprom->len / 2; i++) {
		if (asix_read_cmd(dev, AX_CMD_READ_EEPROM,
			eeprom->offset + i, 0, 2, &ebuf[i]) < 0)
			return -EINVAL;
	}
	return 0;
}

static void asix_get_drvinfo (struct net_device *net,
				 struct ethtool_drvinfo *info)
{
	/* Inherit standard device info */
	usbnet_get_drvinfo(net, info);
	info->eedump_len = 0x3e;
}

static int asix_get_settings(struct net_device *net, struct ethtool_cmd *cmd)
{
	struct usbnet *dev = netdev_priv(net);

	return mii_ethtool_gset(&dev->mii,cmd);
}

static int asix_set_settings(struct net_device *net, struct ethtool_cmd *cmd)
{
	struct usbnet *dev = netdev_priv(net);

	return mii_ethtool_sset(&dev->mii,cmd);
}

/* We need to override some ethtool_ops so we require our
   own structure so we don't interfere with other usbnet
   devices that may be connected at the same time. */
static struct ethtool_ops ax88172_ethtool_ops = {
	.get_drvinfo		= asix_get_drvinfo,
	.get_link		= ethtool_op_get_link,
	.get_msglevel		= usbnet_get_msglevel,
	.set_msglevel		= usbnet_set_msglevel,
	.get_wol		= asix_get_wol,
	.set_wol		= asix_set_wol,
	.get_eeprom_len		= asix_get_eeprom_len,
	.get_eeprom		= asix_get_eeprom,
	.get_settings		= asix_get_settings,
	.set_settings		= asix_set_settings,
};

static int asix_ioctl (struct net_device *net, struct ifreq *rq, int cmd)
{
	struct usbnet *dev = netdev_priv(net);

	return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}

static int ax88172_bind(struct usbnet *dev, struct usb_interface *intf)
{
	int ret = 0;
	void *buf;
	int i;
	unsigned long gpio_bits = dev->driver_info->data;

	usbnet_get_endpoints(dev,intf);

	buf = kmalloc(ETH_ALEN, GFP_KERNEL);
	if(!buf) {
		ret = -ENOMEM;
		goto out1;
	}

	/* Toggle the GPIOs in a manufacturer/model specific way */
	for (i = 2; i >= 0; i--) {
		if ((ret = asix_write_cmd(dev, AX_CMD_WRITE_GPIOS,
					(gpio_bits >> (i * 8)) & 0xff, 0, 0,
					buf)) < 0)
			goto out2;
		msleep(5);
	}

	if ((ret = asix_write_rx_ctl(dev,0x80)) < 0)
		goto out2;

	/* Get the MAC address */
	memset(buf, 0, ETH_ALEN);
	if ((ret = asix_read_cmd(dev, AX_CMD_READ_NODE_ID,
				0, 0, 6, buf)) < 0) {
		dbg("read AX_CMD_READ_NODE_ID failed: %d", ret);
		goto out2;
	}
	memcpy(dev->net->dev_addr, buf, ETH_ALEN);

	/* Initialize MII structure */
	dev->mii.dev = dev->net;
	dev->mii.mdio_read = asix_mdio_read;
	dev->mii.mdio_write = asix_mdio_write;
	dev->mii.phy_id_mask = 0x3f;
	dev->mii.reg_num_mask = 0x1f;
	dev->mii.phy_id = asix_get_phyid(dev);
	dev->net->do_ioctl = asix_ioctl;

	dev->net->set_multicast_list = asix_set_multicast;
	dev->net->ethtool_ops = &ax88172_ethtool_ops;

	asix_mdio_write_le(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
	asix_mdio_write_le(dev->net, dev->mii.phy_id, MII_ADVERTISE,
		ADVERTISE_ALL | ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP);
	mii_nway_restart(&dev->mii);

	return 0;
out2:
	kfree(buf);
out1:
	return ret;
}

static struct ethtool_ops ax88772_ethtool_ops = {
	.get_drvinfo		= asix_get_drvinfo,
	.get_link		= ethtool_op_get_link,
	.get_msglevel		= usbnet_get_msglevel,
	.set_msglevel		= usbnet_set_msglevel,
	.get_wol		= asix_get_wol,
	.set_wol		= asix_set_wol,
	.get_eeprom_len		= asix_get_eeprom_len,
	.get_eeprom		= asix_get_eeprom,
	.get_settings		= asix_get_settings,
	.set_settings		= asix_set_settings,
};

static int ax88772_bind(struct usbnet *dev, struct usb_interface *intf)
{
	int ret;
	void *buf;

	usbnet_get_endpoints(dev,intf);

	buf = kmalloc(6, GFP_KERNEL);
	if(!buf) {
		dbg ("Cannot allocate memory for buffer");
		ret = -ENOMEM;
		goto out1;
	}

	if ((ret = asix_write_cmd(dev, AX_CMD_WRITE_GPIOS,
				     0x00B0, 0, 0, buf)) < 0)
		goto out2;

	msleep(5);
	if ((ret = asix_write_cmd(dev, AX_CMD_SW_PHY_SELECT,
				0x0001, 0, 0, buf)) < 0) {
		dbg("Select PHY #1 failed: %d", ret);
		goto out2;
	}

	if ((ret = asix_sw_reset(dev, AX_SWRESET_IPPD)) < 0)
		goto out2;

	msleep(150);
	if ((ret = asix_sw_reset(dev, AX_SWRESET_CLEAR)) < 0)
		goto out2;

	msleep(150);
	if ((ret = asix_sw_reset(dev, AX_SWRESET_IPRL | AX_SWRESET_PRL)) < 0)
		goto out2;

	msleep(150);
	if ((ret = asix_write_rx_ctl(dev, 0x00)) < 0)
		goto out2;

	/* Get the MAC address */
	memset(buf, 0, ETH_ALEN);
	if ((ret = asix_read_cmd(dev, AX88772_CMD_READ_NODE_ID,
				0, 0, ETH_ALEN, buf)) < 0) {
		dbg("Failed to read MAC address: %d", ret);
		goto out2;
	}
	memcpy(dev->net->dev_addr, buf, ETH_ALEN);

	if ((ret = asix_set_sw_mii(dev)) < 0)
		goto out2;

#ifdef BRCM_FIX		//for adapters with external PHY
	if (((ret = asix_read_cmd(dev, AX_CMD_READ_MII_REG,
	      			0x0010, 2, 2, buf)) < 0)) {
		dbg("Read PHY register 2 failed: %d", ret);
		goto out2;
	}
	if (le16_to_cpu(*((u16 *)buf)) != 0x003b) {	//assume external PHY
		if ((ret = asix_write_cmd(dev, AX_CMD_SW_PHY_SELECT,
					0, 0, 0, buf)) < 0) {
			dbg("Select PHY #0 failed: %d", ret);
			goto out2;
		}
	}
#else
	if (((ret = asix_read_cmd(dev, AX_CMD_READ_MII_REG,
	      			0x0010, 2, 2, buf)) < 0)
			|| (*((u16 *)buf) != 0x003b)) {
		dbg("Read PHY register 2 must be 0x3b00: %d", ret);
		goto out2;
	}
#endif

	/* Initialize MII structure */
	dev->mii.dev = dev->net;
	dev->mii.mdio_read = asix_mdio_read;
	dev->mii.mdio_write = asix_mdio_write;
	dev->mii.phy_id_mask = 0xff;
	dev->mii.reg_num_mask = 0xff;
	dev->net->do_ioctl = asix_ioctl;
	dev->mii.phy_id = asix_get_phyid(dev);

	if ((ret = asix_sw_reset(dev, AX_SWRESET_PRL)) < 0)
		goto out2;

	msleep(150);

	if ((ret = asix_sw_reset(dev, AX_SWRESET_IPRL | AX_SWRESET_PRL)) < 0)
		goto out2;

	msleep(150);

	dev->net->set_multicast_list = asix_set_multicast;
	dev->net->ethtool_ops = &ax88772_ethtool_ops;

	asix_mdio_write_le(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
	asix_mdio_write_le(dev->net, dev->mii.phy_id, MII_ADVERTISE,
			ADVERTISE_ALL | ADVERTISE_CSMA);
	mii_nway_restart(&dev->mii);

	if ((ret = asix_write_cmd(dev, AX_CMD_WRITE_MEDIUM_MODE,
				AX88772_MEDIUM_DEFAULT, 0, 0, buf)) < 0) {
		dbg("Write medium mode register: %d", ret);
		goto out2;
	}

	if ((ret = asix_write_cmd(dev, AX_CMD_WRITE_IPG0,
				AX88772_IPG0_DEFAULT | AX88772_IPG1_DEFAULT,
				AX88772_IPG2_DEFAULT, 0, buf)) < 0) {
		dbg("Write IPG,IPG1,IPG2 failed: %d", ret);
		goto out2;
	}
	if ((ret = asix_set_hw_mii(dev)) < 0)
		goto out2;

	/* Set RX_CTL to default values with 2k buffer, and enable cactus */
	if ((ret = asix_write_rx_ctl(dev, 0x0088)) < 0)
		goto out2;

	kfree(buf);

	/* Asix framing packs multiple eth frames into a 2K usb bulk transfer */
	if (dev->driver_info->flags & FLAG_FRAMING_AX) {
		/* hard_mtu  is still the default - the device does not support
		   jumbo eth frames */
		dev->rx_urb_size = 2048;
	}

	return 0;

out2:
	kfree(buf);
out1:
	return ret;
}

static int ax88772_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
	u8  *head;
	u32  header;
	char *packet;
	struct sk_buff *ax_skb;
	u16 size;

	head = (u8 *) skb->data;
	memcpy(&header, head, sizeof(header));
	le32_to_cpus(&header);
	packet = head + sizeof(header);

	skb_pull(skb, 4);

	while (skb->len > 0) {
		if ((short)(header & 0x0000ffff) !=
		    ~((short)((header & 0xffff0000) >> 16))) {
			devdbg(dev,"header length data is error");
		}
		/* get the packet length */
		size = (u16) (header & 0x0000ffff);

		if ((skb->len) - ((size + 1) & 0xfffe) == 0)
			return 2;
		if (size > ETH_FRAME_LEN) {
			devdbg(dev,"invalid rx length %d", size);
			return 0;
		}
		ax_skb = skb_clone(skb, GFP_ATOMIC);
		if (ax_skb) {
			ax_skb->len = size;
			ax_skb->data = packet;
			ax_skb->tail = packet + size;
			usbnet_skb_return(dev, ax_skb);
		} else {
			return 0;
		}

		skb_pull(skb, (size + 1) & 0xfffe);

		if (skb->len == 0)
			break;

		head = (u8 *) skb->data;
		memcpy(&header, head, sizeof(header));
		le32_to_cpus(&header);
		packet = head + sizeof(header);
		skb_pull(skb, 4);
	}

	if (skb->len < 0) {
		devdbg(dev,"invalid rx length %d", skb->len);
		return 0;
	}
	return 1;
}

static struct sk_buff *ax88772_tx_fixup(struct usbnet *dev, struct sk_buff *skb,
					// This type is not defined in 2.6.12 ->gfp_t flags)
					unsigned int flags)
{
	int padlen;
	int headroom = skb_headroom(skb);
	int tailroom = skb_tailroom(skb);
	u32 packet_len;
	u32 padbytes = 0xffff0000;

	padlen = ((skb->len + 4) % 512) ? 0 : 4;

	if ((!skb_cloned(skb))
	    && ((headroom + tailroom) >= (4 + padlen))) {
		if ((headroom < 4) || (tailroom < padlen)) {
			skb->data = memmove(skb->head + 4, skb->data, skb->len);
			skb->tail = skb->data + skb->len;
		}
	} else {
		struct sk_buff *skb2;
		skb2 = skb_copy_expand(skb, 4, padlen, flags);
		dev_kfree_skb_any(skb);
		skb = skb2;
		if (!skb)
			return NULL;
	}

	skb_push(skb, 4);
#ifdef BRCM_FIX
	packet_len = cpu_to_le32((((skb->len - 4) ^ 0x0000ffff) << 16) + (skb->len - 4));
#else
	packet_len = (((skb->len - 4) ^ 0x0000ffff) << 16) + (skb->len - 4);
#endif
	memcpy(skb->data, &packet_len, sizeof(packet_len));

	if ((skb->len % 512) == 0) {
		memcpy( skb->tail, &padbytes, sizeof(padbytes));
		skb_put(skb, sizeof(padbytes));
	}
	return skb;
}

static int ax88772_link_reset(struct usbnet *dev)
{
	u16 lpa;
	u16 adv;
	u16 res;
	u16 mode;

	mode = AX88772_MEDIUM_DEFAULT;
	lpa = asix_mdio_read_le(dev->net, dev->mii.phy_id, MII_LPA);
	adv = asix_mdio_read_le(dev->net, dev->mii.phy_id, MII_ADVERTISE);
	res = mii_nway_result(lpa|adv);

	if ((res & LPA_DUPLEX) == 0)
		mode &= ~AX88772_MEDIUM_FULL_DUPLEX;
	if ((res & LPA_100) == 0)
		mode &= ~AX88772_MEDIUM_100MB;
	asix_write_cmd(dev, AX_CMD_WRITE_MEDIUM_MODE, mode, 0, 0, NULL);

	return 0;
}

static const struct driver_info ax8817x_info = {
	.description = "ASIX AX8817x USB 2.0 Ethernet",
	.bind = ax88172_bind,
	.status = asix_status,
	.link_reset = ax88172_link_reset,
	.reset = ax88172_link_reset,
	.flags =  FLAG_ETHER,
	.data = 0x00130103,
};

static const struct driver_info dlink_dub_e100_info = {
	.description = "DLink DUB-E100 USB Ethernet",
	.bind = ax88172_bind,
	.status = asix_status,
	.link_reset = ax88172_link_reset,
	.reset = ax88172_link_reset,
	.flags =  FLAG_ETHER,
	.data = 0x009f9d9f,
};

static const struct driver_info netgear_fa120_info = {
	.description = "Netgear FA-120 USB Ethernet",
	.bind = ax88172_bind,
	.status = asix_status,
	.link_reset = ax88172_link_reset,
	.reset = ax88172_link_reset,
	.flags =  FLAG_ETHER,
	.data = 0x00130103,
};

static const struct driver_info hawking_uf200_info = {
	.description = "Hawking UF200 USB Ethernet",
	.bind = ax88172_bind,
	.status = asix_status,
	.link_reset = ax88172_link_reset,
	.reset = ax88172_link_reset,
	.flags =  FLAG_ETHER,
	.data = 0x001f1d1f,
};

static const struct driver_info ax88772_info = {
	.description = "ASIX AX88772 USB 2.0 Ethernet",
	.bind = ax88772_bind,
	.status = asix_status,
	.link_reset = ax88772_link_reset,
	.reset = ax88772_link_reset,
	.flags = FLAG_ETHER | FLAG_FRAMING_AX,
	.rx_fixup = ax88772_rx_fixup,
	.tx_fixup = ax88772_tx_fixup,
};

static const struct usb_device_id	products [] = {
{
	// Linksys USB200M
	USB_DEVICE (0x077b, 0x2226),
	.driver_info =	(unsigned long) &ax8817x_info,
}, {
	// Netgear FA120
	USB_DEVICE (0x0846, 0x1040),
	.driver_info =  (unsigned long) &netgear_fa120_info,
}, {
	// DLink DUB-E100
	USB_DEVICE (0x2001, 0x1a00),
	.driver_info =  (unsigned long) &dlink_dub_e100_info,
}, {
	// DLink DUB-E100, Rev. B
	USB_DEVICE (0x2001, 0x3c05),
	.driver_info =  (unsigned long) &ax88772_info,
}, {
	// Intellinet, ST Lab USB Ethernet
	USB_DEVICE (0x0b95, 0x1720),
	.driver_info =  (unsigned long) &ax8817x_info,
}, {
	// Hawking UF200, TrendNet TU2-ET100
	USB_DEVICE (0x07b8, 0x420a),
	.driver_info =  (unsigned long) &hawking_uf200_info,
}, {
        // Billionton Systems, USB2AR
        USB_DEVICE (0x08dd, 0x90ff),
        .driver_info =  (unsigned long) &ax8817x_info,
}, {
	// ATEN UC210T
	USB_DEVICE (0x0557, 0x2009),
	.driver_info =  (unsigned long) &ax8817x_info,
}, {
	// Buffalo LUA-U2-KTX
	USB_DEVICE (0x0411, 0x003d),
	.driver_info =  (unsigned long) &ax8817x_info,
}, {
	// Sitecom LN-029 "USB 2.0 10/100 Ethernet adapter"
	USB_DEVICE (0x6189, 0x182d),
	.driver_info =  (unsigned long) &ax8817x_info,
}, {
	// corega FEther USB2-TX
	USB_DEVICE (0x07aa, 0x0017),
	.driver_info =  (unsigned long) &ax8817x_info,
}, {
	// Surecom EP-1427X-2
	USB_DEVICE (0x1189, 0x0893),
	.driver_info = (unsigned long) &ax8817x_info,
}, {
	// goodway corp usb gwusb2e
	USB_DEVICE (0x1631, 0x6200),
	.driver_info = (unsigned long) &ax8817x_info,
}, {
	// ASIX AX88772 10/100
        USB_DEVICE (0x0b95, 0x7720),
        .driver_info = (unsigned long) &ax88772_info,
}, {
	// ASIX AX88178 10/100/1000
	USB_DEVICE (0x0b95, 0x1780),
	.driver_info = (unsigned long) &ax88772_info,
}, {
	// Linksys USB200M Rev 2
	USB_DEVICE (0x13b1, 0x0018),
	.driver_info = (unsigned long) &ax88772_info,
}, {
	// 0Q0 cable ethernet
	USB_DEVICE (0x1557, 0x7720),
	.driver_info = (unsigned long) &ax88772_info,
},
	{ },		// END
};
MODULE_DEVICE_TABLE(usb, products);

static struct usb_driver asix_driver = {
	.name =		"asix",
	.id_table =	products,
	.probe =	usbnet_probe,
	.suspend =	usbnet_suspend,
	.resume =	usbnet_resume,
	.disconnect =	usbnet_disconnect,
};

static int __init asix_init(void)
{
 	return usb_register(&asix_driver);
}
module_init(asix_init);

static void __exit asix_exit(void)
{
 	usb_deregister(&asix_driver);
}
module_exit(asix_exit);

MODULE_AUTHOR("David Hollis");
MODULE_DESCRIPTION("ASIX AX8817X based USB 2.0 Ethernet Devices");
MODULE_LICENSE("GPL");


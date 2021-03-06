/*
 *
 * BRIEF MODULE DESCRIPTION
 *	Bcm97038B0 Board specific pci fixups.
 *
 * Copyright 2004-2005 Broadcom Corp.
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 *  THIS  SOFTWARE  IS PROVIDED   ``AS  IS'' AND   ANY  EXPRESS OR IMPLIED
 *  WARRANTIES,   INCLUDING, BUT NOT  LIMITED  TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 *  NO  EVENT  SHALL   THE AUTHOR  BE    LIABLE FOR ANY   DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED   TO, PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES; LOSS OF
 *  USE, DATA,  OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN  CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  You should have received a copy of the  GNU General Public License along
 *  with this program; if not, write  to the Free Software Foundation, Inc.,
 *  675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * Revision Log
 * who when    what
 * tht  041004 Adapted from sample codes from kernel tree
 */
#include <linux/types.h>
#include <linux/pci.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/pci_ids.h>
#include <linux/ioport.h>
#include <asm/io.h>

#include <asm/brcmstb/brcm97038/boardmap.h>
#include <asm/brcmstb/brcm97038/bchp_hif_cpu_intr1.h>
#include <asm/brcmstb/brcm97038/bcmintrnum.h>

#define DEBUG 1


/* from PCI spec, Maybe we can put this in some include file. */
#define PCI_ENABLE              0x80000000
#define PCI_IDSEL(x)		(((x)&0x1f)<<11)
#define PCI_FNCSEL(x)		(((x)&0x7)<<8)

/* Since the following is not defined in any of our header files. */
#define MIPS_PCI_XCFG_INDEX     0xe0600004
#define MIPS_PCI_XCFG_DATA      0xe0600008


#define BCM7038_SATA_VID		0x02421166
#define BCM3250_VID				0x325014e4
#define BCM7041_VID				0xa000141f

/* For now until the BSP defines them */
/* For SATA MMIO BAR5 */
#define PCI_SATA_PHYS_MEM_WIN5_BASE \
	(PCI_7041_PHYS_MEM_WIN0_BASE+0xc0000)
//#define PCI_SATA_PHYS_MEM_WIN5_BASE 0x02000000
#define PCI_SATA_PHYS_MEM_WIN5_SIZE 0x2000

#define PCI_EXPANSION_PHYS_MEM_WIN0_BASE \
	(PCI_SATA_PHYS_MEM_WIN5_BASE+PCI_SATA_PHYS_MEM_WIN5_SIZE)

#define PCI_EXPANSION_PHYS_IO_WIN0_BASE 0x400

// 2nd PCI slot on certain boards.
#define PCI_DEVICE_ID_EXT2 0x0c




void __init pcibios_fixup_irqs(void)
{
	struct pci_dev *dev;
	int slot_num;

#ifdef DEBUG
printk("-->pcibios_fixup_irqs\n");
#endif

	pci_for_each_dev(dev) {
		slot_num = PCI_SLOT(dev->devfn);
#ifdef DEBUG
printk("-->pcibios_fixup_irqs, slot=%x\n", slot_num);
#endif
		switch (slot_num) {
		case PCI_DEVICE_ID_3250:		/* BCM3250  */
			pcibios_update_irq(dev, BCM_LINUX_3250_IRQ);
			dev->irq = BCM_LINUX_3250_IRQ;
			break;
		case PCI_DEVICE_ID_SATA:	/* IDE controller */
			pcibios_update_irq(dev, BCM_LINUX_SATA_IRQ);
			dev->irq = BCM_LINUX_SATA_IRQ;
			break;
		case PCI_DEVICE_ID_EXT:	/* On-board PCI slot */
			pcibios_update_irq(dev, BCM_LINUX_EXT_PCI_IRQ);
			dev->irq = BCM_LINUX_EXT_PCI_IRQ;
			break;
		case PCI_DEVICE_ID_7041:
			/* do not need to fixup. */
		break;
		case PCI_DEVICE_ID_EXT2: /* On-board 2nd PCI slot */
			/* For board with 2 expansion slots, both slots share the same IRQ */
			pcibios_update_irq(dev, BCM_LINUX_EXT_PCI_IRQ);
			dev->irq = BCM_LINUX_EXT_PCI_IRQ;
			break;
		
		default:
			printk("unknown slot num 0x%x for pcibios_fixup_irqs\n", slot_num);
		break;
		}
	}
}



void __init pcibios_update_irq(struct pci_dev *dev, int irq)
{
    u8 val;

#ifdef DEBUG
printk("-->pcibios_update_irq\n");
#endif

	pci_write_config_byte(dev, PCI_INTERRUPT_LINE, irq);

	/* Test this as it does not seem to be working */
	pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &val);
}


unsigned int pcibios_assign_all_busses(void)
{
	return 0;
}

// global to allow multiple slots
static u32 memAddr = PCI_EXPANSION_PHYS_MEM_WIN0_BASE;
static u32 ioAddr = PCI_EXPANSION_PHYS_IO_WIN0_BASE;

// Remembers which devices have already been assigned.
static  int slots[16];

/* Do IO/memory allocation for expansion slot here */
static __init void brcm_pcibios_fixup_expansion_slot(struct pci_dev *dev) 
{
	int i,j,k,l, iosize, msize;
	//int useIOAddr = 0;
	u32 savRegData;
	u32 size;
	u32 mask;
	int slot;
	u32 regData;
		

	/*
	* Make sure that it is in the PCI slot, otherwise we punt.
	*/


	slot = PCI_SLOT(dev->devfn);

	/* Only handle devices in the PCI slot */
	if ( !(PCI_DEVICE_ID_EXT == slot || PCI_DEVICE_ID_EXT2 == slot)) {
		printk("\tDev ID %04x:%04x ignored\n", dev->vendor, dev->device);
		return;
	}

	if (slots[slot]) {
		printk("Skip resource assignment for dev ID %04x:%04x already allocated\n", dev->vendor, dev->device);
		return;
	}

	slots[slot] = 1;

//	pcibios_update_irq(dev, BCM_LINUX_EXT_PCI_IRQ);
//	dev->irq = BCM_LINUX_EXT_PCI_IRQ;


	printk("\tPCI DEV in PCI slot, ID=%04x:%04x\n\r", dev->vendor, dev->device);
	

	/* Write FFFFFFFFH to BAR registers to probe for IO or Mem */
	iosize = msize = 0;
	for (i=0,j=0; i<6; i++,j+=4) {
		pci_write_config_dword(dev,PCI_BASE_ADDRESS_0+j,0xffffffff);
		pci_read_config_dword(dev,PCI_BASE_ADDRESS_0+j,&regData);
		if (regData) {
			printk("Expansion: PCI_BAR[%d] = %x\n", i, regData);


			savRegData = regData;
			regData &= 0xfffffff0; /* Get rid of Bit 0-3 0=Mem, 2:1 32/64, 3=
Prefetchable */
			/*
			* determine io/mem size here by looking at the BAR
			* register, skipping the first 4 bits
			*/
			for (k=4; k<32; k++) {
				if (regData & (1<<k)) {
					break;
		}
	}
			if (k < 32) {
				printk("Expansion: size requested is %x\n", 1<<k);
				size = 1<<k;
				mask = 0xffffffff;
				for (l=0; l<k; l++) {
					mask &= ~(1<<l);
	}
}
			else
				break;
			/* Only the first BAR counts on most devices */
			//if (i == 0) {
			//	useIOAddr = savRegData & 0x1;
			//}

			if (savRegData & 0x1) {	/* IO address */
				/* Calculate the next address that satisfies the boundary condition */
				ioAddr = (ioAddr + size - 1) & mask;
				pci_write_config_dword(dev, PCI_BASE_ADDRESS_0+j, ioAddr);
				printk("Expansion: Writing PCI_IO_BAR[%d]=%x, size=%d, mask=%x\n", i,
					ioAddr, 1<<k, mask);
				iosize += size;
			}
			else { /* Mem address, tag on to the last one, the 7041 mem area */
				/* Calculate the next address that satisfies the boundary condition */
				memAddr = (memAddr + size - 1) & ~(size -1);
				pci_write_config_dword(dev, PCI_BASE_ADDRESS_0+j, memAddr);
				printk("Expansion: Writing PCI_MEM_BAR[%d]=%x, size=%d, mask=%x\n", i,
					memAddr, 1<<k, mask);
				msize = memAddr + size;
			}
		}
	}
	/*  now that it's all configured, turn on the Command Register */
	pci_read_config_dword(dev,PCI_COMMAND,&regData);
	regData |= PCI_COMMAND_SERR|PCI_COMMAND_PARITY |PCI_COMMAND_MASTER;
	if (iosize > 0)
		regData |= PCI_COMMAND_IO;
	if (msize > 0)
		regData |= PCI_COMMAND_MEMORY;

	printk("\tExpansion: PCI_DEV %04x:%04x, command=%x\n", 
		dev->vendor, dev->device, regData);
	pci_write_config_dword(dev,PCI_COMMAND,regData);

	
}



void __init pcibios_fixup_resources(struct pci_dev *dev)
{

}




void __init brcm_pcibios_fixup_device(struct pci_dev *dev)
{
	u32 dev_vendor_id;
	u32 regData;
	u32 size;


	/********************************************************
	 * Configure the Device
	 ********************************************************/
	dev_vendor_id = (u32)dev->device<<16;
	dev_vendor_id |= dev->vendor;
	switch (dev_vendor_id) {
	/********************************************************
	 * SATA Controller
	 ********************************************************/
	case BCM7038_SATA_VID:
		printk("Setting up SATA controller\n");
		
		regData = 0x201;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_0, regData);
		regData = 0x240;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_1, regData);
		regData = 0x280;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_2, regData);
		regData = 0x2c0;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_3, regData);
		regData = 0x300;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_4, regData);

		/* On 2.4.25, we have to assign some mem region for MMIO even though we
		 * have no intention of using it
		 */
		regData = PCI_SATA_PHYS_MEM_WIN5_BASE; //0x02000000;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_5, regData);
	
		
		regData = 0xff;
		pci_write_config_byte(dev, 0xd, regData); /* SATA_CFG_MASTER_LATENCY_TIMER. */

		pci_read_config_dword(dev, PCI_COMMAND, &regData);
		regData |= (PCI_COMMAND_MASTER|PCI_COMMAND_IO);
		pci_write_config_dword(dev, PCI_COMMAND, regData);

#if 0

#endif

//#define DONT_USE_SATA_DMA
#ifndef DONT_USE_SATA_DMA

		pci_read_config_dword(dev, PCI_BASE_ADDRESS_4, &regData);
		regData &= 0xfffffc; // Mask off  Reserved & Res Type bits.
		printk("SATA: Bus Master Status Register offset = %08lx + %08x = %08x\n", 
			mips_io_port_base, regData, mips_io_port_base+regData);
		printk("SATA: before init Bus Master Status reg = 0x%08x.\n", *((volatile unsigned char *)(mips_io_port_base+regData)));
		regData += 2; // Offset 302H
		*((volatile unsigned char *)(mips_io_port_base+regData)) |= 0x20;
		printk("SATA: after init Bus Master Status reg = 0x%08x.\n", *((volatile unsigned char *)(mips_io_port_base+regData)));
#endif

		break;

	/********************************************************
	 * Config the BCM3250 chip
	 ********************************************************/
	case BCM3250_VID:
		printk("\tBCM3250\n\r");
		regData = BCM3250_REG_BASE;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_0, regData);
		regData = BCM3250_MEM_BASE;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_1, regData);

		pci_read_config_dword(dev, PCI_COMMAND, &regData);
		regData |= PCI_COMMAND_MEMORY;
		pci_write_config_dword(dev, PCI_COMMAND, regData);

		break;

	/********************************************************
	 * Config the BCM7041 chip
	 ********************************************************/
	case BCM7041_VID:
		if (PCI_DEVICE_ID_EXT == PCI_SLOT(dev->devfn)) {
			printk("\tBCM7041 Dual Channel MPEG2 Encoder on PCI slot\n\r");
			brcm_pcibios_fixup_expansion_slot(dev);
			break;
		}
		printk("\tBCM7041 Dual Channel MPEG2 Encoder\n\r");
		regData = BCM7041_MEM_BASE;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_0, regData);
		regData += 0x20000;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_1, regData);
		regData += 0x20000;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_2, regData);
		regData += 0x20000;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_3, regData);
		regData += 0x20000;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_4, regData);
		regData += 0x20000;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_5, regData);
 
		pci_read_config_dword(dev, PCI_COMMAND, &regData);
		regData |= PCI_COMMAND_MEMORY;
		pci_write_config_dword(dev, PCI_COMMAND, regData);
		break;

#if 1
	/* Sand Video on expansion slot */
	case 0x540610b5:
	{
		//u32 memAddr = PCI_EXPANSION_PHYS_MEM_WIN0_BASE;
		//u32 ioAddr = PCI_EXPANSION_PHYS_IO_WIN0_BASE;
		int slot;	
			
		printk("\tSand Video\n\r");

		slot = PCI_SLOT(dev->devfn);
		if (slots[slot]) {
			printk("Skip resource assignment for dev ID %04x:%04x already allocated\n", dev->vendor, dev->device);
			return;
		}

		slots[slot] = 1;
		regData = memAddr;
		size = 256;
		memAddr += size;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_0, regData);
printk("SandVideo: Writing PCI_MEM_BAR[0]=%x, size=%08x\n",
					regData, size);
		
		regData = ioAddr;
		size = 256;
		ioAddr += size;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_1, regData);
printk("SandVideo: Writing PCI_IO_BAR[0]=%x, size=%08x\n",
					regData, size);
		
		size = 0x02000000;
		regData = (memAddr + size -1) & ~(size -1);
		memAddr = regData + size;
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_2, regData);
printk("SandVideo: Writing PCI_MEM_BAR[2]=%x, size=%08x\n",
					regData, size);

		size = 0x10000;
		regData = (memAddr + size -1) & ~(size -1); // which is just memAddr	
		pci_write_config_dword(dev, PCI_BASE_ADDRESS_3, regData);
printk("SandVideo: Writing PCI_MEM_BAR[3]=%x, size=%08x\n",
					regData, size);

		pci_read_config_dword(dev, PCI_COMMAND, &regData);
		regData |= (PCI_COMMAND_MASTER|PCI_COMMAND_IO| PCI_COMMAND_MEMORY);
		pci_write_config_dword(dev, PCI_COMMAND, regData);

		break;
	}
#endif
		
	default:
		printk("unknown dev_man id 0x%x, trying expansion slot\n", dev_vendor_id);
		brcm_pcibios_fixup_expansion_slot(dev);
		break;
	}
#ifdef DUMP_PCI_CONFIG
	{
	int i;
	printk("\tPCI Config Space IDSEL%d"),PCI_SLOT(dev->devfn));
	for (i=0;i<0x40;i++) {
		if ((i & 3) == 0) printk("\r\n\t\t");
		pci_read_config_byte(dev,i,(unsigned char *)&regData);
		printk("[%.2x]=%.2x  "),i,regData & 0xFF);
	}
	printk("\n\r");
	}
#endif
	return 0;
}

void __init pcibios_fixup(void)
{
    struct pci_dev *dev;
    pci_for_each_dev(dev) {
		/* <TDT> Our enable_device sets up bios data for the bootrom does not */
		brcm_pcibios_fixup_device(dev);

		/* <TDT> force a rescan in case we still need bios data */
		pci_setup_device(dev);
}
	}


void
dump_ide(void)
{
}
EXPORT_SYMBOL(dump_ide);





/*
 * drivers/mtd/brcmnand/brcmnand.h
 *
 *  Copyright (c) 2005,2006 Broadcom Corp.
 *  
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Data structures for Broadcom NAND controller
 * 
 * when		who		what
 * 20060729	tht		Original coding
 */


#ifndef _BRCM_NAND_H_
#define _BRCM_NAND_H_

#include <linux/config.h>
#include <linux/mtd/nand.h>
#include <linux/types.h>
#include <asm/brcmstb/common/brcmstb.h>

#ifdef CONFIG_MIPS_BCM7440B0
#include <asm/brcmstb/brcm97440b0/bchp_ebi.h>  // For CS registers
#endif

/*
 * Conversion between Kernel Kconfig and Controller version number
 */

#define CONFIG_MTD_BRCMNAND_VERS_0_0		0
#define CONFIG_MTD_BRCMNAND_VERS_0_1		1
#define CONFIG_MTD_BRCMNAND_VERS_1_0		2

#define BRCMNAND_VERSION(major, minor)	((major<<8) | minor)


#if CONFIG_MTD_BRCMNAND_VERSION >= CONFIG_MTD_BRCMNAND_VERS_1_0

#define L_OFF_T			int64_t
#define UL_OFF_T 		uint64_t
#define MAX_NAND_CS	8

#else
#define L_OFF_T			int32_t
#define UL_OFF_T 		uint32_t
#define MAX_NAND_CS	1
#endif


//ST NAND flashes
#ifndef FLASHTYPE_ST
    #define FLASHTYPE_ST            0x20
#endif
#define ST_NAND128W3A           0x73
#define ST_NAND256R3A           0x35
#define ST_NAND256W3A           0x75
#define ST_NAND256R4A           0x45
#define ST_NAND256W4A           0x55
#define ST_NAND512R3A           0x36    //Used on Bcm97400
#define ST_NAND512W3A           0x76
#define ST_NAND512R4A           0x46
#define ST_NAND512W4A           0x56
#define ST_NAND01GR3A           0x39
#define ST_NAND01GW3A           0x79
#define ST_NAND01GR4A           0x49
#define ST_NAND01GW4A           0x59
#define ST_NAND01GR3B           0xA1
#define ST_NAND01GW3B           0xF1
#define ST_NAND01GR4B           0xB1
#define ST_NAND01GW4B           0xC1
#define ST_NAND02GR3B           0xAA
#define ST_NAND02GW3B           0xDA
#define ST_NAND02GR4B           0xBA
#define ST_NAND02GW4B           0xCA
#define ST_NAND04GR3B           0xAC
#define ST_NAND04GW3B           0xDC
#define ST_NAND04GR4B           0xBC
#define ST_NAND04GW4B           0xCC
#define ST_NAND08GR3B           0xA3
#define ST_NAND08GW3B           0xD3
#define ST_NAND08GR4B           0xB3
#define ST_NAND08GW4B           0xC3

//Samsung NAND flash
#define FLASHTYPE_SAMSUNG       0xEC
#define SAMSUNG_K9F1G08R0A      0xA1
#define SAMSUNG_K9F1G08U0A      0xF1
#define SAMSUNG_K9F2G08U1A      0xF1
#define SAMSUNG_K9F2G08U0A      0xDA

//K9F5608(R/U/D)0D
#define SAMSUNG_K9F5608R0D      0x35
#define SAMSUNG_K9F5608U0D      0x75
#define SAMSUNG_K9F5608D0D      0x75
//K9F1208(R/B/U)0B
#define SAMSUNG_K9F1208R0B      0x36
#define SAMSUNG_K9F1208B0B      0x76
#define SAMSUNG_K9F1208U0B      0x76



//Hynix NAND flashes
#define FLASHTYPE_HYNIX         0xAD
//Hynix HY27(U/S)S(08/16)561A
#define HYNIX_HY27US08561A      0x75
#define HYNIX_HY27US16561A      0x55
#define HYNIX_HY27SS08561A      0x35
#define HYNIX_HY27SS16561A      0x45
//Hynix HY27(U/S)S(08/16)121A
#define HYNIX_HY27US08121A      0x76
#define HYNIX_HY27US16121A      0x56
#define HYNIX_HY27SS08121A      0x36
#define HYNIX_HY27SS16121A      0x46
//Hynix HY27(U/S)F(08/16)1G2M
#define HYNIX_HY27UF081G2M      0xF1
#define HYNIX_HY27UF161G2M      0xC1
#define HYNIX_HY27SF081G2M      0xA1
#define HYNIX_HY27SF161G2M      0xAD

/* This is the new version of HYNIX_HY27UF081G2M .  The 2M version is EOL */
#define HYNIX_HY27UF081G2A      0xF1

#define HYNIX_HY27UF082G2A      0xDA
#define HYNIX_HY27UF084G2M     0xDC

//Micron flashes
#define FLASHTYPE_MICRON        0x2C
//MT29F2G(08/16)AAB
#define MICRON_MT29F2G08AAB     0xDA
#define MICRON_MT29F2G16AAB     0xCA

//Spansion flashes
#ifndef FLASHTYPE_SPANSION
    #define FLASHTYPE_SPANSION      0x01
#endif
#define SPANSION_S30ML01GP_08   0xF1    //x8 mode
#define SPANSION_S30ML01GP_16   0xC1    //x16 mode
#define SPANSION_S30ML02GP_08   0xDA    //x8 mode
#define SPANSION_S30ML02GP_16   0xCA    //x16 mode
#define SPANSION_S30ML04GP_08   0xDC    //x8 mode
#define SPANSION_S30ML04GP_16   0xCC    //x16 mode


//Command Opcode
#define OP_PAGE_READ                0x01000000
#define OP_SPARE_AREA_READ          0x02000000
#define OP_STATUS_READ              0x03000000
#define OP_PROGRAM_PAGE             0x04000000
#define OP_PROGRAM_SPARE_AREA       0x05000000
#define OP_COPY_BACK                0x06000000
#define OP_DEVICE_ID_READ           0x07000000
#define OP_BLOCK_ERASE              0x08000000
#define OP_FLASH_RESET              0x09000000
#define OP_BLOCKS_LOCK              0x0A000000
#define OP_BLOCKS_LOCK_DOWN         0x0B000000
#define OP_BLOCKS_UNLOCK            0x0C000000
#define OP_READ_BLOCKS_LOCK_STATUS  0x0D000000

//NAND flash controller 
#define NFC_FLASHCACHE_SIZE     512

#define BRCMNAND_CTRL_REGS		(KSEG1ADDR(0x10000000 + BCHP_NAND_REVISION))
#define BRCMNAND_CTRL_REGS_END	(KSEG1ADDR(0x10000000 + BCHP_NAND_BLK_WR_PROTECT))


/**
 * brcmnand_state_t - chip states
 * Enumeration for BrcmNAND flash chip state
 */
typedef enum {
	BRCMNAND_FL_READY = FL_READY,
	BRCMNAND_FL_READING = FL_READING,
	BRCMNAND_FL_WRITING = FL_WRITING,
	BRCMNAND_FL_ERASING = FL_ERASING,
	BRCMNAND_FL_SYNCING = FL_SYNCING,
	BRCMNAND_FL_CACHEDPRG = FL_CACHEDPRG,
	FL_UNLOCKING,
	FL_LOCKING,
	FL_RESETING,
	FL_OTPING,
	BRCMNAND_FL_PM_SUSPENDED = FL_PM_SUSPENDED,
	BRCMNAND_FL_EXCLUSIVE,	// Exclusive access to NOR flash, prevent all NAND accesses.
	BRCMNAND_FL_XIP,			// Exclusive access to XIP part of the flash
} brcmnand_state_t;



/**
 * struct brcmnand_chip - BrcmNAND Private Flash Chip Data
 * @param base		[BOARDSPECIFIC] address to access Broadcom NAND controller
 * @param chipsize	[INTERN] the size of one chip for multichip arrays
 * @param device_id	[INTERN] device ID
 * @param verstion_id	[INTERN] version ID
 * @param options	[BOARDSPECIFIC] various chip options. They can partly be set to inform brcmnand_scan about
 * @param erase_shift	[INTERN] number of address bits in a block
 * @param page_shift	[INTERN] number of address bits in a page
 * @param ppb_shift	[INTERN] number of address bits in a pages per block
 * @param page_mask	[INTERN] a page per block mask
 * @param readw		[REPLACEABLE] hardware specific function for read short
 * @param writew	[REPLACEABLE] hardware specific function for write short
 * @param command	[REPLACEABLE] hardware specific function for writing commands to the chip
 * @param wait		[REPLACEABLE] hardware specific function for wait on ready
 * @param read_bufferram	[REPLACEABLE] hardware specific function for BufferRAM Area
 * @param write_bufferram	[REPLACEABLE] hardware specific function for BufferRAM Area
 * @param read_word	[REPLACEABLE] hardware specific function for read register of BrcmNAND
 * @param write_word	[REPLACEABLE] hardware specific function for write register of BrcmNAND
 * @param scan_bbt	[REPLACEALBE] hardware specific function for scaning Bad block Table
 * @param chip_lock	[INTERN] spinlock used to protect access to this structure and the chip
 * @param wq		[INTERN] wait queue to sleep on if a BrcmNAND operation is in progress
 * @param state		[INTERN] the current state of the BrcmNAND device
 * @param autooob	[REPLACEABLE] the default (auto)placement scheme
 * @param bbm		[REPLACEABLE] pointer to Bad Block Management
 * @param priv		[OPTIONAL] pointer to private chip date
 */
struct brcmnand_chip {
	unsigned long		regs;	/* Register page */
	unsigned char __iomem		*vbase; /* Virtual address of start of flash */
	unsigned long 		pbase; // Physical address of vbase
	unsigned long		device_id;

	//THT: In BrcmNAND, the NAND controller  keeps track of the 512B Cache
	// so there is no need to manage the buffer ram.
	//unsigned int		bufferram_index;
	//struct brcmnand_bufferram	bufferram;

	int (*command)(struct mtd_info *mtd, int cmd, loff_t address, size_t len);
	int (*wait)(struct mtd_info *mtd, int state, uint32_t* pStatus);
	/*
	int (*read_bufferram)(struct mtd_info *mtd,
			unsigned char *buffer, int offset, size_t count);
	int (*write_bufferram)(struct mtd_info *mtd,
			const unsigned char *buffer, int offset, size_t count);
	*/
	
	unsigned short (*read_word)(void __iomem *addr);
	void (*write_word)(unsigned short value, void __iomem *addr);

	// THT: Sync Burst Read, not supported.
	//void (*mmcontrol)(struct mtd_info *mtd, int sync_read);

	// Private methods exported from BBT
	int (*block_bad)(struct mtd_info *mtd, loff_t ofs, int getchip);	
	int (*block_markbad)(struct mtd_info *mtd, loff_t ofs);
	int (*scan_bbt)(struct mtd_info *mtd);
	int (*erase_bbt)(struct mtd_info *mtd, struct erase_info *instr, int allowbbt, int doNotUseBBT);

	uint32_t (*ctrl_read) (uint32_t command);
	void (*ctrl_write) (uint32_t command, uint32_t val);
	void (*ctrl_writeAddr)(struct brcmnand_chip* chip, L_OFF_T addr, int cmdEndAddr);

	/* THT: Private methods exported to BBT */
	int (*read_raw)(struct mtd_info *mtd, uint8_t *buf, loff_t from, size_t len, size_t ooblen);
	int (*read_pageoob)(struct mtd_info *mtd, L_OFF_T offset,
		u_char* oob_buf, int* retooblen, struct nand_oobinfo *oobsel, int autoplace, int raw);
	int (*write_is_complete)(struct mtd_info *mtd, int* outp_needBBT);

	int		eccmode; // Always NAND_ECC_HW3_512
	int		eccsize; // Size of the ECC block, always 512 for Brcm Nand Controller
	int		eccbytes; // How many bytes are used for ECC per eccsize (3 for Brcm Nand Controller)
	int		eccsteps; // How many ECC block per page (4 for 2K page, 1 for 512B page
	int		eccOobSize; // # of oob byte per ECC steps, always 16
	//int 		chip_delay;


	spinlock_t			chip_lock;
	//atomic_t			semCount; // Used to lock out NAND access for NOR, TBD
	wait_queue_head_t	wq;
	brcmnand_state_t	state;

	unsigned int		chipSize;
	unsigned int		numchips; // Always 1 in v0.0 and 0.1, up to 8 in v1.0+
	int 				directAccess;		// For v1,0+, use directAccess or EBI address	
	int 				CS[MAX_NAND_CS];	// Value of CS selected one per chip, in ascending order of chip Select (enforced)..
										// Say, user uses CS0, CS2, and CS5 for NAND, then the first 3 entries
										// have the values 0, 2 and 5, and numchips=3.
	unsigned int		chip_shift; // How many bits shold be shifted.
	L_OFF_T			mtdSize;	// Total size of NAND flash, 64 bit integer for V1.0

	/* THT Added */
	unsigned int 		busWidth, pageSize, blockSize; /* Actually page size from chip, as reported by the controller */

	unsigned int		erase_shift;
	unsigned int		page_shift;
	int				phys_erase_shift;	
	int				bbt_erase_shift;
	//unsigned int		ppb_shift;	/* Pages per block shift */
	unsigned int		page_mask;

	u_char*	data_buf;
	u_char*	oob_buf;
	int		oobdirty;
	u_char		*data_poi;
	unsigned int	options;
	int		badblockpos;
	
	//unsigned long	chipsize;
	int		pagemask;
	int		pagebuf;
	struct nand_oobinfo	*autooob;
	struct page_layout_item *layout;
	int layout_allocated;

	uint8_t		*bbt;
	int (*isbad_bbt)(struct mtd_info *mtd, loff_t ofs, int allowbbt);
	struct nand_bbt_descr	*bbt_td;
	struct nand_bbt_descr	*bbt_md;
	struct nand_bbt_descr	*badblock_pattern;

	void				*priv;
};




/*
 * Options bits
 */
#define BRCMNAND_CONT_LOCK		(0x0001)


extern void brcmnand_prepare_reboot(void);

/*
 * @ mtd		The MTD interface handle from opening "/dev/mtd<n>" or "/dev/mtdblock<n>"
 * @ buff		Buffer to hold the data read from the NOR flash, must be able to hold len bytes, and aligned on
 *			word boundary.
 * @ offset	Offset of the data from CS0 (on NOR flash), must be on word boundary.
 * @ len		Number of bytes to be read, must be even number.
 *
 * returns 0 on success, negative error codes on failure.
 *
 * The caller thread may block until access to the NOR flash can be granted.
 * Further accesses to the NAND flash (from other threads) will be blocked until this routine returns.
 * The routine performs the required swapping of CS0/CS1 under the hood.
 */
extern int brcmnand_readNorFlash(struct mtd_info *mtd, void* buff, unsigned int offset, int len);

#endif

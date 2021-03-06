/***************************************************************************
 *     Copyright (c) 1999-2005, Broadcom Corporation
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
 * $brcm_Workfile: bcmbgereg.h $
 * $brcm_Revision: SanJose_Linux_Devel/1 $
 * $brcm_Date: 8/13/02 5:1p $
 *
 * Module Description:
 *
 * Revision History:
 *
 * $brcm_Log: /Linux/kernel/src/bcm97xxx_2418/include/asm/brcmstb/brcm97315/bcmbgereg.h $
 * 
 * SanJose_Linux_Devel/1   8/13/02 5:1p ttruong
 * Specific includes for various platforms 7110,7115,7315,7320
 * 
 * SanJose_Linux_Devel\1   5/14/02 3:41p eddieshi
 * newly created for 7315
 * 
 ***************************************************************************/
#ifndef BCMBGEREG_H
#define BCMBGEREG_H

#if __cplusplus
extern "C" {
#endif

/**********************************************************************
 * BCM7115_A0 -- BGE_CTRL_Registers
 **********************************************************************/
#define BGE_CTRL_CPU_INTR_ENA            0x00000000 /* CPU Interrupt Enable Register */
#define BGE_INTR_ENA          BGE_CTRL_CPU_INTR_ENA /* Redefined for compatibility */
#define BGE_CTRL_CPU_INTR_STA_CLR        0x00000004 /* CPU Interrupt Status/Clear Register */
#define BGE_INTR_STATUS   BGE_CTRL_CPU_INTR_STA_CLR /* Redefined for compatibility */
#define BGE_CTRL_TIMER1_COMP             0x00000008 /* Timer1 Compare Register */
#define BGE_CTRL_TIMER1_COUNT            0x0000000C /* Timer1 Count Register */
#define BGE_CTRL_CPU_CTRL                0x00000010 /* CPU Control Register */
#define BGE_CPU_CTRL              BGE_CTRL_CPU_CTRL /* Redefined for compatibility */
#define BGE_CTRL_MAIL_BOX1               0x00000014 /* CPU_PAXEL mailbox1 Register */
#define BGE_CTRL_MAIL_BOX2               0x00000018 /* CPU_PAXEL mailbox2 Register */
#define BGE_CTRL_SOFT_RESET              0x0000001C /* Software Reset Register */
#define BGE_CTRL_DIAG_MUX_CTRL           0x00000020 /* DIAG_MUX Control Register */
#define BGE_CTRL_VEC_CTRL                0x00000024 /* VEC Control Register */
#define BGE_CTRL_PAXEL_INTR_ENA          0x00000028 /* PAXEL_INTR_ENA Register */
#define BGE_CTRL_PAXEL_INTR_STA_CLR      0x0000002C /* PAXEL Interrupt Status/Clear Register */
#define BGE_CTRL_TIMER2_COUNT            0x00000030 /* Timer2 Count Register */
#define BGE_CTRL_PAXEL_CTRL              0x00000034 /* PAXEL Control Register */
#define BGE_CTRL_PAXEL_DMA_STATUS        0x00000038 /* PAXEL_DMA_STATUS Register */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1      0x0000003C /* PAXEL_DMA Command Queue1 Register */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2      0x00000040 /* PAXEL_DMA Command Queue2 Register */
#define BGE_CTRL_PAXEL_ACK_TMR           0x00000044 /* PAXEL ACK Timer Register */
#define BGE_CTRL_MBIST_EN0               0x00000048 /* MBIST_EN0 Register */
#define BGE_CTRL_MBIST_EN1               0x0000004C /* MBIST_EN1 Register */
#define BGE_CTRL_MBIST_CTRL              0x00000050 /* MBIST_CTRL Register */
#define BGE_CTRL_TP_MUX_CTRL             0x00000080 /* TP_MUX Control Register */
#define BGE_CTRL_MBIST_STATUS            0x00000084 /* MBIST_STATUS Register */
#define BGE_CTRL_BGEC_REVISION           0x00000090 /* BGEC Revision Register */
#define BGE_CTRL_PXL_REVISION            0x00000094 /* PAXEL Revision Register */
#define BGE_CTRL_SCRATCH                 0x00000098 /* Scratch Register */

/**********************************************************************
 * BGEC_CPU_INTR_ENA
 **********************************************************************/
/* reserved0 [31:20] -  */
#define BGE_CTRL_CPU_INTR_ENA_reserved0_MASK            0xFFF00000UL
#define BGE_CTRL_CPU_INTR_ENA_reserved0_ALIGN           0
#define BGE_CTRL_CPU_INTR_ENA_reserved0_BITS            12
#define BGE_CTRL_CPU_INTR_ENA_reserved0_SHIFT           20

/* CPU_SOFT_INT [19:19] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_CPU_SOFT_INT_MASK         0x00080000UL
#define BGE_CTRL_CPU_INTR_ENA_CPU_SOFT_INT_ALIGN        0
#define BGE_CTRL_CPU_INTR_ENA_CPU_SOFT_INT_BITS         1
#define BGE_CTRL_CPU_INTR_ENA_CPU_SOFT_INT_SHIFT        19

/* VEC_INTR [18:18] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_VEC_INTR_MASK             0x00040000UL
#define BGE_CTRL_CPU_INTR_ENA_VEC_INTR_ALIGN            0
#define BGE_CTRL_CPU_INTR_ENA_VEC_INTR_BITS             1
#define BGE_CTRL_CPU_INTR_ENA_VEC_INTR_SHIFT            18

/* VDEC1_INTR [17:17] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_VDEC1_INTR_MASK           0x00020000UL
#define BGE_CTRL_CPU_INTR_ENA_VDEC1_INTR_ALIGN          0
#define BGE_CTRL_CPU_INTR_ENA_VDEC1_INTR_BITS           1
#define BGE_CTRL_CPU_INTR_ENA_VDEC1_INTR_SHIFT          17

/* VDEC0_INTR [16:16] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_VDEC0_INTR_MASK           0x00010000UL
#define BGE_CTRL_CPU_INTR_ENA_VDEC0_INTR_ALIGN          0
#define BGE_CTRL_CPU_INTR_ENA_VDEC0_INTR_BITS           1
#define BGE_CTRL_CPU_INTR_ENA_VDEC0_INTR_SHIFT          16

/* PAXEL_ACK_INTR [15:15] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_PAXEL_ACK_INTR_MASK       0x00008000UL
#define BGE_CTRL_CPU_INTR_ENA_PAXEL_ACK_INTR_ALIGN      0
#define BGE_CTRL_CPU_INTR_ENA_PAXEL_ACK_INTR_BITS       1
#define BGE_CTRL_CPU_INTR_ENA_PAXEL_ACK_INTR_SHIFT      15

/* CAP_BF_DONE [14:14] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_CAP_BF_DONE_MASK          0x00004000UL
#define BGE_CTRL_CPU_INTR_ENA_CAP_BF_DONE_ALIGN         0
#define BGE_CTRL_CPU_INTR_ENA_CAP_BF_DONE_BITS          1
#define BGE_CTRL_CPU_INTR_ENA_CAP_BF_DONE_SHIFT         14

/* CAP_TF_DONE [13:13] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_CAP_TF_DONE_MASK          0x00002000UL
#define BGE_CTRL_CPU_INTR_ENA_CAP_TF_DONE_ALIGN         0
#define BGE_CTRL_CPU_INTR_ENA_CAP_TF_DONE_BITS          1
#define BGE_CTRL_CPU_INTR_ENA_CAP_TF_DONE_SHIFT         13

/* RASTER_BF_CMP [12:12] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_RASTER_BF_CMP_MASK        0x00001000UL
#define BGE_CTRL_CPU_INTR_ENA_RASTER_BF_CMP_ALIGN       0
#define BGE_CTRL_CPU_INTR_ENA_RASTER_BF_CMP_BITS        1
#define BGE_CTRL_CPU_INTR_ENA_RASTER_BF_CMP_SHIFT       12

/* RASTER_TF_CMP [11:11] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_RASTER_TF_CMP_MASK        0x00000800UL
#define BGE_CTRL_CPU_INTR_ENA_RASTER_TF_CMP_ALIGN       0
#define BGE_CTRL_CPU_INTR_ENA_RASTER_TF_CMP_BITS        1
#define BGE_CTRL_CPU_INTR_ENA_RASTER_TF_CMP_SHIFT       11

/* DISP_END [10:10] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_DISP_END_MASK             0x00000400UL
#define BGE_CTRL_CPU_INTR_ENA_DISP_END_ALIGN            0
#define BGE_CTRL_CPU_INTR_ENA_DISP_END_BITS             1
#define BGE_CTRL_CPU_INTR_ENA_DISP_END_SHIFT            10

/* ANA_VSYNC_TF [09:09] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_ANA_VSYNC_TF_MASK         0x00000200UL
#define BGE_CTRL_CPU_INTR_ENA_ANA_VSYNC_TF_ALIGN        0
#define BGE_CTRL_CPU_INTR_ENA_ANA_VSYNC_TF_BITS         1
#define BGE_CTRL_CPU_INTR_ENA_ANA_VSYNC_TF_SHIFT        9

/* ANA_VSYNC_BF [08:08] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_ANA_VSYNC_BF_MASK         0x00000100UL
#define BGE_CTRL_CPU_INTR_ENA_ANA_VSYNC_BF_ALIGN        0
#define BGE_CTRL_CPU_INTR_ENA_ANA_VSYNC_BF_BITS         1
#define BGE_CTRL_CPU_INTR_ENA_ANA_VSYNC_BF_SHIFT        8

/* DISP_VSYNC_TF [07:07] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_DISP_VSYNC_TF_MASK        0x00000080UL
#define BGE_CTRL_CPU_INTR_ENA_DISP_VSYNC_TF_ALIGN       0
#define BGE_CTRL_CPU_INTR_ENA_DISP_VSYNC_TF_BITS        1
#define BGE_CTRL_CPU_INTR_ENA_DISP_VSYNC_TF_SHIFT       7

/* DISP_VSYNC_BF [06:06] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_DISP_VSYNC_BF_MASK        0x00000040UL
#define BGE_CTRL_CPU_INTR_ENA_DISP_VSYNC_BF_ALIGN       0
#define BGE_CTRL_CPU_INTR_ENA_DISP_VSYNC_BF_BITS        1
#define BGE_CTRL_CPU_INTR_ENA_DISP_VSYNC_BF_SHIFT       6

/* MEM_DMA_INTR [05:05] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_MEM_DMA_INTR_MASK         0x00000020UL
#define BGE_CTRL_CPU_INTR_ENA_MEM_DMA_INTR_ALIGN        0
#define BGE_CTRL_CPU_INTR_ENA_MEM_DMA_INTR_BITS         1
#define BGE_CTRL_CPU_INTR_ENA_MEM_DMA_INTR_SHIFT        5

/* PCM_INTR [04:04] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_PCM_INTR_MASK             0x00000010UL
#define BGE_CTRL_CPU_INTR_ENA_PCM_INTR_ALIGN            0
#define BGE_CTRL_CPU_INTR_ENA_PCM_INTR_BITS             1
#define BGE_CTRL_CPU_INTR_ENA_PCM_INTR_SHIFT            4

/* PAXEL_DMA_DONE [03:03] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_PAXEL_DMA_DONE_MASK       0x00000008UL
#define BGE_CTRL_CPU_INTR_ENA_PAXEL_DMA_DONE_ALIGN      0
#define BGE_CTRL_CPU_INTR_ENA_PAXEL_DMA_DONE_BITS       1
#define BGE_CTRL_CPU_INTR_ENA_PAXEL_DMA_DONE_SHIFT      3

/* TMR2_TIMEOUT [02:02] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_TMR2_TIMEOUT_MASK         0x00000004UL
#define BGE_CTRL_CPU_INTR_ENA_TMR2_TIMEOUT_ALIGN        0
#define BGE_CTRL_CPU_INTR_ENA_TMR2_TIMEOUT_BITS         1
#define BGE_CTRL_CPU_INTR_ENA_TMR2_TIMEOUT_SHIFT        2

/* TMR1_COMP [01:01] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_TMR1_COMP_MASK            0x00000002UL
#define BGE_CTRL_CPU_INTR_ENA_TMR1_COMP_ALIGN           0
#define BGE_CTRL_CPU_INTR_ENA_TMR1_COMP_BITS            1
#define BGE_CTRL_CPU_INTR_ENA_TMR1_COMP_SHIFT           1

/* TMR1_OVFL [00:00] - boolean */
#define BGE_CTRL_CPU_INTR_ENA_TMR1_OVFL_MASK            0x00000001UL
#define BGE_CTRL_CPU_INTR_ENA_TMR1_OVFL_ALIGN           0
#define BGE_CTRL_CPU_INTR_ENA_TMR1_OVFL_BITS            1
#define BGE_CTRL_CPU_INTR_ENA_TMR1_OVFL_SHIFT           0

/**********************************************************************
 * BGEC_CPU_INTR_STA_CLR
 **********************************************************************/
/* reserved0 [31:20] -  */
#define BGE_CTRL_CPU_INTR_STA_CLR_reserved0_MASK        0xFFF00000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_reserved0_ALIGN       0
#define BGE_CTRL_CPU_INTR_STA_CLR_reserved0_BITS        12
#define BGE_CTRL_CPU_INTR_STA_CLR_reserved0_SHIFT       20

/* CPU_SOFT_INT [19:19] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_CPU_SOFT_INT_MASK     0x00080000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_CPU_SOFT_INT_ALIGN    0
#define BGE_CTRL_CPU_INTR_STA_CLR_CPU_SOFT_INT_BITS     1
#define BGE_CTRL_CPU_INTR_STA_CLR_CPU_SOFT_INT_SHIFT    19

/* VEC_INTR [18:18] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_VEC_INTR_MASK         0x00040000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_VEC_INTR_ALIGN        0
#define BGE_CTRL_CPU_INTR_STA_CLR_VEC_INTR_BITS         1
#define BGE_CTRL_CPU_INTR_STA_CLR_VEC_INTR_SHIFT        18

/* VDEC1_INTR [17:17] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_VDEC1_INTR_MASK       0x00020000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_VDEC1_INTR_ALIGN      0
#define BGE_CTRL_CPU_INTR_STA_CLR_VDEC1_INTR_BITS       1
#define BGE_CTRL_CPU_INTR_STA_CLR_VDEC1_INTR_SHIFT      17

/* VDEC0_INTR [16:16] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_VDEC0_INTR_MASK       0x00010000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_VDEC0_INTR_ALIGN      0
#define BGE_CTRL_CPU_INTR_STA_CLR_VDEC0_INTR_BITS       1
#define BGE_CTRL_CPU_INTR_STA_CLR_VDEC0_INTR_SHIFT      16

/* PAXEL_ACK_INTR [15:15] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_PAXEL_ACK_INTR_MASK   0x00008000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_PAXEL_ACK_INTR_ALIGN  0
#define BGE_CTRL_CPU_INTR_STA_CLR_PAXEL_ACK_INTR_BITS   1
#define BGE_CTRL_CPU_INTR_STA_CLR_PAXEL_ACK_INTR_SHIFT  15

/* CAP_BF_DONE [14:14] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_CAP_BF_DONE_MASK      0x00004000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_CAP_BF_DONE_ALIGN     0
#define BGE_CTRL_CPU_INTR_STA_CLR_CAP_BF_DONE_BITS      1
#define BGE_CTRL_CPU_INTR_STA_CLR_CAP_BF_DONE_SHIFT     14

/* CAP_TF_DONE [13:13] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_CAP_TF_DONE_MASK      0x00002000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_CAP_TF_DONE_ALIGN     0
#define BGE_CTRL_CPU_INTR_STA_CLR_CAP_TF_DONE_BITS      1
#define BGE_CTRL_CPU_INTR_STA_CLR_CAP_TF_DONE_SHIFT     13

/* RASTER_BF_CMP [12:12] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_RASTER_BF_CMP_MASK    0x00001000UL
#define BGE_CTRL_CPU_INTR_STA_CLR_RASTER_BF_CMP_ALIGN   0
#define BGE_CTRL_CPU_INTR_STA_CLR_RASTER_BF_CMP_BITS    1
#define BGE_CTRL_CPU_INTR_STA_CLR_RASTER_BF_CMP_SHIFT   12

/* RASTER_TF_CMP [11:11] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_RASTER_TF_CMP_MASK    0x00000800UL
#define BGE_CTRL_CPU_INTR_STA_CLR_RASTER_TF_CMP_ALIGN   0
#define BGE_CTRL_CPU_INTR_STA_CLR_RASTER_TF_CMP_BITS    1
#define BGE_CTRL_CPU_INTR_STA_CLR_RASTER_TF_CMP_SHIFT   11

/* DISP_END [10:10] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_END_MASK         0x00000400UL
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_END_ALIGN        0
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_END_BITS         1
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_END_SHIFT        10

/* ANA_VSYNC_TF [09:09] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_ANA_VSYNC_TF_MASK     0x00000200UL
#define BGE_CTRL_CPU_INTR_STA_CLR_ANA_VSYNC_TF_ALIGN    0
#define BGE_CTRL_CPU_INTR_STA_CLR_ANA_VSYNC_TF_BITS     1
#define BGE_CTRL_CPU_INTR_STA_CLR_ANA_VSYNC_TF_SHIFT    9

/* ANA_VSYNC_BF [08:08] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_ANA_VSYNC_BF_MASK     0x00000100UL
#define BGE_CTRL_CPU_INTR_STA_CLR_ANA_VSYNC_BF_ALIGN    0
#define BGE_CTRL_CPU_INTR_STA_CLR_ANA_VSYNC_BF_BITS     1
#define BGE_CTRL_CPU_INTR_STA_CLR_ANA_VSYNC_BF_SHIFT    8

/* DISP_VSYNC_TF [07:07] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_VSYNC_TF_MASK    0x00000080UL
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_VSYNC_TF_ALIGN   0
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_VSYNC_TF_BITS    1
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_VSYNC_TF_SHIFT   7

/* DISP_VSYNC_BF [06:06] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_VSYNC_BF_MASK    0x00000040UL
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_VSYNC_BF_ALIGN   0
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_VSYNC_BF_BITS    1
#define BGE_CTRL_CPU_INTR_STA_CLR_DISP_VSYNC_BF_SHIFT   6

/* MEM_DMA_INTR [05:05] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_MEM_DMA_INTR_MASK     0x00000020UL
#define BGE_CTRL_CPU_INTR_STA_CLR_MEM_DMA_INTR_ALIGN    0
#define BGE_CTRL_CPU_INTR_STA_CLR_MEM_DMA_INTR_BITS     1
#define BGE_CTRL_CPU_INTR_STA_CLR_MEM_DMA_INTR_SHIFT    5

/* PCM_INTR [04:04] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_PCM_INTR_MASK         0x00000010UL
#define BGE_CTRL_CPU_INTR_STA_CLR_PCM_INTR_ALIGN        0
#define BGE_CTRL_CPU_INTR_STA_CLR_PCM_INTR_BITS         1
#define BGE_CTRL_CPU_INTR_STA_CLR_PCM_INTR_SHIFT        4

/* PAXEL_DMA_DONE [03:03] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_PAXEL_DMA_DONE_MASK   0x00000008UL
#define BGE_CTRL_CPU_INTR_STA_CLR_PAXEL_DMA_DONE_ALIGN  0
#define BGE_CTRL_CPU_INTR_STA_CLR_PAXEL_DMA_DONE_BITS   1
#define BGE_CTRL_CPU_INTR_STA_CLR_PAXEL_DMA_DONE_SHIFT  3

/* TMR2_TIMEOUT [02:02] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR2_TIMEOUT_MASK     0x00000004UL
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR2_TIMEOUT_ALIGN    0
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR2_TIMEOUT_BITS     1
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR2_TIMEOUT_SHIFT    2

/* TMR1_COMP [01:01] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR1_COMP_MASK        0x00000002UL
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR1_COMP_ALIGN       0
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR1_COMP_BITS        1
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR1_COMP_SHIFT       1

/* TMR1_OVFL [00:00] - boolean */
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR1_OVFL_MASK        0x00000001UL
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR1_OVFL_ALIGN       0
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR1_OVFL_BITS        1
#define BGE_CTRL_CPU_INTR_STA_CLR_TMR1_OVFL_SHIFT       0

/**********************************************************************
 * BGEC_TIMER1_COMP
 **********************************************************************/
/* reserved0 [31:17] -  */
#define BGE_CTRL_TIMER1_COMP_reserved0_MASK             0xFFFE0000UL
#define BGE_CTRL_TIMER1_COMP_reserved0_ALIGN            0
#define BGE_CTRL_TIMER1_COMP_reserved0_BITS             15
#define BGE_CTRL_TIMER1_COMP_reserved0_SHIFT            17

/* VALUE [16:00] - unsigned */
#define BGE_CTRL_TIMER1_COMP_VALUE_MASK                 0x0001FFFFUL
#define BGE_CTRL_TIMER1_COMP_VALUE_ALIGN                0
#define BGE_CTRL_TIMER1_COMP_VALUE_BITS                 17
#define BGE_CTRL_TIMER1_COMP_VALUE_SHIFT                0

/**********************************************************************
 * BGEC_TIMER1_COUNT
 **********************************************************************/
/* reserved0 [31:17] -  */
#define BGE_CTRL_TIMER1_COUNT_reserved0_MASK            0xFFFE0000UL
#define BGE_CTRL_TIMER1_COUNT_reserved0_ALIGN           0
#define BGE_CTRL_TIMER1_COUNT_reserved0_BITS            15
#define BGE_CTRL_TIMER1_COUNT_reserved0_SHIFT           17

/* VALUE [16:00] - unsigned */
#define BGE_CTRL_TIMER1_COUNT_VALUE_MASK                0x0001FFFFUL
#define BGE_CTRL_TIMER1_COUNT_VALUE_ALIGN               0
#define BGE_CTRL_TIMER1_COUNT_VALUE_BITS                17
#define BGE_CTRL_TIMER1_COUNT_VALUE_SHIFT               0

/**********************************************************************
 * BGEC_CPU_CTRL
 **********************************************************************/
/* reserved0 [31:05] -  */
#define BGE_CTRL_CPU_CTRL_reserved0_MASK                0xFFFFFFE0UL
#define BGE_CTRL_CPU_CTRL_reserved0_ALIGN               0
#define BGE_CTRL_CPU_CTRL_reserved0_BITS                27
#define BGE_CTRL_CPU_CTRL_reserved0_SHIFT               5

/* PAXEL_SOFT_INT [04:04] - boolean */
#define BGE_CTRL_CPU_CTRL_PAXEL_SOFT_INT_MASK           0x00000010UL
#define BGE_CTRL_CPU_CTRL_PAXEL_SOFT_INT_ALIGN          0
#define BGE_CTRL_CPU_CTRL_PAXEL_SOFT_INT_BITS           1
#define BGE_CTRL_CPU_CTRL_PAXEL_SOFT_INT_SHIFT          4

/* CPU_SOFT_INT [03:03] - boolean */
#define BGE_CTRL_CPU_CTRL_CPU_SOFT_INT_MASK             0x00000008UL
#define BGE_CTRL_CPU_CTRL_CPU_SOFT_INT_ALIGN            0
#define BGE_CTRL_CPU_CTRL_CPU_SOFT_INT_BITS             1
#define BGE_CTRL_CPU_CTRL_CPU_SOFT_INT_SHIFT            3

/* CPU_INTR_OE [02:02] - boolean */
#define BGE_CTRL_CPU_CTRL_CPU_INTR_OE_MASK              0x00000004UL
#define BGE_CTRL_CPU_CTRL_CPU_INTR_OE_ALIGN             0
#define BGE_CTRL_CPU_CTRL_CPU_INTR_OE_BITS              1
#define BGE_CTRL_CPU_CTRL_CPU_INTR_OE_SHIFT             2

/* CPU_INTR_HIGH [01:01] - boolean */
#define BGE_CTRL_CPU_CTRL_CPU_INTR_HIGH_MASK            0x00000002UL
#define BGE_CTRL_CPU_CTRL_CPU_INTR_HIGH_ALIGN           0
#define BGE_CTRL_CPU_CTRL_CPU_INTR_HIGH_BITS            1
#define BGE_CTRL_CPU_CTRL_CPU_INTR_HIGH_SHIFT           1

/* reserved1 [00:00] -  */
#define BGE_CTRL_CPU_CTRL_reserved1_MASK                0x00000001UL
#define BGE_CTRL_CPU_CTRL_reserved1_ALIGN               0
#define BGE_CTRL_CPU_CTRL_reserved1_BITS                1
#define BGE_CTRL_CPU_CTRL_reserved1_SHIFT               0

/**********************************************************************
 * BGEC_MAIL_BOX1
 **********************************************************************/
/* DATA [31:00] - unsigned */
#define BGE_CTRL_MAIL_BOX1_DATA_MASK                    0xFFFFFFFFUL
#define BGE_CTRL_MAIL_BOX1_DATA_ALIGN                   0
#define BGE_CTRL_MAIL_BOX1_DATA_BITS                    32
#define BGE_CTRL_MAIL_BOX1_DATA_SHIFT                   0

/**********************************************************************
 * BGEC_MAIL_BOX2
 **********************************************************************/
/* DATA [31:00] - unsigned */
#define BGE_CTRL_MAIL_BOX2_DATA_MASK                    0xFFFFFFFFUL
#define BGE_CTRL_MAIL_BOX2_DATA_ALIGN                   0
#define BGE_CTRL_MAIL_BOX2_DATA_BITS                    32
#define BGE_CTRL_MAIL_BOX2_DATA_SHIFT                   0

/**********************************************************************
 * BGEC_SOFT_RESET
 **********************************************************************/
/* reserved0 [31:09] -  */
#define BGE_CTRL_SOFT_RESET_reserved0_MASK              0xFFFFFE00UL
#define BGE_CTRL_SOFT_RESET_reserved0_ALIGN             0
#define BGE_CTRL_SOFT_RESET_reserved0_BITS              23
#define BGE_CTRL_SOFT_RESET_reserved0_SHIFT             9

/* VDEC1_SOFT_RESET [08:08] - boolean */
#define BGE_CTRL_SOFT_RESET_VDEC1_SOFT_RESET_MASK       0x00000100UL
#define BGE_CTRL_SOFT_RESET_VDEC1_SOFT_RESET_ALIGN      0
#define BGE_CTRL_SOFT_RESET_VDEC1_SOFT_RESET_BITS       1
#define BGE_CTRL_SOFT_RESET_VDEC1_SOFT_RESET_SHIFT      8

/* VDEC0_SOFT_RESET [07:07] - boolean */
#define BGE_CTRL_SOFT_RESET_VDEC0_SOFT_RESET_MASK       0x00000080UL
#define BGE_CTRL_SOFT_RESET_VDEC0_SOFT_RESET_ALIGN      0
#define BGE_CTRL_SOFT_RESET_VDEC0_SOFT_RESET_BITS       1
#define BGE_CTRL_SOFT_RESET_VDEC0_SOFT_RESET_SHIFT      7

/* VEC_SOFT_RESET [06:06] - boolean */
#define BGE_CTRL_SOFT_RESET_VEC_SOFT_RESET_MASK         0x00000040UL
#define BGE_CTRL_SOFT_RESET_VEC_SOFT_RESET_ALIGN        0
#define BGE_CTRL_SOFT_RESET_VEC_SOFT_RESET_BITS         1
#define BGE_CTRL_SOFT_RESET_VEC_SOFT_RESET_SHIFT        6

/* GFX_SOFT_RESET [05:05] - boolean */
#define BGE_CTRL_SOFT_RESET_GFX_SOFT_RESET_MASK         0x00000020UL
#define BGE_CTRL_SOFT_RESET_GFX_SOFT_RESET_ALIGN        0
#define BGE_CTRL_SOFT_RESET_GFX_SOFT_RESET_BITS         1
#define BGE_CTRL_SOFT_RESET_GFX_SOFT_RESET_SHIFT        5

/* VIDEO_SOFT_RESET [04:04] - boolean */
#define BGE_CTRL_SOFT_RESET_VIDEO_SOFT_RESET_MASK       0x00000010UL
#define BGE_CTRL_SOFT_RESET_VIDEO_SOFT_RESET_ALIGN      0
#define BGE_CTRL_SOFT_RESET_VIDEO_SOFT_RESET_BITS       1
#define BGE_CTRL_SOFT_RESET_VIDEO_SOFT_RESET_SHIFT      4

/* PAXEL_DMA_SOFT_RESET [03:03] - boolean */
#define BGE_CTRL_SOFT_RESET_PAXEL_DMA_SOFT_RESET_MASK   0x00000008UL
#define BGE_CTRL_SOFT_RESET_PAXEL_DMA_SOFT_RESET_ALIGN  0
#define BGE_CTRL_SOFT_RESET_PAXEL_DMA_SOFT_RESET_BITS   1
#define BGE_CTRL_SOFT_RESET_PAXEL_DMA_SOFT_RESET_SHIFT  3

/* PAXEL_SOFT_RESET [02:02] - boolean */
#define BGE_CTRL_SOFT_RESET_PAXEL_SOFT_RESET_MASK       0x00000004UL
#define BGE_CTRL_SOFT_RESET_PAXEL_SOFT_RESET_ALIGN      0
#define BGE_CTRL_SOFT_RESET_PAXEL_SOFT_RESET_BITS       1
#define BGE_CTRL_SOFT_RESET_PAXEL_SOFT_RESET_SHIFT      2

/* MEM_DMA_SOFT_RESET [01:01] - boolean */
#define BGE_CTRL_SOFT_RESET_MEM_DMA_SOFT_RESET_MASK     0x00000002UL
#define BGE_CTRL_SOFT_RESET_MEM_DMA_SOFT_RESET_ALIGN    0
#define BGE_CTRL_SOFT_RESET_MEM_DMA_SOFT_RESET_BITS     1
#define BGE_CTRL_SOFT_RESET_MEM_DMA_SOFT_RESET_SHIFT    1

/* PCM_SOFT_RESET [00:00] - boolean */
#define BGE_CTRL_SOFT_RESET_PCM_SOFT_RESET_MASK         0x00000001UL
#define BGE_CTRL_SOFT_RESET_PCM_SOFT_RESET_ALIGN        0
#define BGE_CTRL_SOFT_RESET_PCM_SOFT_RESET_BITS         1
#define BGE_CTRL_SOFT_RESET_PCM_SOFT_RESET_SHIFT        0

/**********************************************************************
 * BGEC_DIAG_MUX_CTRL
 **********************************************************************/
/* reserved0 [31:03] -  */
#define BGE_CTRL_DIAG_MUX_CTRL_reserved0_MASK           0xFFFFFFF8UL
#define BGE_CTRL_DIAG_MUX_CTRL_reserved0_ALIGN          0
#define BGE_CTRL_DIAG_MUX_CTRL_reserved0_BITS           29
#define BGE_CTRL_DIAG_MUX_CTRL_reserved0_SHIFT          3

/* IBAFE_BYPASS [02:02] - boolean */
#define BGE_CTRL_DIAG_MUX_CTRL_IBAFE_BYPASS_MASK        0x00000004UL
#define BGE_CTRL_DIAG_MUX_CTRL_IBAFE_BYPASS_ALIGN       0
#define BGE_CTRL_DIAG_MUX_CTRL_IBAFE_BYPASS_BITS        1
#define BGE_CTRL_DIAG_MUX_CTRL_IBAFE_BYPASS_SHIFT       2

/* DIAG_MUX_SEL [01:00] - unsigned */
#define BGE_CTRL_DIAG_MUX_CTRL_DIAG_MUX_SEL_MASK        0x00000003UL
#define BGE_CTRL_DIAG_MUX_CTRL_DIAG_MUX_SEL_ALIGN       0
#define BGE_CTRL_DIAG_MUX_CTRL_DIAG_MUX_SEL_BITS        2
#define BGE_CTRL_DIAG_MUX_CTRL_DIAG_MUX_SEL_SHIFT       0

/**********************************************************************
 * BGEC_VEC_CTRL
 **********************************************************************/
/* reserved0 [31:02] -  */
#define BGE_CTRL_VEC_CTRL_reserved0_MASK                0xFFFFFFFCUL
#define BGE_CTRL_VEC_CTRL_reserved0_ALIGN               0
#define BGE_CTRL_VEC_CTRL_reserved0_BITS                30
#define BGE_CTRL_VEC_CTRL_reserved0_SHIFT               2

/* VEC_RESYNC_OFF [01:01] - boolean */
#define BGE_CTRL_VEC_CTRL_VEC_RESYNC_OFF_MASK           0x00000002UL
#define BGE_CTRL_VEC_CTRL_VEC_RESYNC_OFF_ALIGN          0
#define BGE_CTRL_VEC_CTRL_VEC_RESYNC_OFF_BITS           1
#define BGE_CTRL_VEC_CTRL_VEC_RESYNC_OFF_SHIFT          1

/* reserved1 [00:00] -  */
#define BGE_CTRL_VEC_CTRL_reserved1_MASK                0x00000001UL
#define BGE_CTRL_VEC_CTRL_reserved1_ALIGN               0
#define BGE_CTRL_VEC_CTRL_reserved1_BITS                1
#define BGE_CTRL_VEC_CTRL_reserved1_SHIFT               0

/**********************************************************************
 * BGEC_PAXEL_INTR_ENA
 **********************************************************************/
/* reserved0 [31:20] -  */
#define BGE_CTRL_PAXEL_INTR_ENA_reserved0_MASK          0xFFF00000UL
#define BGE_CTRL_PAXEL_INTR_ENA_reserved0_ALIGN         0
#define BGE_CTRL_PAXEL_INTR_ENA_reserved0_BITS          12
#define BGE_CTRL_PAXEL_INTR_ENA_reserved0_SHIFT         20

/* PAXEL_SOFT_INT [19:19] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_SOFT_INT_MASK     0x00080000UL
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_SOFT_INT_ALIGN    0
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_SOFT_INT_BITS     1
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_SOFT_INT_SHIFT    19

/* VEC_INTR [18:18] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_VEC_INTR_MASK           0x00040000UL
#define BGE_CTRL_PAXEL_INTR_ENA_VEC_INTR_ALIGN          0
#define BGE_CTRL_PAXEL_INTR_ENA_VEC_INTR_BITS           1
#define BGE_CTRL_PAXEL_INTR_ENA_VEC_INTR_SHIFT          18

/* VDEC1_INTR [17:17] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_VDEC1_INTR_MASK         0x00020000UL
#define BGE_CTRL_PAXEL_INTR_ENA_VDEC1_INTR_ALIGN        0
#define BGE_CTRL_PAXEL_INTR_ENA_VDEC1_INTR_BITS         1
#define BGE_CTRL_PAXEL_INTR_ENA_VDEC1_INTR_SHIFT        17

/* VDEC0_INTR [16:16] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_VDEC0_INTR_MASK         0x00010000UL
#define BGE_CTRL_PAXEL_INTR_ENA_VDEC0_INTR_ALIGN        0
#define BGE_CTRL_PAXEL_INTR_ENA_VDEC0_INTR_BITS         1
#define BGE_CTRL_PAXEL_INTR_ENA_VDEC0_INTR_SHIFT        16

/* PAXEL_ACK_INTR [15:15] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_ACK_INTR_MASK     0x00008000UL
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_ACK_INTR_ALIGN    0
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_ACK_INTR_BITS     1
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_ACK_INTR_SHIFT    15

/* CAP_BF_DONE [14:14] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_CAP_BF_DONE_MASK        0x00004000UL
#define BGE_CTRL_PAXEL_INTR_ENA_CAP_BF_DONE_ALIGN       0
#define BGE_CTRL_PAXEL_INTR_ENA_CAP_BF_DONE_BITS        1
#define BGE_CTRL_PAXEL_INTR_ENA_CAP_BF_DONE_SHIFT       14

/* CAP_TF_DONE [13:13] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_CAP_TF_DONE_MASK        0x00002000UL
#define BGE_CTRL_PAXEL_INTR_ENA_CAP_TF_DONE_ALIGN       0
#define BGE_CTRL_PAXEL_INTR_ENA_CAP_TF_DONE_BITS        1
#define BGE_CTRL_PAXEL_INTR_ENA_CAP_TF_DONE_SHIFT       13

/* RASTER_BF_CMP [12:12] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_RASTER_BF_CMP_MASK      0x00001000UL
#define BGE_CTRL_PAXEL_INTR_ENA_RASTER_BF_CMP_ALIGN     0
#define BGE_CTRL_PAXEL_INTR_ENA_RASTER_BF_CMP_BITS      1
#define BGE_CTRL_PAXEL_INTR_ENA_RASTER_BF_CMP_SHIFT     12

/* RASTER_TF_CMP [11:11] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_RASTER_TF_CMP_MASK      0x00000800UL
#define BGE_CTRL_PAXEL_INTR_ENA_RASTER_TF_CMP_ALIGN     0
#define BGE_CTRL_PAXEL_INTR_ENA_RASTER_TF_CMP_BITS      1
#define BGE_CTRL_PAXEL_INTR_ENA_RASTER_TF_CMP_SHIFT     11

/* DISP_END [10:10] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_END_MASK           0x00000400UL
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_END_ALIGN          0
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_END_BITS           1
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_END_SHIFT          10

/* ANA_VSYNC_TF [09:09] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_ANA_VSYNC_TF_MASK       0x00000200UL
#define BGE_CTRL_PAXEL_INTR_ENA_ANA_VSYNC_TF_ALIGN      0
#define BGE_CTRL_PAXEL_INTR_ENA_ANA_VSYNC_TF_BITS       1
#define BGE_CTRL_PAXEL_INTR_ENA_ANA_VSYNC_TF_SHIFT      9

/* ANA_VSYNC_BF [08:08] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_ANA_VSYNC_BF_MASK       0x00000100UL
#define BGE_CTRL_PAXEL_INTR_ENA_ANA_VSYNC_BF_ALIGN      0
#define BGE_CTRL_PAXEL_INTR_ENA_ANA_VSYNC_BF_BITS       1
#define BGE_CTRL_PAXEL_INTR_ENA_ANA_VSYNC_BF_SHIFT      8

/* DISP_VSYNC_TF [07:07] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_VSYNC_TF_MASK      0x00000080UL
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_VSYNC_TF_ALIGN     0
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_VSYNC_TF_BITS      1
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_VSYNC_TF_SHIFT     7

/* DISP_VSYNC_BF [06:06] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_VSYNC_BF_MASK      0x00000040UL
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_VSYNC_BF_ALIGN     0
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_VSYNC_BF_BITS      1
#define BGE_CTRL_PAXEL_INTR_ENA_DISP_VSYNC_BF_SHIFT     6

/* MEM_DMA_INTR [05:05] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_MEM_DMA_INTR_MASK       0x00000020UL
#define BGE_CTRL_PAXEL_INTR_ENA_MEM_DMA_INTR_ALIGN      0
#define BGE_CTRL_PAXEL_INTR_ENA_MEM_DMA_INTR_BITS       1
#define BGE_CTRL_PAXEL_INTR_ENA_MEM_DMA_INTR_SHIFT      5

/* PCM_INTR [04:04] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_PCM_INTR_MASK           0x00000010UL
#define BGE_CTRL_PAXEL_INTR_ENA_PCM_INTR_ALIGN          0
#define BGE_CTRL_PAXEL_INTR_ENA_PCM_INTR_BITS           1
#define BGE_CTRL_PAXEL_INTR_ENA_PCM_INTR_SHIFT          4

/* PAXEL_DMA_DONE [03:03] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_DMA_DONE_MASK     0x00000008UL
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_DMA_DONE_ALIGN    0
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_DMA_DONE_BITS     1
#define BGE_CTRL_PAXEL_INTR_ENA_PAXEL_DMA_DONE_SHIFT    3

/* TMR2_TIMEOUT [02:02] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_TMR2_TIMEOUT_MASK       0x00000004UL
#define BGE_CTRL_PAXEL_INTR_ENA_TMR2_TIMEOUT_ALIGN      0
#define BGE_CTRL_PAXEL_INTR_ENA_TMR2_TIMEOUT_BITS       1
#define BGE_CTRL_PAXEL_INTR_ENA_TMR2_TIMEOUT_SHIFT      2

/* TMR1_COMP [01:01] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_TMR1_COMP_MASK          0x00000002UL
#define BGE_CTRL_PAXEL_INTR_ENA_TMR1_COMP_ALIGN         0
#define BGE_CTRL_PAXEL_INTR_ENA_TMR1_COMP_BITS          1
#define BGE_CTRL_PAXEL_INTR_ENA_TMR1_COMP_SHIFT         1

/* TMR1_OVFL [00:00] - boolean */
#define BGE_CTRL_PAXEL_INTR_ENA_TMR1_OVFL_MASK          0x00000001UL
#define BGE_CTRL_PAXEL_INTR_ENA_TMR1_OVFL_ALIGN         0
#define BGE_CTRL_PAXEL_INTR_ENA_TMR1_OVFL_BITS          1
#define BGE_CTRL_PAXEL_INTR_ENA_TMR1_OVFL_SHIFT         0

/**********************************************************************
 * BGEC_PAXEL_INTR_STA_CLR
 **********************************************************************/
/* reserved0 [31:20] -  */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_reserved0_MASK      0xFFF00000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_reserved0_ALIGN     0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_reserved0_BITS      12
#define BGE_CTRL_PAXEL_INTR_STA_CLR_reserved0_SHIFT     20

/* PAXEL_SOFT_INT [19:19] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_SOFT_INT_MASK 0x00080000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_SOFT_INT_ALIGN 0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_SOFT_INT_BITS 1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_SOFT_INT_SHIFT 19

/* VEC_INTR [18:18] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VEC_INTR_MASK       0x00040000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VEC_INTR_ALIGN      0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VEC_INTR_BITS       1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VEC_INTR_SHIFT      18

/* VDEC1_INTR [17:17] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VDEC1_INTR_MASK     0x00020000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VDEC1_INTR_ALIGN    0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VDEC1_INTR_BITS     1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VDEC1_INTR_SHIFT    17

/* VDEC0_INTR [16:16] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VDEC0_INTR_MASK     0x00010000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VDEC0_INTR_ALIGN    0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VDEC0_INTR_BITS     1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_VDEC0_INTR_SHIFT    16

/* PAXEL_ACK_INTR [15:15] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_ACK_INTR_MASK 0x00008000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_ACK_INTR_ALIGN 0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_ACK_INTR_BITS 1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_ACK_INTR_SHIFT 15

/* CAP_BF_DONE [14:14] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_CAP_BF_DONE_MASK    0x00004000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_CAP_BF_DONE_ALIGN   0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_CAP_BF_DONE_BITS    1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_CAP_BF_DONE_SHIFT   14

/* CAP_TF_DONE [13:13] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_CAP_TF_DONE_MASK    0x00002000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_CAP_TF_DONE_ALIGN   0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_CAP_TF_DONE_BITS    1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_CAP_TF_DONE_SHIFT   13

/* RASTER_BF_CMP [12:12] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_RASTER_BF_CMP_MASK  0x00001000UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_RASTER_BF_CMP_ALIGN 0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_RASTER_BF_CMP_BITS  1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_RASTER_BF_CMP_SHIFT 12

/* RASTER_TF_CMP [11:11] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_RASTER_TF_CMP_MASK  0x00000800UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_RASTER_TF_CMP_ALIGN 0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_RASTER_TF_CMP_BITS  1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_RASTER_TF_CMP_SHIFT 11

/* DISP_END [10:10] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_END_MASK       0x00000400UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_END_ALIGN      0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_END_BITS       1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_END_SHIFT      10

/* ANA_VSYNC_TF [09:09] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_ANA_VSYNC_TF_MASK   0x00000200UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_ANA_VSYNC_TF_ALIGN  0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_ANA_VSYNC_TF_BITS   1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_ANA_VSYNC_TF_SHIFT  9

/* ANA_VSYNC_BF [08:08] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_ANA_VSYNC_BF_MASK   0x00000100UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_ANA_VSYNC_BF_ALIGN  0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_ANA_VSYNC_BF_BITS   1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_ANA_VSYNC_BF_SHIFT  8

/* DISP_VSYNC_TF [07:07] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_VSYNC_TF_MASK  0x00000080UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_VSYNC_TF_ALIGN 0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_VSYNC_TF_BITS  1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_VSYNC_TF_SHIFT 7

/* DISP_VSYNC_BF [06:06] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_VSYNC_BF_MASK  0x00000040UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_VSYNC_BF_ALIGN 0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_VSYNC_BF_BITS  1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_DISP_VSYNC_BF_SHIFT 6

/* MEM_DMA_INTR [05:05] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_MEM_DMA_INTR_MASK   0x00000020UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_MEM_DMA_INTR_ALIGN  0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_MEM_DMA_INTR_BITS   1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_MEM_DMA_INTR_SHIFT  5

/* PCM_INTR [04:04] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PCM_INTR_MASK       0x00000010UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PCM_INTR_ALIGN      0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PCM_INTR_BITS       1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PCM_INTR_SHIFT      4

/* PAXEL_DMA_DONE [03:03] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_DMA_DONE_MASK 0x00000008UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_DMA_DONE_ALIGN 0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_DMA_DONE_BITS 1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_PAXEL_DMA_DONE_SHIFT 3

/* TMR2_TIMEOUT [02:02] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR2_TIMEOUT_MASK   0x00000004UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR2_TIMEOUT_ALIGN  0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR2_TIMEOUT_BITS   1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR2_TIMEOUT_SHIFT  2

/* TMR1_COMP [01:01] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR1_COMP_MASK      0x00000002UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR1_COMP_ALIGN     0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR1_COMP_BITS      1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR1_COMP_SHIFT     1

/* TMR1_OVFL [00:00] - boolean */
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR1_OVFL_MASK      0x00000001UL
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR1_OVFL_ALIGN     0
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR1_OVFL_BITS      1
#define BGE_CTRL_PAXEL_INTR_STA_CLR_TMR1_OVFL_SHIFT     0

/**********************************************************************
 * BGEC_TIMER2_COUNT
 **********************************************************************/
/* VALUE [31:00] - unsigned */
#define BGE_CTRL_TIMER2_COUNT_VALUE_MASK                0xFFFFFFFFUL
#define BGE_CTRL_TIMER2_COUNT_VALUE_ALIGN               0
#define BGE_CTRL_TIMER2_COUNT_VALUE_BITS                32
#define BGE_CTRL_TIMER2_COUNT_VALUE_SHIFT               0

/**********************************************************************
 * BGEC_PAXEL_CTRL
 **********************************************************************/
/* PAXEL_INIT_DONE [31:31] - boolean */
#define BGE_CTRL_PAXEL_CTRL_PAXEL_INIT_DONE_MASK        0x80000000UL
#define BGE_CTRL_PAXEL_CTRL_PAXEL_INIT_DONE_ALIGN       0
#define BGE_CTRL_PAXEL_CTRL_PAXEL_INIT_DONE_BITS        1
#define BGE_CTRL_PAXEL_CTRL_PAXEL_INIT_DONE_SHIFT       31

/* PAXEL_REG_WR_ENA [30:30] - boolean */
#define BGE_CTRL_PAXEL_CTRL_PAXEL_REG_WR_ENA_MASK       0x40000000UL
#define BGE_CTRL_PAXEL_CTRL_PAXEL_REG_WR_ENA_ALIGN      0
#define BGE_CTRL_PAXEL_CTRL_PAXEL_REG_WR_ENA_BITS       1
#define BGE_CTRL_PAXEL_CTRL_PAXEL_REG_WR_ENA_SHIFT      30

/* PAXEL_INTR_OE [29:29] - boolean */
#define BGE_CTRL_PAXEL_CTRL_PAXEL_INTR_OE_MASK          0x20000000UL
#define BGE_CTRL_PAXEL_CTRL_PAXEL_INTR_OE_ALIGN         0
#define BGE_CTRL_PAXEL_CTRL_PAXEL_INTR_OE_BITS          1
#define BGE_CTRL_PAXEL_CTRL_PAXEL_INTR_OE_SHIFT         29

/* reserved0 [28:28] -  */
#define BGE_CTRL_PAXEL_CTRL_reserved0_MASK              0x10000000UL
#define BGE_CTRL_PAXEL_CTRL_reserved0_ALIGN             0
#define BGE_CTRL_PAXEL_CTRL_reserved0_BITS              1
#define BGE_CTRL_PAXEL_CTRL_reserved0_SHIFT             28

/* PAXEL_MEM_OFFSET [27:00] - unsigned */
#define BGE_CTRL_PAXEL_CTRL_PAXEL_MEM_OFFSET_MASK       0x0FFFFFFFUL
#define BGE_CTRL_PAXEL_CTRL_PAXEL_MEM_OFFSET_ALIGN      0
#define BGE_CTRL_PAXEL_CTRL_PAXEL_MEM_OFFSET_BITS       28
#define BGE_CTRL_PAXEL_CTRL_PAXEL_MEM_OFFSET_SHIFT      0

/**********************************************************************
 * BGEC_PAXEL_DMA_STATUS
 **********************************************************************/
/* reserved0 [31:06] -  */
#define BGE_CTRL_PAXEL_DMA_STATUS_reserved0_MASK        0xFFFFFFC0UL
#define BGE_CTRL_PAXEL_DMA_STATUS_reserved0_ALIGN       0
#define BGE_CTRL_PAXEL_DMA_STATUS_reserved0_BITS        26
#define BGE_CTRL_PAXEL_DMA_STATUS_reserved0_SHIFT       6

/* PAXEL_DMA_WR_PTR [05:04] - unsigned */
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_WR_PTR_MASK 0x00000030UL
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_WR_PTR_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_WR_PTR_BITS 2
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_WR_PTR_SHIFT 4

/* PAXEL_DMA_RD_PTR [03:02] - unsigned */
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_RD_PTR_MASK 0x0000000CUL
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_RD_PTR_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_RD_PTR_BITS 2
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_RD_PTR_SHIFT 2

/* PAXEL_DMA_FULL [01:01] - boolean */
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_FULL_MASK   0x00000002UL
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_FULL_ALIGN  0
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_FULL_BITS   1
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_FULL_SHIFT  1

/* PAXEL_DMA_EMPTY [00:00] - boolean */
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_EMPTY_MASK  0x00000001UL
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_EMPTY_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_EMPTY_BITS  1
#define BGE_CTRL_PAXEL_DMA_STATUS_PAXEL_DMA_EMPTY_SHIFT 0

/**********************************************************************
 * BGEC_PAXEL_DMA_CMD_QUE1
 **********************************************************************/
/* reserved0 [31:28] -  */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1_reserved0_MASK      0xF0000000UL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1_reserved0_ALIGN     0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1_reserved0_BITS      4
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1_reserved0_SHIFT     28

/* PAXEL_DMA_MEM_ADDR [27:00] - unsigned */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1_PAXEL_DMA_MEM_ADDR_MASK 0x0FFFFFFFUL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1_PAXEL_DMA_MEM_ADDR_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1_PAXEL_DMA_MEM_ADDR_BITS 28
#define BGE_CTRL_PAXEL_DMA_CMD_QUE1_PAXEL_DMA_MEM_ADDR_SHIFT 0

/**********************************************************************
 * BGEC_PAXEL_DMA_CMD_QUE2
 **********************************************************************/
/* PAXEL_DMA_INT [31:31] - boolean */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_INT_MASK  0x80000000UL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_INT_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_INT_BITS  1
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_INT_SHIFT 31

/* PAXEL_DMA_DIR [30:30] - boolean */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_DIR_MASK  0x40000000UL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_DIR_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_DIR_BITS  1
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_DIR_SHIFT 30

/* SYSTEM_ENDIAN [29:29] - boolean */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_SYSTEM_ENDIAN_MASK  0x20000000UL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_SYSTEM_ENDIAN_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_SYSTEM_ENDIAN_BITS  1
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_SYSTEM_ENDIAN_SHIFT 29

/* BYTE_SWAP [28:27] - unsigned */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_BYTE_SWAP_MASK      0x18000000UL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_BYTE_SWAP_ALIGN     0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_BYTE_SWAP_BITS      2
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_BYTE_SWAP_SHIFT     27

/* reserved0 [26:25] -  */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_reserved0_MASK      0x06000000UL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_reserved0_ALIGN     0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_reserved0_BITS      2
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_reserved0_SHIFT     25

/* PAXEL_DMA_SIZE [24:13] - unsigned */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_SIZE_MASK 0x01FFE000UL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_SIZE_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_SIZE_BITS 12
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_SIZE_SHIFT 13

/* reserved1 [12:12] -  */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_reserved1_MASK      0x00001000UL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_reserved1_ALIGN     0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_reserved1_BITS      1
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_reserved1_SHIFT     12

/* PAXEL_DMA_SRAM_ADDR [11:00] - unsigned */
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_SRAM_ADDR_MASK 0x00000FFFUL
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_SRAM_ADDR_ALIGN 0
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_SRAM_ADDR_BITS 12
#define BGE_CTRL_PAXEL_DMA_CMD_QUE2_PAXEL_DMA_SRAM_ADDR_SHIFT 0

/**********************************************************************
 * BGEC_PAXEL_ACK_TMR
 **********************************************************************/
/* reserved0 [31:08] -  */
#define BGE_CTRL_PAXEL_ACK_TMR_reserved0_MASK           0xFFFFFF00UL
#define BGE_CTRL_PAXEL_ACK_TMR_reserved0_ALIGN          0
#define BGE_CTRL_PAXEL_ACK_TMR_reserved0_BITS           24
#define BGE_CTRL_PAXEL_ACK_TMR_reserved0_SHIFT          8

/* COUNT [07:00] - unsigned */
#define BGE_CTRL_PAXEL_ACK_TMR_COUNT_MASK               0x000000FFUL
#define BGE_CTRL_PAXEL_ACK_TMR_COUNT_ALIGN              0
#define BGE_CTRL_PAXEL_ACK_TMR_COUNT_BITS               8
#define BGE_CTRL_PAXEL_ACK_TMR_COUNT_SHIFT              0

/**********************************************************************
 * BGEC_MBIST_EN0
 **********************************************************************/
/* MBIST_EN_31 [31:31] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_31_MASK             0x80000000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_31_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_31_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_31_SHIFT            31

/* MBIST_EN_30 [30:30] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_30_MASK             0x40000000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_30_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_30_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_30_SHIFT            30

/* MBIST_EN_29 [29:29] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_29_MASK             0x20000000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_29_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_29_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_29_SHIFT            29

/* MBIST_EN_28 [28:28] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_28_MASK             0x10000000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_28_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_28_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_28_SHIFT            28

/* MBIST_EN_27 [27:27] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_27_MASK             0x08000000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_27_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_27_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_27_SHIFT            27

/* MBIST_EN_26 [26:26] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_26_MASK             0x04000000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_26_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_26_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_26_SHIFT            26

/* MBIST_EN_25 [25:25] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_25_MASK             0x02000000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_25_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_25_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_25_SHIFT            25

/* MBIST_EN_24 [24:24] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_24_MASK             0x01000000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_24_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_24_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_24_SHIFT            24

/* MBIST_EN_23 [23:23] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_23_MASK             0x00800000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_23_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_23_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_23_SHIFT            23

/* MBIST_EN_22 [22:22] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_22_MASK             0x00400000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_22_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_22_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_22_SHIFT            22

/* MBIST_EN_21 [21:21] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_21_MASK             0x00200000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_21_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_21_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_21_SHIFT            21

/* MBIST_EN_20 [20:20] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_20_MASK             0x00100000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_20_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_20_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_20_SHIFT            20

/* MBIST_EN_19 [19:19] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_19_MASK             0x00080000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_19_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_19_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_19_SHIFT            19

/* MBIST_EN_18 [18:18] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_18_MASK             0x00040000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_18_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_18_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_18_SHIFT            18

/* MBIST_EN_17 [17:17] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_17_MASK             0x00020000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_17_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_17_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_17_SHIFT            17

/* MBIST_EN_16 [16:16] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_16_MASK             0x00010000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_16_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_16_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_16_SHIFT            16

/* MBIST_EN_15 [15:15] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_15_MASK             0x00008000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_15_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_15_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_15_SHIFT            15

/* MBIST_EN_14 [14:14] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_14_MASK             0x00004000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_14_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_14_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_14_SHIFT            14

/* MBIST_EN_13 [13:13] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_13_MASK             0x00002000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_13_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_13_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_13_SHIFT            13

/* MBIST_EN_12 [12:12] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_12_MASK             0x00001000UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_12_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_12_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_12_SHIFT            12

/* MBIST_EN_11 [11:11] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_11_MASK             0x00000800UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_11_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_11_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_11_SHIFT            11

/* MBIST_EN_10 [10:10] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_10_MASK             0x00000400UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_10_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_10_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_10_SHIFT            10

/* MBIST_EN_09 [09:09] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_09_MASK             0x00000200UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_09_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_09_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_09_SHIFT            9

/* MBIST_EN_08 [08:08] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_08_MASK             0x00000100UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_08_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_08_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_08_SHIFT            8

/* MBIST_EN_07 [07:07] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_07_MASK             0x00000080UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_07_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_07_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_07_SHIFT            7

/* MBIST_EN_06 [06:06] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_06_MASK             0x00000040UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_06_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_06_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_06_SHIFT            6

/* MBIST_EN_05 [05:05] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_05_MASK             0x00000020UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_05_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_05_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_05_SHIFT            5

/* MBIST_EN_04 [04:04] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_04_MASK             0x00000010UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_04_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_04_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_04_SHIFT            4

/* MBIST_EN_03 [03:03] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_03_MASK             0x00000008UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_03_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_03_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_03_SHIFT            3

/* MBIST_EN_02 [02:02] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_02_MASK             0x00000004UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_02_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_02_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_02_SHIFT            2

/* MBIST_EN_01 [01:01] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_01_MASK             0x00000002UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_01_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_01_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_01_SHIFT            1

/* MBIST_EN_00 [00:00] - unsigned */
#define BGE_CTRL_MBIST_EN0_MBIST_EN_00_MASK             0x00000001UL
#define BGE_CTRL_MBIST_EN0_MBIST_EN_00_ALIGN            0
#define BGE_CTRL_MBIST_EN0_MBIST_EN_00_BITS             1
#define BGE_CTRL_MBIST_EN0_MBIST_EN_00_SHIFT            0

/**********************************************************************
 * BGEC_MBIST_EN1
 **********************************************************************/
/* reserved0 [31:12] -  */
#define BGE_CTRL_MBIST_EN1_reserved0_MASK               0xFFFFF000UL
#define BGE_CTRL_MBIST_EN1_reserved0_ALIGN              0
#define BGE_CTRL_MBIST_EN1_reserved0_BITS               20
#define BGE_CTRL_MBIST_EN1_reserved0_SHIFT              12

/* MBIST_EN_43 [11:11] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_43_MASK             0x00000800UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_43_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_43_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_43_SHIFT            11

/* MBIST_EN_42 [10:10] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_42_MASK             0x00000400UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_42_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_42_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_42_SHIFT            10

/* MBIST_EN_41 [09:09] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_41_MASK             0x00000200UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_41_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_41_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_41_SHIFT            9

/* MBIST_EN_40 [08:08] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_40_MASK             0x00000100UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_40_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_40_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_40_SHIFT            8

/* MBIST_EN_39 [07:07] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_39_MASK             0x00000080UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_39_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_39_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_39_SHIFT            7

/* MBIST_EN_38 [06:06] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_38_MASK             0x00000040UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_38_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_38_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_38_SHIFT            6

/* MBIST_EN_37 [05:05] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_37_MASK             0x00000020UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_37_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_37_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_37_SHIFT            5

/* MBIST_EN_36 [04:04] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_36_MASK             0x00000010UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_36_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_36_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_36_SHIFT            4

/* MBIST_EN_35 [03:03] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_35_MASK             0x00000008UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_35_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_35_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_35_SHIFT            3

/* MBIST_EN_34 [02:02] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_34_MASK             0x00000004UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_34_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_34_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_34_SHIFT            2

/* MBIST_EN_33 [01:01] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_33_MASK             0x00000002UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_33_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_33_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_33_SHIFT            1

/* MBIST_EN_32 [00:00] - unsigned */
#define BGE_CTRL_MBIST_EN1_MBIST_EN_32_MASK             0x00000001UL
#define BGE_CTRL_MBIST_EN1_MBIST_EN_32_ALIGN            0
#define BGE_CTRL_MBIST_EN1_MBIST_EN_32_BITS             1
#define BGE_CTRL_MBIST_EN1_MBIST_EN_32_SHIFT            0

/**********************************************************************
 * BGEC_MBIST_CTRL
 **********************************************************************/
/* reserved0 [31:03] -  */
#define BGE_CTRL_MBIST_CTRL_reserved0_MASK              0xFFFFFFF8UL
#define BGE_CTRL_MBIST_CTRL_reserved0_ALIGN             0
#define BGE_CTRL_MBIST_CTRL_reserved0_BITS              29
#define BGE_CTRL_MBIST_CTRL_reserved0_SHIFT             3

/* MBIST_DBG_EN [02:02] - unsigned */
#define BGE_CTRL_MBIST_CTRL_MBIST_DBG_EN_MASK           0x00000004UL
#define BGE_CTRL_MBIST_CTRL_MBIST_DBG_EN_ALIGN          0
#define BGE_CTRL_MBIST_CTRL_MBIST_DBG_EN_BITS           1
#define BGE_CTRL_MBIST_CTRL_MBIST_DBG_EN_SHIFT          2

/* MBIST_DMP_EN [01:01] - unsigned */
#define BGE_CTRL_MBIST_CTRL_MBIST_DMP_EN_MASK           0x00000002UL
#define BGE_CTRL_MBIST_CTRL_MBIST_DMP_EN_ALIGN          0
#define BGE_CTRL_MBIST_CTRL_MBIST_DMP_EN_BITS           1
#define BGE_CTRL_MBIST_CTRL_MBIST_DMP_EN_SHIFT          1

/* MBIST_HOLD_L [00:00] - unsigned */
#define BGE_CTRL_MBIST_CTRL_MBIST_HOLD_L_MASK           0x00000001UL
#define BGE_CTRL_MBIST_CTRL_MBIST_HOLD_L_ALIGN          0
#define BGE_CTRL_MBIST_CTRL_MBIST_HOLD_L_BITS           1
#define BGE_CTRL_MBIST_CTRL_MBIST_HOLD_L_SHIFT          0

/**********************************************************************
 * BGEC_TP_MUX_CTRL
 **********************************************************************/
/* reserved0 [31:01] -  */
#define BGE_CTRL_TP_MUX_CTRL_reserved0_MASK             0xFFFFFFFEUL
#define BGE_CTRL_TP_MUX_CTRL_reserved0_ALIGN            0
#define BGE_CTRL_TP_MUX_CTRL_reserved0_BITS             31
#define BGE_CTRL_TP_MUX_CTRL_reserved0_SHIFT            1

/* TP_MUX_SEL [00:00] - boolean */
#define BGE_CTRL_TP_MUX_CTRL_TP_MUX_SEL_MASK            0x00000001UL
#define BGE_CTRL_TP_MUX_CTRL_TP_MUX_SEL_ALIGN           0
#define BGE_CTRL_TP_MUX_CTRL_TP_MUX_SEL_BITS            1
#define BGE_CTRL_TP_MUX_CTRL_TP_MUX_SEL_SHIFT           0

/**********************************************************************
 * BGEC_MBIST_STATUS
 **********************************************************************/
/* reserved0 [31:06] -  */
#define BGE_CTRL_MBIST_STATUS_reserved0_MASK            0xFFFFFFC0UL
#define BGE_CTRL_MBIST_STATUS_reserved0_ALIGN           0
#define BGE_CTRL_MBIST_STATUS_reserved0_BITS            26
#define BGE_CTRL_MBIST_STATUS_reserved0_SHIFT           6

/* MBIST_FAIL [05:03] - unsigned */
#define BGE_CTRL_MBIST_STATUS_MBIST_FAIL_MASK           0x00000038UL
#define BGE_CTRL_MBIST_STATUS_MBIST_FAIL_ALIGN          0
#define BGE_CTRL_MBIST_STATUS_MBIST_FAIL_BITS           3
#define BGE_CTRL_MBIST_STATUS_MBIST_FAIL_SHIFT          3

/* MBIST_DONE [02:00] - unsigned */
#define BGE_CTRL_MBIST_STATUS_MBIST_DONE_MASK           0x00000007UL
#define BGE_CTRL_MBIST_STATUS_MBIST_DONE_ALIGN          0
#define BGE_CTRL_MBIST_STATUS_MBIST_DONE_BITS           3
#define BGE_CTRL_MBIST_STATUS_MBIST_DONE_SHIFT          0

/**********************************************************************
 * BGEC_BGEC_REVISION
 **********************************************************************/
/* reserved0 [31:16] -  */
#define BGE_CTRL_BGEC_REVISION_reserved0_MASK           0xFFFF0000UL
#define BGE_CTRL_BGEC_REVISION_reserved0_ALIGN          0
#define BGE_CTRL_BGEC_REVISION_reserved0_BITS           16
#define BGE_CTRL_BGEC_REVISION_reserved0_SHIFT          16

/* MAJOR_REV [15:08] - unsigned */
#define BGE_CTRL_BGEC_REVISION_MAJOR_REV_MASK           0x0000FF00UL
#define BGE_CTRL_BGEC_REVISION_MAJOR_REV_ALIGN          0
#define BGE_CTRL_BGEC_REVISION_MAJOR_REV_BITS           8
#define BGE_CTRL_BGEC_REVISION_MAJOR_REV_SHIFT          8

/* MINOR_REV [07:00] - unsigned */
#define BGE_CTRL_BGEC_REVISION_MINOR_REV_MASK           0x000000FFUL
#define BGE_CTRL_BGEC_REVISION_MINOR_REV_ALIGN          0
#define BGE_CTRL_BGEC_REVISION_MINOR_REV_BITS           8
#define BGE_CTRL_BGEC_REVISION_MINOR_REV_SHIFT          0

/**********************************************************************
 * BGEC_PXL_REVISION
 **********************************************************************/
/* reserved0 [31:16] -  */
#define BGE_CTRL_PXL_REVISION_reserved0_MASK            0xFFFF0000UL
#define BGE_CTRL_PXL_REVISION_reserved0_ALIGN           0
#define BGE_CTRL_PXL_REVISION_reserved0_BITS            16
#define BGE_CTRL_PXL_REVISION_reserved0_SHIFT           16

/* MAJOR_REV [15:08] - unsigned */
#define BGE_CTRL_PXL_REVISION_MAJOR_REV_MASK            0x0000FF00UL
#define BGE_CTRL_PXL_REVISION_MAJOR_REV_ALIGN           0
#define BGE_CTRL_PXL_REVISION_MAJOR_REV_BITS            8
#define BGE_CTRL_PXL_REVISION_MAJOR_REV_SHIFT           8

/* MINOR_REV [07:00] - unsigned */
#define BGE_CTRL_PXL_REVISION_MINOR_REV_MASK            0x000000FFUL
#define BGE_CTRL_PXL_REVISION_MINOR_REV_ALIGN           0
#define BGE_CTRL_PXL_REVISION_MINOR_REV_BITS            8
#define BGE_CTRL_PXL_REVISION_MINOR_REV_SHIFT           0

/**********************************************************************
 * BGEC_SCRATCH
 **********************************************************************/
/* reserved0 [31:00] -  */
#define BGE_CTRL_SCRATCH_reserved0_MASK                 0xFFFFFFFFUL
#define BGE_CTRL_SCRATCH_reserved0_ALIGN                0
#define BGE_CTRL_SCRATCH_reserved0_BITS                 32
#define BGE_CTRL_SCRATCH_reserved0_SHIFT                0

#if __cplusplus
}
#endif

#endif	/* BCMBGEREG_H */

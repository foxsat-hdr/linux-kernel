/***************************************************************************
 *     Copyright (c) 1999-2006, Broadcom Corporation
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
 *
 *
 * Date:           Generated on         Fri Oct 21 12:11:02 2005
 *                 MD5 Checksum         e787da23f53e88a7247b18abd494ff4a
 *
 * Compiled with:  RDB Utility          combo_header.pl
 *                 RDB Parser           3.0
 *                 unknown              unknown
 *                 Perl Interpreter     5.006
 *                 Operating System     linux
 *
 * Revision History:
 *
 * $brcm_Log: /magnum/basemodules/chp/3560/rdb/b0/bchp_common.h $
 * 
 * Hydra_Software_Devel/1   10/21/05 1:33p jasonh
 * PR 17692: Initial version
 *
 ***************************************************************************/

#ifndef BCHP_COMMON_H__
#define BCHP_COMMON_H__

/***************************************************************************
 *BCM3560_B0
 ***************************************************************************/
#define BCHP_PHYSICAL_OFFSET                               0x10000000

/****************************************************************************
 * Core instance register start address.
 ***************************************************************************/
#define BCHP_PCI_INTR1_REG_START                           0x00000000
#define BCHP_PCI_INTR1_REG_END                             0x0000001c
#define BCHP_PCI_GEN_REG_START                             0x00000100
#define BCHP_PCI_GEN_REG_END                               0x00000124
#define BCHP_PCI_CFG_REG_START                             0x00000200
#define BCHP_PCI_CFG_REG_END                               0x0000026c
#define BCHP_PCI_DMA_REG_START                             0x00000300
#define BCHP_PCI_DMA_REG_END                               0x00000324
#define BCHP_MISB_BRIDGE_REG_START                         0x00000400
#define BCHP_MISB_BRIDGE_REG_END                           0x00000404
#define BCHP_EBI_REG_START                                 0x00000800
#define BCHP_EBI_REG_END                                   0x0000091c
#define BCHP_HIF_INTR2_REG_START                           0x00001000
#define BCHP_HIF_INTR2_REG_END                             0x0000102c
#define BCHP_HIF_CPU_INTR1_REG_START                       0x00001400
#define BCHP_HIF_CPU_INTR1_REG_END                         0x0000141c
#define BCHP_HIF_RAC_RGR_REG_START                         0x00001800
#define BCHP_HIF_RAC_RGR_REG_END                           0x00001810
#define BCHP_HIF_PCI_RG_REG_START                          0x00001c00
#define BCHP_HIF_PCI_RG_REG_END                            0x00001c0c
#define BCHP_CLKGEN_REG_START                              0x00040000
#define BCHP_CLKGEN_REG_END                                0x00040030
#define BCHP_CLKGEN_GR_REG_START                           0x00041000
#define BCHP_CLKGEN_GR_REG_END                             0x0004100c
#define BCHP_VCXO_0_RM_REG_START                           0x00041700
#define BCHP_VCXO_0_RM_REG_END                             0x00041718
#define BCHP_VCXO_1_RM_REG_START                           0x00041740
#define BCHP_VCXO_1_RM_REG_END                             0x00041758
#define BCHP_GFX_L2_REG_START                              0x000c0000
#define BCHP_GFX_L2_REG_END                                0x000c002c
#define BCHP_GFX_GRB_REG_START                             0x000c0100
#define BCHP_GFX_GRB_REG_END                               0x000c010c
#define BCHP_M2MC_REG_START                                0x000c1000
#define BCHP_M2MC_REG_END                                  0x000c17fc
#define BCHP_MFD_0_REG_START                               0x00100000
#define BCHP_MFD_0_REG_END                                 0x001000fc
#define BCHP_VFD_0_REG_START                               0x00101000
#define BCHP_VFD_0_REG_END                                 0x001010fc
#define BCHP_VFD_1_REG_START                               0x00101200
#define BCHP_VFD_1_REG_END                                 0x001012fc
#define BCHP_VFD_2_REG_START                               0x00101400
#define BCHP_VFD_2_REG_END                                 0x001014fc
#define BCHP_RDC_REG_START                                 0x00102000
#define BCHP_RDC_REG_END                                   0x001023fc
#define BCHP_BVNF_INTR2_0_REG_START                        0x00103000
#define BCHP_BVNF_INTR2_0_REG_END                          0x0010302c
#define BCHP_BVNF_INTR2_1_REG_START                        0x00103100
#define BCHP_BVNF_INTR2_1_REG_END                          0x0010312c
#define BCHP_BVNF_INTR2_2_REG_START                        0x00103200
#define BCHP_BVNF_INTR2_2_REG_END                          0x0010322c
#define BCHP_BVNF_INTR2_3_REG_START                        0x00103300
#define BCHP_BVNF_INTR2_3_REG_END                          0x0010332c
#define BCHP_BVNF_INTR2_4_REG_START                        0x00103400
#define BCHP_BVNF_INTR2_4_REG_END                          0x0010342c
#define BCHP_BVNF_INTR2_5_REG_START                        0x00103500
#define BCHP_BVNF_INTR2_5_REG_END                          0x0010352c
#define BCHP_FMISC_REG_START                               0x00104000
#define BCHP_FMISC_REG_END                                 0x00104008
#define BCHP_BVN_RGR_REG_START                             0x00104400
#define BCHP_BVN_RGR_REG_END                               0x00104410
#define BCHP_MEMC_REG_START                                0x00106000
#define BCHP_MEMC_REG_END                                  0x00106578
#define BCHP_MEMC_DDR_REG_START                            0x00106800
#define BCHP_MEMC_DDR_REG_END                              0x00106868
#define BCHP_SCL_0_REG_START                               0x00120000
#define BCHP_SCL_0_REG_END                                 0x001201fc
#define BCHP_SCL_1_REG_START                               0x00120400
#define BCHP_SCL_1_REG_END                                 0x001205fc
#define BCHP_SCL_2_REG_START                               0x00120800
#define BCHP_SCL_2_REG_END                                 0x001209fc
#define BCHP_VNET_F_REG_START                              0x00122000
#define BCHP_VNET_F_REG_END                                0x0012204c
#define BCHP_VNET_B_REG_START                              0x00122200
#define BCHP_VNET_B_REG_END                                0x00122250
#define BCHP_MMISC_REG_START                               0x00122800
#define BCHP_MMISC_REG_END                                 0x0012280c
#define BCHP_MAD_REG_START                                 0x00123000
#define BCHP_MAD_REG_END                                   0x00123230
#define BCHP_LBOX_0_REG_START                              0x00125000
#define BCHP_LBOX_0_REG_END                                0x00125070
#define BCHP_DNR_0_REG_START                               0x00127000
#define BCHP_DNR_0_REG_END                                 0x0012703c
#define BCHP_CAP_0_REG_START                               0x00140000
#define BCHP_CAP_0_REG_END                                 0x0014004c
#define BCHP_CAP_1_REG_START                               0x00140200
#define BCHP_CAP_1_REG_END                                 0x0014024c
#define BCHP_CAP_2_REG_START                               0x00140400
#define BCHP_CAP_2_REG_END                                 0x0014044c
#define BCHP_GFD_0_REG_START                               0x00141000
#define BCHP_GFD_0_REG_END                                 0x00141154
#define BCHP_CMP_0_REG_START                               0x00142000
#define BCHP_CMP_0_REG_END                                 0x001420e4
#define BCHP_PEP_CMP_0_V0_REG_START                        0x00144000
#define BCHP_PEP_CMP_0_V0_REG_END                          0x00146084
#define BCHP_BVNB_INTR2_REG_START                          0x00148000
#define BCHP_BVNB_INTR2_REG_END                            0x0014802c
#define BCHP_BMISC_REG_START                               0x00148400
#define BCHP_BMISC_REG_END                                 0x00148408
#define BCHP_TNT_CMP_0_V0_REG_START                        0x0014a000
#define BCHP_TNT_CMP_0_V0_REG_END                          0x0014a03c
#define BCHP_DVI_DTG_REG_START                             0x00180700
#define BCHP_DVI_DTG_REG_END                               0x00180738
#define BCHP_DVI_CSC_REG_START                             0x00180740
#define BCHP_DVI_CSC_REG_END                               0x00180764
#define BCHP_DVI_DVF_REG_START                             0x00180780
#define BCHP_DVI_DVF_REG_END                               0x00180794
#define BCHP_PRIM_IT_REG_START                             0x00180800
#define BCHP_PRIM_IT_REG_END                               0x00180c7c
#define BCHP_PRIM_VF_REG_START                             0x00180c80
#define BCHP_PRIM_VF_REG_END                               0x00180ce4
#define BCHP_PRIM_SM_REG_START                             0x00180e00
#define BCHP_PRIM_SM_REG_END                               0x00180e28
#define BCHP_PRIM_CSC_REG_START                            0x00180e40
#define BCHP_PRIM_CSC_REG_END                              0x00180e64
#define BCHP_PRIM_SRC_REG_START                            0x00180e80
#define BCHP_PRIM_SRC_REG_END                              0x00180e84
#define BCHP_PRIM_RM_REG_START                             0x00180ec0
#define BCHP_PRIM_RM_REG_END                               0x00180ed0
#define BCHP_DTRAM_REG_START                               0x00181000
#define BCHP_DTRAM_REG_END                                 0x0018127c
#define BCHP_DTG_REG_START                                 0x00181300
#define BCHP_DTG_REG_END                                   0x00181338
#define BCHP_CSC_REG_START                                 0x00181340
#define BCHP_CSC_REG_END                                   0x00181364
#define BCHP_DVF_REG_START                                 0x00181380
#define BCHP_DVF_REG_END                                   0x00181394
#define BCHP_ITU656_REG_START                              0x001813a0
#define BCHP_ITU656_REG_END                                0x001813b8
#define BCHP_MISC_REG_START                                0x001814c0
#define BCHP_MISC_REG_END                                  0x001814fc
#define BCHP_VIDEO_ENC_REG_START                           0x00181500
#define BCHP_VIDEO_ENC_REG_END                             0x00181508
#define BCHP_VIDEO_ENC_INTR2_REG_START                     0x00181600
#define BCHP_VIDEO_ENC_INTR2_REG_END                       0x0018162c
#define BCHP_VBI_ENC_PRIM_REG_START                        0x00181800
#define BCHP_VBI_ENC_PRIM_REG_END                          0x00181810
#define BCHP_CGMSAE_PRIM_REG_START                         0x00181880
#define BCHP_CGMSAE_PRIM_REG_END                           0x0018189c
#define BCHP_CCE_PRIM_REG_START                            0x00181900
#define BCHP_CCE_PRIM_REG_END                              0x00181928
#define BCHP_TTE_PRIM_REG_START                            0x00181a00
#define BCHP_TTE_PRIM_REG_END                              0x00181a24
#define BCHP_WSE_PRIM_REG_START                            0x00181a80
#define BCHP_WSE_PRIM_REG_END                              0x00181a90
#define BCHP_ANCI656_PRIM_REG_START                        0x00181b00
#define BCHP_ANCI656_PRIM_REG_END                          0x00181b1c
#define BCHP_VBI_ENC_656_REG_START                         0x00182000
#define BCHP_VBI_ENC_656_REG_END                           0x00182008
#define BCHP_CCE_656_REG_START                             0x00182100
#define BCHP_CCE_656_REG_END                               0x00182128
#define BCHP_TTE_656_REG_START                             0x00182200
#define BCHP_TTE_656_REG_END                               0x00182224
#define BCHP_WSE_656_REG_START                             0x00182280
#define BCHP_WSE_656_REG_END                               0x00182288
#define BCHP_ANCI656_656_REG_START                         0x00182300
#define BCHP_ANCI656_656_REG_END                           0x0018231c
#define BCHP_SPARROW_REG_START                             0x001a0000
#define BCHP_SPARROW_REG_END                               0x001a0050
#define BCHP_SPARROW_RM_REG_START                          0x001a02e0
#define BCHP_SPARROW_RM_REG_END                            0x001a02f8
#define BCHP_SPARROW_INTR2_REG_START                       0x001a0300
#define BCHP_SPARROW_INTR2_REG_END                         0x001a032c
#define BCHP_HDMI_RX_REG_START                             0x001b0000
#define BCHP_HDMI_RX_REG_END                               0x001b03f4
#define BCHP_HDMI_RX_INTR2_REG_START                       0x001b0400
#define BCHP_HDMI_RX_INTR2_REG_END                         0x001b042c
#define BCHP_VDEC_L2_0_REG_START                           0x001c0000
#define BCHP_VDEC_L2_0_REG_END                             0x001c002c
#define BCHP_CCD_0_REG_START                               0x001c1200
#define BCHP_CCD_0_REG_END                                 0x001c1230
#define BCHP_CGMSD_0_REG_START                             0x001c1240
#define BCHP_CGMSD_0_REG_END                               0x001c1260
#define BCHP_TTD_0_REG_START                               0x001c1280
#define BCHP_TTD_0_REG_END                                 0x001c12e4
#define BCHP_WSSD_0_REG_START                              0x001c1300
#define BCHP_WSSD_0_REG_END                                0x001c130c
#define BCHP_GSD_0_REG_START                               0x001c1380
#define BCHP_GSD_0_REG_END                                 0x001c13c4
#define BCHP_VD_TOP_0_REG_START                            0x001c1400
#define BCHP_VD_TOP_0_REG_END                              0x001c1490
#define BCHP_VDEC_FE_0_REG_START                           0x001c1800
#define BCHP_VDEC_FE_0_REG_END                             0x001c197c
#define BCHP_VDEC_BE_0_REG_START                           0x001c1a00
#define BCHP_VDEC_BE_0_REG_END                             0x001c1a9c
#define BCHP_VDEC_CD_0_REG_START                           0x001c1ac0
#define BCHP_VDEC_CD_0_REG_END                             0x001c1af8
#define BCHP_VDEC_YC_0_REG_START                           0x001c1b00
#define BCHP_VDEC_YC_0_REG_END                             0x001c1b7c
#define BCHP_EXT_656_TOP_0_REG_START                       0x001c1d00
#define BCHP_EXT_656_TOP_0_REG_END                         0x001c1d88
#define BCHP_IN656_0_REG_START                             0x001c1e00
#define BCHP_IN656_0_REG_END                               0x001c1e28
#define BCHP_HD_DVI_0_REG_START                            0x001c2000
#define BCHP_HD_DVI_0_REG_END                              0x001c20ac
#define BCHP_HD_DVI_1_REG_START                            0x001c2800
#define BCHP_HD_DVI_1_REG_END                              0x001c28ac
#define BCHP_VDEC_L2_1_REG_START                           0x001d0000
#define BCHP_VDEC_L2_1_REG_END                             0x001d002c
#define BCHP_CCD_1_REG_START                               0x001d1200
#define BCHP_CCD_1_REG_END                                 0x001d1230
#define BCHP_VD_TOP_1_REG_START                            0x001d1400
#define BCHP_VD_TOP_1_REG_END                              0x001d1414
#define BCHP_VDEC_FE_1_REG_START                           0x001d1800
#define BCHP_VDEC_FE_1_REG_END                             0x001d197c
#define BCHP_VDEC_BE_1_REG_START                           0x001d1a00
#define BCHP_VDEC_BE_1_REG_END                             0x001d1a9c
#define BCHP_VDEC_CD_1_REG_START                           0x001d1ac0
#define BCHP_VDEC_CD_1_REG_END                             0x001d1af8
#define BCHP_VDEC_YC_1_REG_START                           0x001d1b00
#define BCHP_VDEC_YC_1_REG_END                             0x001d1b50
#define BCHP_XPT_CFG_REG_START                             0x00200000
#define BCHP_XPT_CFG_REG_END                               0x0020628c
#define BCHP_XPT_PF_REG_START                              0x00200040
#define BCHP_XPT_PF_REG_END                                0x0020480c
#define BCHP_XPT_SC_REG_START                              0x002001e8
#define BCHP_XPT_SC_REG_END                                0x00200238
#define BCHP_XPT_CA_REG_START                              0x00200200
#define BCHP_XPT_CA_REG_END                                0x0020342c
#define BCHP_XPT_DVB_REG_START                             0x00200218
#define BCHP_XPT_DVB_REG_END                               0x00200220
#define BCHP_XPT_PB0_REG_START                             0x002002c0
#define BCHP_XPT_PB0_REG_END                               0x002002d8
#define BCHP_XPT_INT_REG_START                             0x002003c0
#define BCHP_XPT_INT_REG_END                               0x00202c10
#define BCHP_XPT_HSX_REG_START                             0x00202200
#define BCHP_XPT_HSX_REG_END                               0x00205000
#define BCHP_XPT_KS_REG_START                              0x00203a80
#define BCHP_XPT_KS_REG_END                                0x00203ab8
#define BCHP_XPT_DPCR0_REG_START                           0x00206000
#define BCHP_XPT_DPCR0_REG_END                             0x00206050
#define BCHP_XPT_DPCR1_REG_START                           0x00206080
#define BCHP_XPT_DPCR1_REG_END                             0x002060d0
#define BCHP_MEM_DMA_REG_START                             0x00207c00
#define BCHP_MEM_DMA_REG_END                               0x00207c24
#define BCHP_MTP_MMTV_1_REG_START                          0x00300000
#define BCHP_MTP_MMTV_1_REG_END                            0x003083f4
#define BCHP_MTP_MMTV_PERI_1_REG_START                     0x00300000
#define BCHP_MTP_MMTV_PERI_1_REG_END                       0x00308408
#define BCHP_MTP_MST_MTV_1_REG_START                       0x00300000
#define BCHP_MTP_MST_MTV_1_REG_END                         0x00308174
#define BCHP_MTP_MST_MTV_32_1_REG_START                    0x00310000
#define BCHP_MTP_MST_MTV_32_1_REG_END                      0x0031cffc
#define BCHP_MTP_SMTV_1_REG_START                          0x00320000
#define BCHP_MTP_SMTV_1_REG_END                            0x003283f4
#define BCHP_MTP_SMTV_PERI_1_REG_START                     0x00320000
#define BCHP_MTP_SMTV_PERI_1_REG_END                       0x00328408
#define BCHP_MTP_SLV_MTV_1_REG_START                       0x00320000
#define BCHP_MTP_SLV_MTV_1_REG_END                         0x003280f4
#define BCHP_MTP_SLV_MTV_32_1_REG_START                    0x00330000
#define BCHP_MTP_SLV_MTV_32_1_REG_END                      0x00338ffc
#define BCHP_MTP_MTT_1_REG_START                           0x00340000
#define BCHP_MTP_MTT_1_REG_END                             0x00340224
#define BCHP_MTP_MTT_MEM_1_REG_START                       0x00340000
#define BCHP_MTP_MTT_MEM_1_REG_END                         0x00348224
#define BCHP_MTP_MTT_MEM_32_1_REG_START                    0x00350000
#define BCHP_MTP_MTT_MEM_32_1_REG_END                      0x0035a7fc
#define BCHP_MTP_1_REG_START                               0x00360000
#define BCHP_MTP_1_REG_END                                 0x00360040
#define BCHP_MTP_L2_1_REG_START                            0x00360400
#define BCHP_MTP_L2_1_REG_END                              0x0036042c
#define BCHP_MTP_RGRB_1_REG_START                          0x00360800
#define BCHP_MTP_RGRB_1_REG_END                            0x00360810
#define BCHP_IRB_REG_START                                 0x00400000
#define BCHP_IRB_REG_END                                   0x00400138
#define BCHP_PM_REG_START                                  0x0040013c
#define BCHP_PM_REG_END                                    0x0040013c
#define BCHP_LDK_REG_START                                 0x00400140
#define BCHP_LDK_REG_END                                   0x0040017c
#define BCHP_UARTA_REG_START                               0x00400180
#define BCHP_UARTA_REG_END                                 0x0040019c
#define BCHP_UARTB_REG_START                               0x004001a0
#define BCHP_UARTB_REG_END                                 0x004001bc
#define BCHP_UARTC_REG_START                               0x004001c0
#define BCHP_UARTC_REG_END                                 0x004001dc
#define BCHP_BSCA_REG_START                                0x00400200
#define BCHP_BSCA_REG_END                                  0x00400254
#define BCHP_ANT_REG_START                                 0x00400280
#define BCHP_ANT_REG_END                                   0x004002bc
#define BCHP_MSPI_REG_START                                0x00400400
#define BCHP_MSPI_REG_END                                  0x0040057c
#define BCHP_PWM_REG_START                                 0x00400580
#define BCHP_PWM_REG_END                                   0x004005a4
#define BCHP_ICAP_REG_START                                0x004005c0
#define BCHP_ICAP_REG_END                                  0x004005fc
#define BCHP_KBD1_REG_START                                0x00400600
#define BCHP_KBD1_REG_END                                  0x0040063c
#define BCHP_TIMER_REG_START                               0x004006c0
#define BCHP_TIMER_REG_END                                 0x004006fc
#define BCHP_GIO_REG_START                                 0x00400700
#define BCHP_GIO_REG_END                                   0x0040075c
#define BCHP_IRQ0_REG_START                                0x00400780
#define BCHP_IRQ0_REG_END                                  0x004007ac
#define BCHP_IRQ1_REG_START                                0x004007c0
#define BCHP_IRQ1_REG_END                                  0x004007ec
#define BCHP_SCA_REG_START                                 0x00400c00
#define BCHP_SCA_REG_END                                   0x00400cbc
#define BCHP_SCIRQ0_REG_START                              0x00400e40
#define BCHP_SCIRQ0_REG_END                                0x00400e44
#define BCHP_SCIRQ1_REG_START                              0x00400e48
#define BCHP_SCIRQ1_REG_END                                0x00400e4c
#define BCHP_SUN_TOP_CTRL_REG_START                        0x00404000
#define BCHP_SUN_TOP_CTRL_REG_END                          0x004040e4
#define BCHP_SUN_GISB_ARB_REG_START                        0x00406000
#define BCHP_SUN_GISB_ARB_REG_END                          0x004060d0
#define BCHP_SUN_RGR_REG_START                             0x00408000
#define BCHP_SUN_RGR_REG_END                               0x00408010
#define BCHP_SUN_L2_REG_START                              0x0040a000
#define BCHP_SUN_L2_REG_END                                0x0040a02c
#define BCHP_AUDIO_MISC_REG_START                          0x00480000
#define BCHP_AUDIO_MISC_REG_END                            0x00480028
#define BCHP_AUDIO_INTH_REG_START                          0x00480100
#define BCHP_AUDIO_INTH_REG_END                            0x0048012c
#define BCHP_AUDIO_INTH_DBG_REG_START                      0x00480400
#define BCHP_AUDIO_INTH_DBG_REG_END                        0x0048042c
#define BCHP_AUDIO_GRB_REG_START                           0x00480800
#define BCHP_AUDIO_GRB_REG_END                             0x0048080c
#define BCHP_PCM_REG_START                                 0x00481000
#define BCHP_PCM_REG_END                                   0x004810b4
#define BCHP_HIFIDAC_CTRL0_REG_START                       0x00482000
#define BCHP_HIFIDAC_CTRL0_REG_END                         0x004821fc
#define BCHP_HIFIDAC_RM0_REG_START                         0x00482200
#define BCHP_HIFIDAC_RM0_REG_END                           0x00482210
#define BCHP_HIFIDAC_ESR0_REG_START                        0x00482300
#define BCHP_HIFIDAC_ESR0_REG_END                          0x00482314
#define BCHP_BTSC_CTRL0_REG_START                          0x00483000
#define BCHP_BTSC_CTRL0_REG_END                            0x00483050
#define BCHP_BTSC_RM0_REG_START                            0x00483200
#define BCHP_BTSC_RM0_REG_END                              0x00483210
#define BCHP_BTSC_ESR0_REG_START                           0x00483300
#define BCHP_BTSC_ESR0_REG_END                             0x00483314
#define BCHP_AUD_ATP0_REG_START                            0x00484000
#define BCHP_AUD_ATP0_REG_END                              0x0048407c
#define BCHP_AUD_ADP0_REG_START                            0x00484080
#define BCHP_AUD_ADP0_REG_END                              0x004840fc
#define BCHP_AUD_SRS0_REG_START                            0x00484100
#define BCHP_AUD_SRS0_REG_END                              0x00484104
#define BCHP_AUD_PLL0_REG_START                            0x00484140
#define BCHP_AUD_PLL0_REG_END                              0x00484164
#define BCHP_AUD_TOP0_REG_START                            0x00484180
#define BCHP_AUD_TOP0_REG_END                              0x004841bc
#define BCHP_AUD_ATP2_REG_START                            0x00484800
#define BCHP_AUD_ATP2_REG_END                              0x0048487c
#define BCHP_AUD_ADP2_REG_START                            0x00484880
#define BCHP_AUD_ADP2_REG_END                              0x004848fc
#define BCHP_AUD_NCO_REG_START                             0x00484900
#define BCHP_AUD_NCO_REG_END                               0x00484914
#define BCHP_AUD_TOP2_REG_START                            0x00484980
#define BCHP_AUD_TOP2_REG_END                              0x00484984
#define BCHP_AUDIO_SPDIF_RCVR_REG_START                    0x00485000
#define BCHP_AUDIO_SPDIF_RCVR_REG_END                      0x0048507c
#define BCHP_USB_INTR2_REG_START                           0x004c0000
#define BCHP_USB_INTR2_REG_END                             0x004c002c
#define BCHP_USB_GR_BRIDGE_REG_START                       0x004c0100
#define BCHP_USB_GR_BRIDGE_REG_END                         0x004c010c
#define BCHP_USB_CTRL_REG_START                            0x004c0200
#define BCHP_USB_CTRL_REG_END                              0x004c0230
#define BCHP_USB_EHCI_REG_START                            0x004c0300
#define BCHP_USB_EHCI_REG_END                              0x004c03a4
#define BCHP_USB_OHCI_REG_START                            0x004c0400
#define BCHP_USB_OHCI_REG_END                              0x004c0458
#define BCHP_USB_OHCI1_REG_START                           0x004c0500
#define BCHP_USB_OHCI1_REG_END                             0x004c0558
#define BCHP_AP_U_32_REG_START                             0x00640400
#define BCHP_AP_U_32_REG_END                               0x006407e0
#define BCHP_AP_32_REG_START                               0x00640400
#define BCHP_AP_32_REG_END                                 0x006407f8
#define BCHP_AP_DIAG_32_REG_START                          0x00640800
#define BCHP_AP_DIAG_32_REG_END                            0x0064094c
#define BCHP_DS_REG_START                                  0x006a0000
#define BCHP_DS_REG_END                                    0x006a07fc
#define BCHP_DS_TER_REG_START                              0x006a1000
#define BCHP_DS_TER_REG_END                                0x006a12d8
#define BCHP_DS_TER_EQ_REG_START                           0x006a2000
#define BCHP_DS_TER_EQ_REG_END                             0x006a541c
#define BCHP_IFD_CORE_REG_START                            0x006b0000
#define BCHP_IFD_CORE_REG_END                              0x006b03cc
#define BCHP_IFD_TOP_REG_START                             0x006b0400
#define BCHP_IFD_TOP_REG_END                               0x006b045c
#define BCHP_IFD_L2_REG_START                              0x006b0480
#define BCHP_IFD_L2_REG_END                                0x006b04ac
#define BCHP_IFD_SS_REG_START                              0x006b04c0
#define BCHP_IFD_SS_REG_END                                0x006b04f4
#define BCHP_IFD_CORE_A2_REG_START                         0x006b0500
#define BCHP_IFD_CORE_A2_REG_END                           0x006b059c
#define BCHP_AI_TOP_REG_START                              0x006b0600
#define BCHP_AI_TOP_REG_END                                0x006b06e8
#define BCHP_AI_AFE_REG_START                              0x006b0740
#define BCHP_AI_AFE_REG_END                                0x006b0760
#define BCHP_OOB_REG_START                                 0x006c0000
#define BCHP_OOB_REG_END                                   0x006c01c4


/***************************************************************************
 *AUD
 ***************************************************************************/
/***************************************************************************
 *ABSTRACT_01_SPECVERSION - Audio Specification Version
 ***************************************************************************/
/* AUD :: ABSTRACT_01_SPECVERSION :: Version [31:00] */
#define BCHP_AUD_ABSTRACT_01_SPECVERSION_Version_MASK              0xffffffff
#define BCHP_AUD_ABSTRACT_01_SPECVERSION_Version_SHIFT             0

/***************************************************************************
 *ABSTRACT_02_INTERRUPT_HANDLING - Interrupt Handling
 ***************************************************************************/
/* AUD :: ABSTRACT_02_INTERRUPT_HANDLING :: MORE_INFORMATION [31:00] */
#define BCHP_AUD_ABSTRACT_02_INTERRUPT_HANDLING_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_AUD_ABSTRACT_02_INTERRUPT_HANDLING_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *PROG_EX_01_TONE_TEST - Tone Test
 ***************************************************************************/
/* AUD :: PROG_EX_01_TONE_TEST :: MORE_INFORMATION [31:00] */
#define BCHP_AUD_PROG_EX_01_TONE_TEST_MORE_INFORMATION_MASK        0xffffffff
#define BCHP_AUD_PROG_EX_01_TONE_TEST_MORE_INFORMATION_SHIFT       0

/***************************************************************************
 *PROG_EX_02_DOLBY_DIGITAL_AUDIO_MODE - Dolby Digital Audio Mode
 ***************************************************************************/
/* AUD :: PROG_EX_02_DOLBY_DIGITAL_AUDIO_MODE :: MORE_INFORMATION [31:00] */
#define BCHP_AUD_PROG_EX_02_DOLBY_DIGITAL_AUDIO_MODE_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_AUD_PROG_EX_02_DOLBY_DIGITAL_AUDIO_MODE_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *PROG_EX_03_MPEG_AUDIO_MODE - MPEG Audio Mode
 ***************************************************************************/
/* AUD :: PROG_EX_03_MPEG_AUDIO_MODE :: MORE_INFORMATION [31:00] */
#define BCHP_AUD_PROG_EX_03_MPEG_AUDIO_MODE_MORE_INFORMATION_MASK  0xffffffff
#define BCHP_AUD_PROG_EX_03_MPEG_AUDIO_MODE_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *PROG_EX_04_SIMULTANEOUS_MODE - Simultaneous Mode
 ***************************************************************************/
/* AUD :: PROG_EX_04_SIMULTANEOUS_MODE :: MORE_INFORMATION [31:00] */
#define BCHP_AUD_PROG_EX_04_SIMULTANEOUS_MODE_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_AUD_PROG_EX_04_SIMULTANEOUS_MODE_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *PROG_EX_05_COMPRESSED_AUDIO_CLIP - Compressed Audio Clip
 ***************************************************************************/
/* AUD :: PROG_EX_05_COMPRESSED_AUDIO_CLIP :: MORE_INFORMATION [31:00] */
#define BCHP_AUD_PROG_EX_05_COMPRESSED_AUDIO_CLIP_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_AUD_PROG_EX_05_COMPRESSED_AUDIO_CLIP_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *PROG_EX_06_PES_PVR_PLAYBACK - PES PVR Playback
 ***************************************************************************/
/* AUD :: PROG_EX_06_PES_PVR_PLAYBACK :: MORE_INFORMATION [31:00] */
#define BCHP_AUD_PROG_EX_06_PES_PVR_PLAYBACK_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_AUD_PROG_EX_06_PES_PVR_PLAYBACK_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *PROG_EX_07_TRICK_MODE_PROGRAMMING - Trick Mode Programming
 ***************************************************************************/
/* AUD :: PROG_EX_07_TRICK_MODE_PROGRAMMING :: MORE_INFORMATION [31:00] */
#define BCHP_AUD_PROG_EX_07_TRICK_MODE_PROGRAMMING_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_AUD_PROG_EX_07_TRICK_MODE_PROGRAMMING_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *BVN_MFD
 ***************************************************************************/
/***************************************************************************
 *DRAM_DATA_STRUCTURE - DRAM Data Structure
 ***************************************************************************/
/* BVN_MFD :: DRAM_DATA_STRUCTURE :: DRAM_DATA_STRUCTURE [31:00] */
#define BCHP_BVN_MFD_DRAM_DATA_STRUCTURE_DRAM_DATA_STRUCTURE_MASK  0xffffffff
#define BCHP_BVN_MFD_DRAM_DATA_STRUCTURE_DRAM_DATA_STRUCTURE_SHIFT 0

/***************************************************************************
 *GFD
 ***************************************************************************/
/***************************************************************************
 *DRAM_DATA_STRUCTURE - DRAM Data Structure
 ***************************************************************************/
/* GFD :: DRAM_DATA_STRUCTURE :: DRAM_DATA_STRUCTURE [31:00] */
#define BCHP_GFD_DRAM_DATA_STRUCTURE_DRAM_DATA_STRUCTURE_MASK      0xffffffff
#define BCHP_GFD_DRAM_DATA_STRUCTURE_DRAM_DATA_STRUCTURE_SHIFT     0

/***************************************************************************
 *HIFIDAC_CTRL
 ***************************************************************************/
/***************************************************************************
 *ABSTRACT_01_COMING_OUT_OF_RESET - Process to come out of reset
 ***************************************************************************/
/* HIFIDAC_CTRL :: ABSTRACT_01_COMING_OUT_OF_RESET :: MORE_INFORMATION [31:00] */
#define BCHP_HIFIDAC_CTRL_ABSTRACT_01_COMING_OUT_OF_RESET_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_HIFIDAC_CTRL_ABSTRACT_01_COMING_OUT_OF_RESET_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *ABSTRACT_02_MUTE_USAGE - Mute usage
 ***************************************************************************/
/* HIFIDAC_CTRL :: ABSTRACT_02_MUTE_USAGE :: MORE_INFORMATION [31:00] */
#define BCHP_HIFIDAC_CTRL_ABSTRACT_02_MUTE_USAGE_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_HIFIDAC_CTRL_ABSTRACT_02_MUTE_USAGE_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *ABSTRACT_03_SAMPLE_RATE_CHANGE - Process to effect a sample rate change
 ***************************************************************************/
/* HIFIDAC_CTRL :: ABSTRACT_03_SAMPLE_RATE_CHANGE :: MORE_INFORMATION [31:00] */
#define BCHP_HIFIDAC_CTRL_ABSTRACT_03_SAMPLE_RATE_CHANGE_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_HIFIDAC_CTRL_ABSTRACT_03_SAMPLE_RATE_CHANGE_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *M2MC
 ***************************************************************************/
/***************************************************************************
 *LIST_PACKET_ABSTRACT - Linked-List Packet Abstract
 ***************************************************************************/
/* M2MC :: LIST_PACKET_ABSTRACT :: PACKET_FORMAT [31:00] */
#define BCHP_M2MC_LIST_PACKET_ABSTRACT_PACKET_FORMAT_MASK          0xffffffff
#define BCHP_M2MC_LIST_PACKET_ABSTRACT_PACKET_FORMAT_SHIFT         0

/***************************************************************************
 *LIST_PACKET_HEADER_0 - Linked-List Packet Header Word 0
 ***************************************************************************/
/* M2MC :: LIST_PACKET_HEADER_0 :: reserved0 [31:28] */
#define BCHP_M2MC_LIST_PACKET_HEADER_0_reserved0_MASK              0xf0000000
#define BCHP_M2MC_LIST_PACKET_HEADER_0_reserved0_SHIFT             28

/* M2MC :: LIST_PACKET_HEADER_0 :: NEXT_PKT_ADDR [27:05] */
#define BCHP_M2MC_LIST_PACKET_HEADER_0_NEXT_PKT_ADDR_MASK          0x0fffffe0
#define BCHP_M2MC_LIST_PACKET_HEADER_0_NEXT_PKT_ADDR_SHIFT         5

/* M2MC :: LIST_PACKET_HEADER_0 :: reserved1 [04:01] */
#define BCHP_M2MC_LIST_PACKET_HEADER_0_reserved1_MASK              0x0000001e
#define BCHP_M2MC_LIST_PACKET_HEADER_0_reserved1_SHIFT             1

/* M2MC :: LIST_PACKET_HEADER_0 :: LAST_PKT_IND [00:00] */
#define BCHP_M2MC_LIST_PACKET_HEADER_0_LAST_PKT_IND_MASK           0x00000001
#define BCHP_M2MC_LIST_PACKET_HEADER_0_LAST_PKT_IND_SHIFT          0
#define BCHP_M2MC_LIST_PACKET_HEADER_0_LAST_PKT_IND_NextPktValid   0
#define BCHP_M2MC_LIST_PACKET_HEADER_0_LAST_PKT_IND_NextPktInvalid 1

/***************************************************************************
 *LIST_PACKET_HEADER_1 - Linked-List Packet Header Word 1
 ***************************************************************************/
/* M2MC :: LIST_PACKET_HEADER_1 :: reserved0 [31:15] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_reserved0_MASK              0xffff8000
#define BCHP_M2MC_LIST_PACKET_HEADER_1_reserved0_SHIFT             15

/* M2MC :: LIST_PACKET_HEADER_1 :: SRC_FEEDER_GRP_CNTRL [14:14] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_FEEDER_GRP_CNTRL_MASK   0x00004000
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_FEEDER_GRP_CNTRL_SHIFT  14
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_FEEDER_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_FEEDER_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: DST_FEEDER_GRP_CNTRL [13:13] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_FEEDER_GRP_CNTRL_MASK   0x00002000
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_FEEDER_GRP_CNTRL_SHIFT  13
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_FEEDER_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_FEEDER_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: OUTPUT_FEEDER_GRP_CNTRL [12:12] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_OUTPUT_FEEDER_GRP_CNTRL_MASK 0x00001000
#define BCHP_M2MC_LIST_PACKET_HEADER_1_OUTPUT_FEEDER_GRP_CNTRL_SHIFT 12
#define BCHP_M2MC_LIST_PACKET_HEADER_1_OUTPUT_FEEDER_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_OUTPUT_FEEDER_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: BLIT_GRP_CNTRL [11:11] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_BLIT_GRP_CNTRL_MASK         0x00000800
#define BCHP_M2MC_LIST_PACKET_HEADER_1_BLIT_GRP_CNTRL_SHIFT        11
#define BCHP_M2MC_LIST_PACKET_HEADER_1_BLIT_GRP_CNTRL_GRP_ENABLE   1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_BLIT_GRP_CNTRL_GRP_DISABLE  0

/* M2MC :: LIST_PACKET_HEADER_1 :: SCALE_PARAM_GRP_CNTRL [10:10] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SCALE_PARAM_GRP_CNTRL_MASK  0x00000400
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SCALE_PARAM_GRP_CNTRL_SHIFT 10
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SCALE_PARAM_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SCALE_PARAM_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: BLEND_PARAM_GRP_CNTRL [09:09] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_BLEND_PARAM_GRP_CNTRL_MASK  0x00000200
#define BCHP_M2MC_LIST_PACKET_HEADER_1_BLEND_PARAM_GRP_CNTRL_SHIFT 9
#define BCHP_M2MC_LIST_PACKET_HEADER_1_BLEND_PARAM_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_BLEND_PARAM_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: ROP_GRP_CNTRL [08:08] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_ROP_GRP_CNTRL_MASK          0x00000100
#define BCHP_M2MC_LIST_PACKET_HEADER_1_ROP_GRP_CNTRL_SHIFT         8
#define BCHP_M2MC_LIST_PACKET_HEADER_1_ROP_GRP_CNTRL_GRP_ENABLE    1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_ROP_GRP_CNTRL_GRP_DISABLE   0

/* M2MC :: LIST_PACKET_HEADER_1 :: SRC_COLOR_KEY_GRP_CNTRL [07:07] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_COLOR_KEY_GRP_CNTRL_MASK 0x00000080
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_COLOR_KEY_GRP_CNTRL_SHIFT 7
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_COLOR_KEY_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_COLOR_KEY_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: DST_COLOR_KEY_GRP_CNTRL [06:06] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_COLOR_KEY_GRP_CNTRL_MASK 0x00000040
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_COLOR_KEY_GRP_CNTRL_SHIFT 6
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_COLOR_KEY_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_COLOR_KEY_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: SCALE_COEF_GRP_CNTRL [05:05] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SCALE_COEF_GRP_CNTRL_MASK   0x00000020
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SCALE_COEF_GRP_CNTRL_SHIFT  5
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SCALE_COEF_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SCALE_COEF_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: SRC_COLOR_MATRIX_GRP_CNTRL [04:04] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_COLOR_MATRIX_GRP_CNTRL_MASK 0x00000010
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_COLOR_MATRIX_GRP_CNTRL_SHIFT 4
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_COLOR_MATRIX_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_COLOR_MATRIX_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: DST_COLOR_MATRIX_GRP_CNTRL [03:03] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_COLOR_MATRIX_GRP_CNTRL_MASK 0x00000008
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_COLOR_MATRIX_GRP_CNTRL_SHIFT 3
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_COLOR_MATRIX_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_COLOR_MATRIX_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: OUTPUT_COLOR_MATRIX_GRP_CNTRL [02:02] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_OUTPUT_COLOR_MATRIX_GRP_CNTRL_MASK 0x00000004
#define BCHP_M2MC_LIST_PACKET_HEADER_1_OUTPUT_COLOR_MATRIX_GRP_CNTRL_SHIFT 2
#define BCHP_M2MC_LIST_PACKET_HEADER_1_OUTPUT_COLOR_MATRIX_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_OUTPUT_COLOR_MATRIX_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: SRC_CLUT_GRP_CNTRL [01:01] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_CLUT_GRP_CNTRL_MASK     0x00000002
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_CLUT_GRP_CNTRL_SHIFT    1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_CLUT_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_SRC_CLUT_GRP_CNTRL_GRP_DISABLE 0

/* M2MC :: LIST_PACKET_HEADER_1 :: DST_CLUT_GRP_CNTRL [00:00] */
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_CLUT_GRP_CNTRL_MASK     0x00000001
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_CLUT_GRP_CNTRL_SHIFT    0
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_CLUT_GRP_CNTRL_GRP_ENABLE 1
#define BCHP_M2MC_LIST_PACKET_HEADER_1_DST_CLUT_GRP_CNTRL_GRP_DISABLE 0

/***************************************************************************
 *LIST_PKT_00_SRC_FEEDER_N - Linked-List Packet Word N for group SRC_FEEDER
 ***************************************************************************/
/* M2MC :: LIST_PKT_00_SRC_FEEDER_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_00_SRC_FEEDER_N_REGISTER_CONTENTS_MASK  0xffffffff
#define BCHP_M2MC_LIST_PKT_00_SRC_FEEDER_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_01_DST_FEEDER_N - Linked-List Packet Word N for group DST_FEEDER
 ***************************************************************************/
/* M2MC :: LIST_PKT_01_DST_FEEDER_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_01_DST_FEEDER_N_REGISTER_CONTENTS_MASK  0xffffffff
#define BCHP_M2MC_LIST_PKT_01_DST_FEEDER_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_02_OUTPUT_FEEDER_N - Linked-List Packet Word N for group OUTPUT_FEEDER
 ***************************************************************************/
/* M2MC :: LIST_PKT_02_OUTPUT_FEEDER_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_02_OUTPUT_FEEDER_N_REGISTER_CONTENTS_MASK 0xffffffff
#define BCHP_M2MC_LIST_PKT_02_OUTPUT_FEEDER_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_03_BLIT_N - Linked-List Packet Word N for group BLIT
 ***************************************************************************/
/* M2MC :: LIST_PKT_03_BLIT_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_03_BLIT_N_REGISTER_CONTENTS_MASK        0xffffffff
#define BCHP_M2MC_LIST_PKT_03_BLIT_N_REGISTER_CONTENTS_SHIFT       0

/***************************************************************************
 *LIST_PKT_04_SCALE_PARAM_N - Linked-List Packet Word N for group SCALE_PARAM
 ***************************************************************************/
/* M2MC :: LIST_PKT_04_SCALE_PARAM_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_04_SCALE_PARAM_N_REGISTER_CONTENTS_MASK 0xffffffff
#define BCHP_M2MC_LIST_PKT_04_SCALE_PARAM_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_05_BLEND_PARAM_N - Linked-List Packet Word N for group BLEND_PARAM
 ***************************************************************************/
/* M2MC :: LIST_PKT_05_BLEND_PARAM_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_05_BLEND_PARAM_N_REGISTER_CONTENTS_MASK 0xffffffff
#define BCHP_M2MC_LIST_PKT_05_BLEND_PARAM_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_06_ROP_N - Linked-List Packet Word N for group ROP
 ***************************************************************************/
/* M2MC :: LIST_PKT_06_ROP_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_06_ROP_N_REGISTER_CONTENTS_MASK         0xffffffff
#define BCHP_M2MC_LIST_PKT_06_ROP_N_REGISTER_CONTENTS_SHIFT        0

/***************************************************************************
 *LIST_PKT_07_SRC_COLOR_KEY_N - Linked-List Packet Word N for group SRC_COLOR_KEY
 ***************************************************************************/
/* M2MC :: LIST_PKT_07_SRC_COLOR_KEY_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_07_SRC_COLOR_KEY_N_REGISTER_CONTENTS_MASK 0xffffffff
#define BCHP_M2MC_LIST_PKT_07_SRC_COLOR_KEY_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_08_DST_COLOR_KEY_N - Linked-List Packet Word N for group DST_COLOR_KEY
 ***************************************************************************/
/* M2MC :: LIST_PKT_08_DST_COLOR_KEY_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_08_DST_COLOR_KEY_N_REGISTER_CONTENTS_MASK 0xffffffff
#define BCHP_M2MC_LIST_PKT_08_DST_COLOR_KEY_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_09_SCALE_COEF_N - Linked-List Packet Word N for group SCALE_COEF
 ***************************************************************************/
/* M2MC :: LIST_PKT_09_SCALE_COEF_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_09_SCALE_COEF_N_REGISTER_CONTENTS_MASK  0xffffffff
#define BCHP_M2MC_LIST_PKT_09_SCALE_COEF_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_10_SRC_COLOR_MATRIX_N - Linked-List Packet Word N for group SRC_COLOR_MATRIX
 ***************************************************************************/
/* M2MC :: LIST_PKT_10_SRC_COLOR_MATRIX_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_10_SRC_COLOR_MATRIX_N_REGISTER_CONTENTS_MASK 0xffffffff
#define BCHP_M2MC_LIST_PKT_10_SRC_COLOR_MATRIX_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_11_DST_COLOR_MATRIX_N - Linked-List Packet Word N for group DST_COLOR_MATRIX
 ***************************************************************************/
/* M2MC :: LIST_PKT_11_DST_COLOR_MATRIX_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_11_DST_COLOR_MATRIX_N_REGISTER_CONTENTS_MASK 0xffffffff
#define BCHP_M2MC_LIST_PKT_11_DST_COLOR_MATRIX_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_12_OUTPUT_COLOR_MATRIX_N - Linked-List Packet Word N for group OUTPUT_COLOR_MATRIX
 ***************************************************************************/
/* M2MC :: LIST_PKT_12_OUTPUT_COLOR_MATRIX_N :: REGISTER_CONTENTS [31:00] */
#define BCHP_M2MC_LIST_PKT_12_OUTPUT_COLOR_MATRIX_N_REGISTER_CONTENTS_MASK 0xffffffff
#define BCHP_M2MC_LIST_PKT_12_OUTPUT_COLOR_MATRIX_N_REGISTER_CONTENTS_SHIFT 0

/***************************************************************************
 *LIST_PKT_13_SRC_CLUT - Linked-List Packet Word for group SRC_CLUT
 ***************************************************************************/
/* M2MC :: LIST_PKT_13_SRC_CLUT :: reserved0 [31:29] */
#define BCHP_M2MC_LIST_PKT_13_SRC_CLUT_reserved0_MASK              0xe0000000
#define BCHP_M2MC_LIST_PKT_13_SRC_CLUT_reserved0_SHIFT             29

/* M2MC :: LIST_PKT_13_SRC_CLUT :: REGISTER_CONTENTS [28:00] */
#define BCHP_M2MC_LIST_PKT_13_SRC_CLUT_REGISTER_CONTENTS_MASK      0x1fffffff
#define BCHP_M2MC_LIST_PKT_13_SRC_CLUT_REGISTER_CONTENTS_SHIFT     0

/***************************************************************************
 *LIST_PKT_14_DST_CLUT - Linked-List Packet Word for group DST_CLUT
 ***************************************************************************/
/* M2MC :: LIST_PKT_14_DST_CLUT :: reserved0 [31:29] */
#define BCHP_M2MC_LIST_PKT_14_DST_CLUT_reserved0_MASK              0xe0000000
#define BCHP_M2MC_LIST_PKT_14_DST_CLUT_reserved0_SHIFT             29

/* M2MC :: LIST_PKT_14_DST_CLUT :: REGISTER_CONTENTS [28:00] */
#define BCHP_M2MC_LIST_PKT_14_DST_CLUT_REGISTER_CONTENTS_MASK      0x1fffffff
#define BCHP_M2MC_LIST_PKT_14_DST_CLUT_REGISTER_CONTENTS_SHIFT     0

/***************************************************************************
 *TYPE_CLUT_COLOR_DATA - color data for color look up table
 ***************************************************************************/
/* M2MC :: TYPE_CLUT_COLOR_DATA :: ALPHA [31:24] */
#define BCHP_M2MC_TYPE_CLUT_COLOR_DATA_ALPHA_MASK                  0xff000000
#define BCHP_M2MC_TYPE_CLUT_COLOR_DATA_ALPHA_SHIFT                 24

/* M2MC :: TYPE_CLUT_COLOR_DATA :: RED [23:16] */
#define BCHP_M2MC_TYPE_CLUT_COLOR_DATA_RED_MASK                    0x00ff0000
#define BCHP_M2MC_TYPE_CLUT_COLOR_DATA_RED_SHIFT                   16

/* M2MC :: TYPE_CLUT_COLOR_DATA :: GREEN [15:08] */
#define BCHP_M2MC_TYPE_CLUT_COLOR_DATA_GREEN_MASK                  0x0000ff00
#define BCHP_M2MC_TYPE_CLUT_COLOR_DATA_GREEN_SHIFT                 8

/* M2MC :: TYPE_CLUT_COLOR_DATA :: BLUE [07:00] */
#define BCHP_M2MC_TYPE_CLUT_COLOR_DATA_BLUE_MASK                   0x000000ff
#define BCHP_M2MC_TYPE_CLUT_COLOR_DATA_BLUE_SHIFT                  0

/***************************************************************************
 *MEM_DMA
 ***************************************************************************/
/***************************************************************************
 *DESC_WORD0 - MEM DMA Descriptor Word 0
 ***************************************************************************/
/* MEM_DMA :: DESC_WORD0 :: MODE_SEL [31:29] */
#define BCHP_MEM_DMA_DESC_WORD0_MODE_SEL_MASK                      0xe0000000
#define BCHP_MEM_DMA_DESC_WORD0_MODE_SEL_SHIFT                     29

/* MEM_DMA :: DESC_WORD0 :: ENC_DEC_INIT [28:28] */
#define BCHP_MEM_DMA_DESC_WORD0_ENC_DEC_INIT_MASK                  0x10000000
#define BCHP_MEM_DMA_DESC_WORD0_ENC_DEC_INIT_SHIFT                 28

/* MEM_DMA :: DESC_WORD0 :: READ_ADDR [27:00] */
#define BCHP_MEM_DMA_DESC_WORD0_READ_ADDR_MASK                     0x0fffffff
#define BCHP_MEM_DMA_DESC_WORD0_READ_ADDR_SHIFT                    0

/***************************************************************************
 *DESC_WORD1 - MEM DMA Descriptor Word 1
 ***************************************************************************/
/* MEM_DMA :: DESC_WORD1 :: ALOGRITHM_SEL [31:28] */
#define BCHP_MEM_DMA_DESC_WORD1_ALOGRITHM_SEL_MASK                 0xf0000000
#define BCHP_MEM_DMA_DESC_WORD1_ALOGRITHM_SEL_SHIFT                28

/* MEM_DMA :: DESC_WORD1 :: WRITE_ADDR [27:00] */
#define BCHP_MEM_DMA_DESC_WORD1_WRITE_ADDR_MASK                    0x0fffffff
#define BCHP_MEM_DMA_DESC_WORD1_WRITE_ADDR_SHIFT                   0

/***************************************************************************
 *DESC_WORD2 - MEM DMA Descriptor Word 2
 ***************************************************************************/
/* MEM_DMA :: DESC_WORD2 :: INTR_ENABLE [31:31] */
#define BCHP_MEM_DMA_DESC_WORD2_INTR_ENABLE_MASK                   0x80000000
#define BCHP_MEM_DMA_DESC_WORD2_INTR_ENABLE_SHIFT                  31

/* MEM_DMA :: DESC_WORD2 :: LAST [30:30] */
#define BCHP_MEM_DMA_DESC_WORD2_LAST_MASK                          0x40000000
#define BCHP_MEM_DMA_DESC_WORD2_LAST_SHIFT                         30

/* MEM_DMA :: DESC_WORD2 :: KEY_SELECT [29:26] */
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_MASK                    0x3c000000
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_SHIFT                   26
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY0                    0
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY1                    1
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY2                    2
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY3                    3
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY4                    4
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY5                    5
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY6                    6
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY7                    7
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY8                    8
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY9                    9
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY10                   10
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY11                   11
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY12                   12
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY13                   13
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY14                   14
#define BCHP_MEM_DMA_DESC_WORD2_KEY_SELECT_KEY15                   15

/* MEM_DMA :: DESC_WORD2 :: reserved0 [25:25] */
#define BCHP_MEM_DMA_DESC_WORD2_reserved0_MASK                     0x02000000
#define BCHP_MEM_DMA_DESC_WORD2_reserved0_SHIFT                    25

/* MEM_DMA :: DESC_WORD2 :: TRANSFER_SIZE [24:00] */
#define BCHP_MEM_DMA_DESC_WORD2_TRANSFER_SIZE_MASK                 0x01ffffff
#define BCHP_MEM_DMA_DESC_WORD2_TRANSFER_SIZE_SHIFT                0

/***************************************************************************
 *DESC_WORD3 - MEM DMA Descriptor Word 3
 ***************************************************************************/
/* MEM_DMA :: DESC_WORD3 :: DATA_OPERATION [31:31] */
#define BCHP_MEM_DMA_DESC_WORD3_DATA_OPERATION_MASK                0x80000000
#define BCHP_MEM_DMA_DESC_WORD3_DATA_OPERATION_SHIFT               31
#define BCHP_MEM_DMA_DESC_WORD3_DATA_OPERATION_Disable             0
#define BCHP_MEM_DMA_DESC_WORD3_DATA_OPERATION_Enable              1

/* MEM_DMA :: DESC_WORD3 :: ENCRYPT_DECRYPT_SEL [30:30] */
#define BCHP_MEM_DMA_DESC_WORD3_ENCRYPT_DECRYPT_SEL_MASK           0x40000000
#define BCHP_MEM_DMA_DESC_WORD3_ENCRYPT_DECRYPT_SEL_SHIFT          30
#define BCHP_MEM_DMA_DESC_WORD3_ENCRYPT_DECRYPT_SEL_Encryption     0
#define BCHP_MEM_DMA_DESC_WORD3_ENCRYPT_DECRYPT_SEL_Decryption     1

/* MEM_DMA :: DESC_WORD3 :: DES_3DES_SEL [29:29] */
#define BCHP_MEM_DMA_DESC_WORD3_DES_3DES_SEL_MASK                  0x20000000
#define BCHP_MEM_DMA_DESC_WORD3_DES_3DES_SEL_SHIFT                 29

/* MEM_DMA :: DESC_WORD3 :: reserved0 [28:28] */
#define BCHP_MEM_DMA_DESC_WORD3_reserved0_MASK                     0x10000000
#define BCHP_MEM_DMA_DESC_WORD3_reserved0_SHIFT                    28

/* MEM_DMA :: DESC_WORD3 :: NEXT_DESC_ADDR [27:04] */
#define BCHP_MEM_DMA_DESC_WORD3_NEXT_DESC_ADDR_MASK                0x0ffffff0
#define BCHP_MEM_DMA_DESC_WORD3_NEXT_DESC_ADDR_SHIFT               4

/* MEM_DMA :: DESC_WORD3 :: reserved1 [03:03] */
#define BCHP_MEM_DMA_DESC_WORD3_reserved1_MASK                     0x00000008
#define BCHP_MEM_DMA_DESC_WORD3_reserved1_SHIFT                    3

/* MEM_DMA :: DESC_WORD3 :: READ_ENDIAN_MODE [02:02] */
#define BCHP_MEM_DMA_DESC_WORD3_READ_ENDIAN_MODE_MASK              0x00000004
#define BCHP_MEM_DMA_DESC_WORD3_READ_ENDIAN_MODE_SHIFT             2
#define BCHP_MEM_DMA_DESC_WORD3_READ_ENDIAN_MODE_BIG_ENDIAN        0
#define BCHP_MEM_DMA_DESC_WORD3_READ_ENDIAN_MODE_LITTLE_ENDIAN     1

/* MEM_DMA :: DESC_WORD3 :: WRITE_ENDIAN_XLATE_MODE [01:00] */
#define BCHP_MEM_DMA_DESC_WORD3_WRITE_ENDIAN_XLATE_MODE_MASK       0x00000003
#define BCHP_MEM_DMA_DESC_WORD3_WRITE_ENDIAN_XLATE_MODE_SHIFT      0
#define BCHP_MEM_DMA_DESC_WORD3_WRITE_ENDIAN_XLATE_MODE_WORD_ALIGNED 0
#define BCHP_MEM_DMA_DESC_WORD3_WRITE_ENDIAN_XLATE_MODE_HALF_WORD_ALIGNED 1
#define BCHP_MEM_DMA_DESC_WORD3_WRITE_ENDIAN_XLATE_MODE_BYTE_ALIGNED 2
#define BCHP_MEM_DMA_DESC_WORD3_WRITE_ENDIAN_XLATE_MODE_reserved   3

/***************************************************************************
 *PCI
 ***************************************************************************/
/***************************************************************************
 *DMA_DESC_WORD0 - PDD_WORD0
 ***************************************************************************/
/* PCI :: DMA_DESC_WORD0 :: reserved0 [31:28] */
#define BCHP_PCI_DMA_DESC_WORD0_reserved0_MASK                     0xf0000000
#define BCHP_PCI_DMA_DESC_WORD0_reserved0_SHIFT                    28

/* PCI :: DMA_DESC_WORD0 :: MEMORY_ADDRESS [27:00] */
#define BCHP_PCI_DMA_DESC_WORD0_MEMORY_ADDRESS_MASK                0x0fffffff
#define BCHP_PCI_DMA_DESC_WORD0_MEMORY_ADDRESS_SHIFT               0

/***************************************************************************
 *DMA_DESC_WORD1 - PDD_WORD1
 ***************************************************************************/
/* PCI :: DMA_DESC_WORD1 :: PCI_ADDRESS [31:00] */
#define BCHP_PCI_DMA_DESC_WORD1_PCI_ADDRESS_MASK                   0xffffffff
#define BCHP_PCI_DMA_DESC_WORD1_PCI_ADDRESS_SHIFT                  0

/***************************************************************************
 *DMA_DESC_WORD2 - PDD_WORD2
 ***************************************************************************/
/* PCI :: DMA_DESC_WORD2 :: INTERRUPT_ENABLE [31:31] */
#define BCHP_PCI_DMA_DESC_WORD2_INTERRUPT_ENABLE_MASK              0x80000000
#define BCHP_PCI_DMA_DESC_WORD2_INTERRUPT_ENABLE_SHIFT             31

/* PCI :: DMA_DESC_WORD2 :: DMA_DIRECTION [30:30] */
#define BCHP_PCI_DMA_DESC_WORD2_DMA_DIRECTION_MASK                 0x40000000
#define BCHP_PCI_DMA_DESC_WORD2_DMA_DIRECTION_SHIFT                30
#define BCHP_PCI_DMA_DESC_WORD2_DMA_DIRECTION_PCI_TO_MEMORY        1
#define BCHP_PCI_DMA_DESC_WORD2_DMA_DIRECTION_MEMORY_TO_PCI        0

/* PCI :: DMA_DESC_WORD2 :: reserved0 [29:25] */
#define BCHP_PCI_DMA_DESC_WORD2_reserved0_MASK                     0x3e000000
#define BCHP_PCI_DMA_DESC_WORD2_reserved0_SHIFT                    25

/* PCI :: DMA_DESC_WORD2 :: DMA_TRANSFER_SIZE [24:00] */
#define BCHP_PCI_DMA_DESC_WORD2_DMA_TRANSFER_SIZE_MASK             0x01ffffff
#define BCHP_PCI_DMA_DESC_WORD2_DMA_TRANSFER_SIZE_SHIFT            0

/***************************************************************************
 *DMA_DESC_WORD3 - PDD_WORD3
 ***************************************************************************/
/* PCI :: DMA_DESC_WORD3 :: LAST_RECORD_INDICATOR [31:31] */
#define BCHP_PCI_DMA_DESC_WORD3_LAST_RECORD_INDICATOR_MASK         0x80000000
#define BCHP_PCI_DMA_DESC_WORD3_LAST_RECORD_INDICATOR_SHIFT        31

/* PCI :: DMA_DESC_WORD3 :: reserved0 [30:28] */
#define BCHP_PCI_DMA_DESC_WORD3_reserved0_MASK                     0x70000000
#define BCHP_PCI_DMA_DESC_WORD3_reserved0_SHIFT                    28

/* PCI :: DMA_DESC_WORD3 :: NEXT_DESC_ADDR [27:04] */
#define BCHP_PCI_DMA_DESC_WORD3_NEXT_DESC_ADDR_MASK                0x0ffffff0
#define BCHP_PCI_DMA_DESC_WORD3_NEXT_DESC_ADDR_SHIFT               4

/* PCI :: DMA_DESC_WORD3 :: reserved1 [03:02] */
#define BCHP_PCI_DMA_DESC_WORD3_reserved1_MASK                     0x0000000c
#define BCHP_PCI_DMA_DESC_WORD3_reserved1_SHIFT                    2

/* PCI :: DMA_DESC_WORD3 :: ENDIAN_XLATE_MODE [01:00] */
#define BCHP_PCI_DMA_DESC_WORD3_ENDIAN_XLATE_MODE_MASK             0x00000003
#define BCHP_PCI_DMA_DESC_WORD3_ENDIAN_XLATE_MODE_SHIFT            0
#define BCHP_PCI_DMA_DESC_WORD3_ENDIAN_XLATE_MODE_NO_SWAP          0
#define BCHP_PCI_DMA_DESC_WORD3_ENDIAN_XLATE_MODE_SWAP_16_IN_32    1
#define BCHP_PCI_DMA_DESC_WORD3_ENDIAN_XLATE_MODE_SWAP_32          2
#define BCHP_PCI_DMA_DESC_WORD3_ENDIAN_XLATE_MODE_reserved         3

/***************************************************************************
 *PCM
 ***************************************************************************/
/***************************************************************************
 *DESCRIPTOR_WORD0 - Descriptor Word0
 ***************************************************************************/
/* PCM :: DESCRIPTOR_WORD0 :: reserved0 [31:28] */
#define BCHP_PCM_DESCRIPTOR_WORD0_reserved0_MASK                   0xf0000000
#define BCHP_PCM_DESCRIPTOR_WORD0_reserved0_SHIFT                  28

/* PCM :: DESCRIPTOR_WORD0 :: SDRAM_BUF_ADRS [27:04] */
#define BCHP_PCM_DESCRIPTOR_WORD0_SDRAM_BUF_ADRS_MASK              0x0ffffff0
#define BCHP_PCM_DESCRIPTOR_WORD0_SDRAM_BUF_ADRS_SHIFT             4

/* PCM :: DESCRIPTOR_WORD0 :: reserved1 [03:00] */
#define BCHP_PCM_DESCRIPTOR_WORD0_reserved1_MASK                   0x0000000f
#define BCHP_PCM_DESCRIPTOR_WORD0_reserved1_SHIFT                  0

/***************************************************************************
 *DESCRIPTOR_WORD1 - Descriptor Word1
 ***************************************************************************/
/* PCM :: DESCRIPTOR_WORD1 :: reserved0 [31:24] */
#define BCHP_PCM_DESCRIPTOR_WORD1_reserved0_MASK                   0xff000000
#define BCHP_PCM_DESCRIPTOR_WORD1_reserved0_SHIFT                  24

/* PCM :: DESCRIPTOR_WORD1 :: BUFFER_SIZE [23:00] */
#define BCHP_PCM_DESCRIPTOR_WORD1_BUFFER_SIZE_MASK                 0x00ffffff
#define BCHP_PCM_DESCRIPTOR_WORD1_BUFFER_SIZE_SHIFT                0

/***************************************************************************
 *DESCRIPTOR_WORD2 - Descriptor Word2
 ***************************************************************************/
/* PCM :: DESCRIPTOR_WORD2 :: reserved0 [31:25] */
#define BCHP_PCM_DESCRIPTOR_WORD2_reserved0_MASK                   0xfe000000
#define BCHP_PCM_DESCRIPTOR_WORD2_reserved0_SHIFT                  25

/* PCM :: DESCRIPTOR_WORD2 :: INTR_ENABLE [24:24] */
#define BCHP_PCM_DESCRIPTOR_WORD2_INTR_ENABLE_MASK                 0x01000000
#define BCHP_PCM_DESCRIPTOR_WORD2_INTR_ENABLE_SHIFT                24

/* PCM :: DESCRIPTOR_WORD2 :: TRIGGER_COUNT [23:00] */
#define BCHP_PCM_DESCRIPTOR_WORD2_TRIGGER_COUNT_MASK               0x00ffffff
#define BCHP_PCM_DESCRIPTOR_WORD2_TRIGGER_COUNT_SHIFT              0

/***************************************************************************
 *DESCRIPTOR_WORD3 - Descriptor Word3
 ***************************************************************************/
/* PCM :: DESCRIPTOR_WORD3 :: LAST_DESC_FLAG [31:31] */
#define BCHP_PCM_DESCRIPTOR_WORD3_LAST_DESC_FLAG_MASK              0x80000000
#define BCHP_PCM_DESCRIPTOR_WORD3_LAST_DESC_FLAG_SHIFT             31

/* PCM :: DESCRIPTOR_WORD3 :: reserved0 [30:28] */
#define BCHP_PCM_DESCRIPTOR_WORD3_reserved0_MASK                   0x70000000
#define BCHP_PCM_DESCRIPTOR_WORD3_reserved0_SHIFT                  28

/* PCM :: DESCRIPTOR_WORD3 :: NEXT_DESC_ADRS [27:04] */
#define BCHP_PCM_DESCRIPTOR_WORD3_NEXT_DESC_ADRS_MASK              0x0ffffff0
#define BCHP_PCM_DESCRIPTOR_WORD3_NEXT_DESC_ADRS_SHIFT             4

/* PCM :: DESCRIPTOR_WORD3 :: reserved1 [03:00] */
#define BCHP_PCM_DESCRIPTOR_WORD3_reserved1_MASK                   0x0000000f
#define BCHP_PCM_DESCRIPTOR_WORD3_reserved1_SHIFT                  0

/***************************************************************************
 *RDC
 ***************************************************************************/
/***************************************************************************
 *RUL - RUL Command.
 ***************************************************************************/
/* RDC :: RUL :: opcode [31:24] */
#define BCHP_RDC_RUL_opcode_MASK                                   0xff000000
#define BCHP_RDC_RUL_opcode_SHIFT                                  24
#define BCHP_RDC_RUL_opcode_NOP                                    0
#define BCHP_RDC_RUL_opcode_REG_WRITE_IMM                          1
#define BCHP_RDC_RUL_opcode_REG_WRITE                              2
#define BCHP_RDC_RUL_opcode_REG_READ                               3
#define BCHP_RDC_RUL_opcode_LOAD_IMM                               4
#define BCHP_RDC_RUL_opcode_WINDOW_WRITE                           5
#define BCHP_RDC_RUL_opcode_BLOCK_WRITE                            6
#define BCHP_RDC_RUL_opcode_WINDOW_COPY                            7
#define BCHP_RDC_RUL_opcode_BLOCK_COPY                             8
#define BCHP_RDC_RUL_opcode_WINDOW_TO_BLOCK                        9
#define BCHP_RDC_RUL_opcode_BLOCK_TO_WINDOW                        10
#define BCHP_RDC_RUL_opcode_AND                                    11
#define BCHP_RDC_RUL_opcode_AND_IMM                                12
#define BCHP_RDC_RUL_opcode_OR                                     13
#define BCHP_RDC_RUL_opcode_OR_IMM                                 14
#define BCHP_RDC_RUL_opcode_XOR                                    15
#define BCHP_RDC_RUL_opcode_XOR_IMM                                16
#define BCHP_RDC_RUL_opcode_NOT                                    17
#define BCHP_RDC_RUL_opcode_ROTATE_RIGHT                           18
#define BCHP_RDC_RUL_opcode_SUM                                    19
#define BCHP_RDC_RUL_opcode_SUM_IMM                                20
#define BCHP_RDC_RUL_opcode_PLACEHOLDER                            255

/* RDC :: RUL :: reserved0 [23:23] */
#define BCHP_RDC_RUL_reserved0_MASK                                0x00800000
#define BCHP_RDC_RUL_reserved0_SHIFT                               23

/* union - case rdc_args [22:00] */
/* RDC :: RUL :: rdc_args :: rotation [22:18] */
#define BCHP_RDC_RUL_rdc_args_rotation_MASK                        0x007c0000
#define BCHP_RDC_RUL_rdc_args_rotation_SHIFT                       18

/* RDC :: RUL :: rdc_args :: src1 [17:12] */
#define BCHP_RDC_RUL_rdc_args_src1_MASK                            0x0003f000
#define BCHP_RDC_RUL_rdc_args_src1_SHIFT                           12

/* RDC :: RUL :: rdc_args :: src2 [11:06] */
#define BCHP_RDC_RUL_rdc_args_src2_MASK                            0x00000fc0
#define BCHP_RDC_RUL_rdc_args_src2_SHIFT                           6

/* RDC :: RUL :: rdc_args :: dest [05:00] */
#define BCHP_RDC_RUL_rdc_args_dest_MASK                            0x0000003f
#define BCHP_RDC_RUL_rdc_args_dest_SHIFT                           0

/* union - case reg_args [22:00] */
/* RDC :: RUL :: reg_args :: rotation [22:18] */
#define BCHP_RDC_RUL_reg_args_rotation_MASK                        0x007c0000
#define BCHP_RDC_RUL_reg_args_rotation_SHIFT                       18

/* RDC :: RUL :: reg_args :: src1 [17:12] */
#define BCHP_RDC_RUL_reg_args_src1_MASK                            0x0003f000
#define BCHP_RDC_RUL_reg_args_src1_SHIFT                           12

/* RDC :: RUL :: reg_args :: count [11:00] */
#define BCHP_RDC_RUL_reg_args_count_MASK                           0x00000fff
#define BCHP_RDC_RUL_reg_args_count_SHIFT                          0

/***************************************************************************
 *XPT_PB
 ***************************************************************************/
/***************************************************************************
 *DESCRIPTOR_ABSTRACT - Playback Linked-List Descriptor Abstract
 ***************************************************************************/
/* XPT_PB :: DESCRIPTOR_ABSTRACT :: DESCRIPTOR_FORMAT [31:00] */
#define BCHP_XPT_PB_DESCRIPTOR_ABSTRACT_DESCRIPTOR_FORMAT_MASK     0xffffffff
#define BCHP_XPT_PB_DESCRIPTOR_ABSTRACT_DESCRIPTOR_FORMAT_SHIFT    0

/***************************************************************************
 *DESC_0 - Playback Linked-List Descriptor Word 0
 ***************************************************************************/
/* XPT_PB :: DESC_0 :: reserved0 [31:27] */
#define BCHP_XPT_PB_DESC_0_reserved0_MASK                          0xf8000000
#define BCHP_XPT_PB_DESC_0_reserved0_SHIFT                         27

/* XPT_PB :: DESC_0 :: PB_BUFFER_START_ADDR [26:00] */
#define BCHP_XPT_PB_DESC_0_PB_BUFFER_START_ADDR_MASK               0x07ffffff
#define BCHP_XPT_PB_DESC_0_PB_BUFFER_START_ADDR_SHIFT              0

/***************************************************************************
 *DESC_1 - Playback Linked-List Descriptor Word 1
 ***************************************************************************/
/* XPT_PB :: DESC_1 :: reserved0 [31:27] */
#define BCHP_XPT_PB_DESC_1_reserved0_MASK                          0xf8000000
#define BCHP_XPT_PB_DESC_1_reserved0_SHIFT                         27

/* XPT_PB :: DESC_1 :: PB_BUFFER_LENGTH [26:00] */
#define BCHP_XPT_PB_DESC_1_PB_BUFFER_LENGTH_MASK                   0x07ffffff
#define BCHP_XPT_PB_DESC_1_PB_BUFFER_LENGTH_SHIFT                  0

/***************************************************************************
 *DESC_2 - Playback Linked-List Descriptor Word 2
 ***************************************************************************/
/* XPT_PB :: DESC_2 :: PB_INTERRUPT_ENABLE [31:31] */
#define BCHP_XPT_PB_DESC_2_PB_INTERRUPT_ENABLE_MASK                0x80000000
#define BCHP_XPT_PB_DESC_2_PB_INTERRUPT_ENABLE_SHIFT               31

/* XPT_PB :: DESC_2 :: PB_FORCE_RESYNC [30:30] */
#define BCHP_XPT_PB_DESC_2_PB_FORCE_RESYNC_MASK                    0x40000000
#define BCHP_XPT_PB_DESC_2_PB_FORCE_RESYNC_SHIFT                   30

/* XPT_PB :: DESC_2 :: reserved0 [29:00] */
#define BCHP_XPT_PB_DESC_2_reserved0_MASK                          0x3fffffff
#define BCHP_XPT_PB_DESC_2_reserved0_SHIFT                         0

/***************************************************************************
 *DESC_3 - Playback Linked-List Descriptor Word 3
 ***************************************************************************/
/* XPT_PB :: DESC_3 :: reserved0 [31:27] */
#define BCHP_XPT_PB_DESC_3_reserved0_MASK                          0xf8000000
#define BCHP_XPT_PB_DESC_3_reserved0_SHIFT                         27

/* XPT_PB :: DESC_3 :: PB_NEXT_DESC_ADDR [26:04] */
#define BCHP_XPT_PB_DESC_3_PB_NEXT_DESC_ADDR_MASK                  0x07fffff0
#define BCHP_XPT_PB_DESC_3_PB_NEXT_DESC_ADDR_SHIFT                 4

/* XPT_PB :: DESC_3 :: reserved1 [03:01] */
#define BCHP_XPT_PB_DESC_3_reserved1_MASK                          0x0000000e
#define BCHP_XPT_PB_DESC_3_reserved1_SHIFT                         1

/* XPT_PB :: DESC_3 :: PB_LAST_DESC_IND [00:00] */
#define BCHP_XPT_PB_DESC_3_PB_LAST_DESC_IND_MASK                   0x00000001
#define BCHP_XPT_PB_DESC_3_PB_LAST_DESC_IND_SHIFT                  0

/***************************************************************************
 *XPT_REGS
 ***************************************************************************/
/***************************************************************************
 *ABSTRACT_00_SPECVERSION - Data Transport Specification Version
 ***************************************************************************/
/* XPT_REGS :: ABSTRACT_00_SPECVERSION :: reserved0 [31:00] */
#define BCHP_XPT_REGS_ABSTRACT_00_SPECVERSION_reserved0_MASK       0xffffffff
#define BCHP_XPT_REGS_ABSTRACT_00_SPECVERSION_reserved0_SHIFT      0

/***************************************************************************
 *ABSTRACT_01_DEFINITION_OF_TERMS - Data Transport Definition of Terms
 ***************************************************************************/
/* XPT_REGS :: ABSTRACT_01_DEFINITION_OF_TERMS :: reserved0 [31:00] */
#define BCHP_XPT_REGS_ABSTRACT_01_DEFINITION_OF_TERMS_reserved0_MASK 0xffffffff
#define BCHP_XPT_REGS_ABSTRACT_01_DEFINITION_OF_TERMS_reserved0_SHIFT 0

/***************************************************************************
 *USER_GUIDE_01_PID_TABLE - Data Transport PID Table Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_01_PID_TABLE :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_01_PID_TABLE_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_01_PID_TABLE_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_02_DMA_MESSAGE_BUFFER - Data Transport DMA Message Buffer Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_02_DMA_MESSAGE_BUFFER :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_02_DMA_MESSAGE_BUFFER_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_02_DMA_MESSAGE_BUFFER_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_03_PSI_SECTION_FILTER - Data Transport PSI Section Filter Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_03_PSI_SECTION_FILTER :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_03_PSI_SECTION_FILTER_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_03_PSI_SECTION_FILTER_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_04_PES_PARSER - Data Transport PES Parser
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_04_PES_PARSER :: reserved0 [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_04_PES_PARSER_reserved0_MASK      0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_04_PES_PARSER_reserved0_SHIFT     0

/***************************************************************************
 *USER_GUIDE_05_CONDITIONAL_ACCESS - Data Transport Conditional Access Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_05_CONDITIONAL_ACCESS :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_05_CONDITIONAL_ACCESS_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_05_CONDITIONAL_ACCESS_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_07_INPUT_AND_PARSER_BAND - Data Transport Input and Parser Band Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_07_INPUT_AND_PARSER_BAND :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_07_INPUT_AND_PARSER_BAND_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_07_INPUT_AND_PARSER_BAND_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_08_AUDIO_VIDEO_INTERFACE - Data Transport Audio/Video Interface Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_08_AUDIO_VIDEO_INTERFACE :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_08_AUDIO_VIDEO_INTERFACE_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_08_AUDIO_VIDEO_INTERFACE_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_10_PVR_LINKED_LISTS - Data Transport PVR (Playback/Record/SCD) Linked-List Descriptor Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_10_PVR_LINKED_LISTS :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_10_PVR_LINKED_LISTS_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_10_PVR_LINKED_LISTS_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_11_PVR_PLAYBACK - Data Transport PVR Playback Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_11_PVR_PLAYBACK :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_11_PVR_PLAYBACK_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_11_PVR_PLAYBACK_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_20_HS_PORT_HSX - Data Transport HSX Programming
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_20_HS_PORT_HSX :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_20_HS_PORT_HSX_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_20_HS_PORT_HSX_MORE_INFORMATION_SHIFT 0

/***************************************************************************
 *USER_GUIDE_23_DPCR_MODULE - Data Transport DPCR Module
 ***************************************************************************/
/* XPT_REGS :: USER_GUIDE_23_DPCR_MODULE :: MORE_INFORMATION [31:00] */
#define BCHP_XPT_REGS_USER_GUIDE_23_DPCR_MODULE_MORE_INFORMATION_MASK 0xffffffff
#define BCHP_XPT_REGS_USER_GUIDE_23_DPCR_MODULE_MORE_INFORMATION_SHIFT 0

#endif /* #ifndef BCHP_COMMON_H__ */

/* End of File */

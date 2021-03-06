/*     Copyright (c) 1999-2005, Broadcom Corporation
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
 */

#ifndef _BCMSDS_H_
#define _BCMSDS_H_


#define SDS_RCVR1_BASE     (SDS_ADR_BASE + 0x000)
#define SDS_RCVR2_BASE     (SDS_ADR_BASE + 0x400)
#define SDS_RCVR3_BASE     (SDS_ADR_BASE + 0x800)
#define SDS_BROADCAST_BASE (SDS_ADR_BASE + 0xc00)


/* SDS registers */
#define SDS_CGDIV10 (0x88*4)
#define SDS_CGDIV11 (0x89*4)
#define SDS_DSCTL13 (0x6E*4)
#define SDS_DSCTL14 (0x6F*4)

#define SDS_STADCTL	(0x1000+0x0029*4)
#define SDS_LDADCTL	(0x1000+0x0038*4)
#define SDS_STRTDC1	(0x1000+0x00B4*4)
#define SDS_LDRTDC1	(0x1000+0x00C4*4)
#define SDS_STRTDC2	(0x1000+0x002A*4)
#define SDS_LDRTDC2	(0x1000+0x0039*4)
#define SDS_STTCTL	(0x1000+0x00B6*4)
#define SDS_LDTCTL	(0x1000+0x00C6*4)
#define SDS_STCICC	(0x1000+0x00B3*4)
#define SDS_LDCICC	(0x1000+0x00C3*4)
#define SDS_STFCIC	(0x1000+0x00B1*4)
#define SDS_LDFCIC	(0x1000+0x00C1*4)
#define SDS_STSCIC	(0x1000+0x00BC*4)
#define SDS_LDSCIC	(0x1000+0x00CC*4)
#define SDS_LDTSTM	(0x1000+0x00C0*4)
#define SDS_STRBDT	(0x1000+0x0026*4)
#define SDS_LDRBDT	(0x1000+0x0035*4)

#define SDS_MBYTE0	(0x00*4)
#define SDS_MBYTE1	(0x01*4)
#define SDS_MBYTE2	(0x02*4)
#define SDS_MBYTE3	(0x03*4)
#define SDS_MBTOPH	(0x04*4)
#define SDS_MBTOPL	(0x05*4)
#define SDS_GLBCTL	(0x06*4)
#define SDS_MISCTL	(0x07*4)
#define SDS_GLBSPU	(0x08*4)
#define SDS_DSTGCTL	(0x09*4)
#define SDS_REVID	(0x0A*4)
#define SDS_MIXCTL	(0x0B*4)
#define SDS_FILTCTL	(0x0C*4)
#define SDS_DFCTL	(0x0D*4)
#define SDS_NDFCTL	(0x0E*4)
#define SDS_AGFCTL	(0x0F*4)
#define SDS_ADCPCTL	(0x10*4)
#define SDS_ADCPCLP	(0x11*4)
#define SDS_ADCDBIT	(0x12*4)
#define SDS_DCOCTL1	(0x13*4)
#define SDS_DCOCTL2	(0x14*4)
#define SDS_IQAMP	(0x15*4)
#define SDS_IQPHS	(0x16*4)
#define SDS_GDECTL	(0x17*4)
#define SDS_CGCTRL	(0x18*4)
#define SDS_CGPDWN	(0x19*4)
#define SDS_CGMISC	(0x1A*4)
#define SDS_CGMISC2	(0x1B*4)
#define SDS_STDIV0	(0x1C*4)
#define SDS_CGDIV0	(0x1C*4)
#define SDS_STDIV1	(0x1D*4)
#define SDS_CGDIV1	(0x1D*4)
#define SDS_STDIV2	(0x1E*4)
#define SDS_CGDIV2	(0x1E*4)
#define SDS_STDIV3	(0x1F*4)
#define SDS_CGDIV3	(0x1F*4)
#define SDS_STSDIV0	(0x20*4)
#define SDS_CGDIV4	(0x20*4)
#define SDS_STSDIV1	(0x21*4)
#define SDS_CGDIV5	(0x21*4)
#define SDS_STSDIV2	(0x22*4)
#define SDS_CGDIV6	(0x22*4)
#define SDS_STSDIV3	(0x23*4)
#define SDS_CGDIV7	(0x23*4)
#define SDS_STSDIV4	(0x24*4)
#define SDS_CGDIV8	(0x24*4)
#define SDS_STSDIV5	(0x25*4)
#define SDS_CGDIV9	(0x25*4)
#define SDS_SPLLN	(0x26*4)
#define SDS_CGPLLCTL1	(0x26*4)
#define SDS_EXTIFDIR    (0x26*4)
#define SDS_CGPLLCTL4	(0x27*4)
#define SDS_CGPLLCTL3	(0x28*4)
#define SDS_CGCTL2	(0x29*4)
#define SDS_CGPLLCTL2	(0x2A*4)
#define SDS_APLLCTL1    (0x2B*4)
#define SDS_APLLCTL2    (0x2C*4)
#define SDS_CGPLLCTL5   (0x2D*4)
#define SDS_CGPLLCTL6	(0x2E*4)
#define SDS_PUPCFG	(0x2F*4)
#define SDS_CGPLL	(0x30*4)
#define SDS_IRQSTS5	(0x31*4)
#define SDS_IRQMSK5	(0x32*4)
#define SDS_CGCTL1	(0x33*4)
#define SDS_BERCTLA	(0x34*4)
#define SDS_BERCTLB	(0x35*4)
#define SDS_TMRCTL	(0x36*4)
#define SDS_NVCTL	(0x37*4)
#define SDS_IRQSTS1	(0x38*4)
#define SDS_IRQSTS2	(0x39*4)
#define SDS_IRQSTS3	(0x3A*4)
#define SDS_IRQSTS4	(0x3B*4)
#define SDS_IRQMSK1	(0x3C*4)
#define SDS_IRQMSK2	(0x3D*4)
#define SDS_IRQMSK3	(0x3E*4)
#define SDS_IRQMSK4	(0x3F*4)
#define SDS_EQMODE	(0x40*4)
#define SDS_EQBLND	(0x41*4)
#define SDS_EQFFE1	(0x42*4)
#define SDS_EQFFE2	(0x43*4)
#define SDS_EQFFE3	(0x44*4)
#define SDS_EQMISC	(0x45*4)
#define SDS_EQCFAD	(0x46*4)
#define SDS_EQFRZ1	(0x47*4)
#define SDS_EQFRZ2	(0x48*4)
#define SDS_VLCTL1	(0x49*4)
#define SDS_VLCTL2	(0x4A*4)
#define SDS_VLCTL3	(0x4B*4)
#define SDS_VTCTL1	(0x4C*4)
#define SDS_VTCTL2	(0x4D*4)
#define SDS_BLPCTL1	(0x50*4)
#define SDS_BLPCTL2	(0x51*4)
#define SDS_BLPCTL3	(0x52*4)
#define SDS_BLCPTH	(0x53*4)
#define SDS_PFCTL	(0x54*4)
#define SDS_AGICTL	(0x55*4)
#define SDS_AGTCTL	(0x56*4)
#define SDS_AGCMISC	(0x57*4)
#define SDS_CLCTL	(0x58*4)
#define SDS_CLPDCTL	(0x59*4)
#define SDS_CLCSQCFD	(0x5A*4)
#define SDS_CLMISC	(0x5B*4)
#define SDS_CLMISC2	(0x5C*4)
#define SDS_CLSTS	(0x5D*4)
#define SDS_CLEXT	(0x5E*4)
#define SDS_DSCTL1	(0x60*4)
#define SDS_DSCTL2	(0x61*4)
#define SDS_DSCTL3	(0x62*4)
#define SDS_DSCTL4	(0x63*4)
#define SDS_DSCTL5	(0x64*4)
#define SDS_DSCTL6	(0x65*4)
#define SDS_DSCTL7	(0x66*4)
#define SDS_DSCTL8	(0x67*4)
#define SDS_DSCTL9	(0x68*4)
#define SDS_DSCMD	(0x69*4)
#define SDS_DSRPLY	(0x6A*4)
#define SDS_DSCTL10	(0x6B*4)
#define SDS_DSCTL11	(0x6C*4)
#define SDS_IICTL1	(0x70*4)
#define SDS_IICTL2	(0x71*4)
#define SDS_IICCNT	(0x72*4)
#define SDS_IICHPA	(0x73*4)
#define SDS_SNRCTL	(0x75*4)
#define SDS_SNRUDI1	(0x76*4)
#define SDS_SNRUDI2	(0x77*4)
#define SDS_MSPIRX	(0x7A*4)
#define SDS_MSPITX	(0x7B*4)
#define SDS_SPICTL	(0x7D*4)
#define SDS_SB001	(0x7E*4)
#define SDS_FECTL	(0x7F*4)
#define SDS_SB002	(0x80*4)
#define SDS_SB003	(0x81*4)
#define SDS_SB004	(0x82*4)
#define SDS_SB008	(0x83*4)
#define SDS_SB009	(0x84*4)
#define SDS_SB010	(0x85*4)
#define SDS_CGPLLCTL7	(0x86*4)
#define SDS_HPLLCTL	(0x87*4)
#define SDS_SB011	(0x8D*4)
#define SDS_SB012	(0x8E*4)
#define SDS_SB013	(0x8F*4)
#define SDS_SB014	(0x90*4)
#define SDS_ADIC8	(0x91*4)
#define SDS_ADIC16	(0x92*4)
#define SDS_SB015	(0x93*4)
#define SDS_SB016     (0x94*4)
#define SDS_SB017	(0x96*4)
#define SDS_SB005	(0x98*4)
#define SDS_SB006	(0x99*4)
#define SDS_SB007	(0x9A*4)
#define SDS_TFECM0	(0x9B*4)
#define SDS_TFECM1	(0x9C*4)
#define SDS_TFECM2	(0x9D*4)
#define SDS_TFECM3	(0x9E*4)
#define SDS_TFECM4	(0x9F*4)
#define SDS_MCTRL	(0xA0*4)
#define SDS_MCTRLMSK	(0xA1*4)
#define SDS_MARB	(0xA2*4)
#define SDS_MBSYWDOG	(0xA3*4)
#define SDS_MHSTSTAT	(0xA4*4)
#define SDS_MINTSTAT	(0xA5*4)
#define SDS_MRCVSTAT	(0xA6*4)
#define SDS_MVIOSTAT	(0xA7*4)
#define SDS_HPLLDIV1    (0xA8*4)
#define SDS_HPLLDIV2    (0xA9*4)
#define SDS_HPLLDIV3    (0xAA*4)
#define SDS_HPLLDIV4    (0xAB*4)
#define SDS_PLL5        (0xAC*4)
#define SDS_PLL6        (0xAD*4)
#define SDS_MMICROSEL   (0xAE*4)
#define SDS_BSY_BYPAS   (0xAF*4)
#define SDS_R1POSTRD1	(0xB0*4)
#define SDS_R1POSTRD2	(0xB1*4)
#define SDS_R1POSTRD3	(0xB2*4)
#define SDS_R1POSTRD4	(0xB3*4)
#define SDS_R2POSTRD1	(0xB4*4)
#define SDS_R2POSTRD2	(0xB5*4)
#define SDS_R2POSTRD3	(0xB6*4)
#define SDS_R2POSTRD4	(0xB7*4)
#define SDS_R3POSTRD1	(0xB8*4)
#define SDS_R3POSTRD2	(0xB9*4)
#define SDS_R3POSTRD3	(0xBA*4)
#define SDS_R3POSTRD4	(0xBB*4)
#define SDS_MSTAT1	(0xBC*4)
#define SDS_MSTAT2	(0xBD*4)
#define SDS_MSTAT3	(0xBE*4)
#define SDS_MSTAT4	(0xBF*4)
#define SDS_PSCTL	(0xD0*4)
#define SDS_OIFCTL	(0xD1*4)
#define SDS_OIFCTL2	(0xD2*4)
#define SDS_OFVCOD	(0xD3*4)
#define SDS_OFVCOM	(0xD4*4)
#define SDS_CPPCTL      (0xD5*4)
#define SDS_OIFCTL4     (0xD6*4)
#define SDS_VBLCTL1     (0xDC*4)
#define SDS_VBLCTL2     (0xDD*4)
#define SDS_MBBRDCST	(0xE4*4)
#define SDS_OIFCTL3	(0xF1*4)
#define SDS_CGCTL3	(0xF2*4)
#define SDS_DSCTL12	(0xF3*4)
#define SDS_GBLTPCTL	(0xF4*4)
#define SDS_BCKTMR      (0xF5*4)
#define SDS_TFECM5	(0xF7*4)
#define SDS_TFECM6	(0xF8*4)
#define SDS_TFECM7	(0xF9*4)
#define SDS_AFECTL1	(0xFD*4)
#define SDS_AUXID       (0xFF*4)
#define SDS_STFLLC	(0x1000+0x0000*4)
#define SDS_STFLLC1	(0x1000+0x0001*4)
#define SDS_STFLIC	(0x1000+0x0002*4)
#define SDS_STFLIC1	(0x1000+0x0003*4)
#define SDS_STFLSW	(0x1000+0x0004*4)
#define SDS_STFLI	(0x1000+0x0005*4)
#define SDS_STFLIF	(0x1000+0x0006*4)
#define SDS_STFLPA	(0x1000+0x0007*4)
#define SDS_STFLTD	(0x1000+0x0008*4)
#define SDS_STCRFTD	(0x1000+0x0008*4)
#define SDS_STPLTD	(0x1000+0x0009*4)
#define SDS_STCRBTD	(0x1000+0x0009*4)
#define SDS_STPLC	(0x1000+0x000A*4)
#define SDS_STCRCO	(0x1000+0x000A*4)
#define SDS_STPLC1	(0x1000+0x000B*4)
#define SDS_STPLSW	(0x1000+0x000D*4)
#define SDS_STCRSWB	(0x1000+0x000D*4)
#define SDS_STPLI	(0x1000+0x000E*4)
#define SDS_STCRIB	(0x1000+0x000E*4)
#define SDS_STPLPA	(0x1000+0x000F*4)
#define SDS_STCRPAB	(0x1000+0x000F*4)
#define SDS_STFSYN	(0x1000+0x0010*4)
#define SDS_STFRS	(0x1000+0x0011*4)
#define SDS_STFMOD	(0x1000+0x0012*4)
#define SDS_STFERR	(0x1000+0x0013*4)
#define SDS_STATHR	(0x1000+0x0014*4)
#define SDS_STABW	(0x1000+0x0015*4)
#define SDS_STAII	(0x1000+0x0016*4)
#define SDS_STAGI	(0x1000+0x0017*4)
#define SDS_STAGI2	(0x1000+0x0018*4)
#define SDS_STAIT	(0x1000+0x0019*4)
#define SDS_STAGT	(0x1000+0x001A*4)
#define SDS_STCMTH	(0x1000+0x001B*4)
#define SDS_STCRBFD	(0x1000+0x001C*4)
#define SDS_STSNRE	(0x1000+0x001D*4)
#define SDS_STSNRHT	(0x1000+0x001E*4)
#define SDS_STSNRLT	(0x1000+0x001F*4)
#define SDS_STBRLC	(0x1000+0x0020*4)
#define SDS_STBRIC	(0x1000+0x0021*4)
#define SDS_STBRI	(0x1000+0x0022*4)
#define SDS_STBFOS	(0x1000+0x0023*4)
#define SDS_STAGF	(0x1000+0x0024*4)
#define SDS_STAIF	(0x1000+0x0025*4)
#define SDS_STTBTI	(0x1000+0x0026*4)
#define SDS_STQ15T	(0x1000+0x0027*4)
#define SDS_STTPWC	(0x1000+0x0028*4)
#define SDS_STRLDT	(0x1000+0x0029*4)
#define SDS_STRHDT	(0x1000+0x002A*4)
#define SDS_STRXBT	(0x1000+0x002B*4)
#define SDS_STDTCT	(0x1000+0x002C*4)
#define SDS_STRXRT	(0x1000+0x002D*4)
#define SDS_STRERT	(0x1000+0x002E*4)
#define SDS_STDSCT	(0x1000+0x002F*4)
#define SDS_STV0	(0x1000+0x0030*4)
#define SDS_STV1	(0x1000+0x0031*4)
#define SDS_STV2	(0x1000+0x0032*4)
#define SDS_STV3	(0x1000+0x0033*4)
#define SDS_STV4	(0x1000+0x0034*4)
#define SDS_STV5	(0x1000+0x0035*4)
#define SDS_STV6	(0x1000+0x0036*4)
#define SDS_STV7	(0x1000+0x0037*4)
#define SDS_STVINT	(0x1000+0x0038*4)
#define SDS_STOPLL	(0x1000+0x0039*4)
#define SDS_STOPLL2	(0x1000+0x003A*4)
#define SDS_STADC	(0x1000+0x0040*4)
#define SDS_STADCCNT	(0x1000+0x0041*4)
#define SDS_STADCT	(0x1000+0x0041*4)
#define SDS_STDCO	(0x1000+0x0043*4)
#define SDS_STDCODS	(0x1000+0x0044*4)
#define SDS_STDCDS	(0x1000+0x0044*4)
#define SDS_STAMPEST	(0x1000+0x0046*4)
#define SDS_STAEST	(0x1000+0x0046*4)
#define SDS_STPHEST	(0x1000+0x0047*4)
#define SDS_STPEST	(0x1000+0x0047*4)
#define SDS_STGDEC	(0x1000+0x0048*4)
#define SDS_MB021	(0x1000+0x0049*4)
#define SDS_MB022	(0x1000+0x004B*4)
#define SDS_MB023	(0x1000+0x004C*4)
#define SDS_STDLIF	(0x1000+0x004D*4)
#define SDS_MB025	(0x1000+0x004E*4)
#define SDS_MB026	(0x1000+0x004F*4)
#define SDS_MB027	(0x1000+0x0050*4)
#define SDS_MB028	(0x1000+0x0051*4)
#define SDS_STCFD	(0x1000+0x0052*4)
#define SDS_MB032RST    (0x1000+0x0052*4)
#define SDS_MB032MSK    (0x1000+0x0053*4)
#define SDS_STBERTMR	(0x1000+0x0056*4)
#define SDS_STVBLLC	(0x1000+0x0057*4)
#define SDS_STVBLIC	(0x1000+0x0058*4)
#define SDS_STVBLI	(0x1000+0x0059*4)
#define SDS_STVBFOS	(0x1000+0x005A*4)
#define SDS_STBLK	(0x1000+0x005B*4)
#define SDS_STF0B	(0x1000+0x0060*4)
#define SDS_ST8PSK1	(0x1000+0x0061*4)
#define SDS_ST8PSK2	(0x1000+0x0062*4)
#define SDS_STQPSK	(0x1000+0x0063*4)
#define SDS_ST16QAM	(0x1000+0x0064*4)
#define SDS_STOFD	(0x1000+0x0065*4)
#define SDS_MB029    (0x1000+0x0066*4)
#define SDS_MB030	(0x1000+0x0067*4)
#define SDS_STCRBFD1	(0x1000+0x0068*4)
#define SDS_MB031	(0x1000+0x0069*4)
#define SDS_MB032	(0x1000+0x006A*4)
#define SDS_MB033	(0x1000+0x006B*4)
#define SDS_STCMA	(0x1000+0x0070*4)
#define SDS_STEQLK	(0x1000+0x0072*4)
#define SDS_STVLCI	(0x1000+0x0078*4)
#define SDS_STVLCQ	(0x1000+0x0079*4)
#define SDS_STVCOS	(0x1000+0x007A*4)
#define SDS_STCLLA	(0x1000+0x007B*4)
#define SDS_STCLHT	(0x1000+0x007C*4)
#define SDS_STCLLT	(0x1000+0x007D*4)
#define SDS_STCLCT	(0x1000+0x007E*4)
#define SDS_STPLPD	(0x1000+0x007F*4)
#define SDS_STBEIT	(0x1000+0x0080*4)
#define SDS_STBERC	(0x1000+0x0081*4)
#define SDS_STBEM1	(0x1000+0x0082*4)
#define SDS_STBEM2	(0x1000+0x0083*4)
#define SDS_STBEM3	(0x1000+0x0084*4)
#define SDS_STPSU1	(0x1000+0x0085*4)
#define SDS_STPSU2	(0x1000+0x0086*4)
#define SDS_STBLLA	(0x1000+0x0087*4)
#define SDS_STBLHT	(0x1000+0x0088*4)
#define SDS_STBLLT	(0x1000+0x0089*4)
#define SDS_STBLCT	(0x1000+0x008A*4)
#define SDS_MB007	(0x1000+0x008B*4)
#define SDS_MB009	(0x1000+0x008C*4)
#define SDS_STTFM2	(0x1000+0x008D*4)
#define SDS_STTFM3	(0x1000+0x008E*4)
#define SDS_STTFM4	(0x1000+0x008F*4)
#define SDS_STTSLV	(0x1000+0x0090*4)
#define SDS_STTSEQ	(0x1000+0x0091*4)
#define SDS_MB003	(0x1000+0x0092*4)
#define SDS_MB005	(0x1000+0x0093*4)
#define SDS_STTCIV	(0x1000+0x0094*4)
#define SDS_MB011	(0x1000+0x0095*4)
#define SDS_STTRND	(0x1000+0x0096*4)
#define SDS_MB013	(0x1000+0x0097*4)
#define SDS_MB015	(0x1000+0x0098*4)
#define SDS_MB017	(0x1000+0x0099*4)
#define SDS_MB019	(0x1000+0x009A*4)
#define SDS_STDCDSX	(0x1000+0x009B*4)
#define SDS_STTFM5	(0x1000+0x009C*4)
#define SDS_STTFM6	(0x1000+0x009D*4)
#define SDS_STTFM7	(0x1000+0x009E*4)
#define SDS_STTFM8	(0x1000+0x009F*4)
#define SDS_STBTMR	(0x1000+0x00A0*4)
#define SDS_STTPDIR	(0x1000+0x00A1*4)
#define SDS_STTPODS1	(0x1000+0x00A2*4)
#define SDS_STTPODS2	(0x1000+0x00A3*4)
#define SDS_STTPODS3	(0x1000+0x00A4*4)
#define SDS_STTPDS	(0x1000+0x00A5*4)
#define SDS_STTPCTL1	(0x1000+0x00A6*4)
#define SDS_STTPCTL2	(0x1000+0x00A7*4)
#define SDS_STTPCTL3	(0x1000+0x00A8*4)
#define SDS_MB034	(0x1000+0x00A9*4)
#define SDS_MB035	(0x1000+0x00AA*4)
#define SDS_MB036	(0x1000+0x00AB*4)
#define SDS_MB037	(0x1000+0x00AC*4)
#define SDS_MB038	(0x1000+0x00AD*4)
#define SDS_MB039	(0x1000+0x00AE*4)
#define SDS_STTPMICD	(0x1000+0x00AF*4)
#define SDS_STMBSTAT	(0x1000+0x00B0*4)
#define SDS_STVTOP	(0x1000+0x00B1*4)
#define SDS_STSLEW	(0x1000+0x00B2*4)
#define SDS_STOCTM	(0x1000+0x00B3*4)
#define SDS_STABYP	(0x1000+0x00B4*4)
#define SDS_STDDIO	(0x1000+0x00B5*4)
#define SDS_STAFECTL2	(0x1000+0x00B8*4)
#define SDS_STTPCTL4	(0x1000+0x00B9*4)
#define SDS_STTPCTL5	(0x1000+0x00BA*4)
#define SDS_STAFECTL	(0x1000+0x00BB*4)
#define SDS_STDSCK	(0x1000+0x00BC*4)
#define SDS_STMIICTX1	(0x1000+0x00BD*4)
#define SDS_STMIICTX2	(0x1000+0x00BE*4)
#define SDS_STFERC	(0x1000+0x00BF*4)
#define SDS_STMBAPR  	(0x1000+0x00D0*4)
#define SDS_STMBCTL	(0x1000+0x00D1*4)
#define SDS_STMBCPCTL	(0x1000+0x00D2*4)
#define SDS_STMBTBCTA	(0x1000+0x00D3*4)
#define SDS_STMBTBCTB	(0x1000+0x00D4*4)
#define SDS_STMBTBCTC	(0x1000+0x00D5*4)
#define SDS_STMBTBCTD	(0x1000+0x00D6*4)
#define SDS_STMBTBCTE	(0x1000+0x00D7*4)
#define SDS_STMBTBCTF	(0x1000+0x00D8*4)
#define SDS_STCPCFG1	(0x1000+0x00E0*4)
#define SDS_STCPCFG2	(0x1000+0x00E1*4)
#define SDS_STCPUW	(0x1000+0x00E2*4)
#define SDS_STTREN	(0x1000+0x00E3*4)
#define SDS_STAPRDA	(0x1000+0x00E4*4)
#define SDS_STAPWA	(0x1000+0x00E5*4)
#define SDS_STTBDL	(0x1000+0x00E7*4)
#define SDS_STVLCSC	(0x1000+0x00E8*4)
#define SDS_STROTD	(0x1000+0x00E9*4)
#define SDS_STCDEN	(0x1000+0x00EA*4)
#define SDS_STSNREN	(0x1000+0x00EB*4)
#define SDS_STBTEN	(0x1000+0x00EC*4)
#define SDS_STQFDT	(0x1000+0x00ED*4)
#define SDS_STMTAD	(0x1000+0x00EE*4)
#define SDS_MB001	(0x1000+0x00EF*4)
#define SDS_STRSMA	(0x1000+0x00F0*4)
#define SDS_STRSSM	(0x1000+0x00F1*4)
#define SDS_STMPLEN	(0x1000+0x00F2*4)
#define SDS_STPSVE	(0x1000+0x00F3*4)
#define SDS_STCPPIE	(0x1000+0x00F4*4)
#define SDS_STCPPIT1	(0x1000+0x00F5*4)
#define SDS_STCPPIT2	(0x1000+0x00F6*4)
#define SDS_STRSTH	(0x1000+0x00F7*4)
#define SDS_STIRSTS	(0x1000+0x00F8*4)
#define SDS_STEXERSE	(0x1000+0x00F9*4)
#define SDS_STEXERS1	(0x1000+0x00FA*4)
#define SDS_STEXERS2	(0x1000+0x00FB*4)
#define SDS_MB_RD_OFFSET (0x1000+0x0100*4)
#define SDS_LDFLLC	(0x1000+0x0000*4)
#define SDS_LDFLLC1	(0x1000+0x0001*4)
#define SDS_LDFLIC	(0x1000+0x0002*4)
#define SDS_LDFLIC1	(0x1000+0x0003*4)
#define SDS_LDFLSW	(0x1000+0x0004*4)
#define SDS_LDFLI	(0x1000+0x0005*4)
#define SDS_LDFLIF	(0x1000+0x0006*4)
#define SDS_LDFLPA	(0x1000+0x0007*4)
#define SDS_LDFLFO	(0x1000+0x0008*4)
#define SDS_LDFLTD	(0x1000+0x0009*4)
#define SDS_LDCRFTD	(0x1000+0x0009*4)
#define SDS_LDPLTD	(0x1000+0x000A*4)
#define SDS_LDCRBTD	(0x1000+0x000A*4)
#define SDS_LDPLC	(0x1000+0x000B*4)
#define SDS_LDCRCO	(0x1000+0x000B*4)
#define SDS_LDPLC1	(0x1000+0x000C*4)
#define SDS_LDPLSW	(0x1000+0x000E*4)
#define SDS_LDCRSWB	(0x1000+0x000E*4)
#define SDS_LDPLI	(0x1000+0x000F*4)
#define SDS_LDCRIB	(0x1000+0x000F*4)
#define SDS_LDPLPA	(0x1000+0x0010*4)
#define SDS_LDCRPAB	(0x1000+0x0010*4)
#define SDS_LDQC	(0x1000+0x0011*4)
#define SDS_LDSFT	(0x1000+0x0012*4)
#define SDS_LDAII	(0x1000+0x0013*4)
#define SDS_LDAGI	(0x1000+0x0014*4)
#define SDS_LDAIT	(0x1000+0x0015*4)
#define SDS_LDATHR	(0x1000+0x0016*4)
#define SDS_LDAGT	(0x1000+0x0017*4)
#define SDS_LDAGI2	(0x1000+0x0018*4)
#define SDS_LDABW	(0x1000+0x0019*4)
#define SDS_LDBRLC	(0x1000+0x001A*4)
#define SDS_LDBRIC	(0x1000+0x001B*4)
#define SDS_LDBRI	(0x1000+0x001C*4)
#define SDS_LDBFOS	(0x1000+0x001D*4)
#define SDS_LDBRFO	(0x1000+0x001E*4)
#define SDS_LDBNCO	(0x1000+0x001F*4)
#define SDS_LDAIF	(0x1000+0x0020*4)
#define SDS_LDAGF	(0x1000+0x0021*4)
#define SDS_LDFSYN	(0x1000+0x0022*4)
#define SDS_LDFRS	(0x1000+0x0023*4)
#define SDS_LDFMOD	(0x1000+0x0024*4)
#define SDS_LDFERR	(0x1000+0x0025*4)
#define SDS_LDFRSV	(0x1000+0x0026*4)
#define SDS_LDV0	(0x1000+0x0027*4)
#define SDS_LDV1	(0x1000+0x0028*4)
#define SDS_LDV2	(0x1000+0x0029*4)
#define SDS_LDV3	(0x1000+0x002A*4)
#define SDS_LDV4	(0x1000+0x002B*4)
#define SDS_LDV5	(0x1000+0x002C*4)
#define SDS_LDV6	(0x1000+0x002D*4)
#define SDS_LDV7	(0x1000+0x002E*4)
#define SDS_LDVINT	(0x1000+0x002F*4)
#define SDS_LDVCNT	(0x1000+0x0030*4)
#define SDS_LDVSTC	(0x1000+0x0031*4)
#define SDS_LDVST	(0x1000+0x0032*4)
#define SDS_LDVREC	(0x1000+0x0033*4)
#define SDS_LDVRCV	(0x1000+0x0034*4)
#define SDS_LDTBTI	(0x1000+0x0035*4)
#define SDS_LDQ15T	(0x1000+0x0036*4)
#define SDS_LDTPWC	(0x1000+0x0037*4)
#define SDS_LDRLDT	(0x1000+0x0038*4)
#define SDS_LDRHDT	(0x1000+0x0039*4)
#define SDS_LDRXBT	(0x1000+0x003A*4)
#define SDS_LDDTCT	(0x1000+0x003B*4)
#define SDS_LDRXRT	(0x1000+0x003C*4)
#define SDS_LDRERT	(0x1000+0x003D*4)
#define SDS_LDDSCT	(0x1000+0x003E*4)
#define SDS_LDCMTH	(0x1000+0x003F*4)
#define SDS_LDADC	(0x1000+0x0040*4)
#define SDS_LDADCCNT	(0x1000+0x0041*4)
#define SDS_LDADCT	(0x1000+0x0041*4)
#define SDS_LDADCCLIP	(0x1000+0x0042*4)
#define SDS_LDADCP	(0x1000+0x0042*4)
#define SDS_LDDCO	(0x1000+0x0043*4)
#define SDS_LDDCODS	(0x1000+0x0044*4)
#define SDS_LDDCDS	(0x1000+0x0044*4)
#define SDS_LDDCOINT	(0x1000+0x0045*4)
#define SDS_LDDCIT	(0x1000+0x0045*4)
#define SDS_LDAMPEST	(0x1000+0x0046*4)
#define SDS_LDAEST	(0x1000+0x0046*4)
#define SDS_LDPHSEST	(0x1000+0x0047*4)
#define SDS_LDPEST	(0x1000+0x0047*4)
#define SDS_MB040	(0x1000+0x0048*4)
#define SDS_MB041	(0x1000+0x004A*4)
#define SDS_MB042	(0x1000+0x004B*4)
#define SDS_LDDLIF	(0x1000+0x004C*4)
#define SDS_MB044	(0x1000+0x004D*4)
#define SDS_MB045	(0x1000+0x004E*4)
#define SDS_MB046	(0x1000+0x004F*4)
#define SDS_MB047	(0x1000+0x0050*4)
#define SDS_MB048	(0x1000+0x0051*4)
#define SDS_MB049	(0x1000+0x0052*4)
#define SDS_MB050	(0x1000+0x0053*4)
#define SDS_MB051	(0x1000+0x0054*4)
#define SDS_MB052	(0x1000+0x0055*4)
#define SDS_MB053	(0x1000+0x0056*4)
#define SDS_LDVBLLC	(0x1000+0x0057*4)
#define SDS_LDVBLIC	(0x1000+0x0058*4)
#define SDS_LDVBLI	(0x1000+0x0059*4)
#define SDS_LDVBFOS	(0x1000+0x005A*4)
#define SDS_LDBLK	(0x1000+0x005B*4)
#define SDS_MB054	(0x1000+0x005D*4)
#define SDS_MB055	(0x1000+0x005E*4)
#define SDS_MB0551	(0x1000+0x005F*4)
#define SDS_MB0552	(0x1000+0x0060*4)
#define SDS_MB0553	(0x1000+0x0061*4)
#define SDS_LDCFD	(0x1000+0x0062*4)
#define SDS_MB064RST    (0x1000+0x0062*4) 
#define SDS_LDBERTMR	(0x1000+0x0063*4)
#define SDS_LDVBLFO	(0x1000+0x0065*4)
#define SDS_LDVBLLA	(0x1000+0x0066*4)
#define SDS_MB064MSK	(0x1000+0x0067*4)
#define SDS_LDTRN	(0x1000+0x0064*4)
#define SDS_LDCCP1	(0x1000+0x006D*4)
#define SDS_MB059	(0x1000+0x006E*4)
#define SDS_LDF0B	(0x1000+0x0070*4)
#define SDS_LD8PSK1	(0x1000+0x0071*4)
#define SDS_LD8PSK2	(0x1000+0x0072*4)
#define SDS_LDQPSK	(0x1000+0x0073*4)
#define SDS_LD16QAM	(0x1000+0x0074*4)
#define SDS_LDOFD	(0x1000+0x0075*4)
#define SDS_LDCMA	(0x1000+0x0076*4)
#define SDS_LDEQLK	(0x1000+0x0078*4)
#define SDS_LDVLCI	(0x1000+0x007A*4)
#define SDS_LDVLCQ	(0x1000+0x007B*4)
#define SDS_LDVCOS	(0x1000+0x007C*4)
#define SDS_LDDST1	(0x1000+0x007D*4)
#define SDS_LDCLLA	(0x1000+0x007E*4)
#define SDS_LDBEST	(0x1000+0x007F*4)
#define SDS_LDBEIT	(0x1000+0x0080*4)
#define SDS_LDBERC	(0x1000+0x0081*4)
#define SDS_LDBEM1	(0x1000+0x0082*4)
#define SDS_LDBEM2	(0x1000+0x0083*4)
#define SDS_LDBEM3	(0x1000+0x0084*4)
#define SDS_LDPSU1	(0x1000+0x0085*4)
#define SDS_LDPSU2	(0x1000+0x0086*4)
#define SDS_LD2CSA	(0x1000+0x0089*4)
#define SDS_LDPISA	(0x1000+0x008A*4)
#define SDS_MB060	(0x1000+0x008B*4)
#define SDS_MB061    (0x1000+0x008C*4)
#define SDS_MB062	(0x1000+0x008D*4)
#define SDS_LDCCP2	(0x1000+0x008E*4)
#define SDS_LDBLLA	(0x1000+0x008F*4)
#define SDS_LDSNRE	(0x1000+0x0090*4)
#define SDS_LDSNRHT	(0x1000+0x0091*4)
#define SDS_LDSNRLT	(0x1000+0x0092*4)
#define SDS_LDTSLV	(0x1000+0x0093*4)
#define SDS_LDTSEQ	(0x1000+0x0094*4)
#define SDS_MB004	(0x1000+0x0095*4)
#define SDS_MB006	(0x1000+0x0096*4)
#define SDS_LDTCIV	(0x1000+0x0097*4)
#define SDS_MB012	(0x1000+0x0098*4)
#define SDS_LDTRND	(0x1000+0x0099*4)
#define SDS_MB014	(0x1000+0x009A*4)
#define SDS_MB016	(0x1000+0x009B*4)
#define SDS_MB018	(0x1000+0x009C*4)
#define SDS_MB020	(0x1000+0x009D*4)
#define SDS_LDTPN	(0x1000+0x009E*4)
#define SDS_LDDST2	(0x1000+0x009F*4)
#define SDS_MB063	(0x1000+0x00A0*4)
#define SDS_MB064	(0x1000+0x00A1*4)
#define SDS_MB065	(0x1000+0x00A2*4)
#define SDS_LDDCDSX	(0x1000+0x00A4*4)
#define SDS_LDCGSTA	(0x1000+0x00A5*4)
#define SDS_LDGDEC	(0x1000+0x00A6*4)
#define SDS_LDCHID	(0x1000+0x00A7*4)
#define SDS_LDTFM6	(0x1000+0x00A8*4)
#define SDS_LDTFM7	(0x1000+0x00A9*4)
#define SDS_LDTFM8	(0x1000+0x00AA*4)
#define SDS_LDTFM9	(0x1000+0x00AB*4)
#define SDS_MB008	(0x1000+0x00AC*4)
#define SDS_MB010	(0x1000+0x00AD*4)
#define SDS_LDTFMC	(0x1000+0x00AE*4)
#define SDS_LDTFMD	(0x1000+0x00AF*4)
#define SDS_LDBTMR	(0x1000+0x00B0*4)
#define SDS_LDTPDIR	(0x1000+0x00B1*4)
#define SDS_LDTPODS1	(0x1000+0x00B2*4)
#define SDS_LDTPODS2	(0x1000+0x00B3*4)
#define SDS_LDTPODS3	(0x1000+0x00B4*4)
#define SDS_LDTPDS	(0x1000+0x00B5*4)
#define SDS_LDTPCTL1	(0x1000+0x00B6*4)
#define SDS_LDTPCTL2	(0x1000+0x00B7*4)
#define SDS_LDTPCTL3	(0x1000+0x00B8*4)
#define SDS_MB066	(0x1000+0x00B9*4)
#define SDS_MB067	(0x1000+0x00BA*4)
#define SDS_MB068	(0x1000+0x00BB*4)
#define SDS_MB069	(0x1000+0x00BC*4)
#define SDS_MB070	(0x1000+0x00BD*4)
#define SDS_MB071	(0x1000+0x00BE*4)
#define SDS_LDTPMICD	(0x1000+0x00BF*4)
#define SDS_LDVTOP	(0x1000+0x00C1*4)
#define SDS_LDSLEW	(0x1000+0x00C2*4)
#define SDS_LDOTCM	(0x1000+0x00C3*4)
#define SDS_LDOCTM	(0x1000+0x00C3*4)
#define SDS_LDABYP	(0x1000+0x00C4*4)
#define SDS_LDDDIO	(0x1000+0x00C5*4)
#define SDS_LDAFECTL2	(0x1000+0x00C8*4)
#define SDS_LDTPCTL4	(0x1000+0x00C9*4)
#define SDS_LDTPCTL5	(0x1000+0x00CA*4)
#define SDS_LDAFECTL	(0x1000+0x00CB*4)
#define SDS_LDDSCK	(0x1000+0x00CC*4)
#define SDS_LDOPLL	(0x1000+0x00CD*4)
#define SDS_LDOPLL2	(0x1000+0x00CE*4)
#define SDS_LDCGSTA1	(0x1000+0x00CF*4)
#define SDS_LDCGSTA2	(0x1000+0x00D0*4)
#define SDS_LDMIICTX1	(0x1000+0x00D1*4)
#define SDS_LDMIICTX2	(0x1000+0x00D2*4)
#define SDS_LDMIICRX1	(0x1000+0x00D3*4)
#define SDS_LDMIICRX2	(0x1000+0x00D4*4)
#define SDS_LDFERC	(0x1000+0x00D5*4)
#define SDS_LDMBAPR	(0x1000+0x00D6*4)
#define SDS_LDMBCTL	(0x1000+0x00D7*4)
#define SDS_LDMSTAT	(0x1000+0x00D8*4)
#define SDS_LDMBSTAT	(0x1000+0x00D8*4)
#define SDS_LDMBCPST	(0x1000+0x00D9*4)
#define SDS_LDMBTBSTA	(0x1000+0x00DA*4)
#define SDS_LDMBTBSTB	(0x1000+0x00DB*4)
#define SDS_LDMBTBSTC	(0x1000+0x00DC*4)
#define SDS_LDMBTBSTD	(0x1000+0x00DD*4)
#define SDS_LDMBTBSTE	(0x1000+0x00DE*4)
#define SDS_LDMBTBSTF	(0x1000+0x00DF*4)
#define SDS_LDCPCFG1	(0x1000+0x00E0*4)
#define SDS_LDCPCFG2	(0x1000+0x00E1*4)
#define SDS_LDCPUW	(0x1000+0x00E2*4)
#define SDS_LDTREN	(0x1000+0x00E3*4)
#define SDS_LDAPRDA	(0x1000+0x00E4*4)
#define SDS_LDAPWA	(0x1000+0x00E5*4)
#define SDS_LDWSAOW	(0x1000+0x00E6*4)
#define SDS_LDTBDL	(0x1000+0x00E7*4)
#define SDS_LDVLCSC	(0x1000+0x00E8*4)
#define SDS_LDROTD	(0x1000+0x00E9*4)
#define SDS_LDCDEN	(0x1000+0x00EA*4)
#define SDS_LDSNREN	(0x1000+0x00EB*4)
#define SDS_LDBTEN	(0x1000+0x00EC*4)
#define SDS_LDMTAD	(0x1000+0x00EE*4)
#define SDS_MB002	(0x1000+0x00EF*4)
#define SDS_LDRSMA	(0x1000+0x00F0*4)
#define SDS_LDRSSM	(0x1000+0x00F1*4)
#define SDS_LDMPLEN	(0x1000+0x00F2*4)
#define SDS_LDPSVE	(0x1000+0x00F3*4)
#define SDS_LDCPPIE	(0x1000+0x00F4*4)
#define SDS_LDCPPIT1	(0x1000+0x00F5*4)
#define SDS_LDCPPIT2	(0x1000+0x00F6*4)
#define SDS_LDRSTH	(0x1000+0x00F7*4)
#define SDS_LDIRSTS	(0x1000+0x00F8*4)
#define SDS_LDEXERSE	(0x1000+0x00F9*4)
#define SDS_LDEXERS1	(0x1000+0x00FA*4)
#define SDS_LDEXERS2	(0x1000+0x00FB*4)
#define SDS_LDQBCSF	(0x1000+0x00FC*4)

/* IRQSTS1/IRQMSK1 bit definitions */
#define IRQSTS1_BTIMER      0x20
#define IRQSTS1_BERTIMER    0x40

/* IRQSTS2/IRQMSK2 bit definitions */
#define IRQSTS2_ALL_LOCKED  0x08
#define IRQSTS2_NOT_LOCKED  0x04

/* IRQMSK3/IRQSTS3 bit definitions */
#define IRQMSK3_BTIMER      0x80
#define IRQSTS3_BTIMER      0x80

/* BCKTMR bit definitions */
#define BCKTMR_DISEQC_CLK   0x01
#define BCKTMR_BTIMER_START 0x02
#define BCKTMR_BER_START    0x04

/* CGCTL2 bit definitions */
#define CGCTL2_DISEQC_CLK   0x40
#define CGCTL2_BTIMER_START 0x80

/* OIFCTL bit definitiions */
#define OIFCTL_XBERT  0x04
#define OIFCTL_TEST   0x01

/* OIFCTL2 bit definitions */
#define OIFCTL2_DELH  0x80
#define OIFCTL2_HEAD4 0x40
#define OIFCTL2_SYNC1 0x20
#define OIFCTL2_DELAY 0x04

/* PSCTL bit definitions */
#define PSCTL_ERRINV  0x80
#define PSCTL_SYNCINV 0x40
#define PSCTL_VLDINV  0x20
#define PSCTL_CLKSUP  0x10
#define PSCTL_CLKINV  0x08
#define PSCTL_SERIAL  0x02

/* DSCTL1 bit definitions */
#define DSCTL1_TBMSEL   0x80
#define DSCTL1_TBMDEN   0x40
#define DSCTL1_CTMSEL   0x20
#define DSCTL1_CTMDEN   0x10
#define DSCTL1_RRPYEN   0x08
#define DSCTL1_RESRCE   0x04
#define DSCTL1_TSTART   0x02
#define DSCTL1_DSTCLR   0x01

/* DSCTL2 bit definitions */
#define DSCTL2_ACWDTX   0x80
#define DSCTL2_ACWEN13V 0x40
#define DSCTL2_SEL13V   0x20
#define DSCTL2_LNBPU    0x10
#define DSCTL2_DFSRST   0x08
#define DSCTL2_LOWSPLY  0x04
#define DSCTL2_RSTPTR   0x02
#define DSCTL2_DSRST    0x01

/* DSCTL3 bit definitions */
#define DSCTL3_SLBYP1   0x40
#define DSCTL3_ACWEN1   0x20
#define DSCTL3_SLVTP1   0x10
#define DSCTL3_VCTEN1   0x08
#define DSCTL3_SLWDS1   0x04
#define DSCTL3_DCADD1   0x02
#define DSCTL3_TNADD1   0x01

/* DSCTL4 bit definitions */
#define DSCTL4_SLBYP2   0x40
#define DSCTL4_ACWEN2   0x20
#define DSCTL4_SLVTP2   0x10
#define DSCTL4_VCTEN2   0x08
#define DSCTL4_SLWDS2   0x04
#define DSCTL4_DCADD2   0x02
#define DSCTL4_TNADD2   0x01

/* DSCTL6 bit definitions */
#define DSCTL6_TSTCLR   0x80
#define DSCTL6_TDETEN   0x40
#define DSCTL6_ACWVCTL  0x20
#define DSCTL6_OVRCEN   0x10
#define DSCTL6_FSTSLW   0x08
#define DSCTL6_TXENMD   0x04
#define DSCTL6_TPOCLP   0x02
#define DSCTL6_TCLPEN   0x01

/* DSCTL7 bit definitions */
#define DSCTL7_RTODIS   0x40

/* DSCTL9 bit definitions */
#define DSCTL9_TIMEEN   0x80
#define DSCTL9_DACTST   0x40
#define DSCTL9_TXOUT    0x20
#define DSCTL9_TXEN     0x10

/* DSCTL10 bit definitions */
#define DSCTL10_PWRUP   0x40

/* DSCTL11 bit definitions */
#define DSCTL11_TRSWEN1 0x40

/* DSCTL12 bit definitions */
#define DSCTL12_TRSWEN2 0x40

/* LDDST1 bit definitions */
#define LDDST1_CWDONE        0x10000000
#define LDDST1_RXDONE        0x08000000
#define LDDST1_TXDONE        0x04000000
#define LDDST1_DSDONE        0x02000000
#define LDDST1_DSERR         0x01000000
#define LDDST1_RXBCNT_MASK   0x00f00000
#define LDDST1_RXBCNT_RSHIFT 20
#define LDDST1_TXSCNT_MASK   0x000f0000
#define LDDST1_RXERTO        0x00008000
#define LDDST1_RXOF          0x00004000
#define LDDST1_RXRPTO        0x00002000
#define LDDST1_RXPARE        0x00001000
#define LDDST1_RXDEME        0x00000800

#endif

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
 *
** File:		bcmintrnum.h
** Description: Linux system int number header file
**
** Created: 03/05/2002 by Qiang Ye
**
** REVISION:
**
** $Log: $
**
**
****************************************************************/
#ifndef BCMINTRNUM_H
#define BCMINTRNUM_H


#ifdef __cplusplus
extern "C" {
#endif

/*
 * Following is the complete map of interrupts in the system. Please
 * keep this up to date and make sure you comment your changes in the
 * comment block above with the date, your initials and what you did.
 *
 * There are two different interrupts in the system. The first type
 * is an actual hardware interrupt. We have a total of eight MIPS
 * interrupts. Two of them are software interrupts and are ignored.
 * The remaining six interrupts are actually monitored and handled
 * by low-level interrupt code in 'int-handler.S' that call dispatch
 * functions in this file to call the IRQ descriptors in the Linux
 * kernel.
 * 
 * The second type is the Linux kernel system interrupt which is
 * a table of IRQ descriptors (see 'include/linux/irq.h' and
 * 'include/linux/interrupt.h') that relate the hardware interrupt
 * handler types to the software IRQ descriptors. This is where all
 * of the status information and function pointers are defined so
 * that registration, releasing, disabling and enabling of interrupts
 * can be performed. Multiple system interrupts can be tied to a
 * single hardware interrupt. Examining this file along with the
 * other three aforementioned files should solidify the concepts.
 *
 * The first table simply shows the MIPS IRQ mapping:
 *
 *   MIPS IRQ   Source
 *   --------   ------
 *       0      Software *Ignored*
 *       1      Software *Ignored*
 *       2      Hardware BRCMSTB chip Internal
 *       3      Hardware External *Unused*
 *       4      Hardware External *Unused*
 *       5      Hardware External *Unused*
 *       6      Hardware External *Unused*
 *       7      R4k timer 
 *
 * The second table shows the table of Linux system interrupt
 * descriptors and the mapping to the hardware IRQ sources:
 *
 *   System IRQ   MIPS IRQ   Source
 *   ----------   --------   ------
 *
 *        0         2         Chip Interrupt Controller/Dedicated Handler
 *      1- 32       2         The 32 Interrupt Controller Bits
 *       33         2         UARTA
 *       34         2         UARTB
 *       60         7      R4k timer (used for master system time)
 *

 *
 * Again, I cannot stress this enough, keep this table up to date!!!
 */


/* JPF Serial Code depends on a unique IRQ for each serial port */
#define BCM_LINUX_UARTA_IRQ		(BCHP_HIF_CPU_INTR1_INTR_W0_STATUS_reserved0_SHIFT+BCHP_HIF_CPU_INTR1_INTR_W1_STATUS_reserved0_SHIFT+1)
#define BCM_LINUX_UARTB_IRQ		(BCM_LINUX_UARTA_IRQ+1)

/* JPF Each line in the INTC has an IRQ */

#define	BCM_LINUX_CPU_ENET_IRQ		16

#define POD_IRQ_NUM 33 

#define BCM_LINUX_SATA_IRQ			37     /* last one for intc level. */


/* Smart Card */
//#define BCM_LINUX_SCA_IRQ		40
//#define BCM_LINUX_SCB_IRQ		41

#define BCM_LINUX_SYSTIMER_IRQ		60


#define BCM_LINUX_3250_IRQ		(BCM_LINUX_UARTB_IRQ+1)
#define BCM_LINUX_EXT_PCI_IRQ	(BCM_LINUX_3250_IRQ+1)

#define POD_DET_IRQ_NUM  58


#ifdef __cplusplus
}
#endif

#endif



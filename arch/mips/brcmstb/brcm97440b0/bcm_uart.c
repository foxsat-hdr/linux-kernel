/*---------------------------------------------------------------------------

    Copyright (c) 2001-2005 Broadcom Corporation                     /\
                                                              _     /  \     _
    _____________________________________________________/ \   /    \   / \_
                                                            \_/      \_/  
    
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License version 2 as
 published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

    File: bcm_uart.c

    Description: 
    Simple UART driver for 7400 16550V2 style UART

when	who what
-----	---	----
051011	tht	Original coding
 ------------------------------------------------------------------------- */

#define DFLT_BAUDRATE   115200

#define SER_DIVISOR(_x, clk)		(((clk) + (_x) * 8) / ((_x) * 16))
#define DIVISOR_TO_BAUD(div, clk)	((clk) / 16 / (div))


#include <linux/config.h>
#include <linux/types.h>
#include "asm/brcmstb/common/serial.h"
#include <linux/serial.h>
#include <linux/serial_reg.h>
#include <asm/serial.h>
#include <asm/io.h>
#include <linux/module.h>


int uart_initialized = 0;

static int shift = 2;

/*
 * At this point, the serial driver is not initialized yet, but we rely on the
 * bootloader to have initialized UARTA
 */

#if 0
/* 
* InitSerial() - initialize UART-A to 115200, 8, N, 1
*/
asm void InitSerial(void)
{
	.set noreorder

	/* t3 contains the UART BAUDWORD */
	li		t3,0x0e
	li	t0, 0xb0400b00
	li	t1,0x83  // DLAB, 8bit
	sw	t1,0x0c(t0)
	sw	t3,0x00(t0)
	sw	zero,0x04(t0)
	li	t1,0x03
	sw	t1,0x0c(t0)
	sw	zero,0x08(t0) //disable FIFO.
	
	jr	ra
	nop
	
	.set reorder
}
#endif

/* 
 * UART IP pin assignments from the 7440A0 RDB SUN_TOP_CTRL_PIN_MUX_CTRL.
 *  bits field is 3 bits wide
 *
 *	UART	GPIO	MUX	bits	value
 *	______________________________________
 *	0 tx	43	8	08:06	1
 *	0 rx	61	9	29:27	1
 *	______________________________________
 *	1 tx	9	4	26:24	1
 *	1 rx	11	5	02:00	1
 *	______________________________________
 *	2 tx	1	4	02:00	1
 *	2 rx	0	3	30:28	1
 *	______________________________________
 *	3 tx	44	8	11:09	1
 *	3 rx	60	9	26:24	1
 *	______________________________________
 *
 */

struct uart_pin_assignment {
	    int tx_mux;
	    int tx_pos;
	    int rx_mux;
	    int rx_pos;
    };

struct uart_pin_assignment brcm_7440A0_uart_pins[4] = {
	{ 8,  6, 9, 27},
	{ 4, 24, 5,  0},
	{ 4,  0, 3, 28},
	{ 8,  9, 9, 24}
    } ;


#define SUN_TOP_CTRL_PIN_MUX_CTRL_0	(0xb0404100)
static void
serial_set_pin_mux(int chan)
{
	int mux, mask;
	struct uart_pin_assignment *pins;
	volatile unsigned long *MuxCtrl;

	/* Pin mux control registers 0-10 are contiguous */
	 MuxCtrl = (volatile unsigned long*) SUN_TOP_CTRL_PIN_MUX_CTRL_0;

	if (chan < 0 || chan > 3)
		return;

	pins = &brcm_7440A0_uart_pins[chan];
	
	/* tx */
	mux  = pins->tx_mux;
	mask = 0x07 <<  pins->tx_pos;
	MuxCtrl[mux] &= ~mask;
	MuxCtrl[mux] |= 1 << pins->tx_pos;
	
	/* rx */
	mux  = pins->rx_mux;
	mask = 0x07 <<  pins->rx_pos;
	MuxCtrl[mux] &= ~mask;
	MuxCtrl[mux] |= 1 << pins->rx_pos;

}

unsigned long serial_init(int chan, void *ignored)
{
#if 0
	struct serial_struct req;

	/* UARTA has already been initialized by the bootloader */
	if (chan > 0) {
		memset(&req, 0, sizeof(struct serial_struct));
		req.port = chan;
		req.iomem_base = UARTA_ADR_BASE + (0x40 * chan);
		req.irq = BRCM_SERIAL1_IRQ + chan;  // FOr now, assume all 3 irqs are consecutive
		req.baud_base = BRCM_BASE_BAUD;
		req.xmit_fifo_size = 32;

		/* How far apart the registers are. */
		req.iomem_reg_shift = shift = 2;  /* Offset by 4 bytes, UART_SDW_LCR=0c offset, UART_LCR=3 */
		
		req.io_type = SERIAL_IO_MEM;
		req.flags = STD_COM_FLAGS;
		req.iomap_base = chan;

		register_serial(&req);

	}
	
#endif

	unsigned long uartBaseAddr = BRCM_SERIAL1_BASE + (0x40 * chan); 
	void uartB_puts(const char *s);
        void uartC_puts(const char *s);
        void uartD_puts(const char *s);


#ifdef CONFIG_MIPS_BRCM_IKOS
  #define DIVISOR (14)
#else
  #define DIVISOR (44)
#endif

	shift = 2;


	/* ttyS0 has already been initialized by the bootloader */

		
	if (chan > 0 ) {
		// Write DLAB, and (8N1) = 0x83
		writel(UART_LCR_DLAB|UART_LCR_WLEN8, (void *)(uartBaseAddr + (UART_LCR << shift)));
		// Write DLL to 0xe
		writel(DIVISOR, (void *)(uartBaseAddr + (UART_DLL << shift)));
		writel(0, (void *)(uartBaseAddr + (UART_DLM << shift)));

		// Clear DLAB
		writel(UART_LCR_WLEN8, (void *)(uartBaseAddr + (UART_LCR << shift)));

		// Disable FIFO
		writel(0, (void *)(uartBaseAddr + (UART_FCR << shift)));

		if (chan == 1) {
			uartB_puts("Done initializing UARTB\n");
		}
                else if (chan == 2) {
                        uartC_puts("Done initializing UARTC\n");
                }
                else if (chan == 3) {
                        uartD_puts("Done initializing UARTD\n");
                }

	}
	return (uartBaseAddr);
}

#if 0

unsigned long 
my_readl(unsigned long addr)
{
	return *((volatile unsigned long*) addr);
}

void
my_writel(unsigned char c, unsigned long addr)
{
	*((volatile unsigned long*) addr) = c;
}

#endif

void
serial_putc(unsigned long com_port, unsigned char c)
{
	while ((readl((void *)(com_port + (UART_LSR << shift))) & UART_LSR_THRE) == 0)
		;
	writel(c, (void *)com_port);
}

unsigned char
serial_getc(unsigned long com_port)
{
	while ((readl((void *)(com_port + (UART_LSR << shift))) & UART_LSR_DR) == 0)
		;
	return readl((void *)com_port);
}

int
serial_tstc(unsigned long com_port)
{
	return ((readl((void *)(com_port + (UART_LSR << shift))) & UART_LSR_DR) != 0);
}

/* Old interface, for compatibility */

extern int console_uart;

/* --------------------------------------------------------------------------
    Name: PutChar
 Purpose: Send a character to the UART
-------------------------------------------------------------------------- */
void 
//PutChar(char c)
uart_putc(char c)
{
	serial_putc(BRCM_SERIAL1_BASE + (console_uart * 0x40), c);
}

void
//PutChar(char c)
uartA_putc(char c)
{
    serial_putc(BRCM_SERIAL1_BASE, c);
}

void 
//PutChar(char c)
uartB_putc(char c)
{
    serial_putc(BRCM_SERIAL2_BASE, c);
}
void
//PutChar(char c)
uartC_putc(char c)
{
    serial_putc(BRCM_SERIAL3_BASE, c);
}
void
//PutChar(char c)
uartD_putc(char c)
{
    serial_putc(BRCM_SERIAL4_BASE, c);
}

/* --------------------------------------------------------------------------
    Name: PutString
 Purpose: Send a string to the UART
-------------------------------------------------------------------------- */
void 
//PutString(const char *s)
uart_puts(const char *s)
{
	if (uart_initialized)
	{
		while (*s) {
			if (*s == '\n') {
				uart_putc('\r');
			}
			uart_putc(*s++);
		}
	}

}

void 
//PutString(const char *s)
uartA_puts(const char *s)
{
    while (*s) {
        if (*s == '\n') {
            uartA_putc('\r');
        }
    	uartA_putc(*s++);
    }
}
void
//PutString(const char *s)
uartB_puts(const char *s)
{
    while (*s) {
        if (*s == '\n') {
            uartB_putc('\r');
        }
        uartB_putc(*s++);
    }
}

void
//PutString(const char *s)
uartC_puts(const char *s)
{
    while (*s) {
        if (*s == '\n') {
            uartC_putc('\r');
        }
        uartC_putc(*s++);
    }
}
void
//PutString(const char *s)
uartD_puts(const char *s)
{
    while (*s) {
        if (*s == '\n') {
            uartD_putc('\r');
        }
        uartD_putc(*s++);
    }
}

/* --------------------------------------------------------------------------
    Name: GetChar
 Purpose: Get a character from the UART. Non-blocking
-------------------------------------------------------------------------- */
char 
uart_getc(void)
{
	return serial_getc(BRCM_SERIAL1_BASE + (console_uart * 0x40) );
}

char
uartA_getc(void)
{
	return serial_getc(BRCM_SERIAL1_BASE);
}

char
uartB_getc(void)
{
        return serial_getc(BRCM_SERIAL2_BASE);
}

char
uartC_getc(void)
{
        return serial_getc(BRCM_SERIAL3_BASE);
}

char
uartD_getc(void)
{
        return serial_getc(BRCM_SERIAL4_BASE);
}



/**************************************************/
/*********** End Broadcom Specific ****************/
/**************************************************/
int console_initialized;
int brcm_console_initialized(void)
{
	return console_initialized;
}
EXPORT_SYMBOL(brcm_console_initialized);

/* --------------------------------------------------------------------------
    Name: bcm71xx_uart_init
 Purpose: Initalize the UARTA abd UARTB
-------------------------------------------------------------------------- */
void 
uart_init(unsigned long ignored)
{
	serial_init(0, NULL); 		/* UARTA */
	serial_init(1, NULL);		/* UARTB */
	serial_init(2, NULL);		/* UARTC */
	serial_init(3, NULL);		/* UARTD */

	serial_set_pin_mux(0);
	serial_set_pin_mux(1);
	serial_set_pin_mux(2);
	serial_set_pin_mux(3);
	//console_initialized = 1;
        uart_initialized = 1;

}


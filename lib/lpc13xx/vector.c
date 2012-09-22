/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#define WEAK __attribute__ ((weak))

#include <libopencm3/cm3/common.h>
/* Symbols exported by the linker script(s). */
extern u32 _etext, _data, _edata, _ebss, _stack;

void main(void);
void reset_handler(void);
void blocking_handler(void);
void null_handler(void);

void WEAK nmi_handler(void);
void WEAK hard_fault_handler(void);
void WEAK mem_manage_handler(void);
void WEAK bus_fault_handler(void);
void WEAK usage_fault_handler(void);
void WEAK sv_call_handler(void);
void WEAK debug_monitor_handler(void);
void WEAK pend_sv_handler(void);
void WEAK sys_tick_handler(void);

void WEAK wakeup_pio_isr(void);
void WEAK i2c_isr(void);
void WEAK timer16_0_isr(void);
void WEAK timer16_1_isr(void);
void WEAK timer32_0_isr(void);
void WEAK timer32_1_isr(void);
void WEAK ssp_isr(void);
void WEAK uart_isr(void);
void WEAK usb0_isr(void);
void WEAK usb1_isr(void);
void WEAK adc_isr(void);
void WEAK wdt_isr(void);
void WEAK bod_isr(void);
void WEAK fmc_isr(void);
void WEAK pio3_isr(void);
void WEAK pio2_isr(void);
void WEAK pio1_isr(void);
void WEAK pio0_isr(void);
/* TODO: Interrupt handler prototypes */

__attribute__ ((section(".vectors")))
void (*const vector_table[]) (void) = {
	(void*)&_stack,		/* Addr: 0x0000_0000 */
	reset_handler,		/* Addr: 0x0000_0004 */
	nmi_handler,		/* Addr: 0x0000_0008 */
	hard_fault_handler,	/* Addr: 0x0000_000C */
	mem_manage_handler,	/* Addr: 0x0000_0010 */
	bus_fault_handler,	/* Addr: 0x0000_0014 */
	usage_fault_handler,	/* Addr: 0x0000_0018 */
	0, 0, 0, 0,		/* Reserved Addr: 0x0000_001C - 0x0000_002B */
	sv_call_handler,	/* Addr: 0x0000_002C */
	debug_monitor_handler,	/* Addr: 0x0000_0030 */
	0,			/* Reserved Addr: 0x0000_00034 */
	pend_sv_handler,	/* Addr: 0x0000_0038 */
	sys_tick_handler,	/* Addr: 0x0000_003C */
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        wakeup_pio_isr,
        i2c_isr,
        timer16_0_isr,
        timer16_1_isr,
        timer32_0_isr,
        timer32_1_isr,
        ssp_isr,
        uart_isr,
        usb0_isr,
        usb1_isr,
        adc_isr,
        wdt_isr,
        bod_isr,
        fmc_isr,
        pio3_isr,
        pio2_isr,
        pio1_isr,
        pio0_isr
};


void reset_handler(void)
{
	u32 *src, *dest;
        /* set main stack pointer (MSP) to the end of ram (_stack) */
	__asm__("MSR msp, %0" : : "r"(&_stack));

        /* Copy initialized values to variables */
	for (src = &_etext, dest = &_data; dest < &_edata; src++, dest++)
		*dest = *src;

        /* Write zero to zero-initialized variables */
	while (dest < &_ebss)
		*dest++ = 0;

	/* Call the application's entry point. */
	main();
}

void blocking_handler(void)
{
	while (1) ;
}

void null_handler(void)
{
	/* Do nothing. */
}

#pragma weak nmi_handler = null_handler
#pragma weak hard_fault_handler = blocking_handler
#pragma weak mem_manage_handler = blocking_handler
#pragma weak bus_fault_handler = blocking_handler
#pragma weak usage_fault_handler = blocking_handler
#pragma weak sv_call_handler = null_handler
#pragma weak debug_monitor_handler = null_handler
#pragma weak pend_sv_handler = null_handler
#pragma weak sys_tick_handler = null_handler


#pragma weak wakeup_pio_isr = null_handler
#pragma weak i2c_isr = null_handler
#pragma weak timer16_0_isr = null_handler
#pragma weak timer16_1_isr = null_handler
#pragma weak timer32_0_isr = null_handler
#pragma weak timer32_1_isr = null_handler
#pragma weak ssp_isr = null_handler
#pragma weak uart_isr = null_handler
#pragma weak usb0_isr = null_handler
#pragma weak usb1_isr = null_handler
#pragma weak adc_isr = null_handler
#pragma weak wdt_isr = null_handler
#pragma weak bod_isr = null_handler
#pragma weak fmc_isr = null_handler
#pragma weak pio3_isr = null_handler
#pragma weak pio2_isr = null_handler
#pragma weak pio1_isr = null_handler
#pragma weak pio0_isr = null_handler
/* TODO: Interrupt handler weak aliases */

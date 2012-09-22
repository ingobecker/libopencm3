/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Ingo Becker <ingo@orgizm.net>
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

#ifndef LPC13XX_NVIC_H
#define LPC13XX_NVIC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc13xx/memorymap.h>

#define ISER0               MMIO32(NVIC_BASE + 0x100)
#define ISER1 	            MMIO32(NVIC_BASE + 0x104)
#define ICER0 	            MMIO32(NVIC_BASE + 0x180)
#define ICER1 	            MMIO32(NVIC_BASE + 0x184)
#define ISPR0 	            MMIO32(NVIC_BASE + 0x200)
#define ISPR1 	            MMIO32(NVIC_BASE + 0x204)
#define ICPR0 	            MMIO32(NVIC_BASE + 0x280)
#define ICPR1 	            MMIO32(NVIC_BASE + 0x284)
#define IABR0 	            MMIO32(NVIC_BASE + 0x300)
#define IABR1 	            MMIO32(NVIC_BASE + 0x304)
#define IPR0  	            MMIO32(NVIC_BASE + 0x400)
#define IPR1  	            MMIO32(NVIC_BASE + 0x404)
#define IPR2  	            MMIO32(NVIC_BASE + 0x408)
#define IPR3  	            MMIO32(NVIC_BASE + 0x40c)
#define IPR4  	            MMIO32(NVIC_BASE + 0x410)
#define IPR5  	            MMIO32(NVIC_BASE + 0x414)
#define IPR6  	            MMIO32(NVIC_BASE + 0x418)
#define IPR7  	            MMIO32(NVIC_BASE + 0x41c)
#define IPR8  	            MMIO32(NVIC_BASE + 0x420)
#define IPR9                MMIO32(NVIC_BASE + 0x424)
#define IPR10               MMIO32(NVIC_BASE + 0x428)
#define IPR11               MMIO32(NVIC_BASE + 0x42c)
#define IPR12               MMIO32(NVIC_BASE + 0x430)
#define IPR13               MMIO32(NVIC_BASE + 0x434)
#define IPR14               MMIO32(NVIC_BASE + 0x438)
#define STIR                MMIO32(NVIC_BASE + 0xf00)

// ISER0
#define ISE_PIO0_0          1
#define ISE_PIO0_1          (1<<1)
#define ISE_PIO0_2          (1<<2)
#define ISE_PIO0_3          (1<<3)
#define ISE_PIO0_4          (1<<4)
#define ISE_PIO0_5          (1<<5)
#define ISE_PIO0_6          (1<<6)
#define ISE_PIO0_7          (1<<7)
#define ISE_PIO0_8          (1<<8)
#define ISE_PIO0_9          (1<<9)
#define ISE_PIO0_10         (1<<10)
#define ISE_PIO0_11         (1<<11)
#define ISE_PIO1_0          (1<<12)
#define ISE_PIO1_1          (1<<13)
#define ISE_PIO1_2          (1<<14)
#define ISE_PIO1_3          (1<<15)
#define ISE_PIO1_4          (1<<16)
#define ISE_PIO1_5          (1<<17)
#define ISE_PIO1_6          (1<<19)
#define ISE_PIO1_7          (1<<20)
#define ISE_PIO1_8          (1<<21)
#define ISE_PIO1_9          (1<<22)
#define ISE_PIO1_10         (1<<23)
#define ISE_PIO1_11         (1<<24)
#define ISE_PIO2_1          (1<<25)
#define ISE_PIO2_2          (1<<26)
#define ISE_PIO2_3          (1<<27)
#define ISE_PIO2_4          (1<<28)
#define ISE_PIO2_5          (1<<29)
#define ISE_PIO2_6          (1<<30)
#define ISE_PIO2_7          (1<<31)

// ISER1
#define ISE_PIO2_8          1
#define ISE_PIO2_9          (1<<1)
#define ISE_PIO2_10         (1<<2)
#define ISE_PIO2_11         (1<<3)
#define ISE_PIO3_0          (1<<4)
#define ISE_PIO3_1          (1<<5)
#define ISE_PIO3_2          (1<<6)
#define ISE_PIO3_3          (1<<7)
#define ISE_I2C0            (1<<8)
#define ISE_CT16B0          (1<<9)
#define ISE_CT16B1          (1<<10)
#define ISE_CT32B0          (1<<11)
#define ISE_CT32B1          (1<<12)
#define ISE_SSP0            (1<<13)
#define ISE_UART            (1<<14)
#define ISE_USBIRQ          (1<<15)
#define ISE_USBFRQ          (1<<16)
#define ISE_ADC             (1<<17)
#define ISE_WDT             (1<<18)
#define ISE_BOD             (1<<19)
#define ISE_PIO_3           (1<<21)
#define ISE_PIO_2           (1<<22)
#define ISE_PIO_1           (1<<23)
#define ISE_PIO_0           (1<<24)
#define ISE_SSP1            (1<<25)

#endif

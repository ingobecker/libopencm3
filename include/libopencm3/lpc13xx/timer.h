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

#ifndef LPC13XX_TIMER_H
#define LPC13XX_TIMER_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc13xx/memorymap.h>

#define TMR16B0IR          MMIO32(TIMER0_16BIT_BASE)
#define TMR16B0TCR         MMIO32(TIMER0_16BIT_BASE + 0x004)
#define TMR16B0TC          MMIO32(TIMER0_16BIT_BASE + 0x008)
#define TMR16B0PR          MMIO32(TIMER0_16BIT_BASE + 0x00c)
#define TMR16B0MCR         MMIO32(TIMER0_16BIT_BASE + 0x014)
#define TMR16B0MR0         MMIO32(TIMER0_16BIT_BASE + 0x018)
#define TMR16B0MR1         MMIO32(TIMER0_16BIT_BASE + 0x01c)
#define TMR16B0MR2         MMIO32(TIMER0_16BIT_BASE + 0x020)
#define TMR16B0MR3         MMIO32(TIMER0_16BIT_BASE + 0x024)
#define TMR16B0CCR         MMIO32(TIMER0_16BIT_BASE + 0x028)
#define TMR16B0CR0         MMIO32(TIMER0_16BIT_BASE + 0x02c)
#define TMR16B0EMR         MMIO32(TIMER0_16BIT_BASE + 0x03c)
#define TMR16B0CTCR        MMIO32(TIMER0_16BIT_BASE + 0x070)
#define TMR16B0PWMC        MMIO32(TIMER0_16BIT_BASE + 0x074)

// TMR16BnIR
#define MR0INT            1
#define MR1INT            (1<<1)
#define MR2INT            (1<<2)
#define MR3INT            (1<<3)
#define CR0INT            (1<<4)

// TMR16BnMCR
#define MR0I              1
#define MR0R              (1<<1)
#define MR0S              (1<<2)
#define MR1I              (1<<3)
#define MR1R              (1<<4)
#define MR1S              (1<<5)
#define MR2I              (1<<6)
#define MR2R              (1<<7)
#define MR2S              (1<<8)
#define MR3I              (1<<9)
#define MR3R              (1<<10)
#define MR3S              (1<<11)

// TMR16BnTCR
#define TMR16TCR_CEN      1
#define TMR16TCR_CRESTET  (1<<1)

#endif

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

#ifndef LPC13XX_IOCFG_H
#define LPC13XX_IOCFG_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc13xx/memorymap.h>


#define IOCON_PIO2_6              MMIO32(IOCONFIG_BASE) 
#define IOCON_PIO2_0              MMIO32(IOCONFIG_BASE + 0x8)
#define IOCON_RESET_PIO0_0        MMIO32(IOCONFIG_BASE + 0xc)
#define IOCON_PIO0_1              MMIO32(IOCONFIG_BASE + 0x10)
#define IOCON_PIO1_8              MMIO32(IOCONFIG_BASE + 0x14)
#define IOCON_PIO0_2              MMIO32(IOCONFIG_BASE + 0x1c)
#define IOCON_PIO2_7              MMIO32(IOCONFIG_BASE + 0x20)
#define IOCON_PIO2_8              MMIO32(IOCONFIG_BASE + 0x24)
#define IOCON_PIO2_1              MMIO32(IOCONFIG_BASE + 0x28)
#define IOCON_PIO0_3              MMIO32(IOCONFIG_BASE + 0x2c)
#define IOCON_PIO0_4              MMIO32(IOCONFIG_BASE + 0x30)
#define IOCON_PIO0_5              MMIO32(IOCONFIG_BASE + 0x34)
#define IOCON_PIO1_9              MMIO32(IOCONFIG_BASE + 0x38)
#define IOCON_PIO3_4              MMIO32(IOCONFIG_BASE + 0x3c)
#define IOCON_PIO2_4              MMIO32(IOCONFIG_BASE + 0x40)
#define IOCON_PIO2_5              MMIO32(IOCONFIG_BASE + 0x44)
#define IOCON_PIO3_5              MMIO32(IOCONFIG_BASE + 0x48)
#define IOCON_PIO0_6              MMIO32(IOCONFIG_BASE + 0x4c)
#define IOCON_PIO0_7              MMIO32(IOCONFIG_BASE + 0x50)
#define IOCON_PIO2_9              MMIO32(IOCONFIG_BASE + 0x54)
#define IOCON_PIO2_10             MMIO32(IOCONFIG_BASE + 0x58)
#define IOCON_PIO2_2              MMIO32(IOCONFIG_BASE + 0x5c)
#define IOCON_PIO0_8              MMIO32(IOCONFIG_BASE + 0x60)
#define IOCON_PIO0_9              MMIO32(IOCONFIG_BASE + 0x64)
#define IOCON_SWCLK_PIO0_10       MMIO32(IOCONFIG_BASE + 0x68)
#define IOCON_PIO1_10             MMIO32(IOCONFIG_BASE + 0x6c)
#define IOCON_PIO2_11             MMIO32(IOCONFIG_BASE + 0x70)
#define IOCON_R_PIO0_11           MMIO32(IOCONFIG_BASE + 0x74)
#define IOCON_R_PIO1_0            MMIO32(IOCONFIG_BASE + 0x78)
#define IOCON_R_PIO1_1            MMIO32(IOCONFIG_BASE + 0x7c)
#define IOCON_R_PIO1_2            MMIO32(IOCONFIG_BASE + 0x80)
#define IOCON_PIO3_0              MMIO32(IOCONFIG_BASE + 0x84)
#define IOCON_PIO3_1              MMIO32(IOCONFIG_BASE + 0x88)
#define IOCON_PIO2_3              MMIO32(IOCONFIG_BASE + 0x8c)
#define IOCON_SWDIO_PIO1_3        MMIO32(IOCONFIG_BASE + 0x90)
#define IOCON_PIO1_4              MMIO32(IOCONFIG_BASE + 0x94)
#define IOCON_PIO1_11             MMIO32(IOCONFIG_BASE + 0x98)
#define IOCON_PIO3_2              MMIO32(IOCONFIG_BASE + 0x9c)
#define IOCON_PIO1_5              MMIO32(IOCONFIG_BASE + 0xa0)
#define IOCON_PIO1_6              MMIO32(IOCONFIG_BASE + 0xa4)
#define IOCON_PIO1_7              MMIO32(IOCONFIG_BASE + 0xa8)
#define IOCON_PIO3_3              MMIO32(IOCONFIG_BASE + 0xac)
#define IOCON_SCK0_LOC            MMIO32(IOCONFIG_BASE + 0xb0)
#define IOCON_DSR_LOC             MMIO32(IOCONFIG_BASE + 0xb4)
#define IOCON_DCD_LOC             MMIO32(IOCONFIG_BASE + 0xb8)
#define IOCON_RI_LOC              MMIO32(IOCONFIG_BASE + 0xbc)

#endif

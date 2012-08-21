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

#ifndef LPC13XX_SYSCTL_H
#define LPC13XX_SYSCTL_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc13xx/memorymap.h>


#define SYSMEMREMAP               MMIO32(SYSCTRL_BASE) 
#define PRESETCTRL                MMIO32(SYSCTRL_BASE + 0x4)
#define SYSPLLCTRL                MMIO32(SYSCTRL_BASE + 0x8)
#define SYSPLLSTAT                MMIO32(SYSCTRL_BASE + 0xc)
#define USBPLLCTRL                MMIO32(SYSCTRL_BASE + 0x10)
#define USBPLLSTAT                MMIO32(SYSCTRL_BASE + 0x14)
#define SYSOSCCTRL                MMIO32(SYSCTRL_BASE + 0x20)
#define WDTOSCCTRL                MMIO32(SYSCTRL_BASE + 0x24)
#define IRCCTRL                   MMIO32(SYSCTRL_BASE + 0x28)
#define SYSRESSTAT                MMIO32(SYSCTRL_BASE + 0x30)
#define SYSPLLCLKSEL              MMIO32(SYSCTRL_BASE + 0x40)
#define SYSPLLCLKUEN              MMIO32(SYSCTRL_BASE + 0x44)
#define USBPLLCLKSEL              MMIO32(SYSCTRL_BASE + 0x48)
#define USBPLLCLKUEN              MMIO32(SYSCTRL_BASE + 0x4c)
#define MAINCLKSEL                MMIO32(SYSCTRL_BASE + 0x70)
#define MAINCLKUEN                MMIO32(SYSCTRL_BASE + 0x74)
#define SYSAHBCLKDIV              MMIO32(SYSCTRL_BASE + 0x78)
#define SYSAHBCLKCTRL             MMIO32(SYSCTRL_BASE + 0x80)
#define SSP0CLKDIV                MMIO32(SYSCTRL_BASE + 0x94)
#define UARTCLKDIV                MMIO32(SYSCTRL_BASE + 0x98)
#define SSP1CLKDIV                MMIO32(SYSCTRL_BASE + 0x9c)
#define TRACECLKDIV               MMIO32(SYSCTRL_BASE + 0xac)
#define SYSTICKCLKDIV             MMIO32(SYSCTRL_BASE + 0xb0)
#define USBCLKSEL                 MMIO32(SYSCTRL_BASE + 0xc0)
#define USBCLKUEN                 MMIO32(SYSCTRL_BASE + 0xc4)
#define USBCLKDIV                 MMIO32(SYSCTRL_BASE + 0xc8)
#define WDTCLKSEL                 MMIO32(SYSCTRL_BASE + 0xd0)
#define WDTCLKUEN                 MMIO32(SYSCTRL_BASE + 0xd4)
#define WDTCLKDIV                 MMIO32(SYSCTRL_BASE + 0xd8)
#define CLKOUTCLKSEL              MMIO32(SYSCTRL_BASE + 0xe0)
#define CLKOUTUEN                 MMIO32(SYSCTRL_BASE + 0xe4)
#define PIOPORCAP0                MMIO32(SYSCTRL_BASE + 0x100)
#define PIOPORCAP1                MMIO32(SYSCTRL_BASE + 0x104)
#define BODCTRL                   MMIO32(SYSCTRL_BASE + 0x150)
#define SYSTCKCAL                 MMIO32(SYSCTRL_BASE + 0x154)
#define STARTAPRP0                MMIO32(SYSCTRL_BASE + 0x200)
#define STARTERP0                 MMIO32(SYSCTRL_BASE + 0x204)
#define STARTRSRP0CLR             MMIO32(SYSCTRL_BASE + 0x208)
#define STARTSRP0                 MMIO32(SYSCTRL_BASE + 0x20c)
#define STARTAPRP1                MMIO32(SYSCTRL_BASE + 0x210)
#define STARTERP1                 MMIO32(SYSCTRL_BASE + 0x214)
#define STARTRSRP1CLR             MMIO32(SYSCTRL_BASE + 0x218)
#define STARTSRP1                 MMIO32(SYSCTRL_BASE + 0x21c)
#define PDSLEEPCFG                MMIO32(SYSCTRL_BASE + 0x230)
#define PDAWAKECFG                MMIO32(SYSCTRL_BASE + 0x234)
#define PDRUNCFG                  MMIO32(SYSCTRL_BASE + 0x238)
#define DEVICE_ID                 MMIO32(SYSCTRL_BASE + 0x3f4)

//SYSAHBCLKCTRL

#define AHBCLK_SYS          1
#define AHBCLK_ROM          (1<<1)
#define AHBCLK_RAM          (1<<2)
#define AHBCLK_FLASHREG     (1<<3)
#define AHBCLK_FLASHARRAY   (1<<4)
#define AHBCLK_I2C          (1<<5)
#define AHBCLK_GPIO         (1<<6)
#define AHBCLK_CT16B0       (1<<7)
#define AHBCLK_CT16B1       (1<<8)
#define AHBCLK_CT32B0       (1<<9)
#define AHBCLK_CT32B1       (1<<10)
#define AHBCLK_SSP          (1<<11)
#define AHBCLK_UART         (1<<12)
#define AHBCLK_ADC          (1<<13)
#define AHBCLK_USB_REG      (1<<14)
#define AHBCLK_USB_WDT      (1<<15)
#define AHBCLK_USB_IOCON    (1<<16)
#define AHBCLK_SSP1         (1<<18)







#endif

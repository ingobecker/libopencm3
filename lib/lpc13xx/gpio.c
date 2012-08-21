/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/lpc13xx/gpio.h>
#include <libopencm3/cm3/common.h>

void gpio_set(u32 gpioport, u16 gpios)
{
	GPIO_DATA(gpioport) = gpios;
}

/**
 * Use the masked i/o access capabilities to set or clear
 * bits with just one write access.
 *
 * @param bits to mask for modification
 * @param bit values to assign
 */

void gpio_masked_set(u32 gpioport, u16 mask, u16 values)
{
  MMIO32((gpioport + (mask << 2))) = values;
}

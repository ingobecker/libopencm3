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

// #include <libopencm3/lpc13xx/rcc.h>
#include <libopencm3/lpc13xx/gpio.h>

#define ALL_PINS      4095
#define DELAY         35E+4
#define M0D_A_2       8
#define M0D_A_3       9
#define M0D_A_2_3     ((1 << M0D_A_2) | (1 << M0D_A_3))

void delay(int n)
{
  int i;
  for(i=0; i < n; i++) {__asm("nop");}
}

int main(void)
{

  // set pin0_7 as output
  GPIO0_DIR = ALL_PINS;

  while (1) {
    gpio_masked_set(GPIO0, (1 << M0D_A_2), ~0);
    delay(DELAY);
    gpio_masked_set(GPIO0, (1 << M0D_A_2), 0);
    delay(DELAY);
  }
  return 0;

}

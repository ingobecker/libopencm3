/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Ingo Becker <ingo@orgizm.net>
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

#include <libopencm3/lpc13xx/sysctl.h>
#include <libopencm3/lpc13xx/gpio.h>
#include <libopencm3/lpc13xx/iocfg.h>

#define ALL_PINS      0xfff
#define DELAY         35E+4

#define RB_LED_TOP_LEFT       (1<<7)
#define RB_LED_TOP_RIGHT      (1<<11)
#define RB_LED_BOTTOM_LEFT    (1<<11)
#define RB_LED_BOTTOM_RIGHT   (1<<6)

void setup_r0ket(){

  // enable clock for IOCON
  SYSAHBCLKCTRL |= 1<<16;

  // config leds
  // activate GPIO
  IOCON_R_PIO0_11 = (1 | (1<<7));
  GPIO0_DIR = RB_LED_BOTTOM_LEFT;
  GPIO1_DIR = RB_LED_TOP_LEFT | RB_LED_TOP_RIGHT | RB_LED_BOTTOM_RIGHT;

}

void delay(int n)
{
  int i;
  for(i=0; i < n; i++) {__asm("nop");}
}

int main(void)
{
  setup_r0ket();

  GPIO0_DATA = 0;
  GPIO1_DATA = 0;

  while (1)
  {
    gpio_masked_set(GPIO1, (RB_LED_TOP_LEFT | RB_LED_TOP_RIGHT), ~RB_LED_TOP_LEFT);
    delay(DELAY);
    gpio_masked_set(GPIO1, (RB_LED_TOP_LEFT | RB_LED_TOP_RIGHT), RB_LED_TOP_LEFT);
    delay(DELAY);
  }

  return 0;
}

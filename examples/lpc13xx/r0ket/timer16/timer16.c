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

#include <libopencm3/lpc13xx/gpio.h>
#include <libopencm3/lpc13xx/timer.h>
#include <libopencm3/lpc13xx/nvic.h>
#include <libopencm3/lpc13xx/sysctl.h>
#include "r0ket.h"

void timer16_0_isr()
{
  static u32 led_toggle = RB_LED_TOP_RIGHT;

  if(TMR16B0IR & MR0INT)
  {
    gpio_masked_set(GPIO1, (RB_LED_TOP_LEFT | RB_LED_TOP_RIGHT), led_toggle);
    led_toggle = ~led_toggle;
    TMR16B0IR |= (1 << MR0INT);
  }
}

int main()
{
  init_pll();
  init_r0ket();

  // connect clk to ct16b0
  SYSAHBCLKCTRL |= AHBCLK_CT16B0;
  // enable interrupt for ct16b0
  ISER1 = ISE_CT16B0;
  // enable timer0
  TMR16B0TCR = TMR16TCR_CEN;
  // setting prescaler
  TMR16B0PR = 7200;
  // enable interrupt for MR0 and reset timer to 0 on match
  TMR16B0MCR = MR0I | MR0R;
  // setting match
  TMR16B0MR0 = 1000;

  while(1)
    ;
  return 0;
}

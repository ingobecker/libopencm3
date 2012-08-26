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
  GPIO0_DIR = 1<<11;
  GPIO1_DIR = (1<<6) | (1<<7) | (1<<11);

}

void delay(int n)
{
  int i;
  for(i=0; i < n; i++) {__asm("nop");}
}

void setup_irc(){
  // power up irc
  PDRUNCFG &= ~(IRC_PD | IRCOUT_PD);
  delay(200);

  // switch from irc to pll
  MAINCLKSEL = MAINCLK_IRC;
  MAINCLKUEN = 0;
  MAINCLKUEN = 1;

  // power down pll
  PDRUNCFG |= (SYSPLL_PD | SYSOSC_PD);
}

void setup_pll()
{
  // setup external clock source to 72 MHz
  // power up the pll
  //PDRUNCFG |= ADC_PD | WDTOSC_PD | USBPLL_PD | USBPAD_PD | FIXEDVAL_PD;
  PDRUNCFG &= ~(SYSOSC_PD);

  // set range to 25 MHz and bypass osc
  SYSOSCCTRL = SYSOSC_FREQRANGE_LT_20MHZ;

  // select pll clock source
  SYSPLLCLKSEL = SYSPLLCLK_SYSOSC;
  // update clock source select
  SYSPLLCLKUEN = 0;
  SYSPLLCLKUEN = 1;

  // MSEL 4:0 (1-32)
  // PSEL 6:5 (2 x P=1-8)
  // set to 25 MHz external, 75 MHz internal
  SYSPLLCTRL = SYSPLL_PSEL_2 | 5;

  PDRUNCFG &= ~(SYSPLL_PD);
  // wait for the pll to lock
  while(!(SYSPLLSTAT&1));
  
  // switch from irc to pll
  MAINCLKSEL = MAINCLK_PLL_OUTPUT;
  MAINCLKUEN = 0;
  MAINCLKUEN = 1;

  // power down the irc
  PDRUNCFG |= (IRC_PD | IRCOUT_PD);
}

int main(void)
{
  setup_pll();
  setup_r0ket();

  GPIO0_DATA = 0;
  GPIO1_DATA = 0;

  u32 release = 1;

  while (1)
  {
    gpio_masked_set(GPIO1, (RB_LED_TOP), ~RB_LED_TOP_LEFT);
    delay(DELAY);
    gpio_masked_set(GPIO1, (RB_LED_TOP), RB_LED_TOP_LEFT);
    delay(DELAY);
  }
  return 0;

}

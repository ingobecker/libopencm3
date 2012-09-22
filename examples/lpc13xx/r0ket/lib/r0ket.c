#include <libopencm3/lpc13xx/sysctl.h>
#include <libopencm3/lpc13xx/gpio.h>
#include <libopencm3/lpc13xx/iocfg.h>
#include "r0ket.h"

void delay(int n)
{
  int i;
  for(i=0; i < n; i++) {__asm("nop");}
}

void init_r0ket()
{

  // enable clock for IOCON
  SYSAHBCLKCTRL |= (1<<16);

  // config joystick
  // activate pull-ups
  // right
  IOCON_PIO2_9 = (2<<3);
  // left
  IOCON_PIO0_1 = (2<<3);
  // down
  IOCON_PIO2_6 = (2<<3);
  // up
  IOCON_PIO3_3 = (2<<3);

  // config leds
  // activate GPIO
  IOCON_R_PIO0_11 = (1 | (1<<7));
  GPIO0_DIR = (1<<11) | (1<<6);
  GPIO1_DIR = (1<<6) | (1<<7) | (1<<11) | (1<<8);
  GPIO1_DATA = 0;//(1<<7);
  GPIO0_DATA = (1<<6);
}

void init_irc()
{
  // power up irc
  PDRUNCFG &= ~(IRC_PD | IRCOUT_PD);
  delay(200);

  // switch from irc to pll
  MAINCLKSEL = MAINCLK_IRC;
  MAINCLKUEN = 0;
  MAINCLKUEN = 1;

  PDRUNCFG |= (SYSPLL_PD | SYSOSC_PD);
}

void init_pll()
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

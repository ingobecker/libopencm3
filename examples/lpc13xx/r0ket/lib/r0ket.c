#include <libopencm3/lpc13xx/sysctl.h>
#include <libopencm3/lpc13xx/gpio.h>
#include <libopencm3/lpc13xx/iocfg.h>
#include "r0ket.h"

void delay(int n)
{
  int i;
  for(i=0; i < n; i++) {__asm("nop");}
}

void init_r0ket_spi(){
  
  // set all chip-select pins as outputs and high
  GPIO_DIR(RB_SPI_SS0_GPIO) |= RB_SPI_SS0_MASK;
  gpio_masked_set(RB_SPI_SS0_GPIO, RB_SPI_SS0_MASK, RB_SPI_SS0_MASK);

  GPIO_DIR(RB_SPI_SS3_GPIO) |= RB_SPI_SS3_MASK;
  gpio_masked_set(RB_SPI_SS3_GPIO, RB_SPI_SS3_MASK, RB_SPI_SS3_MASK);
}

void init_r0ket_nrf24(){
  init_spi();
  GPIO_DIR(RB_CSN_GPIO) |= RB_CSN_MASK;
  gpio_masked_set(RB_CSN_GPIO, RB_CSN_MASK, RB_CSN_MASK);
  
  GPIO_DIR(RB_CE_GPIO) |= RB_CE_MASK;
  gpio_masked_set(RB_CE_GPIO, RB_CE_MASK, RB_CE_MASK);

  GPIO_DIR(RB_IRQ_GPIO) &= ~RB_IRQ_MASK;
  IOCON_PIO0_7 = (2<<3);
}

void r0ket_ext_power(u8 state){
  //gpio
}

void init_r0ket_leds(){
  // setting all leds as output
  IOCON_R_PIO0_11 = (1 | (1<<7));
  GPIO_DIR(RB_LED_B_R_GPIO) |= RB_LED_B_R_MASK;
  GPIO_DIR(RB_LED_B_L_GPIO) |= RB_LED_B_L_MASK;
  GPIO_DIR(RB_LED_T_L_GPIO) |= RB_LED_T_L_MASK;
  GPIO_DIR(RB_LED_T_R_GPIO) |= RB_LED_T_R_MASK;
  gpio_masked_set(RB_LED_B_R_GPIO, RB_LED_B_R_MASK, 0);
  gpio_masked_set(RB_LED_B_L_GPIO, RB_LED_B_L_MASK, 0);
  gpio_masked_set(RB_LED_T_R_GPIO, RB_LED_T_R_MASK, 0);
  gpio_masked_set(RB_LED_T_L_GPIO, RB_LED_T_L_MASK, 0);
}

void init_r0ket_buttons(){
  // activate pull-ups
  // right
  IOCON_PIO2_9 = (2<<3);
  GPIO_DIR(RB_BTN_R_GPIO) |= RB_BTN_R_MASK;
  // left
  IOCON_PIO0_1 = (2<<3);
  GPIO_DIR(RB_BTN_L_GPIO) |= RB_BTN_L_MASK;
  // down
  IOCON_PIO2_6 = (2<<3);
  GPIO_DIR(RB_BTN_D_GPIO) |= RB_BTN_D_MASK;
  // up
  IOCON_PIO3_3 = (2<<3);
  GPIO_DIR(RB_BTN_U_GPIO) |= RB_BTN_U_MASK;
}

void init_r0ket()
{
  // enable clock for IOCON
  SYSAHBCLKCTRL |= (1<<16);

  // disconnect USB
  GPIO_DIR(RB_USB_CONNECT_GPIO) |= RB_USB_CONNECT_MASK;
  gpio_masked_set(RB_USB_CONNECT_GPIO, RB_USB_CONNECT_MASK, RB_USB_CONNECT_MASK);

  // set power_good as output
  // and disable ext power
  GPIO_DIR(RB_POWER_GOOD_GPIO) |= RB_POWER_GOOD_MASK;
  gpio_masked_set(RB_POWER_GOOD_GPIO, RB_POWER_GOOD_MASK, RB_POWER_GOOD_MASK);
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

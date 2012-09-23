#ifndef R0KET_H
#define R0KET_H

// PIO1
#define RB_LED_TOP_LEFT       (1<<7)
// PIO1
#define RB_LED_TOP_RIGHT      (1<<11)
// PIO0
#define RB_LED_BOTTOM_LEFT    (1<<11)
// PIO1
#define RB_LED_BOTTOM_RIGHT   (1<<6)
// PIO2_9

#define BTN_RIGHT             (1<<9)
#define BTN_LEFT              0xf00
#define BTN_UP                0xf00
#define BTN_DOWN              0xf00
#define BTN_PRESSED           0xf00


// nRF24
#define RB_CSN_GPIO       GPIO1
#define RB_CSN_MASK       (1<<5)
#define RB_CE_GPIO        GPIO1
#define RB_CE_MASK        (1<<10)
#define RB_IRQ_GPIO       GPIO0
#define RB_IRQ_MASK       (1<<7)

#define RB_USB_CONNECT_GPIO GPIO0
#define RB_USB_CONNECT_MASK (1<<6)
// power_good
#define RB_POWER_GOOD_GPIO GPIO1
#define RB_POWER_GOOD_MASK (1<<8)
// LED BOTTOM RIGHT
#define RB_LED_B_R_GPIO   GPIO1
#define RB_LED_B_R_MASK   (1<<6)
// LED BOTTOM LEFT
#define RB_LED_B_L_GPIO   GPIO0
#define RB_LED_B_L_MASK   (1<<11)
// LED TOP RIGHT
#define RB_LED_T_R_GPIO   GPIO1
#define RB_LED_T_R_MASK   (1<<11)
// LED TOP LEFT
#define RB_LED_T_L_GPIO   GPIO1
#define RB_LED_T_L_MASK   (1<<7)
// Joystick
#define RB_BTN_R_GPIO     GPIO0
#define RB_BTN_R_MASK     (1<<9)
#define RB_BTN_L_GPIO     GPIO0
#define RB_BTN_L_MASK     (1<<1)
#define RB_BTN_D_GPIO     GPIO2
#define RB_BTN_D_MASK     (1<<6)
#define RB_BTN_U_GPIO     GPIO3
#define RB_BTN_U_MASK     (1<<3)

// modbus

// m0dA

// SS0 chip select
#define RB_SPI_SS0_GPIO   GPIO2
#define RB_SPI_SS0_MASK   (1<<5)
// SS1
#define RB_SPI_SS1_GPIO   GPIO2
#define RB_SPI_SS1_MASK   (1<<4)
// SS2
#define RB_SPI_SS2_GPIO   GPIO2
#define RB_SPI_SS2_MASK   (1<<8)

// m0dB
// SS3
#define RB_SPI_SS3_GPIO   GPIO3
#define RB_SPI_SS3_MASK   (1<<2)
// SS4
#define RB_SPI_SS4_GPIO   GPIO3
#define RB_SPI_SS4_MASK   (1<<1)
// SS5
#define RB_SPI_SS5_GPIO   GPIO2
#define RB_SPI_SS5_MASK   (1<<10)

extern void init_pll(void);
extern void init_irc(void);
extern void init_r0ket(void);
extern void init_r0ket_spi(void);
extern void init_r0ket_leds(void);
extern void init_r0ket_buttons(void);
extern void init_r0ket_nrf24(void);

#endif

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

void init_r0ket(void);
void init_pll(void);
void init_irc(void);
#endif

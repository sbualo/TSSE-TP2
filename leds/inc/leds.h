
#include <stdint.h>
#define LED_TO_BIT(x) (1 << (x - 1))
#define ALL_LED_OFF   0x00

#define ALL_LED_ON    0b1111111111111111

void leds_init(uint16_t * puerto);

void leds_turn_on(int led);

void leds_turn_off(int led);

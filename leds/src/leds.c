#include "leds.h"

#define LED_TO_BIT(x) (1 << (x - 1))
#define ALL_LED_OFF   0x00

#define ALL_LED_ON    0b1111111111111111

static uint16_t * leds_array;

void leds_init(uint16_t * puerto) {

    leds_array = puerto;
    *puerto = ALL_LED_OFF;
}
void leds_turn_on(int led) {

    // turn on led
    *leds_array |= LED_TO_BIT(led);
}

void leds_turn_off(int led) {
    // turn off led
    *leds_array &= ~(LED_TO_BIT(led));
}

void leds_turn_all_on(void) {

    *leds_array |= ALL_LED_ON;
}

void leds_turn_all_off(void) {

    *leds_array &= (ALL_LED_OFF);
}

bool led_check_status(int led) {
    return (*leds_array >> (led - 1)) &
           1; // El numero de led es un numero menos del nro de bit (bit 0 es el 1er led)
}

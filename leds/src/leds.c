#include "leds.h"

#define LED_TO_BIT(x) (1<<(x-1))
#define ALL_LED_OFF 0x00

static uint16_t * leds_array;


void leds_init(uint16_t * puerto){

    leds_array = puerto;
    *puerto = ALL_LED_OFF;

}
void leds_turn_on(int led){

    //*leds_array = 0b0000000000000100;   // turn on led 3
    *leds_array |= LED_TO_BIT(led);

}

void leds_turn_off(int led){
    //*leds_array = 0b0000000000000000;   // turn on led 3
    *leds_array &= ~(LED_TO_BIT(led));
}
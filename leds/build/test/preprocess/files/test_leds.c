#include "inc/leds.h"
#include "/Library/Ruby/Gems/2.6.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






static uint16_t leds_virtuales;

static const int LED = 4;





void setUp(void){



    leds_init(&leds_virtuales);



}





void test_todos_los_led_deben_estar_apagados_al_iniciar_el_driver(void){



    uint16_t leds_virtuales = 0xFF;

    leds_init(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void*)0)), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_UINT16);

}









void test_prender_un_led(void){



    leds_turn_on(LED);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1<<(LED-1))), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void*)0)), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_UINT16);



    UnityAssertBits((UNITY_INT)((~(1<<(LED-1)))), (UNITY_INT)((UNITY_UINT)(0)), (UNITY_INT)((leds_virtuales)), (((void*)0)), (UNITY_UINT)(33));

}



void test_apagar_un_led(void){





    leds_turn_on(LED);

    leds_turn_off(LED);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void*)0)), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_UINT16);

}





void test_operar_varios_led(void){





    leds_turn_on(5);

    leds_turn_on(7);

    leds_turn_on(5);

    leds_turn_off(5);

    leds_turn_off(9);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 << (7-1))), (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void*)0)), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_UINT16);

}

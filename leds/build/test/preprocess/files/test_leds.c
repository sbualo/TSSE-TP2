#include "inc/leds.h"
#include "/Library/Ruby/Gems/2.6.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"

static uint16_t leds_virtuales;

static const int LED = 4;

void setUp(void) {

    leds_init(&leds_virtuales);
}

void test_todos_los_led_deben_estar_apagados_al_iniciar_el_driver(void) {

    uint16_t leds_virtuales = 0xFF;

    leds_init(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_UINT16);
}

void test_prender_un_led(void) {

    leds_turn_on(LED);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 << (LED - 1))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertBits((UNITY_INT)((~(1 << (LED - 1)))), (UNITY_INT)((UNITY_UINT)(0)),
                    (UNITY_INT)((leds_virtuales)), (((void *)0)), (UNITY_UINT)(30));
}

void test_apagar_un_led(void) {

    leds_turn_on(LED);

    leds_turn_off(LED);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_UINT16);
}

void test_operar_varios_led(void) {

    leds_turn_on(5);

    leds_turn_on(7);

    leds_turn_on(5);

    leds_turn_off(5);

    leds_turn_off(9);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 << (7 - 1))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_UINT16);
}

void test_prender_apagar_todos_los_led(void) {

    int espected_value = 0x00;

    for (int i = 1; i < 17; i++) {

        leds_turn_on(i);

        espected_value |= (1 << (i - 1));

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((espected_value)),
                               (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                               (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_UINT16);
    }

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_UINT16);

    for (int i = 1; i < 17; i++) {

        leds_turn_off(i);

        espected_value &= ~((1 << (i - 1)));

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((espected_value)),
                               (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                               (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_UINT16);
    }

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_UINT16);
}

void test_limit_values(void) {

    leds_turn_on(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)(((1 << (1 - 1)))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)(((1 << (1 - 1)))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)(((1 << (16 - 1)))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)(((1 << (16 - 1)))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_UINT16);
}

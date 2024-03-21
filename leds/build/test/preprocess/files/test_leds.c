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
                           (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_UINT16);
}

void test_prender_un_led(void) {

    leds_turn_on(LED);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 << (LED - 1))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertBits((UNITY_INT)((~(1 << (LED - 1)))), (UNITY_INT)((UNITY_UINT)(0)),
                    (UNITY_INT)((leds_virtuales)), (((void *)0)), (UNITY_UINT)(38));
}

void test_apagar_un_led(void) {

    leds_turn_on(LED);

    leds_turn_off(LED);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_UINT16);
}

void test_operar_varios_led(void) {

    leds_turn_on(5);

    leds_turn_on(7);

    leds_turn_on(5);

    leds_turn_off(5);

    leds_turn_off(9);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1 << (7 - 1))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_UINT16);
}

void test_prender_todos_los_led(void) {

    leds_turn_all_on();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_UINT16);
}

void test_apagar_todos_los_led(void) {

    leds_turn_all_off();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_UINT16);
}

void test_limit_values(void) {

    leds_turn_on(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)(((1 << (1 - 1)))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)(((1 << (1 - 1)))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)(((1 << (16 - 1)))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)(((1 << (16 - 1)))),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x00)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_UINT16);
}

void test_limit_values_all_leds_on(void) {

    leds_turn_all_on();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111110)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(1);

    leds_turn_on(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_on(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(119), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b1111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_UINT16);

    leds_turn_off(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0b0111111111111111)),
                           (UNITY_INT)(UNITY_UINT16)((leds_virtuales)), (((void *)0)),
                           (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_UINT16);
}

void test_check_led_status(void) {

    _Bool status = led_check_status(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status)),
                           (((void *)0)), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_UINT16);
}

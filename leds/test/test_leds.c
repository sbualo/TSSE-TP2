
#include "unity.h"

#include "leds.h"

static uint16_t leds_virtuales;
static const int LED = 4;

/*Funcion que se ejecuta antes de cada test (nombre especifico de ceedling)*/
void setUp(void) {

    leds_init(&leds_virtuales);
}

void test_todos_los_led_deben_estar_apagados_al_iniciar_el_driver(void) {
    // TEST_FAIL_MESSAGE("Arrancamos");
    uint16_t leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

/* prueba de encendido de un led*/

void test_prender_un_led(void) {

    leds_turn_on(LED);
    // El bit 2 esta en alto
    TEST_ASSERT_EQUAL_UINT16(1 << (LED - 1), leds_virtuales);
    // Todos los bits estan en bajo
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_virtuales);
}

void test_apagar_un_led(void) {

    leds_turn_on(LED);
    leds_turn_off(LED);

    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

void test_operar_varios_led(void) {

    leds_turn_on(5);
    leds_turn_on(7);
    leds_turn_on(5);
    leds_turn_off(5);
    leds_turn_off(9);

    TEST_ASSERT_EQUAL_UINT16(1 << (7 - 1), leds_virtuales);
}

void test_prender_apagar_todos_los_led(void) {
    int espected_value = ALL_LED_OFF;
    for (int i = 1; i < 17; i++) {
        leds_turn_on(i);
        espected_value |= LED_TO_BIT(i);
        TEST_ASSERT_EQUAL_UINT16(
            espected_value,
            leds_virtuales); // Comparo que a medida que se prenden voy obteniendo el valor esperado
    }
    TEST_ASSERT_EQUAL_UINT16(0b1111111111111111, leds_virtuales);
    for (int i = 1; i < 17; i++) {
        leds_turn_off(i);
        espected_value &= ~(LED_TO_BIT(i));
        TEST_ASSERT_EQUAL_UINT16(
            espected_value,
            leds_virtuales); // Comparo que a medida que se prenden voy obteniendo el valor esperado
    }
}

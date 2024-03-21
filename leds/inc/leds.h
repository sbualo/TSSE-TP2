
#include <stdint.h>
#include <stdbool.h>

// Documentar como si fuese un driver

/**
 * @brief Funcion que inicializa los LEDs y setea a los LEDs en OFF
 *
 * @param puerto Direccion en la que se encuentran los LEDs
 */
void leds_init(uint16_t * puerto);

/**
 * @brief Funcion que prende un led especificado
 *
 * @param led numero de led a prender
 */
void leds_turn_on(int led);

/**
 * @brief funcion que apaga un led especificado
 *
 * @param led Numero de led a apagar
 */
void leds_turn_off(int led);

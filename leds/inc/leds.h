
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

/**
 * @brief Funcion que prende todos los LEDs utilizados
 *
 */
void leds_turn_all_on(void);

/**
 * @brief Funcion que apaga todos los LEDs utilizados
 *
 */
void leds_turn_all_off(void);

/**
 * @brief Funcion que devuelve el estado de un led
 *
 * @param led  El numerdo de led a consultar
 * @return true si el led esta prendido
 * @return false si el led está apagado
 */
bool led_check_status(int led);

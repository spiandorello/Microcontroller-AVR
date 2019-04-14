/*
 * leddisplay.c
 *
 *  Created on: Aug 20, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#include <avr/pgmspace.h>
#include <util/delay.h>

#include "../lib/avr_gpio.h"
#include "../lib/bits.h"
#include "led_display_mux.h"

/* Tabela de conversão em flash: Anodo comum */
#ifdef COM_ANODO
const uint8_t convTableMux[] PROGMEM = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02,
		0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E };

//xtern uint8_t convTable[];
#endif

/* Tabela de conversão em flash: Catodo comum */
#ifdef COM_CATODO
const uint8_t convTableMux[] PROGMEM = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
		0x07, 0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
#endif

void display_mux_init() {

	/* Configuração de portas */
	DISPLAY_PORT->DDR = 0xFF;
	DISPLAY_PORT->PORT = 0xFF;

	SELECTOR_PORT->DDR = SET(EN_1) | SET(EN_2);
	SELECTOR_PORT->PORT = SET(EN_1) | SET(EN_2);
}

void display_mux_write(uint8_t data){

	uint8_t data_4bits = data & 0x0F;


	/* Escreve no primeiro display */
	GPIO_ClrBit(SELECTOR_PORT, EN_1);
	GPIO_SetBit(SELECTOR_PORT, EN_2);
	DISPLAY_PORT->PORT = pgm_read_byte(&convTableMux[data_4bits]);
	_delay_ms(20);

	/* Escreve no segundo display */
	data_4bits = data >> 4;

	GPIO_ClrBit(SELECTOR_PORT, EN_2);
	GPIO_SetBit(SELECTOR_PORT, EN_1);
	DISPLAY_PORT->PORT = pgm_read_byte(&convTableMux[data_4bits]);
	_delay_ms(20);

}

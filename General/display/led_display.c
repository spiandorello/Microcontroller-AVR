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
#include "led_display.h"
#include "led_table.h"

void display_init() {

	/* Configuração de portas */
	DISPLAY_PORT->DDR = 0xFF;
	DISPLAY_PORT->PORT = 0xFF;
}

void display_write(uint8_t data){
	/* Escreve no display */
	DISPLAY_PORT->PORT = conv_to_7seg(data);
}

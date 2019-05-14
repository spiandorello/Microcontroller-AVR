/*
 * matrix.h
 *
 *  Created on: May 5, 2019
 *      Author: eduardo
 */

#ifndef KEYBOARD_MATRIX_H_
#define KEYBOARD_MATRIX_H_

//#define INTERRUPT

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "../lib/avr_gpio.h"
#include "../lib/bits.h"

#define MATRIX_KEYBOARD GPIO_D
#define COLLUM PORTD
#define LINE PIND

void extIRQ_config();
void keyboard_config();
uint8_t read_keyboard();



#endif /* KEYBOARD_MATRIX_H_ */

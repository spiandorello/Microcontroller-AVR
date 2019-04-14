/*
 * interrupt_config.h
 *
 *  Created on: 31 de mar de 2019
 *      Author: eduardo
 */

#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

#include <avr/interrupt.h>
#include <avr/io.h>

#include "lib/avr_gpio.h"
#include "lib/bits.h"

void interrupt_config();
ISR(INT0_vect);

#endif /* INTERRUPT_CONFIG_H_ */

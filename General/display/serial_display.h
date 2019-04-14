#ifndef DISPLAY_SERIAL_DISPLAY_H_
#define DISPLAY_SERIAL_DISPLAY_H_

#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "../lib/avr_gpio.h"
#include "../lib/bits.h"
#include "led_table.h"

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#define DISPLAY_PORT GPIO_B
#define DATA PB0
#define CLK	PB1
#define STB	PB2

#define CLK_pulse() GPIO_SetBit(DISPLAY_PORT, CLK); _delay_us(10); GPIO_ClrBit(DISPLAY_PORT, CLK)
#define STB_pulse() GPIO_SetBit(DISPLAY_PORT, STB); _delay_us(10); GPIO_ClrBit(DISPLAY_PORT, STB)


void serial_display_init();
void serial_display_write(uint8_t data);
void display_write_byte(uint8_t data);

#endif /* DISPLAY_SERIAL_DISPLAY_H_ */

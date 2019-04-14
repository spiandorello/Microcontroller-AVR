#ifndef DISPLAY_LED_TABLE_H_
#define DISPLAY_LED_TABLE_H_


#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#define COM_ANODO
//#define COM_CATODO

uint8_t conv_to_7seg(uint8_t data);

#endif /* DISPLAY_LED_TABLE_H_ */

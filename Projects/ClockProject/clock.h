#ifndef CLOCK_H_
#define CLOCK_H_

#include <stdint.h>
#include <avr/interrupt.h>

#include "lib/bits.h"
#include "lib/avr_gpio.h"
#include "lib/avr_timer.h"

void timer1_hardware_init();
void clock_function();
void clock_setup();
void clock_init();

uint8_t get_minutes();
uint8_t get_second();
uint8_t get_hours();

#endif /* CLOCK_H_ */

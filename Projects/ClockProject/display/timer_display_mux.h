#ifndef TIMERDISPLAYMUX_H_
#define TIMERDISPLAYMUX_H_

#include <avr/interrupt.h>
#include <stdint.h>

#include "../lib/avr_timer.h"
#include "../lib/avr_gpio.h"
#include "../lib/bits.h"
#include "led_table.h"


#define DISPLAY GPIO_D
#define DISPLAY_SEL GPIO_B
#define DISP_0 PB0
#define DISP_1 PB1
#define DISP_2 PB2
#define DISP_3 PB3

void display_write(uint8_t data);
void timer0_hardware_init();
void display_init();

#endif /* TIMERDISPLAYMUX_H_ */

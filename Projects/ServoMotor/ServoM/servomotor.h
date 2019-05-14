#ifndef SERVOM_SERVOMOTOR_H_
#define SERVOM_SERVOMOTOR_H_

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

#include "../lib/bits.h"
#include "../lib/avr_gpio.h"
#include "../lib/avr_timer.h"

#define SERVO_PORT GPIO_B
#define SERVO_CONTROLLER PB2
#define TOP 39999

void timer1_pwm_hardware_init();
void servo_motor_hardware_intit();
uint16_t calc_duty(uint16_t angle);
void set_dutty(uint16_t dutty);
void setup_duty(uint16_t angle);


#endif /* SERVOM_SERVOMOTOR_H_ */

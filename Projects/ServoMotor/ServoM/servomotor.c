#include "servomotor.h"

void timer1_pwm_hardware_init() {
	TIMER_1->ICR = TOP;

	TIMER_1->TCCRA = SET(WGM11) | SET(COM1A1) | SET(COM1B1);
	TIMER_1->TCCRB = SET(WGM13) | SET(WGM12) | SET(CS11);
}

void servo_motor_hardware_intit() {
	SERVO_PORT->DDR |= SET(SERVO_CONTROLLER);

	timer1_pwm_hardware_init();
}

void setup_duty(uint16_t angle) {
	set_dutty(calc_duty(angle));
}

uint16_t calc_duty(uint16_t angle) {
	return (TOP*(angle + 45))/ 1800;
}

void set_dutty(uint16_t dutty){
	if (dutty <= TOP)
		TIMER_1->OCRB = dutty;
}

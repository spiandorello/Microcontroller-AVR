#include "../clock/clock.h"

typedef struct clock {
	uint8_t hours;
	uint8_t min;
	uint8_t sec;
} clock_t ;

volatile clock_t clockInfo;

ISR(TIMER1_COMPA_vect) {
	clockInfo.sec++;
	clock_function();
}

void timer1_hardware_init() {
	TIMER_1->TCCRA = 0;
	TIMER_1->TCCRB = SET(WGM12) | SET(CS12) | SET(CS10);
	TIMER_1->OCRA = 15625;
	TIMER_IRQS->TC1.BITS.OCIEA = 1;
}

void clock_init() {
	timer1_hardware_init();
	clockInfo.min = 0x3B;
}

void inline clock_function() {
	if (clockInfo.sec > 59) {
		clockInfo.sec = 0;
		clockInfo.min++;
	}

	if (clockInfo.min > 59) {
		clockInfo.min = 0;
		clockInfo.hours++;
	}

	if (clockInfo.hours > 23) {
		clockInfo.hours = 0;
	}
}

uint8_t get_second() {
	return (clockInfo.sec);
}

uint8_t get_minutes() {
	return (clockInfo.min);
}

uint8_t get_hours() {
	return (clockInfo.hours);
}

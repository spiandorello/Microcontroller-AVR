#include "clock.h"

typedef struct clock {
	uint8_t hours;
	uint8_t min;
	uint8_t sec;
} clock_t ;

volatile uint8_t clock_1sec = 0;
volatile clock_t clockInfo;

ISR(TIMER1_COMPA_vect){
	if (clock_1sec == 5) {
		clockInfo.sec++;
		clock_1sec = 0;
		GPIO_CplBit(GPIO_B, 0);
	}
	clock_1sec++;
}

void timer1_hardware_init() {
	TIMER_1->TCCRA = 0;
	TIMER_1->TCCRB = SET(WGM13) | SET(WGM12) | SET(CS12) | SET(CS11);
	TIMER_1->OCRA = 3125;
	TIMER_IRQS->TC1.BITS.OCIEA = 1;
}

void clock_init() {
	timer1_hardware_init();

	GPIO_B->DDR = SET(0);
	GPIO_B->PORT = SET(0);
}

void clock_function() {
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
	return(clockInfo.sec);
}

uint8_t get_minutes() {
	return(clockInfo.min);
}

uint8_t get_hours() {
	return(clockInfo.min);
}


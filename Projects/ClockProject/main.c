#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>

#include "display/timer_display_mux.h"
#include "lib/avr_timer.h"
#include "lib/avr_usart.h"
#include "lib/avr_gpio.h"
#include "clock/clock.h"
#include "lib/bits.h"

int main() {
	display_init();
	clock_init();
	sei();

	while(1) {

	//	display_write();
	}
}

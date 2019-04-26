#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <avr/io.h>

#include "lib/avr_timer.h"
#include "lib/avr_gpio.h"
#include "lib/bits.h"
#include "clock.h"

int main() {
	clock_init();
	sei();

	while(1) {

	}
}

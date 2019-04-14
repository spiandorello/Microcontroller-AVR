#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>

#include "display/serial_display.h"
#include "interrupt_config.h"
#include "lib/avr_gpio.h"
#include "lib/bits.h"

volatile uint8_t count = 0;

int main() {

	interrupt_config();
	serial_display_init();

	while(1) {
		while(count < 256) {
			display_write_byte(count);
			_delay_ms(50);
		}
		count = 0;
	}
}

ISR(INT0_vect)
{
	count++;
}


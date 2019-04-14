#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "lib/bits.h"
#include "lib/avr_gpio.h"
#include "display/led_display_mux.h"


int main() {

	display_mux_init();

	while(1) {
		display_mux_write(0x01);
	}
}

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>

#include "HCSR04/hcrs04.h"
#include "display/lcd.h"
#include "lib/avr_gpio.h"
#include "lib/bits.h"

extern uint8_t Distance;

int main() {

	FILE *lcd_stream = inic_stream();

	inic_LCD_4bits();
	hcrs04_config();
	sei();

	while(1) {
		/* Vai para primeira linha/coluna */
		cmd_LCD(0x80,0);

		TRIG_PULSE();
		/* Imprime msg */
		fprintf(lcd_stream,"%d", Distance);
		_delay_ms(1000);
	}
}


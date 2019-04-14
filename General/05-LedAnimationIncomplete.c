#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "lib/avr_gpio.h"
#include "lib/bits.h"

#define LED_PORT GPIO_D

void hardwareInit();

int main() {

	uint8_t led = 0x00;

	hardwareInit();
	while(1) {

		LED_PORT->PORT = SET(led);
		led = (1 << led);
		_delay_ms(500);
	}
}

void hardwareInit() {
	LED_PORT->DDR = 0xFF;
	LED_PORT->PORT = 0x00;
}


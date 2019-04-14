#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "lib/avr_gpio.h"
#include "lib/bits.h"

#define LED_PORT GPIO_B
#define LED_PIN PB0

int main() {

	LED_PORT->PORT = SET(LED_PIN);
	LED_PORT->DDR = SET(LED_PIN);

	while(1) {

		GPIO_CplBit(LED_PORT, LED_PIN);
		_delay_ms(200);

	}
}

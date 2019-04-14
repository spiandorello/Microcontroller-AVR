#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "lib/avr_gpio.h"
#include "lib/bits.h"

#define LED_PORT GPIO_B
#define LED PB1
#define BUTTON_PORT GPIO_B
#define BUTTON PB0

void hardwareInit();

int main() {

	hardwareInit();

	while(1) {
		if (!GPIO_PinTstBit(BUTTON_PORT, BUTTON)) {
			GPIO_CplBit(LED_PORT, LED);
			_delay_ms(250);
		}
	}
}

void hardwareInit() {
	LED_PORT->DDR = SET(LED);
	LED_PORT->PORT = SET(LED);
	BUTTON_PORT->PORT = SET(BUTTON);
}


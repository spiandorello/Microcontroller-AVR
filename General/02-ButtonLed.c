#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "lib/bits.h"
#include "lib/avr_gpio.h"

#define BUTTON_PORT GPIO_B
#define BUTTON PB0
#define LED_PORT GPIO_B
#define LED PB1

int main() {

	LED_PORT->DDR = SET(LED);
	LED_PORT->PORT = SET(LED);
	BUTTON_PORT->PORT = SET(BUTTON);

	while (1) {

		while (!GPIO_PinTstBit(BUTTON_PORT, BUTTON)) {
			GPIO_SetBit(LED_PORT, LED);
		}

		GPIO_ClrBit(LED_PORT, LED);
	}
}

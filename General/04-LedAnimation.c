#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "lib/avr_gpio.h"
#include "lib/bits.h"

#define LED_PORT GPIO_B
#define LED PB0

void hardwareInit();

int main() {

	hardwareInit();
	uint8_t i=0, flag=0;

	while(1) {
		i = 0;

		while (i < 6) {
			if (flag == 1) {
				GPIO_CplBit(LED_PORT, LED);
				_delay_ms(1000);
			} else {
				GPIO_CplBit(LED_PORT, LED);
				_delay_ms(250);
			}
			i++;
		}


		flag == 1 ? (flag = 0) : (flag = 1);
	}
}

void hardwareInit() {
	LED_PORT->DDR = SET(LED);
	LED_PORT->PORT = SET(LED);
}


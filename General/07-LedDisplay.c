#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "lib/bits.h"
#include "lib/avr_gpio.h"
#include "display/led_display.h"

#define BUTTON_PORT GPIO_B
#define BUTTON PB0

void hardwareInit();

int main() {

	uint8_t i=0;

	hardwareInit();
	display_init();

	while(1) {

		while (i < 16)
		{
			if (!GPIO_PinTstBit(BUTTON_PORT, BUTTON)) {
				while(!GPIO_PinTstBit(BUTTON_PORT, BUTTON));
				_delay_ms(200);

				display_write(i++);
			}
		}

		i = 0;
	}
}

void hardwareInit() {
	BUTTON_PORT->PORT = SET(BUTTON);
}

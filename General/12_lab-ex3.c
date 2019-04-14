#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>

#include "lib/avr_gpio.h"
#include "lib/bits.h"

ISR(INT0_vect) {
	GPIO_CplBit(GPIO_B, PB0);
}

int main() {

	//EICRA = ~SET(ISC00) | ~SET(ISC01); //low level
	EICRA = ~SET(ISC00) | SET(ISC01); //low edge
	EIMSK = SET(INT0);

	GPIO_D->PORT = ~SET(PD2);
	GPIO_D->PORT = SET(PD2);

	GPIO_B->DDR = SET(PB0);
	GPIO_B->PORT = ~SET(PB0);

	sei();

	while(1) {

	}
}


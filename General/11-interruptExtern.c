#define F_CPU 16000000UL

#define LED_PORT GPIO_B
#define LED PB0

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "lib/avr_gpio.h"
#include "lib/bits.h"

ISR(INT0_vect) {
	GPIO_CplBit(LED_PORT, LED);
}

int main() {


	LED_PORT->DDR = SET(LED);
	LED_PORT->PORT = ~SET(LED);

	GPIO_D->DDR  = ~SET(PD2);
	GPIO_D->PORT = SET(PD2);

	EICRA = SET(ISC01); //gera interrupção na borda de descida;
	EIMSK = SET(INT0);

	sei();
	while(1) {
	}
}

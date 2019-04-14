#include "interrupt_config.h"

void interrupt_config() {
	GPIO_D->DDR |= ~SET(PD2);
	GPIO_D->PORT |= SET(PD2);

	EICRA = SET(ISC01); //gera interrup��o na borda de descida;
	EIMSK = SET(INT0);

	sei();
}

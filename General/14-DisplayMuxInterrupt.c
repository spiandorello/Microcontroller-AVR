#define F_CPU 16000000UL
/*
 * 05_main_timer.c
 *
 *  Created on: Mar 9, 2018
 *      Author: Renan Augusto Starke
 */

#include <avr/interrupt.h>

#include "lib/bits.h"
#include "lib/avr_gpio.h"
#include "lib/avr_timer.h"
#include "lib/avr_extirq.h"

/**
  * @brief  Configura hardware do timer0 para IRQ em overflow.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void timer0_hardware_init(){

	/* H� tr�s maneiras de configurar o TIMER: *
	 * - Acesso direto ao registradores;
	 * - Acesso indireto por struct aos registradores;
	 * - Acesso indireto por struct utilizando bit fields
	 */

	/* Acesso direto: sem avr_timer.h */

	/* Modo normal: TOP = 0xff; */
	TCCR0A = 0;
	/* Ligar fonte de clock: prescaler de 1024 */
	TCCR0B = SET(CS02) | SET(CS00);
	/* Habilita��o de IRQ: overflow */
	TIMSK0 = SET(TOIE0);

    /* ou */

	/* Acesso indireto por struct: com avr_timer.h */
	TIMER_0->TCCRA = 0;
	TIMER_0->TCCRB = SET(CS02) | SET(CS00);
	TIMER_IRQS->TC0.MASK = SET(TOIE0);

    /* ou */

	/* Acesso indireto por struct e bit field: com avr_timer.h */
	TIMER_0->TCCRA = 0;
	TIMER_0->TCCRB = SET(CS02) | SET(CS00);
	TIMER_IRQS->TC0.BITS.TOIE = 1;
}


/* Quando habilitado IRQ de overflow no timer 0*/
ISR(TIMER0_OVF_vect){
	GPIO_CplBit(GPIO_B, 0);
}


/**
  * @brief  Configura hardware do timer1 para IRQ em CTC.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */
void timer1_hardware_init(){

	/* Acesso indireto por struct e bit field: com avr_timer.h */
	TIMER_1->TCCRA = 0;
	/* Modo CTC e prescaler 8 */
	TIMER_1->TCCRB = SET(WGM12) |  SET(CS11);

	/* Defini��o do TOP */
	TIMER_1->OCRA = 8535;

	/* Habilita��o da IRQ: capture pois o top � OCR1A */
	TIMER_IRQS->TC1.BITS.OCIEA = 1;
}

ISR(TIMER1_COMPA_vect){
	GPIO_CplBit(GPIO_B, 1);
}

int main(){

	/* PORTB como sa�da */
	GPIO_B->DDR = 0xff;

	/* Inicializa��o do timer */
	timer0_hardware_init();
	timer1_hardware_init();

	sei();

	/* C�digo de menor prioridade aqui */
	while (1){


	}
}

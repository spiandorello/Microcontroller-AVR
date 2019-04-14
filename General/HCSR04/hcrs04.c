#include "hcrs04.h"
volatile uint8_t Distance = 0, Signal_start = 0;

ISR(TIMER1_CAPT_vect) //interrupção por captura do valor do TCNT1
{
	CPL_BIT(TCCR1B,ICES1); //troca a borda de captura do sinal

	if(!TST_BIT(TCCR1B,ICES1))//lê o valor de contagem do TC1 na borda de subida do sinal

		Signal_start = ICR1;//salva a primeira contagem para determinar a largura do pulso

	else //lê o valor de contagem do TC1 na borda de descida do sinal
		Distance = (ICR1 - Signal_start) / 58; /*agora ICR1 tem o valor do TC1 na borda de descida do sinal, então calcula a distância */
}

void hcrs04_config() {
	TCCR1B = (1<<ICES1)|(1<<CS11); //TC1 com prescaler = 8, captura na borda de subida
	TIMSK1 = 1<<ICIE1; //habilita a interrupção por captura

	HRCS04_PORT->DDR |= SET(TRIGGER) | ~SET(ECHO);
	HRCS04_PORT->PORT |= ~SET(TRIGGER) | SET(ECHO);
}

uint8_t hcrs04_read() {

	TRIG_PULSE();

	return 0;
}

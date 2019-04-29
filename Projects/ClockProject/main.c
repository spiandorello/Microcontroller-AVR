#include "main.h"

int main() {
	display_init();
	clock_init();
	sei();

	//FILE *debug = get_usart_stream();

	/* Inicializa hardware da USART */
	//USART_Init(B9600);


	/* Mensagem incial: terminal do Proteus
	 * utiliza final de linha com '\r' */
	//display_write(get_second());
	//fprintf(debug,"Teste de debug\n\r");

	while(1) {
		//fprintf(debug, "%d\n\r", get_second());
		display_write(get_second());
	}
}

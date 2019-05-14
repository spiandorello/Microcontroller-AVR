#include "matrix.h"

const uint8_t keyboard[4][4] PROGMEM = { {'1', '2', '3', 'F'},
		{'4', '5', '6', 'E'},
		{'7', '8', '9', 'D'},
		{'A', '0', 'B', 'C'}};

#ifdef INTERRUPT
volatile uint8_t led = 0;

ISR(PCINT0_vect)
{
	if(!TST_BIT(PINC,PB0))
		led = 2;
	else if(!TST_BIT(PINC,PB1))
		led = 4;
	else if(!TST_BIT(PINC,PB2))
		led = 8;
}
void extIRQ_config() {
	PCICR = 1 << PCIE0;
	PCMSK0 = 0xFF;
}
#endif


void keyboard_config() {

	MATRIX_KEYBOARD->DDR = 0x0F;
	MATRIX_KEYBOARD->PORT = 0xFF;

#ifdef INTERRUPT
	extIRQ_config();
#endif
}

uint8_t read_keyboard() {
	uint8_t n, j, key=0xFF, line;

	for(n=0;n<4;n++) {

		CLR_BIT(COLLUM,n);
		_delay_ms(10);

		line = LINE >> 4;

		for(j=0;j<4;j++) {
			if(!TST_BIT(line,j)) {

				key = pgm_read_byte(&keyboard[j][n]);
				while(!TST_BIT(LINE >> 4,j));
			}
		}
		SET_BIT(COLLUM,n);
	}
	return key;
}

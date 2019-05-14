#include <avr/io.h>
#include <util/delay.h>

#include <stdlib.h>
#include <stdio.h>

#include "lib/avr_gpio.h"
#include "display/lcd.h"
#include "keyboard/matrix.h"
#include "ServoM/servomotor.h"
int main(){

	uint16_t aux;
	uint8_t buffer[3], i = 0;
	FILE *LCD_stream = inic_stream();
	inic_LCD_4bits();
	keyboard_config();
	servo_motor_hardware_intit();
	sei();

	fprintf(LCD_stream, "DIGITE O ANGULO: ");
	cmd_LCD(0xc0, 0);

	while (1) {
		aux = read_keyboard();
		if (aux != 255) {
			buffer[i] = aux;
			i++;

			if (i > 2) {
				aux = atoi(buffer);
				fprintf(LCD_stream, "%d", aux);
				setup_duty(aux);
			}
		}
	}
}

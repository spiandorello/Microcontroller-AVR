#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>

#include "display/lcd.h"
#include "lib/avr_gpio.h"
#include "lib/bits.h"

int main() {

	inic_LCD_4bits();

	while(1) {

	}
}


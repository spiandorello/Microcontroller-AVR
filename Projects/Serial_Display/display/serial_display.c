#include "serial_display.h"

void serial_display_init() {
	DISPLAY_PORT->DDR |= SET(CLK) | SET(DATA) | SET(STB);
	DISPLAY_PORT->PORT |= CLR_BIT(DISPLAY_PORT->PORT, DATA) | CLR_BIT(DISPLAY_PORT->PORT, CLK)
			| CLR_BIT(DISPLAY_PORT->PORT, STB);
}

void serial_display_write(uint8_t data) {
	uint8_t i = 8;
	uint8_t data_7seg;

	data_7seg = conv_to_7seg(data);

	while(i-- != 0) {
		TST_BIT(data_7seg, i) ? GPIO_SetBit(DISPLAY_PORT, DATA) : GPIO_ClrBit(DISPLAY_PORT, DATA);
		CLK_pulse();
	}

	STB_pulse();
}

void display_write_byte(uint8_t data) {

	// uint8_t data_4bits = data & 0x0F;

	serial_display_write(data & 0x0F);
	serial_display_write(data >> 4);
}

#include "timer_display_mux.h"

typedef struct displayInfo {
	uint8_t data[6];
} displayInfo_t;

volatile displayInfo_t display_info;

ISR(TIMER0_OVF_vect) {
	static uint8_t x = 0;

	DISPLAY_SEL->PORT = 0;
	DISPLAY->PORT = display_info.data[x];
	GPIO_SetBit(DISPLAY_SEL, x);

	x++;
	if (x == 6) x = 0;
}

void timer0_hardware_init() {
	TIMER_0->TCCRA = 0;
	TIMER_0->TCCRB = SET(CS02);
	TIMER_IRQS->TC0.BITS.TOIE = 1;
}

void display_init() {
	timer0_hardware_init();

	DISPLAY->DDR |= 0xFF;
	DISPLAY_SEL->DDR = SET(DISP_0) | SET(DISP_1) | SET(DISP_2) | SET(DISP_3) |
			SET(DISP_4) | SET(DISP_5);
}

void display_write_sec(uint8_t data) {
	display_info.data[0] = conv_to_7seg(data & 0x0F);
	display_info.data[1] = conv_to_7seg(data >> 4);
}

void display_write_min(uint8_t data) {
	display_info.data[2] = conv_to_7seg(data & 0x0F);
	display_info.data[3] = conv_to_7seg(data >> 4);
}

void display_write_hour(uint8_t data) {
	display_info.data[4] = conv_to_7seg(data & 0x0F);
	display_info.data[5] = conv_to_7seg(data >> 4);
}

void display_write(uint8_t data, unsigned char sel) {

}

#include "timer_display_mux.h"

typedef struct displayInfo {
	uint8_t sel;
	uint8_t data[4];

} displayInfo_t;

volatile displayInfo_t display_info;

ISR(TIMER0_OVF_vect) {
	static uint8_t x;

	DISPLAY_SEL->PORT = SET(DISP_0) | SET(DISP_1) | SET(DISP_2) | SET(DISP_3);
	DISPLAY->PORT = display_info.data[x];

	DISPLAY_SEL->PORT = ~SET(x++);

	if (x == 4) x = 0;
}

void timer0_hardware_init() {
	TIMER_0->TCCRA = 0;
	TIMER_0->TCCRB = SET(CS02) | SET(CS00);
	TIMER_IRQS->TC0.BITS.TOIE = 1;
}

void display_init() {
	timer0_hardware_init();

	DISPLAY->DDR |= 0xFF;
	DISPLAY_SEL->DDR = SET(DISP_0) | SET(DISP_1) | SET(DISP_2) | SET(DISP_3);
	//DISPLAY_SEL->PORT = ~SET(DISP_0) | ~SET(DISP_1) | ~SET(DISP_2) | ~SET(DISP_3);
}

void display_write(uint8_t data) {
	display_info.data[0] = conv_to_7seg(data & 0x0F);
	display_info.data[1] = conv_to_7seg(data >> 4);
	display_info.data[2] = conv_to_7seg(0);
	display_info.data[3] = conv_to_7seg(0);
}

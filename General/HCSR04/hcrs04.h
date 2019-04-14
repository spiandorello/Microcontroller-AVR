#ifndef HCSR04_HCRS04_H_
#define HCSR04_HCRS04_H_

#define HRCS04_PORT GPIO_B
#define TRIGGER PB1
#define ECHO PB0

#define TRIG_PULSE() GPIO_SetBit(HRCS04_PORT, TRIGGER); _delay_us(10); GPIO_ClrBit(HRCS04_PORT, TRIGGER); _delay_us(10); _delay_ms(60)

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../lib/bits.h"
#include "../lib/avr_gpio.h"

void hcrs04_config();
uint8_t hcrs04_read();

#endif /* HCSR04_HCRS04_H_ */

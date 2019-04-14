#ifndef DISPLAY_LEDDISPLAY_H_
#define DISPLAY_LEDDISPLAY_H_

#include <avr/pgmspace.h>
#include <util/delay.h>


#include "../lib/avr_timer.h"
#include "../lib/avr_gpio.h"
#include "led_display_mux.h"
#include "../lib/bits.h"
#include "led_table.h"


#define COM_ANODO
//#define COM_CATODO

#define DISPLAY_PORT GPIO_D

#define SELECTOR_PORT GPIO_B
#define EN_1 PB0
#define EN_2 PB1


/**
  * @brief  Configura hardware.
  * @param	Nenhum
  *
  * @retval Nenhum.
  */

void display_config();
/**
  * @brief  Escrevre no display de 7 segmentos.
  * @param	data: valor sem decimal sem conversão. Dados
  * 			são convertidos internamente.
  *
  * @retval Nenhum.
  */

void display_wrie();

#endif /* DISPLAY_LEDDISPLAY_H_ */

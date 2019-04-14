/*
 * leddisplay.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 */

#ifndef DISPLAY_LEDDISPLAY_H_
#define DISPLAY_LEDDISPLAY_H_

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
void display_mux_init();

/**
  * @brief  Escrevre no display de 7 segmentos.
  * @param	data: valor sem decimal sem conversão. Dados
  * 			são convertidos internamente.
  *
  * @retval Nenhum.
  */
void display_mux_write(uint8_t data);

#endif /* DISPLAY_LEDDISPLAY_H_ */

/*
 * gpiox_config.h
 *
 *  Created on: Jul 17, 2024
 *      Author: Anurag
 */

#ifndef GPIOX_CONFIG_H_
#define GPIOX_CONFIG_H_

#include <stdint.h>
#include <stddef.h>
#include "stm32f446xx.h"

#define INPUT  0U
#define OUTPUT 1U

extern uint32_t map_port_to_num(char GPIOx);

extern GPIO_TypeDef* get_GPIOx_PORT(char GPIOx);
extern uint32_t get_GPIOx_PORT_Enabler(char GPIOx);
extern void GPIOx_init(char GPIOx, const uint32_t pin_number, const uint32_t IO_type);

extern uint8_t is_IDR_ON_at_pin(char GPIOx, uint8_t pin_number);
extern void set_ODR_at_pin(char GPIOx, uint32_t pin_number);
extern void reset_ODR_at_pin(char GPIOx, uint32_t pin_number);
extern uint8_t is_pin_set(char GPIOx, uint8_t pin_number);
extern void toggle_ODR_at_pin(char GPIOx, uint32_t pin_number);

#endif /* GPIOX_CONFIG_H_ */

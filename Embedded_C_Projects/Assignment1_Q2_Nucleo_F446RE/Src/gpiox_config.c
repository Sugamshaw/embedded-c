/*
 * gpiox_config.c
 *
 *  Created on: Jul 17, 2024
 *      Author: anurag
 */


#include "gpiox_config.h"


uint32_t map_port_to_num(char GPIOx) {
	switch(GPIOx) {
	case 'A':
		return 0U;
	case 'B':
		return 1U;
	case 'C':
		return 2U;
	case 'D':
		return 3U;
	case 'E':
		return 4U;
	case 'F':
		return 5U;
	case 'G':
		return 6U;
	case 'H':
		return 6U;
	}

	return 10U;
}

GPIO_TypeDef* get_GPIOx_PORT(char GPIOx) {
	uint32_t GPIOxn = map_port_to_num(GPIOx);
	if (GPIOxn > 6u) {
		return NULL;
	}

	GPIO_TypeDef* GPIOx_PORTS[] = {
			GPIOA,
			GPIOB,
			GPIOC,
			GPIOD,
			GPIOE,
			GPIOF,
			GPIOG,
			GPIOH,
	};

	return GPIOx_PORTS[GPIOxn];
}

uint32_t get_GPIOx_PORT_Enabler(char GPIOx) {
	uint32_t PORT_Enablers[] = {
			RCC_AHB1ENR_GPIOAEN,
			RCC_AHB1ENR_GPIOBEN,
			RCC_AHB1ENR_GPIOCEN,
			RCC_AHB1ENR_GPIODEN,
			RCC_AHB1ENR_GPIOEEN,
			RCC_AHB1ENR_GPIOFEN,
			RCC_AHB1ENR_GPIOGEN,
			RCC_AHB1ENR_GPIOHEN,
	};
	uint32_t GPIOxn = map_port_to_num(GPIOx);
	if (GPIOxn > 6u) {
		return 0U;
	}
	return PORT_Enablers[GPIOxn];
}

void GPIOx_init(char GPIOx, const uint32_t pin_number, const uint32_t IO_type) {
	// 0: input
	// 1: output

	GPIO_TypeDef *GPIOx_PORT = get_GPIOx_PORT(GPIOx);
	uint32_t PORT_Enabler = get_GPIOx_PORT_Enabler(GPIOx);

	if (!GPIOx_PORT) {
		return;
	}
	if (PORT_Enabler == 0U) {
		return;
	}

	RCC->AHB1ENR |= PORT_Enabler;
	if ((GPIOx == 'A') && (pin_number == 5)) {
		if (IO_type == 0) {
//			#error "Cannot turn GPIOA5 (PA5) to INPUT mode."
			return;
		}
	}
	if ((GPIOx == 'C') && (pin_number == 13)) {
		if (IO_type == 1) {
//			#error "Cannot turn GPIOC13 (PC13) to OUTPUT mode."
			return;
		}
	}

	GPIOx_PORT->OTYPER &= ~(1 << pin_number);
	GPIOx_PORT->OSPEEDR |= (3 << (2 * pin_number));
	GPIOx_PORT->PUPDR &= ~(2 << (2 * pin_number));

	if (IO_type == 0) {
		GPIOx_PORT->MODER &= ~(1 << (2 * pin_number));

	} else {
		GPIOx_PORT->MODER |= (1 << (2 * pin_number));
	}

	return;
}

uint8_t is_IDR_ON_at_pin(char GPIOx, uint8_t pin_number) {
	GPIO_TypeDef *GPIOx_PORT = get_GPIOx_PORT(GPIOx);

	uint32_t result = ((GPIOx_PORT->IDR) & (1U << pin_number));
	return result > 0? 0: 1;
}

uint8_t is_pin_set(char GPIOx, uint8_t pin_number) {
	GPIO_TypeDef *GPIOx_PORT = get_GPIOx_PORT(GPIOx);

	uint32_t result = ((GPIOx_PORT->ODR) & (1U << pin_number));
	return result > 0? 1: 0;
}

void set_ODR_at_pin(char GPIOx, uint32_t pin_number) {
	GPIO_TypeDef *GPIOx_PORT = get_GPIOx_PORT(GPIOx);
	GPIOx_PORT->ODR |= (1U << pin_number);
}

void reset_ODR_at_pin(char GPIOx, uint32_t pin_number) {
	GPIO_TypeDef *GPIOx_PORT = get_GPIOx_PORT(GPIOx);
	GPIOx_PORT->ODR &= ~(1U << pin_number);
}

void toggle_ODR_at_pin(char GPIOx, uint32_t pin_number) {
	GPIO_TypeDef *GPIOx_PORT = get_GPIOx_PORT(GPIOx);
	GPIOx_PORT->ODR ^= (1U << pin_number);
}

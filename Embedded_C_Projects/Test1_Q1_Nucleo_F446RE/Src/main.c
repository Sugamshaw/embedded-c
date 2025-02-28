/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */



/*
 * Question: Blink an led. It should be ON 5 times longer than its OFF
 *
 * */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define __IO volatile

#define RCC_BASE 				(0x40023800)
#define RCC_OFFSET				(RCC_BASE + 0x30)
#define RCC						((__IO uint32_t *) RCC_OFFSET)

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

#define GPIOA_BASE				(0x40020000)
#define GPIOA					((GPIO_TypeDef *)GPIOA_BASE)

void GPIOA_Init(uint32_t pin) {
	*RCC |= (1 << 0);

	GPIOA->MODER |= (1 << (2 * pin));
	GPIOA->OTYPER &= ~(1 << pin);
	GPIOA->OSPEEDR |= (3 << (2 * pin));
	GPIOA->PUPDR |= (2 << (2 * pin));
}

void delay(uint32_t time) {
	for (uint32_t i = 0u; i < (500000 * time); i++);
}



int main(void)
{
	uint32_t pin = 0;
	GPIOA_Init(pin);
    /* Loop forever */
	for(;;) {
		GPIOA->ODR |= (1 << pin);
		delay(5u);
		GPIOA->ODR &= ~(1 << pin);
		delay(1u);
	}

	return 0;
}

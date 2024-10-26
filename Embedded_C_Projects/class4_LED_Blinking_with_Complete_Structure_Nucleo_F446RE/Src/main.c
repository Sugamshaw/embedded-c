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

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define _IO volatile

// RCC
typedef struct {
	_IO uint32_t RCC_CR;
	_IO uint32_t RCC_PLLCFGR;
	_IO uint32_t RCC_CFGR;
	_IO uint32_t RCC_CIR;
	_IO uint32_t RCC_AHB1RSTR;
	_IO uint32_t RCC_AHB2RSTR;
	_IO uint32_t RCC_AHB3RSTR;
	_IO uint32_t RCC_Reserved0;

	_IO uint32_t RCC_APB1RSTR;
	_IO uint32_t RCC_APB2RSTR;
	_IO uint32_t RCC_Reserved1;
	_IO uint32_t RCC_Reserved2;

	_IO uint32_t RCC_AHB1ENR;
	_IO uint32_t RCC_AHB2ENR;
	_IO uint32_t RCC_AHB3ENR;
	_IO uint32_t RCC_Reserved3;

	_IO uint32_t RCC_APB1ENR;
	_IO uint32_t RCC_APB2ENR;
	_IO uint32_t RCC_Reserved4;
	_IO uint32_t RCC_Reserved5;

	_IO uint32_t RCC_AHB1LPENR;
	_IO uint32_t RCC_AHB2LPENR;
	_IO uint32_t RCC_AHB3LPENR;
	_IO uint32_t RCC_Reserved6;

	_IO uint32_t RCC_APB1LPENR;
	_IO uint32_t RCC_APB2LPENR;
	_IO uint32_t RCC_Reserved7;
	_IO uint32_t RCC_Reserved8;

	_IO uint32_t RCC_BDCR;
	_IO uint32_t RCC_CSR;
	_IO uint32_t RCC_Reserved9;
	_IO uint32_t RCC_Reserved10;

	_IO uint32_t RCC_SSCGR;
	_IO uint32_t RCC_PLLI2SCFGR;
	_IO uint32_t RCC_PLLSAICFGR;
	_IO uint32_t RCC_DCKCFGR;
	_IO uint32_t RCC_CKGATENR;
	_IO uint32_t RCC_DCKCFGR2;
} RCC_TypeDef;

#define RCC_BASE				(0x40023800)
#define RCC						((RCC_TypeDef*) RCC_BASE)

typedef struct {
	_IO uint32_t MODER;
	_IO uint32_t OTYPER;
	_IO uint32_t OSPEEDER;
	_IO uint32_t PUPDR;
	_IO uint32_t IDR;
	_IO uint32_t ODR;
	_IO uint32_t BSRR;
	_IO uint32_t LCKR;
	_IO uint32_t AFRL;
	_IO uint32_t AFRH;
} GPIO_TypeDef;

#define GPIOA_BASE				(0x40020000)
#define GPIOA					((GPIO_TypeDef*) GPIOA_BASE)


void delay(uint32_t frequency) {
	for (uint32_t i = 0; i < frequency; i++);
}

//void delay() {
//	for (uint32_t i = 0; i < 50000; i++);
//}

int main(void)
{
	(RCC->RCC_AHB1ENR) |= (1 << 0);

	GPIOA->MODER |= (1 << 10);
	GPIOA->OTYPER &= ~(1 << 5);
	GPIOA->OSPEEDER |= (1 << 10);
	GPIOA->PUPDR &= ~(3 << 10);


	uint32_t frequency = 500000;

	printf("Blinking at a frequency of : %lu\n", frequency);
	printf("Hello, World!\n");

    /* Loop forever */
	for(;;) {
		GPIOA->ODR |= (1 << 5);
		delay(frequency);
		GPIOA->ODR &= ~(1 << 5);
		delay(frequency);
	}

	return 0;
}

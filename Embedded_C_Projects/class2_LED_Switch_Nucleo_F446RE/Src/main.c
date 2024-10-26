/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Anurag
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
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define _IO volatile

#define RCC_BASE				(0x40023800)
#define RCC_OFFSET				(RCC_BASE + 0x30)
#define RCC						((_IO uint32_t*)RCC_OFFSET)

typedef struct {
	_IO uint32_t MODER;
	_IO uint32_t OTYPER;
	_IO uint32_t OSPEEDR;
	_IO uint32_t PUPDR;
	_IO uint32_t IDR;
	_IO uint32_t ODR;
	_IO uint32_t BSRR;
	_IO uint32_t LCKR;
	_IO uint32_t AFR[2];
} GPIO_TypeDef;

#define GPIOA_BASE				(0x40020000)
#define GPIOC_BASE				(0x40020800)
#define GPIOA					((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOC					((GPIO_TypeDef *)GPIOC_BASE)

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
	#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay() {
	for(uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
//	(*RCC) |= (1 << 0);
	(*RCC) |= (5 << 0);

	GPIOA->MODER |= (1 << 10);
	GPIOA->OTYPER &= ~(1 << 5);
	GPIOA->OSPEEDR |= (3 << 10);

//	GPIOC->MODER &= ~(0 << 26);
	GPIOC->OSPEEDR |= (3 << 26);
	GPIOC->PUPDR |= (2 << 26);

	printf("Hello, World!\n");

    /* Loop forever */
	for(;;) {
//		// on press: OFF
//		if((GPIOC->IDR) & (1 << 13)) {
//			GPIOA->ODR |= (1 << 5);
//		} else {
//			GPIOA->ODR &= ~(1 << 5);
//			printf("Pressed\n");
//		}

		// on press: ON
		if((GPIOC->IDR) & (1 << 13)) {
			GPIOA->ODR &= ~(1 << 5);
		} else {
			GPIOA->ODR |= (1 << 5);
			printf("Pressed\n");
		}
	}

}

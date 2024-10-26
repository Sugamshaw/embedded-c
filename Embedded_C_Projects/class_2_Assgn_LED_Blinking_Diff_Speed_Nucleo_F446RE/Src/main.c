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
#define GPIOA					((GPIO_TypeDef *)GPIOA_BASE)

#define GPIOC_BASE				(0x40020800)
#define GPIOC					((GPIO_TypeDef *)GPIOC_BASE)

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
	#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define SPEED_RANGE 10

void delay(uint32_t speed) {
	for(uint32_t i = 0; i < speed; i++);
}

int main(void)
{
	(*RCC) |= (5 << 0);

	GPIOA->MODER |= (1 << 10);
	GPIOA->OTYPER &= ~(1 << 5);
	GPIOA->OSPEEDR |= (3 << 10);

	GPIOC->OSPEEDR |= (3 << 26);
	GPIOC->PUPDR |= (2 << 26);

	printf("Hello, World!\n");
	uint32_t speeds[SPEED_RANGE] = {100000u, 150000u, 200000u, 250000u, 300000u, 350000u, 400000u, 450000u, 500000u, 550000u};
	uint32_t speed_index = 0;
	uint32_t speed = speeds[speed_index];
    /* Loop forever */

//	for(;;) {
//		GPIOA->ODR &= ~(1 << 5);
//		delay(speeds[speed_index]);
//		GPIOA->ODR |= (1 << 5);
//		delay(speeds[speed_index]);
//		if(!((GPIOC->IDR) & (1 << 13))) {
//			speed_index = 9;
//			printf("Changed Speed to : %u\n", speeds[speed_index]);
//		} else {
//			speed_index = 0;
//			printf("Changed Speed to : %u\n", speeds[speed_index]);
//		}
//	}

	for(;;) {
		GPIOA->ODR &= ~(1 << 5);
		for(uint32_t i = 0; i < speed; i++) {
			if(!((GPIOC->IDR) & (1 << 13))) {
				speed_index = (speed_index + 1) % SPEED_RANGE;
//				printf("Changed Speed to : %lu\n", speeds[speed_index]);
				break;
			}
		}
		speed = speeds[speed_index];

		GPIOA->ODR |= (1 << 5);
		for(uint32_t i = 0; i < speed; i++) {
			if(!((GPIOC->IDR) & (1 << 13))) {
				speed_index = (speed_index + 1) % SPEED_RANGE;
//				printf("Changed Speed to : %lu\n", speeds[speed_index]);
				break;
			}
		}
		speed = speeds[speed_index];
	}

	return 0;
}

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
#include <time.h>
#include "stm32f446xx.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define _IO volatile


void Timer2_init() {
	// Enable RCC APB1ENR for TIM
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/*
	 * Scaling down the incoming clock frequency.
	 * So, after every 16k pulses, the PSC will reset
	 * to 0 and CNT will increment by 1
	 * Now, the system clock frequency is 16MHz, so,
	 * in 1 second, the PSC will reset 16MHz/16KHz = 1000 times.
	 * Meaning, CNT will increment 1000 times. So, if we want
	 * a delay of say 1sec, the the ARR must to set to 1000.
	 *
	 * Now, you may be wondering why `-1` in both PSC and ARR.
	 * source:
	 * 	> TIM2->PSC = (16000 - 1);
	 * 	> TIM2->ARR = (1000 - 1);
	 *
	 * setting PSC=16k - 1 means PSC will increment till 15999 and
	 * as soon as PSC is incremented to 16k, it will reset to 0. So,
	 * we are not wasting even a single clock cycle. In other words,
	 * CNT must increment at 16000th pulse, not after 16000th pulse.
	 *
	 * Same as above, we want to reach the overflow state AT 1000th CNT,
	 * not AFTER 1000th CNT. So, CNT will go up to 999, and as soon as it
	 * increments to 1000, it will reset to 0, and ARR will set the overflow state in
	 * the SR(Status Register).
	 **/
	TIM2->PSC = (16000 - 1);
	TIM2->ARR = (1000 - 1);
	TIM2->CNT = 0;
}

void Timer2_delay(const uint32_t delay) {
	uint32_t ARR_default = TIM2->ARR;
	TIM2->ARR *= delay;

	// start timer
	// when the CR1 is set, the timer begins
	TIM2->CR1 |= (1U << 0);
	while (!(TIM2->SR & (0X0001)));
	TIM2->SR &= ~(1 << 0);
	TIM2->CR1 &= ~(1U << 0); // not necessary. This happens by default

	TIM2->ARR = ARR_default;
}

void GPIOA5_init() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= (1 << 10);
	GPIOA->OTYPER &= ~(1 << 5);
	GPIOA->OSPEEDR |= (1 << 10);
}

void turn_GPIOA5_LED_ON() {
	GPIOA->ODR |= (1 << 5);
}

void turn_GPIOA5_LED_OFF() {
	GPIOA->ODR &= ~(1 << 5);
}

void toggle_GPIOA5_LED() {
	GPIOA->ODR ^= (1 << 5);
}

int main(void)
{
	/*
	 * in order to access the timer, we first need to
	 * access the AHB1 bus. It has a maximum frequency of
	 * 45MHz. The system clock frequency is 16MHz, that is
	 * what we are using.
	 * */
	Timer2_init();

	/*
	 * Since we are using the default LED in
	 * GPIOA5 (PA5) we must first initialize it
	 * appropriate configurations.
	 * */
	GPIOA5_init();

	uint32_t delay = 5u; // in seconds

	clock_t begin, end;
    /* Loop forever */
	for(;;) {
		begin = clock();
		toggle_GPIOA5_LED();
		Timer2_delay(delay);
		end = clock();
//		double time_taken = (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC;
		double time_taken = (double)end - (double)begin;
		printf("duration: %f\n", time_taken);
	}

	return 0;
}

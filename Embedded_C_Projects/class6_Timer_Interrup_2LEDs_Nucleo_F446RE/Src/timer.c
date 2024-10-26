/*
 * timer.c
 *
 *  Created on: Jul 17, 2024
 *      Author: Anurag
 */

#include "timer.h"

void Timer2_Init(uint32_t delay) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	TIM2->PSC = 16000 - 1;
	TIM2->ARR = (100 - 1) * delay;
	TIM2->CNT = 0;

	TIM2->DIER |= TIM_DIER_UIE; //(1<<0)
	NVIC_EnableIRQ(TIM2_IRQn);
}

void Timer5_Init(uint32_t delay) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

	TIM5->PSC = 16000 - 1;
	TIM5->ARR = (100 - 1) * delay;
	TIM5->CNT = 0;

	TIM5->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM5_IRQn);
}

void start_Timer2(void) {
	TIM2->CR1 |= TIM_CR1_CEN; //(1<<0)
}

void start_Timer5(void) {
	TIM5->CR1 |= TIM_CR1_CEN;
}

void TIM2_IRQHandler(void) {
	TIM2->SR &= ~TIM_SR_UIF;
	// simple LEDs toggle
	GPIOA->ODR ^= (1 << 0);
}

void TIM5_IRQHandler(void) {
	TIM5->SR &= ~TIM_SR_UIF;
	// simple LEDs toggle
	GPIOA->ODR ^= (1 << 1);
}

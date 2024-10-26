/*
 * timer.c
 *
 *  Created on: Jul 17, 2024
 *      Author: Anurag
 */

#include "timer.h"

void Timer2_init(uint32_t delay) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	TIM2->PSC = 1600 - 1;
	TIM2->ARR = (10 - 1) * delay;
	TIM2->CNT = 0;

	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
}

void Timer5_init(uint32_t delay) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

	TIM5->PSC = 16000 - 1;
	TIM5->ARR = (100 - 1) * delay;
	TIM5->CNT = 0;

	TIM5->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM5_IRQn);
}

extern void Timer2_init_WI(void) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = (1600 - 1);
	TIM2->ARR = (10 - 1);
	TIM2->CNT = 0;
}

extern void Timer5_init_WI(void) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->PSC = (16 - 1);
	TIM5->ARR = (1 - 1);
	TIM5->CNT = 0;
}

void start_Timer2(void) {
	TIM2->CR1 |= TIM_CR1_CEN;
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

void TIM2_delay(uint32_t delay_time_in_millisec) {
	uint32_t ARR_default = TIM2->ARR;
	TIM2->ARR *= delay_time_in_millisec;

	// start timer
	// when the CR1 is set, the timer begins
	TIM2->CR1 |= (1U << 0);
	while (!(TIM2->SR & (0X0001)));
	TIM2->SR &= ~(1 << 0);
	TIM2->CR1 &= ~(1U << 0); // not necessary. This happens by default

	TIM2->ARR = ARR_default;
}

void TIM5_delay(uint32_t delay_time_in_millisec) {
	uint32_t ARR_default = TIM5->ARR;
	TIM5->ARR *= delay_time_in_millisec;

	// start timer
	// when the CR1 is set, the timer begins
	TIM5->CR1 |= (1U << 0);
	while (!(TIM5->SR & (0X0001)));
	TIM5->SR &= ~(1 << 0);
	TIM5->CR1 &= ~(1U << 0); // not necessary. This happens by default

	TIM5->ARR = ARR_default;
}

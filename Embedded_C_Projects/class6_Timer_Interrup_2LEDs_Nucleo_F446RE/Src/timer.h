/*
 * timer.h
 *
 *  Created on: Jul 17, 2024
 *      Author: anurag
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "stm32f446xx.h"

extern void Timer2_Init(uint32_t delay);
extern void Timer5_Init(uint32_t delay);
extern void start_Timer2(void);
extern void start_Timer5(void);
extern void TIM2_IRQHandler(void);
extern void TIM5_IRQHandler(void);

#endif /* TIMER_H_ */

/*
 * timer.h
 *
 *  Created on: Jul 17, 2024
 *      Author: anurag
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "stm32f446xx.h"

extern void Timer2_init(uint32_t delay);
extern void Timer5_init(uint32_t delay);
extern void Timer2_init_WI(void);
extern void Timer5_init_WI(void);
extern void start_Timer2(void);
extern void start_Timer5(void);
extern void TIM2_IRQHandler(void);
extern void TIM5_IRQHandler(void);
extern void TIM2_delay(uint32_t delay_time_in_millisec);
extern void TIM5_delay(uint32_t delay_time_in_millisec);

#endif /* TIMER_H_ */

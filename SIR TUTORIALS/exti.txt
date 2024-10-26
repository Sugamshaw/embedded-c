#include <stdint.h>
#include <stdio.h>
#include "stm32f446xx.h"
#include <stddef.h>

#define PA5_OUTPUT  (1 << 10)
#define LED_PIN     (1 << 5)
#define BUTTON_PIN  (1 << 13)
#define EXTI_C13    (2 << 4)

int main(){


    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN;
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    GPIOA->MODER |= PA5_OUTPUT;
    GPIOA->OSPEEDR |=(1<<10)|(1<<0);
    __disable_irq();

    SYSCFG->EXTICR[3] |= EXTI_C13;
    EXTI->IMR |= BUTTON_PIN;
    EXTI->FTSR |= BUTTON_PIN;

    NVIC_EnableIRQ(EXTI15_10_IRQn);

    __enable_irq();
    printf("im in main\n");
    while(1){
    	printf("in while\n");
    	for(uint32_t i=0;i<=0xffffff;i++);
    }
}

void EXTI15_10_IRQHandler(void){
    if(EXTI->PR & BUTTON_PIN){
        EXTI->PR |= BUTTON_PIN;
        GPIOA->ODR ^= LED_PIN;
        printf("in EXTI ISR\n");
    }
}

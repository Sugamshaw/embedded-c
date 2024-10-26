/*
 * usart.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Abhisek
 */


#include<usart.h>

// UART Configuration and functions


// Function to send a single character over UART2
void UART2_SendChar(char ch)
{
	USART2->DR = ch; // Load the data register with the character
	while(!(USART2->SR & USART_SR_TXE)); // Wait until the transmit data register is empty
}

// Function to send a string over UART2
void UART2_SendString(char *string)
{
	while(*string != '\0')
	{
		UART2_SendChar(*string); // Send each character of the string
		string++;
	}
}

// Function to configure USART2
void Usart2_config(void)
{
	// Enable the clocks for GPIOA and USART2
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // Enable USART2 clock

	// Configure PA2 and PA3 for alternate function (USART2 TX/RX)
	GPIOA->MODER |= PA2_AF;  // Set PA2 to alternate function mode
	GPIOA->MODER |= PA3_AF;  // Set PA3 to alternate function mode

	GPIOA->OSPEEDR |= (3 << 4); // Set high speed for PA2
	GPIOA->OSPEEDR |= (3 << 6); // Set high speed for PA3

	GPIOA->AFR[0] |= PA2_AF_USART2_TX; // Set alternate function for PA2 as USART2 TX
	GPIOA->AFR[0] |= PA3_AF_USART2_RX; // Set alternate function for PA3 as USART2 RX

	USART2->CR1 = 0x00; // Clear all settings in CR1
	USART2->CR1 |= USART_CR1_UE; // Enable USART2

	USART2->CR1 &= ~(1 << 12); // Set word length to 8 bits

	USART2->BRR |= (1 << 0); // Set baud rate mantissa
	USART2->BRR |= (24 << 4); // Set baud rate fraction

	USART2->CR1 |= USART_CR1_RE; // Enable receiver
	USART2->CR1 |= USART_CR1_TE; // Enable transmitter
}

// Function to receive data from UART2
uint8_t receiverdata(void)
{
	while(!(USART2->SR & USART_SR_RXNE)); // Wait until data is received
	uint8_t data = USART2->DR; // Read the received data
	return data; // Return the received data
}

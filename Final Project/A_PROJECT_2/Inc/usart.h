/*
 * usart.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Abhisek
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f446xx.h"
#include <string.h>       // Include standard string library
#include <stdint.h>       // Include standard integer types

// Define macros for alternate functions

#define PA2_AF           (2 << 4)  // Alternate function mode for PA2
#define PA2_AF_USART2_TX (7 << 8)  // USART2 TX alternate function for PA2
#define PA3_AF           (2 << 6)  // Alternate function mode for PA3
#define PA3_AF_USART2_RX (7 << 12) // USART2 RX alternate function for PA3



// Function Prototype to send a single character over UART2
void UART2_SendChar(char ch);

// Function Prototype to send a string over UART2
void UART2_SendString(char *string);

// Function Prototype to configure USART2 settings
void Usart2_config(void);

// Function Prototype to receive data from USART2
uint8_t receiverdata(void);

#endif /* USART_H_ */

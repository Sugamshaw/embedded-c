/*
 * operations.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Abhisek
 */

#include "operations.h"
#include "usart.h"
#include "adc.h"
#include "interrupt.h"  // Include the header for interrupt functions

// Function to print the main menu
void print_menu(void) {
    UART2_SendString("======================================== \r\n");
    UART2_SendString("|                PROJECT - 1           | \r\n");
    UART2_SendString("======================================== \r\n");
    UART2_SendString("|      1. Start ADC Conversion         | \r\n");
    UART2_SendString("|      2. Trigger Interrupt            | \r\n");
    UART2_SendString("|           3. Exit                    | \r\n");
    UART2_SendString("======================================== \r\n");
    UART2_SendString("\r\n");
}

// Function to print the interrupt menu
void print_interrupt_menu(void) {
    UART2_SendString("\r\n");
    UART2_SendString("Select Interrupt to Trigger:\r\n");
    UART2_SendString("1. Timer Interrupt\r\n");
    UART2_SendString("2. External Interrupt\r\n");
    UART2_SendString("\r\n");
}

// Function to handle the selected option from the main menu
void handle_option(char option) {
    switch (option) {
        case '1':
            start_adc_conversion();
            break;
        case '2':
            trigger_interrupt();
            break;
        case '3':
            exit_program();
            break;
        default:
            UART2_SendString("Invalid Option! Please enter '1', '2', or '3'\r\n");
            break;
    }
}

// Function to start the ADC conversion process
void start_adc_conversion(void) {
    UART2_SendString("\r\n");
    UART2_SendString("Starting ADC Conversion...\r\n");

    // Initialize the ADC
    adc_init();

    // Start ADC conversion
    adc_start_conversion();

    // Read the ADC conversion value
    uint32_t value = adc_read();

    // Buffer to hold the ADC value as a string
    char buffer[10];

    // Convert ADC value to string and store in buffer
    sprintf(buffer, "%lu\n\r", value);

    // Send ADC value over UART
    UART2_SendString(buffer);

    // Loop to continue ADC conversion based on user input
    while (1) {
        UART2_SendString("Do you want to Continue ADC Conversion? (Y/N): ");

        // Receive user input
        char continue_option = receiverdata();

        // Echo the received character
        UART2_SendChar(continue_option);
        UART2_SendString("\r\n");

        // Check user input to continue or stop ADC conversion
        if (continue_option == 'N') {
            break;
        }
        else if (continue_option == 'Y') {
            adc_start_conversion();
            value = adc_read();
            sprintf(buffer, "%lu\n\r", value);
            UART2_SendString(buffer);
        }
        else {
            UART2_SendString("Invalid Option! Please enter 'Y' or 'N'\r\n");
        }
    }
}

// Function to trigger the selected interrupt
void trigger_interrupt(void) {
    UART2_SendString("\r\n");

    // Print the interrupt menu
    print_interrupt_menu();

    // Receive user input for interrupt option
    char interrupt_option = receiverdata();

    // Echo the received character
    UART2_SendChar(interrupt_option);

    UART2_SendString("\r\n");

    // Check the selected interrupt option
    if (interrupt_option == '1') {
        UART2_SendString("\r\n");
        UART2_SendString("Triggering Timer Interrupt...\r\n");

        // Initialize Timer 2
        Timer2_init();
    }
    else if (interrupt_option == '2') {
        UART2_SendString("\r\n");
        UART2_SendString("Triggering External Interrupt...\r\n");

        // Initialize External Interrupt
        EXTI15_10_init();

        // Infinite loop to keep the program running
        while(1);
    }
    else {
        UART2_SendString("\r\n");
        UART2_SendString("Invalid Option! Please enter '1' or '2'\r\n");
    }
}

// Function to exit the program
void exit_program(void) {
    UART2_SendString("Exiting..............................\r\n");

    // Infinite loop to keep the program running
    while (1);
}

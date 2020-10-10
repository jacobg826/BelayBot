/*
File: Bluetooth.c
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the c file for defining functions to enable bluetooth
             communication.
*/

#ifndef _BLUETOOTH_C_
#define _BLUETOOTH_C_

#include "Bluetooth.h"
#include "TM4CREGISTERS.h"

/*
* Function: bluetoothInit()
* Inputs: N/A
* Outputs: N/A
* Description: This function initializes UART3 and GPIO pins A4 and A5 to allow
*              communication with the bluetooth module. The baud
*              rate is 9600 and there are 8 bits sent with stop bits too.
*/
void bluetoothInit(void)
{
   unsigned char delay = 0;
   
   ALTCLK_CC &= ~0x1; //enable alternate 16MHz PIOSC clock
   
   //enable UART3
   UART_ENABLE |= 0x8;
   
   delay++;
   delay++;
   
   //enable GPIO port A
   GPIO_TOGGLE |= 0x1;
   
   delay++;
   delay++;
   
   //____________CONFIGURE PORT A4 and A5 FOR UART Tx and Rx______________
   
   GPIO_AFSEL_A |= 0x30; //enable alternate function ports A4, and A5
   GPIO_DEN_A |= 0x30; //enable digital function ports A4, and A5
   GPIO_PCTL_A |= 0x10000; //enable U3Rx
   GPIO_PCTL_A |= 0x100000; //enable U3Tx
   
   //__________________________CONFIGURE UART0_______________________________
   
   UART_3_CTL &= ~0x1; //Disable UART3
   
   //calculating values for IBRD and FBRD UART registers
   float brd = 0;
   brd = 16000000.0 / ( 16.0 * 9600.0 );
   char brdi = (char)(brd);
   char brdf = (char)( (brd - brdi)*64.0 + .5 );
   
   ///Set Baud Rate to 9600 with PIOSC as clock
   UART_3_IBRD |= brdi;
   UART_3_FBRD |= brdf; 
   
   UART_3_LCTL |= 0x60; //transmit/receive 8 bits
   
   UART_3_CC |= 0x5; //Set Baud Clock source to PIOSC
   
   UART_3_CTL |= 0x301; //enable UART3
}

void btSend(char data)
{
   UART_3_DATA = data;
   //if busy wait by polling busy
   while(UART_3_FLAG & 0x8)
   {}
   UART_3_DATA = 0xD;
   //if busy wait by polling busy
   while(UART_3_FLAG & 0x8)
   {}
   UART_3_DATA = 0xA;
   while(UART_3_FLAG & 0x8)
   {}
   UART_3_DATA = 0xD;
}
#endif
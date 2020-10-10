/*
File: Bluetooth.c
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the c file for defining functions to enable bluetooth
             communication.
*/

#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

/*
* Function: bluetoothInit()
* Inputs: N/A
* Outputs: N/A
* Description: This function initializes UART3 and GPIO pins A4 and A5 to allow
*              communication with the bluetooth module. The baud
*              rate is 9600 and there are 8 bits sent with stop bits too.
*/
void bluetoothInit(void);

void btSend(char data);

#endif
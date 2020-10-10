/*
File: main.c
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the main file for implementing the joystick functions
*/

#include "TM4CREGISTERS.h"
#include "Lab_3_Driver.h"
#include "Lab_3_Header.h"
#include "Joystick.h"
#include "Bluetooth.h"
#include "LEDs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void ADC0_Handler(void);

int main()
{
   //SET MAIN CLOCK TO 60 MHz
   PLL_Init(PRESET2);
   //INITIALIZE BLUETOOTH MODULE
   bluetoothInit();
   //INITIALIZE JOYSTICK MODULE
   joystickInitX();
   
   while(1)
   {}
   
   return 0;
}

void ADC0_Handler(void)
{
   //Clear Flag For Timer 0 and ADC0
   GPTM_0_RIC = GPTM_RIC_TA;
   ADC_0_ISC = 0x8;
   int adcRead = joystickReadX();
   //sample temperature onboard
   if((adcRead) < 1000)
   {
      extLedOn(5);
      extLedOff(4);
      extLedOff(3);
      extLedOff(2);
   }
   else if(adcRead < 2000)
   {
      extLedOn(4);
      extLedOff(5);
      extLedOff(3);
      extLedOff(2);
   }
   else if(adcRead < 3000)
   {
      extLedOn(3);
      extLedOff(5);
      extLedOff(4);
      extLedOff(2);
   }
   else
   {
      extLedOn(2);
      extLedOff(5);
      extLedOff(4);
      extLedOff(3);
   }
   char adcReading[4];
   snprintf(adcReading,5,"%d",adcRead);
   for(int i = 0; i < sizeof(adcReading); i++)
   {
      //if busy wait by polling busy
      while(UART_3_FLAG & 0x8)
      {}
      //else write the next char
      UART_3_DATA = adcReading[i];
   }
   //if busy wait by polling busy
   while(UART_3_FLAG & 0x8)
   {}
   //Return Carriage
   UART_3_DATA = 0xD;
   while(UART_3_FLAG & 0x8)
   {}
   //Newline
   UART_3_DATA = 0xA;
}

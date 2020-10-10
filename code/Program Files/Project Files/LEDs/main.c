/*
File: main.c
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the main file for implementing the onboard and off board
             LEDs.

             PL0 ==> Red off board LED
             PL1 ==> Yellow off board LED
             PL2 ==> Green off board LED
             PL3 ==> Blue off board LED
             PH0 ==> White off board LED
*/

#include "TM4CREGISTERS.h"
#include "LEDs.h"

int main()
{
  /*
   //Enable GPIO ports L and H
   GPIO_TOGGLE |= GPIO_PORTL_EN | GPIO_PORTH_EN;
   
   //Set PL0, PL1, PL2, PL3, PH0 to digital
   GPIO_DEN_L |= 0xF;
   GPIO_DEN_H |= 0x1;
   
   //Set PL0, PL1, PL2, PL3, PH0 to outputs
   GPIO_DIR_L |= 0xF;
   GPIO_DIR_H |= 0x1;
   */
   while(1)
   {
      //Turn on white LED
      extLedOn(1);
      extLedOff(5);
      
      //wait a bit
      for(int i = 0; i < 800000; i++) {}
      
      //Turn on blue LED
      extLedOn(2);
      extLedOff(1);
      
      //wait a bit
      for(int i = 0; i < 800000; i++) {}
      
      //Turn on Green LED
      extLedOn(3);
      extLedOff(2);
      
      //wait a bit
      for(int i = 0; i < 800000; i++) {}
      
      //Turn on Yellow LED
      extLedOn(4);
      extLedOff(3);
      
      //wait a bit
      for(int i = 0; i < 800000; i++) {}
      
      //Turn on Red LED
      extLedOn(5);
      extLedOff(4);
      
      //wait a bit
      for(int i = 0; i < 800000; i++) {}
   }
   return 0;
}

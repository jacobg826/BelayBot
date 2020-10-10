/*
File: LEDs.c
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the h file for defining functions to turn on and off
             the onboard and off board LEDs.

             PL0 ==> Red off board LED ==> 5
             PL1 ==> Yellow off board LED ==> 4
             PL2 ==> Green off board LED ==> 3
             PL3 ==> Blue off board LED ==> 2
             PH0 ==> White off board LED ==> 1
*/
#ifndef _LEDS_C_
#define _LEDS_C_

#include "TM4CREGISTERS.h"
#include "LEDs.h"

/*
* Function: extLedOn()
* Inputs: char - LED
* Outputs: N/A
* Description: This function turns on an external LED.
* 
*              LED == 5 ==> PL0 LED on (RED)
*              LED == 4 ==> PL1 LED on (YELLOW)
*              LED == 3 ==> PL2 LED on (GREEN)
*              LED == 2 ==> PL3 LED on (BLUE)
*              LED == 1 ==> PH0 LED on (WHITE)
*/
void extLedOn(char LED)
{
   //White LED on
   if(LED == 1)
   {
      //enable digital output for port H0
      GPIO_TOGGLE |= GPIO_PORTH_EN;
      GPIO_DEN_H |= 0x1;
      GPIO_DIR_H |= 0x1;
      //turn on LED
      GPIO_DATA_H |= 0x1;
   }
   //Blue LED on
   else if(LED == 2)
   {
      //enable digital output for port L0
      GPIO_TOGGLE |= GPIO_PORTL_EN;
      GPIO_DEN_L |= 0x1;
      GPIO_DIR_L |= 0x1;
      //turn on LED
      GPIO_DATA_L |=0x1;
   }
   //Green LED on
   else if(LED == 3)
   {
      //enable digital output for port L1
      GPIO_TOGGLE |= GPIO_PORTL_EN;
      GPIO_DEN_L |= 0x2;
      GPIO_DIR_L |= 0x2;
      //turn on LED
      GPIO_DATA_L |=0x2;
   }
   //Yellow LED on
   else if(LED == 4)
   {
      //enable digital output for port L2
      GPIO_TOGGLE |= GPIO_PORTL_EN;
      GPIO_DEN_L |= 0x4;
      GPIO_DIR_L |= 0x4;
      //turn on LED
      GPIO_DATA_L |=0x4;
   }
   //Red LED on
   else if(LED == 5)
   {
      //enable digital output for port L1
      GPIO_TOGGLE |= GPIO_PORTL_EN;
      GPIO_DEN_L |= 0x8;
      GPIO_DIR_L |= 0x8;
      //turn on LED
      GPIO_DATA_L |=0x8;
   }
}

/*
* Function: extLedOff()
* Inputs: char - LED
* Outputs: N/A
* Description: This function turns off an external LED.
* 
*              LED == 5 ==> PL0 LED off (RED)
*              LED == 4 ==> PL1 LED off (YELLOW)
*              LED == 3 ==> PL2 LED off (GREEN)
*              LED == 2 ==> PL3 LED off (BLUE)
*              LED == 1 ==> PH0 LED off (WHITE)
*/
void extLedOff(char LED)
{
   //White LED off
   if(LED == 1)
   {
      //turn off LED
      GPIO_DATA_H &= ~0x1;
   }
   //Blue LED off
   else if(LED == 2)
   {
      //turn off LED
      GPIO_DATA_L &= ~0x1;
   }
   //Green LED off
   else if(LED == 3)
   {
      //turn on LED
      GPIO_DATA_L &= ~0x2;
   }
   //Yellow LED off
   else if(LED == 4)
   {
      //turn on LED
      GPIO_DATA_L &= ~0x4;
   }
   //Yellow LED off
   else if(LED == 5)
   {
      //turn on LED
      GPIO_DATA_L &= ~0x8;
   }
}

#endif
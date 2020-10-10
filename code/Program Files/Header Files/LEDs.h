/*
File: LEDs.h
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the h file for declaring functions to turn on and off
             the onboard and off board LEDs.

             PL0 ==> Red off board LED ==> 5
             PL1 ==> Yellow off board LED ==> 4
             PL2 ==> Green off board LED ==> 3
             PL3 ==> Blue off board LED ==> 2
             PH0 ==> White off board LED ==> 1
*/
#ifndef _LEDS_H_
#define _LEDS_H_


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
void extLedOn(char LED);

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
void extLedOff(char LED);

#endif
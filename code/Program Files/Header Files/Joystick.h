/*
File: Joystick.h
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the header file for declaring functions to enable and read
             the joystick values.
*/

#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

/*
* Function: joystickInitY()
* Inputs: N/A
* Outputs: N/A
* Description: This function initializes ADC___ to read the value of the 
               vertical potentiometer.
*/
void joystickInitY(void);

/*
* Function: joystickInitX()
* Inputs: N/A
* Outputs: N/A
* Description: This function initializes ADC___ to read the value of the 
               horizontal potentiometer.
*/
void joystickInitX(void);

/*
* Function: joystickReadX()
* Inputs: N/A
* Outputs: unsigned int
* Description: This function returns the value of the potentiometer as measured
*              from 0 to 4096 by ADC 0.
*/
int joystickReadX(void);

#endif
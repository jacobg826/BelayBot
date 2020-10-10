/*
File: Joystick.c
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the c file for defining functions to enable and read
             the joystick values.
*/

#ifndef _JOYSTICK_C_
#define _JOYSTICK_C_

#include "Joystick.h"
#include "TM4CREGISTERS.h"

/*
* Function: joystickInitX()
* Inputs: N/A
* Outputs: N/A
* Description: This function initializes ADC 0 to read the value of the 
               horizontal potentiometer.
*/
void joystickInitX(void)
{
   volatile unsigned char delay = 0;
   
   //SELECT PIOSC CLOCK FOR ALTERNATE CLOCK
   ALTCLK_CC &= ~0x1;
   
   //PORT E3 FOR ADC0 X DIRECTION
   
   //TURN ON GPIO PORT E
   GPIO_TOGGLE |= 0x10;
   delay++;
   delay++;
   //SELECT ALTERNATE FUNCTION PORT E3
   GPIO_AFSEL_E |= 0x8;
   //DISABLE DIGITAL FUNCTION PORT E3
   GPIO_DEN_E &= ~0x8;
   //ENABLE ANALOG FUNCTION PORT E3
   GPIO_ANAL_E |= 0x8;
   //SET PORT E3 AS AN INPUT
   GPIO_DIR_E |= ~0x8;
   //ENABLE ANALOG IN FOR PORT E3
   GPIO_PCTL_E |= 0x1;
   
   //GPTM 0 FOR SAMPLING ADC 0 & 1
   
   //TURN ON GPTM 0
   GPTM_ENABLE |= 0x1;
   delay++;
   delay++;
   delay++;
   //ENABLE GPTM 0
   GPTM_0_CTL &= 0x0000;
   //RESET GPTM 0 CONFIGURATION
   GPTM_0_CONFIG &= GPTM_CONFIG_RESET;
   //CONFIGURE GPTM 0 AS 32 BIT
   GPTM_0_CONFIG &= 0x0;
   //MAKE GPTM 0 PERIODIC
   GPTM_0_A_MODE |= 0x2;
   //MAKE TIMER 0 DOWN COUNT
   GPTM_0_A_MODE &= ~0x10;
   //LOAD 16,000,000 INTO GPTM 0
   GPTM_0_TAILR = 0xB71B00;
   //ENABLE ADC TRIGGER FOR GPTM 0
   GPTM_0_ADCE |= 0x1;
   //ENABLE GPTM 0
   GPTM_0_CTL |= TIMER_A_ENABLE | 0x20;
   GPTM_0_RIC = GPTM_RIC_TA;
   //ENABLE GPTM 0 INTERRUPT ON TIMEOUT
   GPTM_0_IM |= 0x1;
   
   //ADC0 FOR SAMPLING X AXIS
   
   //ENABLE ADC0
   ADC_ENABLE |= 0x1;
   delay++;
   delay++;
   //SETUP ALTERNATE CLOCK FOR ADC 0
   ADC_0_CC = 0x1;
   //DISABLE SAMPLE SEQUENCER 3
   ADC_0_ASS &= ~0x8;
   //SS3 TRIGGER SELECT TIMER
   ADC_0_EMS |= 0x5000;
   //SELECT AIN 0
   ADC_0_SSIMS3 = 0;
   //Sample input from 15:0
   //ADC_0_SSEMS3 &= 0x0;
   //ENABLE INTERRUPT WHEN SAMPLE SEQUENCER IS DONE CONVERTING
   ADC_0_SSCTL3 = 0x4;
   //ENABLE ADC 0 INTERRUPTS FOR SS3
   ADC_0_IM |= 0x8;
   //ENABLE SAMPLE SEQUENCER 3
   ADC_0_ASS |= 0x8;
   //clear flag
   ADC_0_ISC = 0x8;
   //MAKE SAMPLE AND HOLD TIME 16 CLOCKS
   //ADC_0_SHT |= 0x4;
   
   //ENABLE TIMER ADC SEQ3 INTERRUPT
   INTERUPT_0_31_EN = 0x20000;
}

/*
* Function: joystickInitY()
* Inputs: N/A
* Outputs: N/A
* Description: This function initializes ADC___ to read the value of the 
               vertical potentiometer.
*/
void joystickInitY(void)
{
   
}

/*
* Function: joystickReadX()
* Inputs: N/A
* Outputs: unsigned int
* Description: This function returns the value of the potentiometer as measured
*              from 0 to 4096 by ADC 0.
*/
int joystickReadX(void)
{
   return (unsigned int)ADC_0_SSR;
}

#endif
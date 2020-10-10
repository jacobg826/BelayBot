// _TM4CREGISTER HEADER FILE (.h)_
/* 
 * Anton Soderqvist
 * 1975400
 * 4/14/2020
 * This file defines GPIO and GPTM register adresses and some keys to enable
 * them.
*/
#ifndef _TM4CREGISTER_H_
#define _TM4CREGISTER_H_

//_______________________GPIO REGISTERS__________________________________

//To enable GPIO
#define GPIO_TOGGLE (*(volatile unsigned int*)0x400FE608)

//Keys to enable GPIO ports
#define GPIO_PORTA_EN 0x1
#define GPIO_PORTB_EN 0x2
#define GPIO_PORTC_EN 0x4
#define GPIO_PORTD_EN 0x8
#define GPIO_PORTE_EN 0x10
#define GPIO_PORTF_EN 0x20
#define GPIO_PORTG_EN 0x40
#define GPIO_PORTH_EN 0x80
#define GPIO_PORTJ_EN 0x100
#define GPIO_PORTK_EN 0x200
#define GPIO_PORTL_EN 0x400
#define GPIO_PORTM_EN 0x800
#define GPIO_PORTN_EN 0x1000
#define GPIO_PORTP_EN 0x2000
#define GPIO_PORTQ_EN 0x4000

//To write to GPIOLOCK for port J
#define GPIO_LOCK_J (*(volatile unsigned int*)0x40060520)

//key to enable GPIOLOCK
#define GPIO_LOCK_KEY 0x4C4F434B

//To enable GPIO commit register
#define GPIO_CR_J (*(volatile unsigned int*)0x40060524)

//To access/write values to GPIO ports F, N, J, L 3FC
#define GPIO_DATA_A (*(volatile unsigned int*)0x400583FC)
#define GPIO_DATA_B (*(volatile unsigned int*)0x400593FC)
#define GPIO_DATA_C (*(volatile unsigned int*)0x4005A3FC)
#define GPIO_DATA_D (*(volatile unsigned int*)0x4005B3FC)
#define GPIO_DATA_E (*(volatile unsigned int*)0x4005C3FC)
#define GPIO_DATA_F (*(volatile unsigned int*)0x4005D3FC)
#define GPIO_DATA_G (*(volatile unsigned int*)0x4005E3FC)
#define GPIO_DATA_H (*(volatile unsigned int*)0x4005F3FC)
#define GPIO_DATA_J (*(volatile unsigned int*)0x400603FC)
#define GPIO_DATA_K (*(volatile unsigned int*)0x400613FC)
#define GPIO_DATA_L (*(volatile unsigned int*)0x400623FC)
#define GPIO_DATA_M (*(volatile unsigned int*)0x400633FC)
#define GPIO_DATA_N (*(volatile unsigned int*)0x400643FC)
#define GPIO_DATA_P (*(volatile unsigned int*)0x400653FC)
#define GPIO_DATA_Q (*(volatile unsigned int*)0x400663FC)

//To define GPIO ports F, N, J, L as input vs output 
#define GPIO_DIR_A (*(volatile unsigned int*)0x40058400)
#define GPIO_DIR_B (*(volatile unsigned int*)0x40059400)
#define GPIO_DIR_C (*(volatile unsigned int*)0x4005A400)
#define GPIO_DIR_D (*(volatile unsigned int*)0x4005B400)
#define GPIO_DIR_E (*(volatile unsigned int*)0x4005C400)
#define GPIO_DIR_F (*(volatile unsigned int*)0x4005D400)
#define GPIO_DIR_G (*(volatile unsigned int*)0x4005E400)
#define GPIO_DIR_H (*(volatile unsigned int*)0x4005F400)
#define GPIO_DIR_J (*(volatile unsigned int*)0x40060400)
#define GPIO_DIR_K (*(volatile unsigned int*)0x40061400)
#define GPIO_DIR_L (*(volatile unsigned int*)0x40062400)
#define GPIO_DIR_M (*(volatile unsigned int*)0x40063400)
#define GPIO_DIR_N (*(volatile unsigned int*)0x40064400)
#define GPIO_DIR_P (*(volatile unsigned int*)0x40065400)
#define GPIO_DIR_Q (*(volatile unsigned int*)0x40066400)

//To define GPIO ports F, N, J, L as digital 
#define GPIO_DEN_A (*(volatile unsigned int*)0x4005851C)
#define GPIO_DEN_B (*(volatile unsigned int*)0x4005951C)
#define GPIO_DEN_C (*(volatile unsigned int*)0x4005A51C)
#define GPIO_DEN_D (*(volatile unsigned int*)0x4005B51C)
#define GPIO_DEN_E (*(volatile unsigned int*)0x4005C51C)
#define GPIO_DEN_F (*(volatile unsigned int*)0x4005D51C)
#define GPIO_DEN_G (*(volatile unsigned int*)0x4005E51C)
#define GPIO_DEN_H (*(volatile unsigned int*)0x4005F51C)
#define GPIO_DEN_J (*(volatile unsigned int*)0x4006051C)
#define GPIO_DEN_K (*(volatile unsigned int*)0x4006151C)
#define GPIO_DEN_L (*(volatile unsigned int*)0x4006251C)
#define GPIO_DEN_M (*(volatile unsigned int*)0x4006351C)
#define GPIO_DEN_N (*(volatile unsigned int*)0x4006451C)
#define GPIO_DEN_P (*(volatile unsigned int*)0x4006551C)
#define GPIO_DEN_Q (*(volatile unsigned int*)0x4006651C)

//To enable GPIO ports F, N, J, L pull up resistor
#define GPIO_PUR_A (*(volatile unsigned int*)0x40058510)
#define GPIO_PUR_B (*(volatile unsigned int*)0x40059510)
#define GPIO_PUR_C (*(volatile unsigned int*)0x4005A510)
#define GPIO_PUR_D (*(volatile unsigned int*)0x4005B510)
#define GPIO_PUR_E (*(volatile unsigned int*)0x4005C510)
#define GPIO_PUR_F (*(volatile unsigned int*)0x4005D510)
#define GPIO_PUR_G (*(volatile unsigned int*)0x4005E510)
#define GPIO_PUR_H (*(volatile unsigned int*)0x4005F510)
#define GPIO_PUR_J (*(volatile unsigned int*)0x40060510)
#define GPIO_PUR_K (*(volatile unsigned int*)0x40061510)
#define GPIO_PUR_L (*(volatile unsigned int*)0x40062510)
#define GPIO_PUR_M (*(volatile unsigned int*)0x40063510)
#define GPIO_PUR_N (*(volatile unsigned int*)0x40064510)
#define GPIO_PUR_P (*(volatile unsigned int*)0x40065510)
#define GPIO_PUR_Q (*(volatile unsigned int*)0x40066510)

//To enable GPIO Alternate Function Select
#define GPIO_AFSEL_A (*(volatile unsigned int*)0x40058420)
#define GPIO_AFSEL_B (*(volatile unsigned int*)0x40059420)
#define GPIO_AFSEL_C (*(volatile unsigned int*)0x4005A420)
#define GPIO_AFSEL_D (*(volatile unsigned int*)0x4005B420)
#define GPIO_AFSEL_E (*(volatile unsigned int*)0x4005C420)
#define GPIO_AFSEL_F (*(volatile unsigned int*)0x4005D420)
#define GPIO_AFSEL_G (*(volatile unsigned int*)0x4005E420)
#define GPIO_AFSEL_H (*(volatile unsigned int*)0x4005F420)
#define GPIO_AFSEL_J (*(volatile unsigned int*)0x40060420)
#define GPIO_AFSEL_K (*(volatile unsigned int*)0x40061420)
#define GPIO_AFSEL_L (*(volatile unsigned int*)0x40062420)
#define GPIO_AFSEL_M (*(volatile unsigned int*)0x40063420)
#define GPIO_AFSEL_N (*(volatile unsigned int*)0x40064420)
#define GPIO_AFSEL_P (*(volatile unsigned int*)0x40065420)
#define GPIO_AFSEL_Q (*(volatile unsigned int*)0x40066420)

//To enable GPIO Analog Mode for ports  F, N, J, L
#define GPIO_ANAL_A (*(volatile unsigned int*)0x40058528)
#define GPIO_ANAL_B (*(volatile unsigned int*)0x40059528)
#define GPIO_ANAL_C (*(volatile unsigned int*)0x4005A528)
#define GPIO_ANAL_D (*(volatile unsigned int*)0x4005B528)
#define GPIO_ANAL_E (*(volatile unsigned int*)0x4005C528)
#define GPIO_ANAL_F (*(volatile unsigned int*)0x4005D528)
#define GPIO_ANAL_G (*(volatile unsigned int*)0x4005E528)
#define GPIO_ANAL_H (*(volatile unsigned int*)0x4005F528)
#define GPIO_ANAL_J (*(volatile unsigned int*)0x40060528)
#define GPIO_ANAL_K (*(volatile unsigned int*)0x40061528)
#define GPIO_ANAL_L (*(volatile unsigned int*)0x40062528)
#define GPIO_ANAL_M (*(volatile unsigned int*)0x40063528)
#define GPIO_ANAL_N (*(volatile unsigned int*)0x40064528)
#define GPIO_ANAL_P (*(volatile unsigned int*)0x40065528)
#define GPIO_ANAL_Q (*(volatile unsigned int*)0x40066528)

//To enable GPIO interrupt sense for ports F, N, J
#define GPIO_IS_A (*(volatile unsigned int*)0x40058404)
#define GPIO_IS_B (*(volatile unsigned int*)0x40059404)
#define GPIO_IS_C (*(volatile unsigned int*)0x4005A404)
#define GPIO_IS_D (*(volatile unsigned int*)0x4005B404)
#define GPIO_IS_E (*(volatile unsigned int*)0x4005C404)
#define GPIO_IS_F (*(volatile unsigned int*)0x4005D404)
#define GPIO_IS_G (*(volatile unsigned int*)0x4005E404)
#define GPIO_IS_H (*(volatile unsigned int*)0x4005F404)
#define GPIO_IS_J (*(volatile unsigned int*)0x40060404)
#define GPIO_IS_K (*(volatile unsigned int*)0x40061404)
#define GPIO_IS_L (*(volatile unsigned int*)0x40062404)
#define GPIO_IS_M (*(volatile unsigned int*)0x40063404)
#define GPIO_IS_N (*(volatile unsigned int*)0x40064404)
#define GPIO_IS_P (*(volatile unsigned int*)0x40065404)
#define GPIO_IS_Q (*(volatile unsigned int*)0x40066404)

//To enable GPIO interrupt event for ports F, N, J, L
#define GPIO_IEV_A (*(volatile unsigned int*)0x4005840C)
#define GPIO_IEV_B (*(volatile unsigned int*)0x4005940C)
#define GPIO_IEV_C (*(volatile unsigned int*)0x4005A40C)
#define GPIO_IEV_D (*(volatile unsigned int*)0x4005B40C)
#define GPIO_IEV_E (*(volatile unsigned int*)0x4005C40C)
#define GPIO_IEV_F (*(volatile unsigned int*)0x4005D40C)
#define GPIO_IEV_G (*(volatile unsigned int*)0x4005E40C)
#define GPIO_IEV_H (*(volatile unsigned int*)0x4005F40C)
#define GPIO_IEV_J (*(volatile unsigned int*)0x4006040C)
#define GPIO_IEV_K (*(volatile unsigned int*)0x4006140C)
#define GPIO_IEV_L (*(volatile unsigned int*)0x4006240C)
#define GPIO_IEV_M (*(volatile unsigned int*)0x4006340C)
#define GPIO_IEV_N (*(volatile unsigned int*)0x4006440C)
#define GPIO_IEV_P (*(volatile unsigned int*)0x4006540C)
#define GPIO_IEV_Q (*(volatile unsigned int*)0x4006640C)

//To enable GPIO interrupt mask for ports F, N, J, L 
#define GPIO_IM_A (*(volatile unsigned int*)0x40058410)
#define GPIO_IM_B (*(volatile unsigned int*)0x40059410)
#define GPIO_IM_C (*(volatile unsigned int*)0x4005A410)
#define GPIO_IM_D (*(volatile unsigned int*)0x4005B410)
#define GPIO_IM_E (*(volatile unsigned int*)0x4005C410)
#define GPIO_IM_F (*(volatile unsigned int*)0x4005D410)
#define GPIO_IM_G (*(volatile unsigned int*)0x4005E410)
#define GPIO_IM_H (*(volatile unsigned int*)0x4005F410)
#define GPIO_IM_J (*(volatile unsigned int*)0x40060410)
#define GPIO_IM_K (*(volatile unsigned int*)0x40061410)
#define GPIO_IM_L (*(volatile unsigned int*)0x40062410)
#define GPIO_IM_M (*(volatile unsigned int*)0x40063410)
#define GPIO_IM_N (*(volatile unsigned int*)0x40064410)
#define GPIO_IM_P (*(volatile unsigned int*)0x40065410)
#define GPIO_IM_Q (*(volatile unsigned int*)0x40066410)

//To enable GPIO masked interrupt status for ports F, N, J, L
#define GPIO_RIS_A (*(volatile unsigned int*)0x40058414)
#define GPIO_RIS_B (*(volatile unsigned int*)0x40059414)
#define GPIO_RIS_C (*(volatile unsigned int*)0x4005A414)
#define GPIO_RIS_D (*(volatile unsigned int*)0x4005B414)
#define GPIO_RIS_E (*(volatile unsigned int*)0x4005C414)
#define GPIO_RIS_F (*(volatile unsigned int*)0x4005D414)
#define GPIO_RIS_G (*(volatile unsigned int*)0x4005E414)
#define GPIO_RIS_H (*(volatile unsigned int*)0x4005F414)
#define GPIO_RIS_J (*(volatile unsigned int*)0x40060414)
#define GPIO_RIS_K (*(volatile unsigned int*)0x40061414)
#define GPIO_RIS_L (*(volatile unsigned int*)0x40062414)
#define GPIO_RIS_M (*(volatile unsigned int*)0x40063414)
#define GPIO_RIS_N (*(volatile unsigned int*)0x40064414)
#define GPIO_RIS_P (*(volatile unsigned int*)0x40065414)
#define GPIO_RIS_Q (*(volatile unsigned int*)0x40066414)

//To enable GPIO masked interrupt status for ports F, N, J, L
#define GPIO_MIS_A (*(volatile unsigned int*)0x40058418)
#define GPIO_MIS_B (*(volatile unsigned int*)0x40059418)
#define GPIO_MIS_C (*(volatile unsigned int*)0x4005A418)
#define GPIO_MIS_D (*(volatile unsigned int*)0x4005B418)
#define GPIO_MIS_E (*(volatile unsigned int*)0x4005C418)
#define GPIO_MIS_F (*(volatile unsigned int*)0x4005D418)
#define GPIO_MIS_G (*(volatile unsigned int*)0x4005E418)
#define GPIO_MIS_H (*(volatile unsigned int*)0x4005F418)
#define GPIO_MIS_J (*(volatile unsigned int*)0x40060418)
#define GPIO_MIS_K (*(volatile unsigned int*)0x40061418)
#define GPIO_MIS_L (*(volatile unsigned int*)0x40062418)
#define GPIO_MIS_M (*(volatile unsigned int*)0x40063418)
#define GPIO_MIS_N (*(volatile unsigned int*)0x40064418)
#define GPIO_MIS_P (*(volatile unsigned int*)0x40065418)
#define GPIO_MIS_Q (*(volatile unsigned int*)0x40066418)

//To enable GPIO interrupt clear for ports F, N, J, L 
#define GPIO_IC_A (*(volatile unsigned int*)0x4005841C)
#define GPIO_IC_B (*(volatile unsigned int*)0x4005941C)
#define GPIO_IC_C (*(volatile unsigned int*)0x4005A41C)
#define GPIO_IC_D (*(volatile unsigned int*)0x4005B41C)
#define GPIO_IC_E (*(volatile unsigned int*)0x4005C41C)
#define GPIO_IC_F (*(volatile unsigned int*)0x4005D41C)
#define GPIO_IC_G (*(volatile unsigned int*)0x4005E41C)
#define GPIO_IC_H (*(volatile unsigned int*)0x4005F41C)
#define GPIO_IC_J (*(volatile unsigned int*)0x4006041C)
#define GPIO_IC_K (*(volatile unsigned int*)0x4006141C)
#define GPIO_IC_L (*(volatile unsigned int*)0x4006241C)
#define GPIO_IC_M (*(volatile unsigned int*)0x4006341C)
#define GPIO_IC_N (*(volatile unsigned int*)0x4006441C)
#define GPIO_IC_P (*(volatile unsigned int*)0x4006541C)
#define GPIO_IC_Q (*(volatile unsigned int*)0x4006641C)

//To set GPIO port control for ports F, N, J, L 
#define GPIO_PCTL_A (*(volatile unsigned int*)0x4005852C)
#define GPIO_PCTL_B (*(volatile unsigned int*)0x4005952C)
#define GPIO_PCTL_C (*(volatile unsigned int*)0x4005A52C)
#define GPIO_PCTL_D (*(volatile unsigned int*)0x4005B52C)
#define GPIO_PCTL_E (*(volatile unsigned int*)0x4005C52C)
#define GPIO_PCTL_F (*(volatile unsigned int*)0x4005D52C)
#define GPIO_PCTL_G (*(volatile unsigned int*)0x4005E52C)
#define GPIO_PCTL_H (*(volatile unsigned int*)0x4005F52C)
#define GPIO_PCTL_J (*(volatile unsigned int*)0x4006052C)
#define GPIO_PCTL_K (*(volatile unsigned int*)0x4006152C)
#define GPIO_PCTL_L (*(volatile unsigned int*)0x4006252C)
#define GPIO_PCTL_M (*(volatile unsigned int*)0x4006352C)
#define GPIO_PCTL_N (*(volatile unsigned int*)0x4006452C)
#define GPIO_PCTL_P (*(volatile unsigned int*)0x4006552C)
#define GPIO_PCTL_Q (*(volatile unsigned int*)0x4006652C)

//To set GPIO open drain select
#define GPIO_ODR_A (*(volatile unsigned int*)0x4005850C)
#define GPIO_ODR_B (*(volatile unsigned int*)0x4005950C)
#define GPIO_ODR_C (*(volatile unsigned int*)0x4005A50C)
#define GPIO_ODR_D (*(volatile unsigned int*)0x4005B50C)
#define GPIO_ODR_E (*(volatile unsigned int*)0x4005C50C)
#define GPIO_ODR_F (*(volatile unsigned int*)0x4005D50C)
#define GPIO_ODR_G (*(volatile unsigned int*)0x4005E50C)
#define GPIO_ODR_H (*(volatile unsigned int*)0x4005F50C)
#define GPIO_ODR_J (*(volatile unsigned int*)0x4006050C)
#define GPIO_ODR_K (*(volatile unsigned int*)0x4006150C)
#define GPIO_ODR_L (*(volatile unsigned int*)0x4006250C)
#define GPIO_ODR_M (*(volatile unsigned int*)0x4006350C)
#define GPIO_ODR_N (*(volatile unsigned int*)0x4006450C)
#define GPIO_ODR_P (*(volatile unsigned int*)0x4006550C)
#define GPIO_ODR_Q (*(volatile unsigned int*)0x4006650C)

//Onboard LED register bits
#define LED4 0x1
#define LED3 0x10
#define LED2 0x1
#define LED1 0x2

//Onboard SW register bits
#define SW1 0x1
#define SW2 0x2

//_______________________GEN-PURP TIMERS________________________

//Enable 16/32 Bit GEN-PURP Timer
#define GPTM_ENABLE (*(volatile unsigned int*)0x400FE604)

//Enable 16/32 Bit GEN-PURP Timer 0
#define GPTM_0 0x1
#define GPTM_1 0x2
#define GPTM_2 0x4
#define GPTM_3 0x8

//Enable interupts 0-31
#define INTERUPT_0_31_EN (*(volatile unsigned int*)0xE000E100)
#define INTERUPT_32_63_EN (*(volatile unsigned int*)0xE000E104)

//enable interupt keys
#define INTERUPT_KEY_19 0x80000

//GPTM Control address for Timer 0
#define GPTM_0_CTL (*(volatile unsigned int*)0x4003000C)
#define GPTM_1_CTL (*(volatile unsigned int*)0x4003100C)
#define GPTM_2_CTL (*(volatile unsigned int*)0x4003200C)
#define GPTM_3_CTL (*(volatile unsigned int*)0x4003300C)

//Disable TIMER A and Timer B via GPTM_X_CTL
#define TIMER_A_DISABLE 0x0
#define TIMER_B_DISABLE 0x000
#define TIMER_A_ENABLE 0x1
#define TIMER_B_ENABLE 0x100


//GPTM Configuration register address for timer 0
#define GPTM_0_CONFIG (*(volatile unsigned int*)0x40030000)
#define GPTM_1_CONFIG (*(volatile unsigned int*)0x40031000)
#define GPTM_2_CONFIG (*(volatile unsigned int*)0x40032000)
#define GPTM_3_CONFIG (*(volatile unsigned int*)0x40033000)


//Reset GPTM Configuration register key
#define GPTM_CONFIG_RESET 0x00000000

//configure 32 bit timer GPTM Config
#define GPTM_CONFIG_32 0x0

//GPTM Timer A Mode register for timer 0
#define GPTM_0_A_MODE (*(volatile unsigned int*)0x40030004)
#define GPTM_1_A_MODE (*(volatile unsigned int*)0x40031004)
#define GPTM_2_A_MODE (*(volatile unsigned int*)0x40032004)
#define GPTM_3_A_MODE (*(volatile unsigned int*)0x40033004)

//GPTM TIMER A mode TAMR periodic timer
#define GPTM_TAMR_PERIODIC 0x2 

//GPTM Timer A mode count direction down
#define GPTM_TADIR_D 0x00

//GPTM TImer A interval load register for timer 0
#define GPTM_0_TAILR (*(volatile unsigned int*)0x40030028)
#define GPTM_1_TAILR (*(volatile unsigned int*)0x40031028)
#define GPTM_2_TAILR (*(volatile unsigned int*)0x40032028)
#define GPTM_3_TAILR (*(volatile unsigned int*)0x40033028)

//GPTM TIMER A load 16,000,000
#define GPTM_TAILR_16M 0xF42400

//GPTM TIMER A load 32,000,000
#define GPTM_TAILR_32M 0x1E84800

//GPTM TIMER A load 80,000,000
#define GPTM_TAILR_80M 0x4C4B400

//GPTM Interupt Mask register for timer 0
#define GPTM_0_IM (*(volatile unsigned int*)0x40030018)
#define GPTM_1_IM (*(volatile unsigned int*)0x40031018)
#define GPTM_2_IM (*(volatile unsigned int*)0x40032018)
#define GPTM_3_IM (*(volatile unsigned int*)0x40033018)

//GPTM Raw Interupt Status timer 0 register
#define  GPTM_0_RIS (*(volatile unsigned int*)0x4003001C)
#define  GPTM_1_RIS (*(volatile unsigned int*)0x4003101C)
#define  GPTM_2_RIS (*(volatile unsigned int*)0x4003201C)
#define  GPTM_3_RIS (*(volatile unsigned int*)0x4003301C)

//GPTM Timer A raw interupt status (timed out?)
#define GPTM_RIS_A_TOUT 0x1

//GPTM Interupt Clear register timer 0
#define  GPTM_0_RIC (*(volatile unsigned int*)0x40030024)
#define  GPTM_1_RIC (*(volatile unsigned int*)0x40031024)
#define  GPTM_2_RIC (*(volatile unsigned int*)0x40032024)
#define  GPTM_3_RIC (*(volatile unsigned int*)0x40033024)

//GPTM ADC event register timer 0
#define  GPTM_0_ADCE (*(volatile unsigned int*)0x40030070)
#define  GPTM_1_ADCE (*(volatile unsigned int*)0x40031070)
#define  GPTM_2_ADCE (*(volatile unsigned int*)0x40032070)
#define  GPTM_3_ADCE (*(volatile unsigned int*)0x40033070)

//GPTM Interupt Clear Timer A
#define GPTM_RIC_TA 0x1

//__________________________ADC Keywords_______________________________

//Enable ADC clock
#define ADC_ENABLE (*(volatile unsigned int*)0x400FE638)

//ADC Active Sample Sequencer registers
#define  ADC_0_ASS (*(volatile unsigned int*)0x40038000)
#define  ADC_1_ASS (*(volatile unsigned int*)0x40039000)

//ADC Event Mux Select registers
#define  ADC_0_EMS (*(volatile unsigned int*)0x40038014)
#define  ADC_1_EMS (*(volatile unsigned int*)0x40039014)

//Analog input configuration for Sample Sequencer 3
#define ADC_0_SSIMS3 (*(volatile unsigned int*)0x400380A0)
#define ADC_1_SSIMS3 (*(volatile unsigned int*)0x400390A0)

//ADC Sample Sequence Extended Input Multiplexer Select 3 registers
#define ADC_0_SSEMS3 (*(volatile unsigned int*)0x400380B8)
#define ADC_1_SSEMS3 (*(volatile unsigned int*)0x400390B8)

//ADC Sample Sequencer Control 3 registers
#define ADC_0_SSCTL3 (*(volatile unsigned int*)0x400380A4)
#define ADC_1_SSCTL3 (*(volatile unsigned int*)0x400390A4)

//ADC Interrupt Mask registers
#define ADC_0_IM (*(volatile unsigned int*)0x40038008)
#define ADC_1_IM (*(volatile unsigned int*)0x40039008)

//ADC Clock Configuration registers
#define ADC_0_CC (*(volatile unsigned int*)0x40038FC8)
#define ADC_1_CC (*(volatile unsigned int*)0x40039FC8)

//ADC Sample Sequence Result registers
#define ADC_0_SSR (*(volatile unsigned int*)0x400380A8)
#define ADC_1_SSR (*(volatile unsigned int*)0x400390A8)

//ADC Interrupt Status and Clear registers
#define ADC_0_ISC (*(volatile unsigned int*)0x4003800C)
#define ADC_1_ISC (*(volatile unsigned int*)0x4003900C)

//ADC Sample Sequence 3 Sample and Hold Time Registers
#define ADC_0_SHT (*(volatile unsigned int*)0x400380BC)
#define ADC_1_SHT (*(volatile unsigned int*)0x400390BC)

//_______________________ALTERNATE CLOCK_____________________________

#define ALTCLK_CC (*(volatile unsigned int*)0x400FE138)

//_______________________UART Registers______________________________

//enabe UART module
#define UART_ENABLE (*(volatile unsigned int*)0x400FE618)

//UART DATA registers (Tx or Rx)
#define UART_0_DATA (*(volatile unsigned int*)0x4000C000)
#define UART_1_DATA (*(volatile unsigned int*)0x4000D000)
#define UART_2_DATA (*(volatile unsigned int*)0x4000E000)
#define UART_3_DATA (*(volatile unsigned int*)0x4000F000)
#define UART_4_DATA (*(volatile unsigned int*)0x40010000)
#define UART_5_DATA (*(volatile unsigned int*)0x40011000)
#define UART_6_DATA (*(volatile unsigned int*)0x40012000)
#define UART_7_DATA (*(volatile unsigned int*)0x40013000)

//UART Receive status and error clear registers
#define UART_0_RSEC (*(volatile unsigned int*)0x4000C004)
#define UART_1_RSEC (*(volatile unsigned int*)0x4000D004)
#define UART_2_RSEC (*(volatile unsigned int*)0x4000E004)
#define UART_3_RSEC (*(volatile unsigned int*)0x4000F004)
#define UART_4_RSEC (*(volatile unsigned int*)0x40010004)
#define UART_5_RSEC (*(volatile unsigned int*)0x40011004)
#define UART_6_RSEC (*(volatile unsigned int*)0x40012004)
#define UART_7_RSEC (*(volatile unsigned int*)0x40013004)

//UART Flag registers
#define UART_0_FLAG (*(volatile unsigned int*)0x4000C018)
#define UART_1_FLAG (*(volatile unsigned int*)0x4000D018)
#define UART_2_FLAG (*(volatile unsigned int*)0x4000E018)
#define UART_3_FLAG (*(volatile unsigned int*)0x4000F018)
#define UART_4_FLAG (*(volatile unsigned int*)0x40010018)
#define UART_5_FLAG (*(volatile unsigned int*)0x40011018)
#define UART_6_FLAG (*(volatile unsigned int*)0x40012018)
#define UART_7_FLAG (*(volatile unsigned int*)0x40013018)

//UART Integer Baud Rate Divisor registers
#define UART_0_IBRD (*(volatile unsigned int*)0x4000C024)
#define UART_1_IBRD (*(volatile unsigned int*)0x4000D024)
#define UART_2_IBRD (*(volatile unsigned int*)0x4000E024)
#define UART_3_IBRD (*(volatile unsigned int*)0x4000F024)
#define UART_4_IBRD (*(volatile unsigned int*)0x40010024)
#define UART_5_IBRD (*(volatile unsigned int*)0x40011024)
#define UART_6_IBRD (*(volatile unsigned int*)0x40012024)
#define UART_7_IBRD (*(volatile unsigned int*)0x40013024)

//UART Fractional Baud Rate Divisor registers
#define UART_0_FBRD (*(volatile unsigned int*)0x4000C028)
#define UART_1_FBRD (*(volatile unsigned int*)0x4000D028)
#define UART_2_FBRD (*(volatile unsigned int*)0x4000E028)
#define UART_3_FBRD (*(volatile unsigned int*)0x4000F028)
#define UART_4_FBRD (*(volatile unsigned int*)0x40010028)
#define UART_5_FBRD (*(volatile unsigned int*)0x40011028)
#define UART_6_FBRD (*(volatile unsigned int*)0x40012028)
#define UART_7_FBRD (*(volatile unsigned int*)0x40013028)

//UART Line Control registers
#define UART_0_LCTL (*(volatile unsigned int*)0x4000C02C)
#define UART_1_LCTL (*(volatile unsigned int*)0x4000D02C)
#define UART_2_LCTL (*(volatile unsigned int*)0x4000E02C)
#define UART_3_LCTL (*(volatile unsigned int*)0x4000F02C)
#define UART_4_LCTL (*(volatile unsigned int*)0x4001002C)
#define UART_5_LCTL (*(volatile unsigned int*)0x4001102C)
#define UART_6_LCTL (*(volatile unsigned int*)0x4001202C)
#define UART_7_LCTL (*(volatile unsigned int*)0x4001302C)

//UART Control registers
#define UART_0_CTL (*(volatile unsigned int*)0x4000C030)
#define UART_1_CTL (*(volatile unsigned int*)0x4000D030)
#define UART_2_CTL (*(volatile unsigned int*)0x4000E030)
#define UART_3_CTL (*(volatile unsigned int*)0x4000F030)
#define UART_4_CTL (*(volatile unsigned int*)0x40010030)
#define UART_5_CTL (*(volatile unsigned int*)0x40011030)
#define UART_6_CTL (*(volatile unsigned int*)0x40012030)
#define UART_7_CTL (*(volatile unsigned int*)0x40013030)

//UART Control registers
#define UART_0_CC (*(volatile unsigned int*)0x4000CFC8)
#define UART_1_CC (*(volatile unsigned int*)0x4000DFC8)
#define UART_2_CC (*(volatile unsigned int*)0x4000EFC8)
#define UART_3_CC (*(volatile unsigned int*)0x4000FFC8)
#define UART_4_CC (*(volatile unsigned int*)0x40010FC8)
#define UART_5_CC (*(volatile unsigned int*)0x40011FC8)
#define UART_6_CC (*(volatile unsigned int*)0x40012FC8)
#define UART_7_CC (*(volatile unsigned int*)0x40013FC8)

//_______________________I2C Registers______________________________

#define I2C_ENABLE (*(volatile unsigned int*)0x400FE620)

//i2c Master control register
#define I2C_0_MCR (*(volatile unsigned int*)0x40020020)
#define I2C_1_MCR (*(volatile unsigned int*)0x40021020)
#define I2C_2_MCR (*(volatile unsigned int*)0x40022020)
#define I2C_3_MCR (*(volatile unsigned int*)0x40023020)
#define I2C_4_MCR (*(volatile unsigned int*)0x400C0020)
#define I2C_5_MCR (*(volatile unsigned int*)0x400C1020)
#define I2C_6_MCR (*(volatile unsigned int*)0x400C2020)
#define I2C_7_MCR (*(volatile unsigned int*)0x400C3020)
#define I2C_8_MCR (*(volatile unsigned int*)0x400B8020)
#define I2C_9_MCR (*(volatile unsigned int*)0x400B9020)

//I2C Master Timer Period
#define I2C_0_MTPR (*(volatile unsigned int*)0x4002000C)
#define I2C_1_MTPR (*(volatile unsigned int*)0x4002100C)
#define I2C_2_MTPR (*(volatile unsigned int*)0x4002200C)
#define I2C_3_MTPR (*(volatile unsigned int*)0x4002300C)
#define I2C_4_MTPR (*(volatile unsigned int*)0x400C000C)
#define I2C_5_MTPR (*(volatile unsigned int*)0x400C100C)
#define I2C_6_MTPR (*(volatile unsigned int*)0x400C200C)
#define I2C_7_MTPR (*(volatile unsigned int*)0x400C300C)
#define I2C_8_MTPR (*(volatile unsigned int*)0x400B800C)
#define I2C_9_MTPR (*(volatile unsigned int*)0x400B900C)

//i2c Master slave address
#define I2C_0_MSA (*(volatile unsigned int*)0x40020000)
#define I2C_1_MSA (*(volatile unsigned int*)0x40021000)
#define I2C_2_MSA (*(volatile unsigned int*)0x40022000)
#define I2C_3_MSA (*(volatile unsigned int*)0x40023000)
#define I2C_4_MSA (*(volatile unsigned int*)0x400C0000)
#define I2C_5_MSA (*(volatile unsigned int*)0x400C1000)
#define I2C_6_MSA (*(volatile unsigned int*)0x400C2000)
#define I2C_7_MSA (*(volatile unsigned int*)0x400C3000)
#define I2C_8_MSA (*(volatile unsigned int*)0x400B8000)
#define I2C_9_MSA (*(volatile unsigned int*)0x400B9000)

//i2c Master Data transmit register
#define I2C_0_MDR (*(volatile unsigned int*)0x40020008)
#define I2C_1_MDR (*(volatile unsigned int*)0x40021008)
#define I2C_2_MDR (*(volatile unsigned int*)0x40022008)
#define I2C_3_MDR (*(volatile unsigned int*)0x40023008)
#define I2C_4_MDR (*(volatile unsigned int*)0x400C0008)
#define I2C_5_MDR (*(volatile unsigned int*)0x400C1008)
#define I2C_6_MDR (*(volatile unsigned int*)0x400C2008)
#define I2C_7_MDR (*(volatile unsigned int*)0x400C3008)
#define I2C_8_MDR (*(volatile unsigned int*)0x400B8008)
#define I2C_9_MDR (*(volatile unsigned int*)0x400B9008)

//i2c Master Data transmit register
#define I2C_0_MCS (*(volatile unsigned int*)0x40020004)
#define I2C_1_MCS (*(volatile unsigned int*)0x40021004)
#define I2C_2_MCS (*(volatile unsigned int*)0x40022004)
#define I2C_3_MCS (*(volatile unsigned int*)0x40023004)
#define I2C_4_MCS (*(volatile unsigned int*)0x400C0004)
#define I2C_5_MCS (*(volatile unsigned int*)0x400C1004)
#define I2C_6_MCS (*(volatile unsigned int*)0x400C2004)
#define I2C_7_MCS (*(volatile unsigned int*)0x400C3004)
#define I2C_8_MCS (*(volatile unsigned int*)0x400B8004)
#define I2C_9_MCS (*(volatile unsigned int*)0x400B9004)

#endif
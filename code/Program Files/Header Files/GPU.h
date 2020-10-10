/*
File: GPU.h
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the c file for declaring functions to enable and read
             GPU data using i2c protocol.
*/



#ifndef _GPU_H_
#define _GPU_H_

/*
* Function: i2cSend()
* Inputs: char - slaveAddress
          char - numData
          char* - data
* Outputs: N/A
* Description: This function sends one or multiple arguments to the specified
               slave address. 
*/
void i2cSend(char slaveAddress, char numData, char* data);

/*
* Function: i2cReceive()
* Inputs: char - slaveAddress
          char - numData
* Outputs: char* - dataRx
* Description: This function receives one or multiple arguments and saves them
               in a dynamic array.
*/
char* i2cReceive(char slaveAddress, char numData);

void i2c0Init(void);

void recordAccelRegisters(void);



#endif

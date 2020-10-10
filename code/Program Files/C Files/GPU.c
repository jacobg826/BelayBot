/*
File: GPU.c
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the c file for defining functions to enable and read
             GPU data using i2c protocol.
*/

#ifndef _GPU_C_
#define _GPU_C_

#include "TM4CREGISTERS.h"
#include "LEDs.h"
#include "GPU.h"
#include "Bluetooth.h"
#include <stdlib.h>

void i2c0Init(void)
{
   volatile unsigned char delay = 0;
   
   //Enable I2C 0
   I2C_ENABLE |= 0x1;
   
   delay++;
   delay++;
   
   //Enable GPIO port B
   GPIO_TOGGLE |= 0x2;
   
   delay++;
   delay++;
   
   //Select alternate function for port B2 and B3
   GPIO_AFSEL_B |= 0xC;
   //Select i2c alternate function
   GPIO_PCTL_B |= 0x200 | 0x2000;
   //sELECT OPEN DRAIN CONTROL REGISTER FOR PORT B3
   GPIO_ODR_B |= 0x8;
   //ENABlE DIGITAL FUNCTION PORT B3 and B2
   GPIO_DEN_B |= 0xC;
   
   //Initialize i2c Master
   I2C_0_MCR = 0x00000010;
   //Calaculation TPR value for SCL clock speed
   //TPR = (60000000/(2*(6+4)*100000)-1; == 29
   //Set SCL clock speed for 100 kbps
   I2C_0_MTPR |= 0x29;
   
   //create transmission array to turn off sleep mode
   char sleep[2] = {0x6B, 0x00};
   //open communication with MPU
   i2cSend(0xD0,2,sleep);
   
   //Create transmission array to configure accelerometer
   char accelerometerConfig[2] = {0x1C, 0x80};
   //configure accelerometer registers
   i2cSend(0xD0,2,accelerometerConfig);
   
   
}

void recordAccelRegisters(void)
{
   //create array with addreses of accelerometer registers
   char accelerometerReg[3] = {0x3B, 0x3C, 0x3D};
   //specify the register to be read
   i2cSend(0xD0,1,accelerometerReg);
   
   //Read the value from accelerometer
   char* accelerometerValX = i2cReceive(0xD0,1);
   
   //Send accelerometer x value to putty
   btSend(*accelerometerValX);
   
   //check if anything has been received
   if(*accelerometerValX != 0)
   {
      extLedOn(1);
   }
}

/*
* Function: i2cSend()
* Inputs: char - slaveAddress
          char - numData
          char* - data
* Outputs: N/A
* Description: This function sends one or multiple arguments to the specified
               slave address. 
*/
void i2cSend(char slaveAddress, char numData, char* data)
{
   //Protocol for sending one argument to slave address
   if(numData == 1)
   {
      //Specify slave address and Tx
      I2C_0_MSA = slaveAddress;
      //Write data to master data register
      I2C_0_MDR = *data;
      //transmit data and return to idle
      I2C_0_MCS = 0x07;
      //Check if address was acknowledged
      while(I2C_0_MCS & 0x4)
      {}
      //Check if data was acknowledged
      while(I2C_0_MCS & 0x8)
      {}
      //wait until transmission is complete
      while(I2C_0_MCS & 0x1)
      {}
      //check for any errors
      while(I2C_0_MCS & 0x2)
      {}
   }
   //Protocol for sending multiple arguments to the slave address
   else
   {
      //specify slave address and Tx
      I2C_0_MSA = slaveAddress;
      //Write data to master data register
      I2C_0_MDR = *data;
      //transmit data and maintain transmit state
      I2C_0_MCS = 0x03;
      //Check if address was acknowledged
      while(I2C_0_MCS & 0x4)
      {}
      //Check if data was acknowledged
      while(I2C_0_MCS & 0x8)
      {}
      //wait until transmission is complete
      while(I2C_0_MCS & 0x1)
      {}
      //check for any errors
      while(I2C_0_MCS & 0x2)
      {}
      //Continue sending data until all data is sent
      for(int i = 1; i < numData; i++)
      {
         //Write data to master data register
         I2C_0_MDR = *(data+i);
         //transmit data and maintain transmit state
         I2C_0_MCS = 0x01;
         //wait until transmission is complete
         while(I2C_0_MCS & 0x1)
         {}
         //check for any errors
         while(I2C_0_MCS & 0x2)
         {}
      }
      //Specify Last data
      I2C_0_MDR = *(data+(numData-1));
      //transmit data and return to idle state
      I2C_0_MCS = 0x05;
      //wait until transmission is complete
      while(I2C_0_MCS & 0x1)
      {}
      //check for any errors
      while(I2C_0_MCS & 0x2)
      {}
   }
}

/*
* Function: i2cReceive()
* Inputs: char - slaveAddress
          char - numData
* Outputs: char* - dataRx
* Description: This function receives one or multiple arguments and saves them
               in a dynamic array.
*/
char* i2cReceive(char slaveAddress, char numData)
{
   //create a dynamic array for 
   char *dataRx;
   dataRx = (char*)malloc(numData * 8);
   
   //Protocol for single receive
   if(numData == 1)
   {
      //Specify Slave address and Rx
      I2C_0_MSA = slaveAddress | 0x1;
      //receive data and return to idle state
      I2C_0_MCS = 0x07;
      //wait until transmission is complete
      while(I2C_0_MCS & 0x1)
      {}
      //check for any errors
      while(I2C_0_MCS & 0x2)
      {}
      //save Rx data to array
      //How do we know that the data register has the data ready
      *dataRx = I2C_0_MDR;
   }
   //Protocol for multiple receive
   else
   {
      //Specify Slave address and Rx
      I2C_0_MSA = slaveAddress | 0x1;
      //receive data and maintain receive state
      I2C_0_MCS = 0x0B;
      //wait until transmission is complete
      while(I2C_0_MCS & 0x1)
      {}
      //check for any errors
      while(I2C_0_MCS & 0x2)
      {}
      *dataRx = I2C_0_MDR;
      for(int i = 1; i < numData; i++)
      {
         //receive data and maintain receive state
         I2C_0_MCS = 0x09;
         //wait until transmission is complete
         while(I2C_0_MCS & 0x1)
         {}
         //check for any errors
         while(I2C_0_MCS & 0x2)
         {}
         *(dataRx + i) = I2C_0_MDR;
      }
      //receive data and maintain receive state
      I2C_0_MCS = 0x05;
      //wait until transmission is complete
      while(I2C_0_MCS & 0x1)
      {}
      //check for any errors
      while(I2C_0_MCS & 0x2)
      {}
      //save last received argument
      *(dataRx + numData - 1) = I2C_0_MDR;
   }
   return dataRx;
}


#endif
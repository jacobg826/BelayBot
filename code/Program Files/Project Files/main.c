/*
File: main.c
Author: Anton Soderqvist
Date: 7-17-2020
Description: This is the main file for implementing the i2c communication with
             the GPU
*/

#include "GPU.h"
#include "TM4CREGISTERS.h"
#include "LAB_3_Header.h"
#include "LAB_3_Driver.h"

int main()
{
   PLL_Init(PRESET2);
   bluetoothInit();
   i2c0Init();
   
   while(1)
   {
     for(int i = 0; i < 2000000;i++)
     {}
     recordAccelRegisters(); 
   }
   
   return 0;
}

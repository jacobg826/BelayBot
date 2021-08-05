# BelayHu
## EE 475 Capstone Project
#### Anton Soderqvist, Jacob Gervais, Nick Righi, Kushaun Kak, Kaijun Gao
### Where to watch the [Demo](https://www.youtube.com/watch?v=drQGYvJ-_U8&ab_channel=JacobGervais)
### Project Description:

This project utilizes a STM32 and a Raspberry Pi to create an embedded system that belays a climber as they ascend. 

The STM32 utilizes two accelerometers to monitor the speed at which the climber moves. These readings are then tranmitted via UART to the 
Raspberry Pi. 

The Raspberry Pi recieves this data and uses it to calculate the position of the climber relative to the bottom of the wall. From these calculations
the Raspberry Pi then controls a winch connected via GPIO pins. 

### Where to View The Code:

To view the code for the Raspberry Pi go to `BelayBot/BelayHuRasPi`

To view the code for the STM32 go to `BelayBot/BelayHuSTM/Core/Src` and `BelayBot/BelayHuSTM/Core/Inc` 



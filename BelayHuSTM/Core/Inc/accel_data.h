/*
 * accel_data.h
 *
 *  Created on: Jan 28, 2021
 *      Author: nicho
 */

#ifndef SRC_ACCEL_DATA_H_
#define SRC_ACCEL_DATA_H_

#define PACKET_HEADER 	0x0102030405


#include "main.h"


/*
 *	Struct that contains the accelerometer data
 */
struct accel_data{
	int16_t x_data;
	int16_t y_data;
	int16_t z_data;
};


/*
 *  Data packet that stores unique header, acceleration data, and a time stamp
 */
struct packet{
	char 		header[2];
	uint16_t	accel_data;
	uint16_t	time_stamp;
};


/*
 *	Reads back the elapsed time since the last read
 *
 *	params: none
 *
 *	return: elapsed time since last read
 */
uint16_t get_elapsed_time(TIM_HandleTypeDef* t);


/*
 *	Configures the accelerometer to start collecting data at 100Hz.
 *
 *	params:
 *			h:			spi hande to send data over
 *
 *	return: none
 */
void accel_setup(SPI_HandleTypeDef* h, TIM_HandleTypeDef* t);


/*
 * 	Blocking read of X,Y, and Z axis acceleration data from the accelerometer into the
 * 	specified accel_data struct. Polls the new data ready bit of the accelerometer until
 * 	new data is ready
 *
 * 	params:
 * 			h:		spi handle to send data over
 *
 * 			data	pointer to a accel_data struct. Reads data from the X,Y, and Z registers
 * 					into the struct
 *
 * return:	none
 */
void read_accel_data(SPI_HandleTypeDef* h, struct accel_data* data);


/*
 *  Sets up the i2c module to measure acceleration data with max values +/- 2g
 *
 *  params:
 *  		h:    i2c handle
 *
 * 	return:  none
 */
void setup_MPU(I2C_HandleTypeDef* h);


/*
 * Blocking read of X, Y, and Z axis acceleration data from the external accelerometer
 * into accel_data struct. HAL function is blocking until data is ready
 *
 * params:
 * 			h:    i2c handle
 * 			data: pointer to an accel_data struct
 *
 */
void read_data_i2c(I2C_HandleTypeDef* h, struct accel_data* data);

#endif /* SRC_ACCEL_DATA_H_ */

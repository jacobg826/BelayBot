/*
 *  Accelerometer data functions
 *  Team BelayHu
 */


#include "accel_data.h"
#include <string.h>
#include "printf.h"

#define READ 			0x80	//	The header that all read messages need to have

#define REG_SIZE		1		//	Number of bytes in a status register

#define	INFO1			0x0D
#define WHO_AM_I		0x0F	//	read to determine device ID number

#define NEW_DATA_MASK	0x8		//  Mask for reading new data bit from status register
#define STATUS_REG		0x27	//	read to determine if new data is available

#define CONTROL_REG_4	0x20	//	set on startup to start reading data
#define START_UP_SEQ	0x67	//	this value needs to be written to CONTROL_REG_4
								//	on startup to turn the device on and start reading from it
#define X_LOW_ADDR		0x28
#define X_HIGH_ADDR		0x29
#define Y_LOW_ADDR		0x2A
#define Y_HIGH_ADDR		0x2B
#define Z_LOW_ADDR		0x2C
#define Z_HIGH_ADDR		0x2D

#define CALIB_THRESHOLD 500

#define TIMER_SCALER	10				// number of ticks per ms

int16_t x_offset = 0;
int16_t y_offset = 0;
int16_t z_offset = 0;

int16_t x2_offset = 0;
int16_t y2_offset = 0;
int16_t z2_offset = 0;

uint16_t timer_val = 0;


/*
 * Returns the amount of elapsed time in ms as an unsigned 16 bit integer. Assumes that the
 * frequency of the passed clock handle is 10,000kHz. Currently setup using TIM6 with a pre-scaler
 * of 8400-1. Will suffer roll-over is timer isn't checked frequently enough
 *
 * 	params:
 * 			t:			handle to timer
 *
 * 	return:	amount of elapsed time, in ms, since the last call to this function.
 */
uint16_t get_elapsed_time(TIM_HandleTypeDef* t) {
	uint16_t new_value = __HAL_TIM_GET_COUNTER(t);
	uint16_t elapsed_time = (new_value - timer_val);
	timer_val = new_value;
	return elapsed_time;
}

/*
 * 	Writes the given data over the SPI line to the device
 *
 * 	params:
 * 			h:			spi handle to send data over
 *
 * 			data:		data to send to the accelerometer
 *
 * 			num:bytes:	number of bytes to send to the device
 *
 * 	return:	none
 */
void write_reg(SPI_HandleTypeDef* h, char* data, int num_bytes) {
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_SPI_Transmit(h, (unsigned char*)data, num_bytes, 100);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
}

/*
 * Reads the value from specified register address and stores the data in the structure
 * pointed to by store_data
 *
 * params:
 * 			h:			spi handle to send data over
 *
 * 			reg_addr:	register address to read from
 *
 * 			store_data:	pointer to character to store data in
 *
 * 			num_bytes:	the number of consecutive bytes to read. If num_bytes > 1 then
 * 						subsequent bytes are read from the next sequential address after
 * 						reg_addr
 *
 * 	return: none
 */
void read_reg(SPI_HandleTypeDef* h, int reg_addr, char* store_data, int num_bytes) {
	char data = READ | reg_addr;
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_SPI_Transmit(h, (unsigned char*)&data, REG_SIZE, 100);
	HAL_SPI_Receive(h, (unsigned char*)store_data, num_bytes, 100);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
}

/*
 * Sets up the accelerometer to read data at 100Hz.
 *
 * params:
 * 			h:			spi handle to send data over
 *
 *
 * 	return: none
 */
void accel_setup(SPI_HandleTypeDef* h, TIM_HandleTypeDef* t) {

	timer_val = __HAL_TIM_GET_COUNTER(t);

	char data[2];
	data[0] = CONTROL_REG_4;
	data[1] = START_UP_SEQ;
	write_reg(h, data, sizeof(data));

	//	calibrate the offset field of the accelerometer
	struct accel_data calibration_data;
	read_accel_data(h, &calibration_data);

	x_offset = -1*calibration_data.x_data;
	y_offset = -1*calibration_data.y_data;
	z_offset = -1*calibration_data.z_data;
}

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
void read_accel_data(SPI_HandleTypeDef* h, struct accel_data* data) {
	char data_ready = 0;
	read_reg(h, STATUS_REG, &data_ready, sizeof(data_ready));
	while (!(data_ready & NEW_DATA_MASK)) {
		read_reg(h, STATUS_REG, &data_ready, sizeof(data_ready));
	}
	// STM is little endian, so LOW_ADDR bit needs to be at the lower memory address,
	// which this setup does
	read_reg(h, X_LOW_ADDR, (char*)&data->x_data, sizeof(struct accel_data));
	data->x_data += x_offset;
	data->y_data += y_offset;
	data->z_data += z_offset;
}


/*
 * Reads x, y, z acceleration data from the MPU
 * 	  Params:
 * 	  	   h    - handle for the i2c
 *	       data - pointer to the acceleration data
 *	  return void
 */
void read_data_i2c (I2C_HandleTypeDef* h, struct accel_data* data) {
	uint8_t xlow, xhigh, ylow, yhigh, zlow, zhigh;
	int16_t mpuAddr = 0x68 << 1;
	HAL_StatusTypeDef ret;
	uint32_t delay = 100;

	ret = HAL_I2C_Mem_Read(h, mpuAddr, 0x3C, 1, &xlow, 1, delay); // X Accel
	ret = HAL_I2C_Mem_Read(h, mpuAddr, 0x3B, 1, &xhigh, 1, delay);

	ret = HAL_I2C_Mem_Read(h, mpuAddr, 0x3E, 1, &ylow, 1, delay); // Y Accel
	ret = HAL_I2C_Mem_Read(h, mpuAddr, 0x3D, 1, &yhigh, 1, delay);

	ret = HAL_I2C_Mem_Read(h, mpuAddr, 0x40, 1, &zlow, 1, delay); // Z Accel
	ret = HAL_I2C_Mem_Read(h, mpuAddr, 0x3F, 1, &zhigh, 1, delay);
	if (ret != HAL_OK) {
		printf("ERROR  RECIEVE\r\n");
	}

	// format data into 16 bit integer
	int16_t xdata = (((int16_t) xhigh << 8) | ( (int16_t) xlow));
	int16_t ydata = (((int16_t) yhigh << 8) | ( (int16_t) ylow));
	int16_t zdata = (((int16_t) zhigh << 8) | ( (int16_t) zlow));


	// correct for offset
	data->x_data = xdata + x2_offset;
	data->y_data = ydata + y2_offset;
	data->z_data = zdata + z2_offset;

}

/*
 * Set up the MPU accelerometer
 * Take out of sleep mode, configure gyro and accel upper limits
 *
 * 		h: I2C handle to communicate data
 */
void setup_MPU(I2C_HandleTypeDef* h) {
	int16_t mpuAddr = 0x68 << 1; // needs to be left shifted by 1

	HAL_StatusTypeDef ret;
	uint8_t zero = 0;
	uint32_t delay = 100;

	ret = HAL_I2C_Mem_Write(h, mpuAddr, 0x6B, 1, &zero, 1, delay); // take out of sleep mode
	if(ret != HAL_OK) {
		printf("ERROR CONFIG SLEEP MODE \n\r");
	}

	ret = HAL_I2C_Mem_Write(h, mpuAddr, 0x1B, 1, &zero, 1, delay); // set the gyro  to +- 250 deg
	if(ret != HAL_OK) {
		printf("ERROR CONFIG GYRO \n \r");
	}

	ret = HAL_I2C_Mem_Write(h, mpuAddr, 0x1C, 1, &zero, 1, delay); // set the accel to +- 2g
	if(ret != HAL_OK) {
		printf("ERROR CONFIG ACCEL \n \r");
	}

	HAL_Delay(500);

	//	calibrate the offset field of the accelerometer
	struct accel_data calibration_data;
	read_data_i2c(h, &calibration_data);

	x2_offset = -1*calibration_data.x_data;
	y2_offset = -1*calibration_data.y_data;
	z2_offset = -1*calibration_data.z_data;
}




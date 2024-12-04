#include "adxl345.h"




char data;
 uint8_t data_rec[6];

void adxl_read_address (uint8_t reg)
{
	 I2C1_byteRead( DEVICE_ADDR, reg, &data);

}

void adxl_write (uint8_t reg, char value)
{
	char data[1];
	data[0] = value;

	I2C1_burstWrite( DEVICE_ADDR, reg,1, data) ;
}

void adxl_read_values (uint8_t reg)
{
	I2C1_burstRead(DEVICE_ADDR, reg, 6,(char *)data_rec);

}


void adxl_init (void)
{
	I2C1_init();

	adxl_read_address(DEVID_R);
	adxl_write (DATA_FORMAT_R, FOUR_G);
	adxl_write (POWER_CTL_R, RESET);
	adxl_write (POWER_CTL_R, SET_MEASURE_B);
}

#include "adxl345.h"


#define   MULTI_BYTE_EN				0x40
#define	  READ_OPERATION		    0x80



void adxl_read(uint8_t address, uint8_t * rxdata){
	
	  address |= READ_OPERATION;
	  address |= MULTI_BYTE_EN;
	  cs_enable();
	  spi1_transmit(&address,1);
	  spi1_receive(rxdata,6);
	  cs_disable();
}

void adxl_write (uint8_t address, uint8_t value){
	
  uint8_t data[2];
  data[0] = address|MULTI_BYTE_EN;
  data[1] = value;
  cs_enable();
  spi1_transmit(data, 2);
  cs_disable();
}



void adxl_init (void){
	
	spi_gpio_init();
	spi1_config();
	adxl_write (DATA_FORMAT_R, FOUR_G);
	adxl_write (POWER_CTL_R, RESET);
	adxl_write (POWER_CTL_R, SET_MEASURE_B);
}

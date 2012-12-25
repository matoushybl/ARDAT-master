/*
 * slavecom.h
 *
 *  Created on: 23.12.2012
 *      Author: matous
 */

#ifndef SLAVECOM_H_
#define SLAVECOM_H_
#include "SPI.h"
#define sPORTB 1
#define sPORTC 2
#define sPORTD 3
#define sDDRB 4
#define sDDRC 5
#define sDDRD 6
#define sPINB 7
#define sPINC 8
#define sPIND 9
#define HIGH 1
#define LOW 0
void servo(int position){
	SPI_write(1);
	SPI_write(position);
}
int slave_analog_read(int channel){
	SPI_write(2);
	SPI_write(channel);
	return SPI_read();
}
void setPin(int reg,int number,int value){
	SPI_write(3);
	SPI_write(reg);
	SPI_write(number);
	SPI_write(value);

}
int readPin(int reg, int number){
	SPI_write(4);
	SPI_write(reg);
	SPI_write(number);
	return SPI_read();
}


#endif /* SLAVECOM_H_ */

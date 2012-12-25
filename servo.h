/*
 * servo.h
 *
 *  Created on: 1.10.2011
 *      Author: matous
 */

#ifndef SERVO_H_
#define SERVO_H_
#include "usart.h"
#include "SPI.h"
#define SERVO_CENTER 22
#define SERVO_MAX 39
#define SERVO_MIN 7
void servotest(){
	int data=SERVO_MIN;
	for(;;){
				if(readBit(PINA,PA7)==0){
					data++;
				}else if(readBit(PINA,PA6)==0){
					data--;
				}

				servo(data);
				LCDWriteInt(data,3);
				if(readBit(PINC,PC7)==0){
					LCDWriteStringXY(0,1,"prekazka");
							}
				_delay_ms(20);
				LCDClear();


		 }
}

#endif /* SERVO_H_ */

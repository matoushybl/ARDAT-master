/*
 * board.h
 *
 *  Created on: 6.9.2011
 *      Author: matous
 */

#ifndef BOARD_H_
#define BOARD_H_
#define  F_CPU 16000000UL
#include "lcd.h"
#define sbi(a,b) a|=b
#define readBit(a,b) ((a & (1 << b)) > 0)
#define cbi(a,b) a&=~b
#include "ADC.h"
#include "motor.h"
#include "SPI.h"
#include "slavecom.h"
#include "usart.h"


#endif /* BOARD_H_ */

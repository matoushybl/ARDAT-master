/*
 * motor.h
 *
 *  Created on: 6.9.2011
 *      Author: matous
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include <inttypes.h>

#endif /* MOTOR_H_ */
#define mot1_EN (1<<PD4)
#define mot2_EN (1<<PD5)
#define mot1_for (1<<PD6)
#define mot2_for (1<<PC2)
#define mot1_rev (1<<PC4)
#define mot2_rev (1<<PC3)

void mot_init(void){
	DDRD|=mot1_EN|mot2_EN|mot1_for;
		DDRC|=mot2_for|mot2_rev|mot1_rev;
}
void mot_pwm_init(void){

	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM10);
	TCCR1B|=(1<<WGM12)|(1<<CS11);
	ICR1=62;
}
void couvat_vlevo(){
	PORTD=mot1_EN|mot2_EN;
	PORTC=mot1_rev|mot2_rev;
	_delay_ms(1000);
	cbi(PORTC,mot1_EN);
	_delay_ms(500);
}
void motortest(){
PORTD|=mot1_EN|mot2_EN|mot1_for;
PORTC|=mot2_rev;
_delay_ms(1000);
cbi(PORTD,mot1_for);
cbi(PORTC,mot2_rev);
PORTC|=mot1_rev|mot2_for;
_delay_ms(1000);
PORTC=0x00;
}
void motpwmtest(){
	OCR1B=255;
	int16_t pln=0;
	mot_init();
	PORTD=mot1_for;
	PORTC=mot2_for;
	mot_pwm_init();
	for(;;){
	if(readBit(PINA,PA7)==0){
		pln++;
	}else if(readBit(PINA,PA6)==0){
	pln--;
	}
	OCR1A=pln;

	LCDWriteInt(pln,5);
	_delay_ms(5);
	LCDClear();
}}

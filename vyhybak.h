/*
 * vyhybak.h
 *
 *  Created on: 27.8.2011
 *      Author: matous
 */

#ifndef VYHYBAK_H_
#define VYHYBAK_H_
#include "servo.h"
void vyhybejse(void){
	init_usart();
	mot_init();
	int vlevo;
	int vpravo;

	_delay_ms(1000);
	for(;;){
		cbi(PORTD,mot1_for);
		PORTD=mot1_EN|mot2_EN;
			 if(!(readBit(PINA,PA7))){
				 sbi(PORTD,mot1_for);
				 sbi(PORTC,mot2_rev);
				 LCDWriteString("naraznik1");
				 loop_until_bit_is_set(PINA,PA7);
				 cbi(PORTD,mot1_for);
				 cbi(PORTC,mot2_rev);
			 	 }else{if(!(readBit(PINA,PA6))){
			 		 sbi(PORTC,mot2_for);
			 		sbi(PORTC,mot1_rev);
			 	 	LCDWriteString("naraznik2");
			 	 	loop_until_bit_is_set(PINA,PA6);
			 	 	cbi(PORTC,mot2_for);
			 		 }else{if(readBit(PINC,PC7)==0){
			 		 	LCDWriteString("prekazka vpredu");
			 		 	servo(15);
			 		 	_delay_ms(500);
			 		 		if(!readBit(PINC,PC7)){
			 		 			vlevo=1;
			 		 		}
			 		 		servo(29);
			 		 		_delay_ms(500);
			 		 		if(!readBit(PINC,PC7)){
			 		 			vpravo=1;
			 		 		}
			 		 		PORTC=mot1_rev|mot2_rev;
			 		 		_delay_ms(1000);
			 		 		if(vlevo==1){
			 		 		cbi(PORTC,mot2_rev);
			 		 		_delay_ms(500);}else if(vpravo==1){
			 		 			cbi(PORTC,mot1_rev);
			 		 			_delay_ms(500);
			 		 		}else{
			 		 			cbi(PORTC,mot1_rev);
			 		 			_delay_ms(500);
			 		 		}
			 		 		PORTC=0x00;
	 				 }else{

	 				 	LCDWriteString("nic");
	 				 	sbi(PORTD,mot1_for);
	 				 	sbi(PORTC,mot2_for);
		 				 }}
		 				 }
			 vlevo=0;
			 vpravo=0;
			 _delay_ms(1);
			 LCDClear();
			 PORTC=0x00;
			 servo(SERVO_CENTER);


		 }
}
#endif /* VYHYBAK_H_ */

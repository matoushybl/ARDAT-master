/*
 * line.h
 *
 *  Created on: 2.12.2011
 *      Author: matous
 */

#ifndef LINE_H_
#define LINE_H_
void test(){
	for(;;){
		LCDWriteInt(readADC(0),1);
		LCDWriteInt(readADC(1),1);
		LCDWriteInt(readADC(2),1);
		LCDWriteInt(readADC(3),1);
		LCDWriteInt(readADC(4),1);
		_delay_ms(20);
	LCDClear();
	}
}
void testline(){
	mot_init();
	PORTD=mot1_EN|mot2_EN;
	float sens[5];
	int nejvetsi=0;
	for(;;){
		nejvetsi=0;
		sens[0]=readADC(0);
		sens[1]=readADC(1);
		sens[2]=readADC(2);
		sens[3]=readADC(3);
		sens[4]=readADC(4);
		for(int i=0;i<5;i++){
			if(sens[i]>sens[nejvetsi]){
				nejvetsi=i;
			}

		}
		for(int i=0;i<5;i++){
			LCDWriteInt(sens[i],1);
		}

		switch(nejvetsi){
				case 0:
					sbi(PORTC,mot2_for);
					cbi(PORTD,mot1_for);
					break;
				case 1:
					sbi(PORTC,mot2_for);
					cbi(PORTD,mot1_for);
					break;
				case 2:
					sbi(PORTC,mot2_for);
					sbi(PORTD,mot1_for);
					break;
				case 3:
					cbi(PORTC,mot2_for);
					sbi(PORTD,mot1_for);
					break;
				case 4:
					cbi(PORTC,mot2_for);
					sbi(PORTD,mot1_for);
					break;
				default: cbi(PORTC,mot2_for);
						 sbi(PORTD,mot1_for);
						 break;
				}

		LCDClear();


	}
}




#endif /* LINE_H_ */

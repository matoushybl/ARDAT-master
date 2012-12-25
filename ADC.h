/*
 * ADC.h
 *
 *  Created on: 23.8.2011
 *      Author: matous
 */

#ifndef ADC_H_
#define ADC_H_


#endif /* ADC_H_ */


void ADC_init(){
	ADMUX|=(1<<REFS0);
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
float readADC(int ch)
{  float vysl;

   ADMUX= ADMUX |(ch & 0b00000111);
   ADCSRA|=(1<<ADSC);
   while(!(ADCSRA & (1<<ADIF)));
   ADCSRA|=(1<<ADIF);
  vysl=ADCW;
  vysl=vysl/1024;
  vysl=vysl*5;
  ADMUX=0;
  ADCSRA=0;
  ADC_init();
   return(vysl);
}

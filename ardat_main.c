#include <avr/io.h>
#include <util/delay.h>
#include "board.h"
#include "servo.h"
#include "vyhybak.h"
int command;
#include "lcdcommand.h"
#include "line.h"
int main (void){
	int res,temp;
	ADC_init();
	InitLCD(LS_ULINE);
	LCDClear();
	LCDWriteString("ARDAT 1.0");
	_delay_ms(2000);
	LCDClear();
	init_usart();
	mot_init();
	SPI_init();
	servo(22);
	for(;;){
			get_lcd_instructions();
			switch(command){
			case 0: vyhybejse();
				break;
			case 1: testline();
			break;
			case 2: motpwmtest();
				break;
			case 3: servotest();
				break;
			case 4: //free slot
				break;
			case 5: test();
			break;
			case 6: for(;;){res=readADC(7);
			temp=(res- 2.7325)*100;
				LCDWriteInt(temp,3);
			_delay_ms(20);
			LCDClear();}
			break;

			case 8:
				for(;;){
					LCDWriteString("Nejsem ONUR!!!");
					_delay_ms(20);
					LCDClear();
				}
			break;
			}

		}}

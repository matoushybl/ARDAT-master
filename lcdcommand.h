/*
 * lcdcommand.h
 *
 *  Created on: 26.10.2011
 *      Author: matous
 */
#include "board.h"
#ifndef LCDCOMMAND_H_
#define LCDCOMMAND_H_
void get_lcd_instructions(){
	while(readBit(PINC,PC7)==1){
		if(readBit(PINA,PA7)==0){
			command--;
			LCD_write_comm(command);
			_delay_ms(20);
			LCDClear();
			_delay_ms(300);
		}else if(readBit(PINA,PA6)==0){
			command++;
			LCD_write_comm(command);
			_delay_ms(20);
			LCDClear();
			_delay_ms(300);
		}
		LCD_write_comm(command);
		_delay_ms(20);
		LCDClear();

	}

}
void LCD_write_comm(int com){
	if(com==0){
		LCDWriteString("Vyhybani se ");
		LCDWriteStringXY(14,1,">>");
	}else if(com==1){
		LCDWriteString("Sleduj caru ");
		LCDWriteStringXY(14,1,">>");
		LCDWriteStringXY(0,1,"<<");
	}else if(com==2){
		LCDWriteString("Test- motoru");
		LCDWriteStringXY(14,1,">>");
		LCDWriteStringXY(0,1,"<<");
	}else if(com==3){
		LCDWriteString("Test- predni servo");
		LCDWriteStringXY(0,1,"<<");
		LCDWriteStringXY(14,1,">>");
	}else if(com==4){
		LCDWriteString("Test- zadni servo");
		LCDWriteStringXY(0,1,"<<");
		LCDWriteStringXY(14,1,">>");
	}else if(com==5){
		LCDWriteString("Test- sensor cary");
		LCDWriteStringXY(0,1,"<<");
		LCDWriteStringXY(14,1,">>");
	}else if(com==6){
		LCDWriteString("Teplota vzduchu");
		LCDWriteStringXY(0,1,"<<");
		LCDWriteStringXY(14,1,">>");

	}else if(com==7){
		LCDWriteString("istro-testing");
		LCDWriteStringXY(0,1,"<<");
		LCDWriteStringXY(14,1,">>");
	}else if(com==8){
		LCDWriteString("Predstav se");
		LCDWriteStringXY(0,1,"<<");
	}

}


#endif /* LCDCOMMAND_H_ */

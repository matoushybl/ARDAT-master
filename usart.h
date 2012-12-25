/*
 * usart.h
 *
 *  Created on: 4.10.2011
 *      Author: matous
 */

#ifndef USART_H_
#define USART_H_
void init_usart(){
	DDRD|=(1<<PD1);
	UBRRL = 6;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

}
void usart_send_int(int data)
	{
	while ( !( UCSRA & (1<<UDRE)) )
	;
	UDR = data;
	}
int usart_receive_int(){
	int data;
	while ( !(UCSRA & (1<<RXC)) );
	data=UDR;
	return data;
}


#endif /* USART_H_ */

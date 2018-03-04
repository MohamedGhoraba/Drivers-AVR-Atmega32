/*
 * usart.c
 *
 *  Created on: Jan 6, 2018
 *      Author: Mohamed
 */

#include "usart.h"

void USART_Init()
{
	UCSRA |= (1<<U2X);
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	UBRRH = 0;
	UBRRL = 12;
}

void USART_SendByte(uint8 data)
{
	while(Bit_Is_Clear(UCSRA,UDRE));
	UDR = data;
}

uint8 USART_ReceiveByte()
{
	while(Bit_Is_Clear(UCSRA,RXC));
	return UDR;
}

void USART_SendString(uint8 *str)
{
	while(*str != '\0')
	{
		USART_SendByte(*str);
		str++;
	}
}

void USART_ReceiveString(uint8 *str)
{
	uint8 i = 0;
	str[i] = USART_ReceiveByte();
	while(str[i] != '#')
	{
		i++;
		str[i] = USART_ReceiveByte();
	}
	str[i] = '\0';
}

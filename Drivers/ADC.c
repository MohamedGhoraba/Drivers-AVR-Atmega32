/*
 * ADC.c
 *
 *  Created on: Jan 13, 2018
 *      Author: Mohamed
 */
#include "ADC.h"

void ADC_Init()
{
	ADCSRA |= (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1);
	ADMUX = 0;
}

uint16 ADC_read(uint8 num_pin)
{
	ADMUX |= (num_pin & 0x1F);
	Set_Bit(ADCSRA,ADSC);
	while(Bit_Is_Clear(ADCSRA,ADIF));
	Set_Bit(ADCSRA,ADIF);
	return ADC;
}


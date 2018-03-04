/*
 * usart.h
 *
 *  Created on: Jan 6, 2018
 *      Author: Mohamed
 */

#ifndef USART_H_
#define USART_H_

#include "Micro_config.h"
#include "Common_Macros.h"
#include "Std_Types.h"

void USART_Init();
void USART_SendByte(uint8 data);
uint8 USART_ReceiveByte();
void USART_SendString(uint8 *str);
void USART_ReceiveString(uint8 *str);


#endif /* USART_H_ */

/*
 * SPI.h
 *
 *  Created on: Jan 14, 2018
 *      Author: Mohamed
 */

#ifndef SPI_H_
#define SPI_H_

#include "Micro_config.h"
#include "Common_Macros.h"
#include "Std_Types.h"

void SPI_ReceiveString(uint8 *str);
void SPI_SendString(uint8 *str);
uint8 SPI_ReceiveByte();
void SPI_SendByte(uint8 data);
void SPI_InitSlave();
void SPI_InitMaster();


#endif /* SPI_H_ */

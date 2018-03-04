/*
 * EEPROM.h
 *
 *  Created on: Jan 15, 2018
 *      Author: Mohamed
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"

#define ERROR 0
#define SUCCESS 1


void EEPROM_Init();
uint8 EEPROM_WriteByte(uint16 Addr,uint8 data);
uint8 EEPROM_ReadByte(uint16 Addr,uint8 *data);

#endif /* EEPROM_H_ */

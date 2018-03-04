/*
 * EEPROM.c
 *
 *  Created on: Jan 15, 2018
 *      Author: Mohamed
 */

#include "EEPROM.h"

void EEPROM_Init()
{
	I2C_Init();
}

uint8 EEPROM_WriteByte(uint16 Addr,uint8 data)
{
	I2C_Start();
	if(I2C_Status() != I2C_START)
		return ERROR;
	I2C_Write((uint8)(0xA0 | ((Addr & 0x0700) >> 7)));
	if(I2C_Status() != I2C_MT_SLA_W_ACK)
		return ERROR;
	I2C_Write((uint8)Addr);
	if(I2C_Status() != I2C_MT_DATA_ACK)
		return ERROR;
	I2C_Write(data);
	if(I2C_Status() != I2C_MT_DATA_ACK)
		return ERROR;
	I2C_Stop();

	return SUCCESS;
}

uint8 EEPROM_ReadByte(uint16 Addr,uint8 *data)
{
	I2C_Start();
	if(I2C_Status() != I2C_START)
		return ERROR;
	I2C_Write((uint8)(0xA0 | ((Addr & 0x0700) >> 7)));
	if(I2C_Status() != I2C_MT_SLA_W_ACK)
		return ERROR;
	I2C_Write((uint8)Addr);
	if(I2C_Status() != I2C_MT_DATA_ACK)
		return ERROR;
	I2C_Start();
	if(I2C_Status() != I2C_REP_START)
		return ERROR;
	I2C_Write((uint8)(0xA0 | ((Addr & 0x0700) >> 7) | 1));
	if(I2C_Status() != I2C_MT_SLA_R_ACK)
		return ERROR;
	*data = I2C_Read_NO_ACK();
	if(I2C_Status() != I2C_MR_DATA_NACK)
		return ERROR;
	I2C_Stop();

	return SUCCESS;
}

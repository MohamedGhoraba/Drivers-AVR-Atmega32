/*
 * LCD.c
 *
 *  Created on: Jan 9, 2018
 *      Author: Mohamed
 */
#include "LCD.h"

void LCD_Init()
{
	LCD_Data_Dir = 0xFF;
	LCD_Ctrl_Dir |= (1<<E) | (1<<W) | (1<<RS);
	LCD_SendCommand(Eight_Bit_Mode);
	LCD_SendCommand(CURSOR_OFF);
	LCD_SendCommand(CLEAR_COMMAND);
}

void LCD_SendCommand(uint8 data)
{
	Clear_Bit(LCD_Ctrl_Out,RS);
	Clear_Bit(LCD_Ctrl_Out,W);
	_delay_ms(1);
	Set_Bit(LCD_Ctrl_Out,E);
	_delay_ms(1);
	LCD_Data_Out = data;
	_delay_ms(1);
	Clear_Bit(LCD_Ctrl_Out,E);
	_delay_ms(1);
}

void LCD_SendCharacter(uint8 data)
{
	Set_Bit(LCD_Ctrl_Out,RS);
	Clear_Bit(LCD_Ctrl_Out,W);
	_delay_ms(1);
	Set_Bit(LCD_Ctrl_Out,E);
	_delay_ms(1);
	LCD_Data_Out = data;
	_delay_ms(1);
	Clear_Bit(LCD_Ctrl_Out,E);
	_delay_ms(1);
}

void LCD_SendString(uint8 *str)
{
	while(*str != '\0')
	{
		LCD_SendCharacter(*str);
		str++;
	}
}

void LCD_GoToRowCol(uint8 row, uint8 col)
{
	uint8 address;
	switch (row)
	{
		case 0:
			address = col;
			break;
		case 1:
			address = col + 0x40;
			break;
	}
	LCD_SendCommand(address | SET_CURSOR_LOCATION);
}

void LCD_SendStringRowCol(uint8 row, uint8 col, uint8 *str)
{
	LCD_GoToRowCol(row,col);
	LCD_SendString(str);
}

void LCD_IntegerToString(uint16 data)
{
	uint8 BUFF[16];
	itoa(data,BUFF,10);
	LCD_SendString(BUFF);
}

void LCD_ClearScreen()
{
	LCD_SendCommand(CLEAR_COMMAND);
}

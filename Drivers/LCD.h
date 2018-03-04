/*
 * LCD.h
 *
 *  Created on: Jan 9, 2018
 *      Author: Mohamed
 */

#ifndef LCD_H_
#define LCD_H_

#include "Micro_config.h"
#include "Common_Macros.h"
#include "Std_Types.h"

#define LCD_Data_Dir DDRC
#define LCD_Data_Out PORTC
#define LCD_Ctrl_Dir DDRD
#define LCD_Ctrl_Out PORTD

#define E PD4
#define W PD5
#define RS PD6

#define Eight_Bit_Mode 0x38
#define CLEAR_COMMAND 0x01
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

void LCD_Init();
void LCD_SendCommand(uint8 data);
void LCD_SendCharacter(uint8 data);
void LCD_SendString(uint8 *str);
void LCD_GoToRowCol(uint8 row, uint8 col);
void LCD_SendStringRowCol(uint8 row, uint8 col, uint8 *str);
void LCD_IntegerToString(uint16 data);
void LCD_ClearScreen();

#endif /* LCD_H_ */

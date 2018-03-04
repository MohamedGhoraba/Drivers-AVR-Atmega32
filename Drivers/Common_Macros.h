/*
 * Common_Macros.h
 *
 *  Created on: Jan 4, 2018
 *      Author: Mohamed
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define Set_Bit(REG,BIT) (REG |= (1<<BIT))
#define Clear_Bit(REG,BIT) (REG &= (~(1<<BIT)))
#define Toggle_Bit(REG,BIT) (REG ^= (1<<BIT))
#define ROR(REG,NUM) (REG = ((REG >> NUM) | (REG << (8-NUM))))
#define ROL(REG,NUM) (REG = ((REG << NUM) | (REG >> (8-NUM))))
#define Bit_Is_Set(REG,BIT) (REG & (1<<BIT))
#define Bit_Is_Clear(REG,BIT) (!(REG & (1<<BIT)))

#endif /* COMMON_MACROS_H_ */

/*
 * ADC.h
 *
 *  Created on: Jan 13, 2018
 *      Author: Mohamed
 */

#ifndef ADC_H_
#define ADC_H_

#include "Micro_config.h"
#include "Common_Macros.h"
#include "Std_Types.h"

void ADC_Init();
uint16 ADC_read(uint8 num_pin);

#endif /* ADC_H_ */

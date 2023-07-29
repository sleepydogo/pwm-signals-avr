/*
 * ADC.h
 *
 * Created: 28/7/2023 18:12:38
 *  Author: Usuario
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include "main.h"

void ADC_Init(void);

uint16_t ADC_Read(void);


#endif /* ADC_H_ */
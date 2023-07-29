/*
 * MEF.h
 *
 * Created: 28/7/2023 18:05:37
 *  Author: Usuario
 */ 


#ifndef MEF_H_
#define MEF_H_

#include <stdint.h>
#include "pwm_generator.h"
#include "ADC.h"
#include "main.h"
void MEF_Init(void);
void MEF_UPDATE();

#define RED		56
#define	GREEN	153
#define BLUE	255

typedef enum {
	PRENDIENDO, MAX, APAGANDO, OFF
} t_eSystem ;

#endif /* MEF_H_ */
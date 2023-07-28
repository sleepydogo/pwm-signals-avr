
#ifndef _MAIN_H
#define _MAIN_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "timer.h"
#include "pwm_generator.h"

typedef enum {
	PRENDIENDO, MAX, APAGANDO, OFF
} t_eSystem ;


void SET_MEF_FLAG(void);

#endif
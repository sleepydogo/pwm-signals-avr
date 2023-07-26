
#ifndef _MAIN_H
#define _MAIN_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

#define PWM_PERIOD	10
#define PWM_DELTA	5
#define PWM_OFF		PORTB &=~(1<<PORTB5)
#define PWM_ON		PORTB |=(1<<PORTB5)
#define PWM_START	DDRB |= (1<<PORTB1)+ (1<<PORTB2)+ (1<<PORTB5)

#endif
/*
 * timer.h
 *
 * Created: 24/07/2023 15:35:51
 *  Author: Mariano Rodriguez y Tomas Schattmann
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include "main.h"
#include "pwm_generator.h"

void TIMER0_Init();
void TIMER1_Init();



#endif /* TIMER_H_ */
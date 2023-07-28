/*
 * pwm_generator.h
 *
 * Created: 28/7/2023 19:51:13
 *  Author: Tom
 */ 


#ifndef PWM_GENERATOR_H_
#define PWM_GENERATOR_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define PWM_PERIOD	255
#define PWM_ON		PORTB &=~(1<<PORTB5)
#define PWM_OFF		PORTB |=(1<<PORTB5)
#define PORT_START	DDRB |= (1<<PORTB5) + (1<<PORTB1)+ (1<<PORTB2)


void PWM_INIT_OUTPUTS (void);
void PWM_SOFTWARE_UPDATE (void);
void PWM_CHANGE_DELTAS(uint8_t red, uint8_t green, uint8_t blue);

#endif /* PWM_GENERATOR_H_ */
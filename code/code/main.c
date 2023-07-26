/*
 * code.c
 *
 * Created: 26/7/2023 15:33:47
 * Author : Tom
 */ 

#include <avr/io.h>


#define PWM_PERIOD	100
#define PWM_DELTA	25
#define PWM_OFF		PORTB &=~(1<<PORTB0)
#define PWM_OFF		PORTB |=(1<<PORTB0)
#define PWM_START	DDR

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}


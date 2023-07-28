/*
 * code.c
 *
 * Created: 24/7/2023 15:33:47
 * Author : Tom
 */ 

// NOTE: OCR1A = blue ; OCR1B = green ; PWM_DELTA = red

#include "main.h"

int main(void)
{
	
	PWM_INIT_OUTPUTS();
	TIMER0_Init();
	TIMER1_Init();
	PWM_CHANGE_DELTAS(255,145,1);
	sei();
	while (1) {
		LED_MEF();
	}
}


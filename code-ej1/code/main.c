/*
 * code.c
 *
 * Created: 24/7/2023 15:33:47
 * Author : Tom
 */ 

// NOTE: OCR1A = blue ; OCR1B = green ; PWM_DELTA = red

#include "main.h"

static uint8_t MEF_flag = 0;
uint8_t MEF_cont = 0;

int main(void)
{
	
	TIMER0_Init();
	TIMER1_Init();
	MEF_Init();
	PWM_INIT_OUTPUTS();
	sei();
	while (1) {
		if (MEF_flag) {
			MEF_UPDATE();
			MEF_flag = 0;
		}
	}
}

ISR (TIMER0_COMPA_vect) {
	PWM_SOFTWARE_UPDATE();
	if (++ MEF_cont == 126) { // Cada 5ms se chequea la MEF
		MEF_flag = 1;
		MEF_cont = 0;
	}
}





/*
 * code.c
 *
 * Created: 24/7/2023 15:33:47
 * Author : Tom
 */ 

// OCR1A = blue ; OCR1B = green ; PWM_DELTA = red

#include "main.h"

/*
	Se inicializa en -1 para que cuando se ejecute por primera vez el PWM_SOFTWARE_UPDATE
	se ponga en alto la senial de salida.
*/

int main(void)
{
	
	PWM_INIT_OUTPUTS();
	TIMER0_Init();
	TIMER1_Init();
	PWM_CHANGE_DELTAS(255,145,1);
	sei();
	while (1);
}


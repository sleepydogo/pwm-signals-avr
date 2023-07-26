/*
 * code.c
 *
 * Created: 24/7/2023 15:33:47
 * Author : Tom
 */ 

#include "main.h"

/*
	Se inicializa en -1 para que cuando se ejecute por primera vez el PWM_SOFTWARE_UPDATE
	se ponga en alto la senial de salida.
*/
static uint8_t PWM_position = -1;

void PWM_SOFTWARE_UPDATE(void) {
	if (++PWM_position >= PWM_PERIOD) {
		PWM_position = 0;
		PWM_ON;
	} else {
		if (PWM_position < PWM_DELTA) {
			PWM_ON;
		}
		else {
			PWM_OFF;
		}
	}
}

int main(void)
{
	PWM_START;
	TIMER0_Init();
	TIMER1_Init();
	sei();
	while (1);
}


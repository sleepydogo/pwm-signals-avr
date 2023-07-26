/*
 * code.c
 *
 * Created: 24/7/2023 15:33:47
 * Author : Tom
 */ 

#include <avr/io.h>
#include <>

#define PWM_PERIOD	10
#define PWM_DELTA	3
#define PWM_OFF		PORTB &=~(1<<PORTB0)
#define PWM_ON		PORTB |=(1<<PORTB0)
#define PWM_START	DDRB |= (1<<PORTB0)


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
	
	while (1);
}


ISR (TIMER0_COMPA_vect) {
	PWM_SOFTWARE_UPDATE();
}


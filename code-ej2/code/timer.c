/*
 * timer.c
 *
 * Created: 24/07/2023 15:35:36
 *  Author: Mariano Rodriguez y Tomas Schattmann
 */ 

#include "timer.h"


//				Timer0
void TIMER0_Init(){
	OCR0A = 249;            //124 para 8MHz y 248 para 16MHz
	TCCR0A = (1<<WGM01);   // Modo CTC, clock interno, prescalador 64
	TCCR0B = (1<<CS01)|(1<<CS00);   // Modo CTC, clock interno, prescalador 64
	TIMSK0 = (1<<OCIE0A);   // Habilito Timer 0 en modo de interrupci�n de comparaci�n
}


//				Timer1
void TIMER1_Init(){
		
		// Modo Fast PWM de 8 bits (WGM1[3:0] = 5)
		// N -> 1024 
		TCCR1B |= (1<<WGM12)|(1<<CS12)|(1<<CS10);
		TCCR1A |= (1<<WGM10)|(1<<COM1A1)|(1<<COM1A0); // Para OC1A
		TCCR1A |= (1<<COM1B1)|(1<<COM1B0); // Para OC1B
		
		OCR1A = 10;	
		OCR1B = 200;
}

ISR (TIMER0_COMPA_vect) {
	PWM_SOFTWARE_UPDATE();
}

/*
 * timer.c
 *
 * Created: 24/07/2023 15:35:36
 *  Author: Mariano Rodriguez y Tomas Schattmann
 */ 

#include "timer.h"

static uint16_t mef_contador = 0;

//				Timer0	- interrupcion cada 39,4 us aprox
void TIMER0_Init(){
	OCR0A  = 78;            
	TCCR0A = (1<<WGM01);   // Modo CTC, clock interno, prescalador 8
	TCCR0B = (1<<CS01);   
	TIMSK0 = (1<<OCIE0A);   // Habilito Timer 0 en modo de interrupci�n de comparaci�n
}


//				Timer1
void TIMER1_Init(){
		
		// Modo Fast PWM de 8 bits (WGM1[3:0] = 5)
		// N -> 1024 
		TCCR1B |= (1<<WGM12)|(1<<CS12)|(1<<CS10);
		TCCR1A |= (1<<WGM10)|(1<<COM1A1)|(1<<COM1A0); // Para OC1A
		TCCR1A |= (1<<COM1B1)|(1<<COM1B0); // Para OC1B

		OCR1A = 255;			//blue
		OCR1B = 153;			//green
}

ISR (TIMER0_COMPA_vect) {
	PWM_SOFTWARE_UPDATE();
	if (++mef_contador == 126) {
		SET_MEF_FLAG();
		mef_contador = 0;
	}
}

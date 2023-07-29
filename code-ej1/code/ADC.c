/*
 * ADC.c
 *
 * Created: 28/7/2023 18:12:30
 *  Author: Usuario
 */ 

#include "ADC.h"

void ADC_Init(){
	
	DDRC &= ~(1 << PORTC3);
	
	// Configurar la referencia de voltaje del ADC a AVCC con ajuste a la izquierda
	ADMUX |= (0 << REFS1) | (1 << REFS0);
	ADMUX &= ~(1 << ADLAR);
	
	// Configurar el canal del ADC (ADC3 en este caso)
	ADMUX |= (0 << MUX3) | (0 << MUX2) | (1 << MUX1) | (1 << MUX0);
	
	// Habilitar el ADC y configurar el preescalador a 64
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
	
}


uint16_t ADC_Read(void){
	
	ADMUX &= 0xF0;
	ADMUX |= 0x03;
	
	ADCSRA |= (1 << ADSC);
	
	while ((ADCSRA & (1 << ADIF)) == 0);
	
	ADCSRA |= (1 << ADIF);
	
	uint8_t lowByte = ADCL;
	uint8_t highByte = ADCH;
	uint16_t valorADC = (highByte << 8) | lowByte;
	
	return valorADC;
	
}
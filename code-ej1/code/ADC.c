/*
 * ADC.c
 *
 * Created: 28/7/2023 18:12:30
 *  Author: Usuario
 */ 

#include "ADC.h"
uint8_t lowByte = 0;
uint8_t highByte = 0;
uint16_t valorLeido = 0;

void ADC_Init(){
	
	  // Configure ADC clock prescaler.
	  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	  // Enable ADC.
	  ADCSRA |= (1 << ADEN);

	  // Set ADC reference to AVCC.
	  ADMUX |= (1 << REFS0);

	  // Set ADC channel to 3.
	  ADMUX |= (1 << MUX0) | (1 << MUX1);
	
}


uint16_t ADC_Read(void){
	
	// Select ADC channel 3.
	ADMUX |= (1 << MUX0) | (1 << MUX1);

	// Start ADC conversion.
	ADCSRA |= (1 << ADSC);

	// Wait for conversion to complete.
	while (ADCSRA & (1 << ADSC));

	// Clear ADIF flag.
	ADCSRA |= (1 << ADIF);
	
	valorLeido = ADC;

	// Return ADC value.
	return valorLeido;
}
/*
 * MEF.c
 *
 * Created: 28/7/2023 18:05:28
 *  Author: Usuario
 */ 

#include "MEF.h"
static t_eSystem eSystem;
static uint8_t state_call_count;
uint16_t valorADC = 0;

void MEF_Init(){
	eSystem = PRENDIENDO;
	state_call_count = -1;
}

void MEF_UPDATE() {
	state_call_count++;
	
	switch (eSystem) {
		case PRENDIENDO:
		if (state_call_count < 10) {
			PWM_UPDATE_DELTAS((RED/10), (GREEN/10), (BLUE/10));
		} else {
			PWM_UPDATE_DELTAS((RED%10) , (GREEN%10), (BLUE%10));
			eSystem = MAX;
			state_call_count = -1;
		}
		break;
		case MAX:
		if (state_call_count == 20) {
			eSystem = APAGANDO;
			state_call_count = -1;
		}
		break;
		case APAGANDO:
		if (state_call_count < 10) {
			PWM_UPDATE_DELTAS(-(RED/10), -(GREEN/10), -(BLUE/10));
		} else {
			PWM_UPDATE_DELTAS(-RED%10, -GREEN%10, -BLUE%10);
			TIMER1_OFF();
			PORTB |= (1 << PORTB5);
			eSystem = OFF;
			state_call_count = -1;
		}
		break;
		case OFF:
		valorADC = ADC_Read();
		if (valorADC < 1000){
			if (state_call_count == 60) {
				TIMER1_ON();
				eSystem = PRENDIENDO;
				state_call_count = -1;
			}			
		}else{
			TIMER1_ON();
			eSystem = PRENDIENDO;
			state_call_count = -1;
		}	
		break;		
		}
		
}
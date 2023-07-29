/*
 * MEF.c
 *
 * Created: 28/7/2023 18:05:28
 *  Author: Usuario
 */ 

#include "MEF.h"
static t_eSystem eSystem;
static uint8_t state_call_count;

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
			PWM_UPDATE_DELTAS((RED%10), (GREEN%10), (BLUE%10));
			eSystem = MAX;
			state_call_count = -1;
		}
		break;
		case MAX:
		if (state_call_count < 20) {
			eSystem = APAGANDO;
			state_call_count = -1;
		}
		break;
		case APAGANDO:
		if (state_call_count < 10) {
			PWM_UPDATE_DELTAS(-(RED/10), -(GREEN/10), -(BLUE/10));
		} else {
			PWM_UPDATE_DELTAS(-RED%10 + 1, -GREEN%10 +1 , -BLUE%10 + 1);
			eSystem = OFF;
			state_call_count = -1;
		}
		break;
		case OFF:
		if (state_call_count < 20) {
			eSystem = PRENDIENDO;
			state_call_count = -1;
		}
		break;
	}
}
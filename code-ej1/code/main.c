/*
 * code.c
 *
 * Created: 24/7/2023 15:33:47
 * Author : Tom
 */ 

// NOTE: OCR1A = blue ; OCR1B = green ; PWM_DELTA = red

#include "main.h"


static t_eSystem eSystem = PRENDIENDO;
static uint8_t mef_flag = 0;
static uint8_t state_call_count = -1;

void SET_MEF_FLAG(void) {
	mef_flag = 1;
}

void MEF_UPDATE() {
	state_call_count++; 
	switch (eSystem) {
		case PRENDIENDO:
			if (state_call_count < 100) {
				PWM_UPDATE_DELTAS((151/100), (153/100), (255/100));
			} else {
				eSystem = MAX;
				state_call_count = -1;
			}
		break;
		case MAX:
			if (state_call_count < 600) {
				eSystem = APAGANDO;
				state_call_count = -1;
			}
		break;
		case APAGANDO:
			if (state_call_count < 100) {
				PWM_UPDATE_DELTAS(-(151/100), -(153/100), -(255/100));
				} else {
				PWM_CHANGE_DELTAS(1,1,1);
				eSystem = OFF;
				state_call_count = -1;
			}
		break;
		case OFF:
			if (state_call_count < 600) {
				eSystem = PRENDIENDO;
				state_call_count = -1;
			}
		break;
	}
}

int main(void)
{
	
	TIMER0_Init();
	TIMER1_Init();
	PWM_INIT_OUTPUTS();
	sei();
	while (1) {
		if (mef_flag) {
			MEF_UPDATE();
			mef_flag = 0;
		}
	}
}






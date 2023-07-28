/*
 * pwm_generator.c
 *
 * Created: 28/7/2023 19:50:52
 *  Author: Tom
 */ 

#include "pwm_generator.h"

static uint8_t delta_red = 1;
static uint8_t PWM_position = -1;

void PWM_INIT_OUTPUTS (void) {
	PORT_START;
}

void PWM_SOFTWARE_UPDATE(void) {
	if (++PWM_position >= PWM_PERIOD) {
		PWM_position = 0;
		PWM_OFF;
		} else {
		if (PWM_position < delta_red) {
			PWM_ON;
		}
		else {
			PWM_OFF;
		}
	}
}

void PWM_CHANGE_DELTAS(uint8_t red, uint8_t green, uint8_t blue) {
	delta_red = red;
	OCR1B = green;
	OCR1A = blue;
}

void PWM_UPDATE_DELTAS(int8_t red, int8_t green, int8_t blue) {
	delta_red += red;
	OCR1B += green;
	OCR1A += blue;
}
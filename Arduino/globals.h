#ifndef __GLOBALS_H
#define __GLOBALS_H

#include "hardware_def.h"
#include "ramp.h"
#include "button.h"

int SQ1, SQ2, SB1, SB2;

int M1_PWM, M1_DIR;
int M1_RAMP_IN;

int R1, R2;

int M1_SETP, M1_RATE;


int fsmState = 0;

ramp_t   m1Ramp;
button_t sb1Button;
button_t sb2Button;

void readInputs();
void control();
void writeOutputs();

#endif

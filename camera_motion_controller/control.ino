#include "globals.h"

void control() {
  int iTemp = 0;
  
  iTemp = map(R1, 0, 1023, 255, 0);
  M1_SETP = constrain(iTemp, 0, 255);
  
  iTemp = map(R2, 0, 1023, 25, 1);
  M1_RATE = constrain(iTemp, 1, 25);
  
  button_update(&sb1Button, SB1);
  button_update(&sb2Button, SB2);
  
  switch (fsmState) {
    case 0:
      if (SB1) {
        fsmState = 10;
        break;
      }
      
      M1_RAMP_IN = 0;
      M1_PWM = ramp_update(&m1Ramp, M1_RAMP_IN);
            
      break;

    case 10:
      if (sb2Button.out || SQ1) {
        fsmState = 20;
        break;
      }
      if (!SB1) {
        fsmState = 0;
        ramp_reset(&m1Ramp);        
        break;
      }
      
      M1_RAMP_IN = -1*M1_SETP;
      ramp_set_rate(&m1Ramp, M1_RATE);
      M1_PWM = ramp_update(&m1Ramp, M1_RAMP_IN);
      
      break;

    case 20:
      if (sb2Button.out || SQ2) {
        fsmState = 10;
        break;
      }
      if (!SB1) {
        fsmState = 0;
        ramp_reset(&m1Ramp);        
        break;
      }
      
      M1_RAMP_IN = M1_SETP;
      ramp_set_rate(&m1Ramp, M1_RATE);
      M1_PWM = ramp_update(&m1Ramp, M1_RAMP_IN);

      break;

    default:
      break;
  }
}

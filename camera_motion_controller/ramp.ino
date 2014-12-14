#include "ramp.h"

void ramp_reset(ramp_t* pramp) {
  pramp->out = pramp->in;  
}

void ramp_set_rate(ramp_t* pramp, int new_rate) {
  pramp->rate = new_rate;  
}

int ramp_update(ramp_t* pramp, int new_value) {
  int temp;
  
  pramp->in = new_value;
 
  if (pramp->out < pramp->in) {
    temp = pramp->out+pramp->rate;
    if (temp >= pramp->in) {
      pramp->out = pramp->in;
    } else {
      pramp->out = temp;    
    }
  }

  if (pramp->out > pramp->in) {
    temp = pramp->out-pramp->rate;
    if (temp <= pramp->in) {
      pramp->out = pramp->in;
    } else {
      pramp->out = temp;    
    }
  } 
  
  return pramp->out;
}


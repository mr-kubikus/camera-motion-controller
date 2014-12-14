#ifndef __RAMP_H
#define __RAMP_H

struct ramp_t{
  int in;
  int rate;
  int out;
};

void ramp_reset(ramp_t*);
void ramp_set_rate(ramp_t*, int);
int  ramp_update(ramp_t*, int);

#endif

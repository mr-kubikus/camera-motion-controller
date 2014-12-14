#ifndef __BUTTON_H
#define __BUTTON_H

struct button_t{
  int state;
  int in;
  int out;
  int counter;
};

void button_reset(button_t*);
int  button_update(button_t*, int);

#endif

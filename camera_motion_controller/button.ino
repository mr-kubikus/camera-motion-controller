#include "button.h"

void button_reset(button_t* pbutton) {
  pbutton->state = 0;
  pbutton->counter = 0;
  pbutton->in = 0;
  pbutton->out = 0;
}

int  button_update(button_t* pbutton, int new_value) {

  pbutton->in = new_value;

  switch (pbutton->state) {
    case 0:
    if (pbutton->in) {
      pbutton->state = 10;
      pbutton->counter = 0;
      break;
    }

    break;

  case 10:
    if (!pbutton->in) {
      pbutton->state = 0;
      break;
    }

    pbutton->counter++;
    
    if (pbutton->counter >= 3) {
      pbutton->state = 20;
      pbutton->out = 1;
      break;
    }
    
    break;

  case 20:
    pbutton->out = 0;
    if (!pbutton->in) {
      pbutton->state = 0;
      pbutton->counter = 0;
      pbutton->out = 0;
      break;
    }

    break;
  
  default:
    break;
  } 

  return (pbutton->out);

}

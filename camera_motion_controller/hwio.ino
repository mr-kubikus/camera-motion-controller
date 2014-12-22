#include "hardware_def.h"
#include "globals.h"

void readInputs() {
  // В текущем проекте используются путевые концевые выключатели с НЗ контактами
  // Если вы использует НР контакты, то тогда код для одного входа будет выглядеть так:
  // SQ1 = !digitalRead(SQ1_PIN);   
  SQ1 = digitalRead(SQ1_PIN);
  SQ2 = digitalRead(SQ2_PIN);
  SB1 = !digitalRead(SB1_PIN);
  SB2 = !digitalRead(SB2_PIN);

  R1 = analogRead(R1_PIN);
  R2 = analogRead(R2_PIN);  
}

void writeOutputs() {
  if (M1_PWM > 0) {
    analogWrite(M1_PWM_PIN, M1_PWM);
    digitalWrite(M1_DIR_PIN, MV_RIGHT);
  } else if (M1_PWM < 0){
    analogWrite(M1_PWM_PIN, -1*M1_PWM);
    digitalWrite(M1_DIR_PIN, MV_LEFT);  
  } else {
    analogWrite(M1_PWM_PIN, 0);
    digitalWrite(M1_DIR_PIN, MV_LEFT);  
  }
}

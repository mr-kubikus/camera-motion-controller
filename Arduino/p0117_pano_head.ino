#include "globals.h"

void setup() {
  //Настраиваем входы
  pinMode(SQ1_PIN, INPUT_PULLUP);
  pinMode(SQ2_PIN, INPUT_PULLUP);
  pinMode(SB1_PIN, INPUT_PULLUP);
  pinMode(SB2_PIN, INPUT_PULLUP);  
  
  //Настраиваем выходы
  pinMode(M1_PWM_PIN, OUTPUT);
  pinMode(M1_DIR_PIN, OUTPUT);  
  
  //Переводим выходы в исходное состояние
  analogWrite(M1_PWM_PIN, 0);
  digitalWrite(M1_DIR_PIN, MV_LEFT);
  
  //Инициализируем конечный автомат
  int fsmState = 0;
  
  //Инициализируем UART
  Serial.begin(19200);
  
  ramp_reset(&m1Ramp);
  button_reset(&sb1Button);
  button_reset(&sb2Button);  
}

void loop() {
  readInputs();
  control();
  writeOutputs();
 
  delay(20);
}

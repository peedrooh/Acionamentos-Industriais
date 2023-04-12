#include <Arduino.h>

#define BUTTON_01_PIN 17
#define BUTTON_02_PIN 18
#define CONTACTOR_01_PIN 7
#define CONTACTOR_02_PIN 11


void setup() {
  // Starting Serial
  Serial.begin(9600);
  // Starting button`s input mode
  pinMode(BUTTON_01_PIN, INPUT);
  pinMode(BUTTON_02_PIN, INPUT);

  // Starting contactor`s output mode
  pinMode(CONTACTOR_01_PIN, OUTPUT);
  pinMode(CONTACTOR_02_PIN, OUTPUT);
}

void loop() {

  if(digitalRead(BUTTON_01_PIN)) {
    Serial.println("Botão 1 apertado");
    delay(1000);
    digitalWrite(CONTACTOR_01_PIN, HIGH);
  } else {
    digitalWrite(CONTACTOR_01_PIN, LOW);
  }

  if(digitalRead(BUTTON_02_PIN)) {
    Serial.println("Botão 2 apertado");
    delay(1000);
    digitalWrite(CONTACTOR_02_PIN, HIGH);
  } else {
    digitalWrite(CONTACTOR_02_PIN, LOW);
  }
}
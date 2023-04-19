#include <Arduino.h>

#define BUTTON_01_PIN 16
#define BUTTON_02_PIN 19
#define BUTTON_03_PIN 17
#define CONTACTOR_01_PIN 7
#define CONTACTOR_02_PIN 11
#define CONTACTOR_03_PIN 4

bool turn_c01_on = false;
bool turn_c02_on = false;
bool turn_c03_on = false;

void setup() {
  // Starting Serial
  // Serial.begin(9600);

  // Starting button`s input mode
  pinMode(BUTTON_01_PIN, INPUT);
  pinMode(BUTTON_02_PIN, INPUT);
  pinMode(BUTTON_03_PIN, INPUT);

  // Starting contactor`s output mode
  pinMode(CONTACTOR_01_PIN, OUTPUT);
  pinMode(CONTACTOR_02_PIN, OUTPUT);
  pinMode(CONTACTOR_03_PIN, OUTPUT);
}

void loop() {

  // This section is responsible for toggling the contactor state when the corresponding button is pressed
  if(digitalRead(BUTTON_01_PIN)) {
    delay(200);
    turn_c01_on = !turn_c01_on;
  };
  
  if(digitalRead(BUTTON_02_PIN)) {
    delay(200);
    turn_c02_on = !turn_c02_on;
  };

  if(digitalRead(BUTTON_03_PIN)) {
    delay(200);
    turn_c03_on = !turn_c03_on;
  };

  // This section (de)activate the contactors based on their current state defined above
  if(!turn_c01_on) {
    digitalWrite(CONTACTOR_01_PIN, LOW);
  } else {
    digitalWrite(CONTACTOR_01_PIN, HIGH);
    // Serial.println("Botão 1 apertado");
    // delay(1000);
  }

  if(!turn_c02_on) {
    digitalWrite(CONTACTOR_02_PIN, LOW);
  } else {
    digitalWrite(CONTACTOR_02_PIN, HIGH);
    // Serial.println("Botão 2 apertado");
    // delay(1000);
  }

  if(!turn_c03_on) {
    digitalWrite(CONTACTOR_03_PIN, LOW);
  } else {
    digitalWrite(CONTACTOR_03_PIN, HIGH);
    // Serial.println("Botão 3 apertado");
    // delay(1000);
  }
}
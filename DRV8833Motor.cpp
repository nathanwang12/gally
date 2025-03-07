#include "DRV8833Motor.h"
#include <Arduino.h>

// Constructor
DRV8833Motor::DRV8833Motor(int AIN1, int AIN2, int BIN1, int BIN2) : pinAIN1(AIN1), pinAIN2(AIN2), pinBIN1(BIN1), pinBIN2(BIN2) {}

void DRV8833Motor::init() {
  ledcAttach(pinAIN1, 5000, 8);
  ledcAttach(pinBIN1, 5000, 8);

  pinMode(pinAIN2, OUTPUT);
  pinMode(pinBIN2, OUTPUT);

  digitalWrite(pinAIN2, LOW);
  digitalWrite(pinBIN2, LOW);
}

void DRV8833Motor::setSpeed(int speed) {
    speed = constrain(speed, 0, 255);
    ledcWrite(pinAIN1, speed);
    ledcWrite(pinBIN1, speed);
}


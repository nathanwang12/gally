#include "DRV8833Motor.h"
#include <Arduino.h>

// Constructor
DRV8833Motor::DRV8833Motor(int AIN1, int AIN2, int BIN1, int BIN2) : pinAIN1(AIN1), pinAIN2(AIN2), pinBIN1(BIN1), pinBIN2(BIN2) {}

void DRV8833Motor::init() {
    pinMode(pinAIN1, OUTPUT);
    pinMode(pinAIN2, OUTPUT);
    pinMode(pinBIN1, OUTPUT);
    pinMode(pinBIN2, OUTPUT);
}

void DRV8833Motor::set_speed(int speed) {
    speed = constrain(speed, 0, 255);
    analogWrite(pinAIN1, speed);
    digitalWrite(pinAIN2, LOW);
    analogWrite(pinBIN1, speed);
    digitalWrite(pinBIN2, LOW);
    Serial.print("Set motors PWM = ");
    Serial.println(speed);
}

void DRV8833Motor::stop() {
    digitalWrite(pinAIN1, LOW);
    digitalWrite(pinAIN2, LOW);
    digitalWrite(pinBIN1, LOW);
    digitalWrite(pinBIN2, LOW);
    Serial.print("stopping motor");
}

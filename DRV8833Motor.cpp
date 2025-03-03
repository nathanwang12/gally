#include "DRV8833Motor.h"

// Constructor
DRV8833Motor::DRV8833Motor(int AIN1, int AIN2) : pinAIN1(AIN1), pinAIN2(AIN2) {}

void DRV8833Motor::init() {
    pinMode(pinAIN1, OUTPUT);
    pinMode(pinAIN2, OUTPUT);
}

void DRV8833Motor::set_speed(int speed) {
    speed = constrain(speed, 0, 255);
    analogWrite(pinAIN1, speed);
    digitalWrite(pinAIN2, LOW);
    Serial.print("Set motor A PWM = ");
    Serial.println(speed);
}

void DRV8833Motor::stop() {
    digitalWrite(pinAIN1, LOW);
    digitalWrite(pinAIN2, LOW);
    Serial.print("stopping motor");
}
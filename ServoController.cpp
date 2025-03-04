#include "ServoController.h"

ServoController::ServoController(int pwmPin) : pwmPin(pwmPin) {}

void ServoController::init() {
  ESP32PWM::allocateTimer(0);
  myservo.setPeriodHertz(50);
  myservo.attach(pwmPin, 500, 2400);
}

void ServoController::left() {
  myservo.write(LEFT_POS);
}

void ServoController::forward() {
  myservo.write(FORWARD_POS);
}

void ServoController::right() {
  myservo.write(RIGHT_POS);
}
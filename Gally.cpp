#include "Gally.h"

Gally::Gally() : motor(MOTOR_AIN1, MOTOR_AIN2, MOTOR_BIN1, MOTOR_BIN2), servo(SERVO_PWM), sensors() {}

void Gally::init() {
  motor.init();
  servo.init();
  sensors.init();
}

void Gally::moveForward() {
  motor.setSpeed(100);
  delay(1000);
  motor.setSpeed(0);
}

void Gally::turnLeft() {
  servo.left();
  delay(500);
  motor.setSpeed(100);
  delay(500);
  motor.setSpeed(0);
  servo.forward();
}

void Gally::turnRight() {
  servo.right();
  delay(500);
  motor.setSpeed(100);
  delay(500);
  motor.setSpeed(0);
  servo.forward();
}

int Gally::getFrontDistance() {
  return sensors.front.getDistance();
}
int Gally::getRightDistance() {
  return sensors.right.getDistance();
}


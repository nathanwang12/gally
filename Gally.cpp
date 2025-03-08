#include "Gally.h"

Gally::Gally() : motor(MOTOR_AIN1, MOTOR_AIN2, MOTOR_BIN1, MOTOR_BIN2), servo(SERVO_PWM), sensors() {}

void Gally::init() {
  motor.init();
  servo.init();
  sensors.init();
}

void Gally::moveForward() {
  servo.forward();
  motor.setSpeed(150);
  delay(750);
  motor.setSpeed(0);
}

void Gally::stop() {
  motor.setSpeed(0);
}

void Gally::turnLeft() {
  servo.left();
  delay(500);
  motor.setSpeed(150);
  delay(850);
  motor.setSpeed(0);
  // servo.forward();
}

void Gally::turnRight() {
  servo.right();
  delay(500);
  motor.setSpeed(150);
  delay(850);
  motor.setSpeed(0);
  // servo.forward();
}

void Gally::straightenRight() {
  servo.halfRight();
  motor.setSpeed(150);
  delay(750);
  motor.setSpeed(0);
}

void Gally::straightenLeft() {
  servo.halfLeft();
  motor.setSpeed(150);
  delay(750);
  motor.setSpeed(0);
}

int Gally::getFrontDistance() {
  int discard1 = sensors.front.getDistance();
  int discard2 = sensors.front.getDistance();
  int discard3 = sensors.front.getDistance();
  return sensors.front.getDistance();
}
int Gally::getRight1Distance() {
  int discard1 = sensors.right1.getDistance();
  int discard2 = sensors.right1.getDistance();
  int discard3 = sensors.right1.getDistance();
  return sensors.right1.getDistance();
}
int Gally::getRight2Distance() {
  int discard1 = sensors.right2.getDistance();
  int discard2 = sensors.right2.getDistance();
  int discard3 = sensors.right2.getDistance();
  return sensors.right2.getDistance();
}


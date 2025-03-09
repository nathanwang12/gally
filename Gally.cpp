#include "Gally.h"

Gally::Gally() : motor(MOTOR_AIN1, MOTOR_AIN2, MOTOR_BIN1, MOTOR_BIN2), servo(SERVO_PWM), sensors(), stopped(1) {}

void Gally::init() {
  motor.init();
  servo.init();
  sensors.init();
}

void Gally::moveForward() {
  // stopped = 0;
  servo.forward();
  delay(500);
  motor.setSpeed(MOTOR_SPEED);
  delay(750);
  motor.setSpeed(0);
}

void Gally::inchForward() {
  servo.forward();
  delay(500);
  motor.setSpeed(MOTOR_SPEED);
  delay(750);
  motor.setSpeed(0);
}

void Gally::stop() {
  stopped = 1;
  motor.setSpeed(0);
}

void Gally::turnLeft() {
  servo.left();
  delay(500);
  motor.setSpeed(MOTOR_SPEED);
  delay(TURN_TIME);
  motor.setSpeed(0);
  // servo.forward();
}

void Gally::turnRight() {
  servo.right();
  delay(500);
  motor.setSpeed(MOTOR_SPEED);
  delay(TURN_TIME);
  motor.setSpeed(0);
  // servo.forward();
}

void Gally::straightenRight() {
  servo.slightRight();
  delay(500);
  motor.setSpeed(MOTOR_SPEED);
  delay(750);
  motor.setSpeed(0);
}

void Gally::straightenLeft() {
  servo.slightLeft();
  delay(500);
  motor.setSpeed(MOTOR_SPEED);
  delay(750);
  motor.setSpeed(0);
}

int Gally::isStopped() {
  return stopped;
}


int Gally::getFront1Distance() {
  int discard1 = sensors.front1.getDistance();
  int discard2 = sensors.front1.getDistance();
  int discard3 = sensors.front1.getDistance();
  int discard4 = sensors.front1.getDistance();
  return sensors.front1.getDistance();
}
int Gally::getFront2Distance() {
  int discard1 = sensors.front2.getDistance();
  int discard2 = sensors.front2.getDistance();
  int discard3 = sensors.front2.getDistance();
  int discard4 = sensors.front2.getDistance();
  return sensors.front2.getDistance();
}
int Gally::getRight1Distance() {
  int discard1 = sensors.right1.getDistance();
  int discard2 = sensors.right1.getDistance();
  int discard3 = sensors.right1.getDistance();
  int discard4 = sensors.right1.getDistance();
  return sensors.right1.getDistance();
}
int Gally::getRight2Distance() {
  int discard1 = sensors.right2.getDistance();
  int discard2 = sensors.right2.getDistance();
  int discard4 = sensors.right2.getDistance();
  return sensors.right2.getDistance();
}


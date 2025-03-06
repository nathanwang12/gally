#include "Gally.h"

Gally::Gally() : motor(MOTOR_AIN1, MOTOR_AIN2), servo(SERVO_PWM), sensors() {}

void Gally::init() {
  motor.init();
  servo.init();
  sensors.init();
}

void Gally::moveForward() {
  Serial.println("Gally moving forward");
  motor.setSpeed(100);
  delay(1000);
  motor.stop();
}

void Gally::turnLeft() {
  Serial.println("Gally turning left");
  servo.left();
  delay(500);
  motor.setSpeed(100);
  delay(500);
  motor.stop();
  servo.forward();
}

void Gally::turnRight() {
  Serial.println("Gally turning right");
  servo.right();
  delay(500);
  motor.setSpeed(100);
  delay(500);
  motor.stop();
  servo.forward();
}

int Gally::getFrontDistance() {
  return sensors.front.getDistance();
}
int Gally::getRightDistance() {
  return sensors.right.getDistance();
}


#include "Gally.h"

Gally::Gally() : motor(MOTOR_AIN1, MOTOR_AIN2), servo(SERVO_PWM) {}

void Gally::init() {
  motor.init();
  servo.init();
}

void Gally::moveForward() {
  Serial.println("Gally moving forward");
  motor.set_speed(100);
}

void Gally::turnLeft() {
  servo.left();

  // Serial.println("Gally turning left");
  // motor.stop();
  // servo.left();
  // motor.set_speed(75);
  // delay(TURN_TIME);
  // motor.stop();
  // servo.forward();
}

void Gally::turnRight() {
  servo.right();

  Serial.println("Gally turning right");
  motor.stop();
  servo.right();
  motor.set_speed(75);
  delay(TURN_TIME);
  motor.stop();
  servo.forward();
}


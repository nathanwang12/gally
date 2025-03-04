#include "Gally.h"

Gally::Gally() : motor(MOTOR_AIN1, MOTOR_AIN2), servo(SERVO_PWM), sensors() {}

void Gally::init() {
  motor.init();
  servo.init();
  sensors.init();
}

void Gally::moveForward() {
  Serial.println("Gally moving forward");
  servo.forward();

  // Serial.println("Gally moving forward");
  // // motor.set_speed(200);
  // digitalWrite(motor.pinAIN1, HIGH);
  // digitalWrite(motor.pinAIN2, LOW);
}

void Gally::turnLeft() {
  Serial.println("Gally turning left");
  servo.left();

  // Serial.println("Gally turning left");
  // motor.stop();
  // servo.left();
  // delay(TURN_TIME);
  // // motor.set_speed(200);
  // digitalWrite(motor.pinAIN1, HIGH);
  // digitalWrite(motor.pinAIN2, LOW);
  // delay(TURN_TIME);
  // motor.stop();
  // servo.forward();
}

void Gally::turnRight() {
  Serial.println("Gally turning right");
  servo.right();

  // Serial.println("Gally turning right");
  // motor.stop();
  // servo.right();
  // delay(TURN_TIME);
  // // motor.set_speed(200);
  // digitalWrite(motor.pinAIN1, HIGH);
  // digitalWrite(motor.pinAIN2, LOW);
  // delay(TURN_TIME);
  // motor.stop();
  // servo.forward();
}

int Gally::getFrontDistance() {
  return sensors.front.getDistance();
}
int Gally::getRightDistance() {
  return sensors.right.getDistance();
}


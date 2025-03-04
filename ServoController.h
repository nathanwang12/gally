#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <ESP32Servo.h>

class ServoController {
private:
    Servo myservo;
    int pwmPin;

    const int LEFT_POS = 45;
    const int FORWARD_POS = 90;
    const int RIGHT_POS = 135;

public:
    ServoController(int pwmPin);
    void init();
    void left();
    void forward();
    void right();
};

#endif
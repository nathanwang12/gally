#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <ESP32Servo.h>

class ServoController {
private:
    Servo myservo;
    int pwmPin;

    const int LEFT_POS = 40;
    const int HALF_LEFT = 74;
    const int FORWARD_POS = 83;
    const int HALF_RIGHT = 92;
    const int RIGHT_POS = 126;

public:
    ServoController(int pwmPin);
    void init();
    void left();
    void forward();
    void right();
    void halfLeft();
    void halfRight();
};

#endif
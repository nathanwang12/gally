#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <ESP32Servo.h>

class ServoController {
private:
    Servo myservo;
    int pwmPin;

    const int LEFT_POS = 3;
    const int FORWARD_POS = 93;
    const int RIGHT_POS = 180;

public:
    ServoController(int pwmPin);
    void init();
    void left();
    void forward();
    void right();
};

#endif
#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <ESP32Servo.h>

class ServoController {
private:
    Servo myservo;
    int pwmPin;

    const int LEFT_POS = 44;
    const int SLIGHT_LEFT = 78;
    const int FORWARD_POS = 87;
    const int SLIGHT_RIGHT = 96;
    const int RIGHT_POS = 130;

public:
    ServoController(int pwmPin);
    void init();
    void left();
    void forward();
    void right();
    void slightLeft();
    void slightRight();
};

#endif
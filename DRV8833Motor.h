#ifndef DRV8833MOTOR_H
#define DRV8833MOTOR_H

#include <Arduino.h>

class DRV8833Motor {
public:
    int pinAIN1;
    int pinAIN2;

    // Constructor
    DRV8833Motor(int AIN1, int AIN2);
    
    void init();
    void set_speed(int speed);
    void stop();
};

#endif
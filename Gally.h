#ifndef GALLY_H
#define GALLY_H

#include "DRV8833Motor.h"
#include "ServoController.h"
#include "Sensors.h"

#define SERVO_PWM 13
#define MOTOR_AIN1 4
#define MOTOR_AIN2 5
#define TURN_TIME 2000

class Gally {
  public:
    Gally();

    void init();
    void moveForward();
    void turnLeft();
    void turnRight();
    int getFrontDistance();
    int getRightDistance();

  private:
    DRV8833Motor motor;
    ServoController servo;
    Sensors sensors;
};

#endif 


#ifndef GALLY_H
#define GALLY_H

#include "DRV8833Motor.h"
#include "ServoController.h"
#include "Sensors.h"

#define SERVO_PWM 13
#define MOTOR_AIN1 15
#define MOTOR_AIN2 33
#define MOTOR_BIN1 12
#define MOTOR_BIN2 27
#define TURN_TIME 1000
#define MOTOR_SPEED 120

class Gally {
  public:
    Gally();

    void init();
    void moveForward();
    void stop();
    void turnLeft();
    void turnRight();
    void straightenRight();
    void straightenLeft();
    void inchForward();
    int isStopped();
    int getFront1Distance();
    int getFront2Distance();
    int getRight1Distance();
    int getRight2Distance();

  private:
    DRV8833Motor motor;
    ServoController servo;
    Sensors sensors;

    int stopped;
};

#endif 


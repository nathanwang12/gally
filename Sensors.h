#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <Wire.h>
#include <vl53l4cx_class.h>

#define DEV_I2C Wire

class DistanceSensor {
public:
    VL53L4CX sensor;
    int xshutPin;
    uint8_t i2cAddress;

    DistanceSensor(int xshutPin, uint8_t i2cAddress);
    void init();
    int getDistance();
};

class Sensors {
public:
    DistanceSensor front;
    DistanceSensor right1;
    DistanceSensor right2;

    Sensors();
    void init();
};

#endif

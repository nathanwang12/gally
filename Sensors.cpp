#include "Sensors.h"

DistanceSensor::DistanceSensor(int xshutPin, uint8_t i2cAddress)
  : sensor(&DEV_I2C, xshutPin), xshutPin(xshutPin), i2cAddress(i2cAddress) {}

void DistanceSensor::init() {
  pinMode(xshutPin, OUTPUT);
  digitalWrite(xshutPin, LOW);
  delay(10);
  digitalWrite(xshutPin, HIGH);
  delay(10);

  sensor.VL53L4CX_WaitDeviceBooted();
  sensor.begin();
  sensor.InitSensor(i2cAddress);
  sensor.VL53L4CX_StartMeasurement();
}

int DistanceSensor::getDistance() {
  VL53L4CX_MultiRangingData_t MultiRangingData;
  int status = sensor.VL53L4CX_WaitMeasurementDataReady();
  if (status) return -1;
  sensor.VL53L4CX_GetMultiRangingData(&MultiRangingData);
  sensor.VL53L4CX_ClearInterruptAndStartMeasurement();
  return MultiRangingData.RangeData[0].RangeMilliMeter;
}

Sensors::Sensors()
  : front(A0, 0x12), right(A1, 0x14) {}

void Sensors::init() {
  DEV_I2C.begin();
  front.init();
  right.init();
}

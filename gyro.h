#ifndef GYRO_H
#define GYRO_H

#include <MPU6500_WE.h>

#define MPU6500_ADDR 0x68

extern TwoWire Wire1;
extern MPU6500_WE myMPU6500;

// Function to initialize the MPU6500 gyroscope
void gyroinit();

// Function to read values from the MPU6500 gyroscope
void gyroreading();

#endif // GYRO_H
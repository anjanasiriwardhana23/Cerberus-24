#ifndef TOFCONFIG_H
#define TOFCONFIG_H

#include <Arduino.h>
#include <Wire.h>
#include <VL6180X.h>
#include "indication.h"

// Declare sensor objects globally
extern VL6180X sensor1;
extern VL6180X sensor2;
extern VL6180X sensor3;
extern VL6180X sensor4;
extern VL6180X sensor5;

extern int elapsedTime;  // Renamed from 'time' to 'elapsedTime'
extern int xk;
extern int yk;
extern int frontWallAvailable;
extern int rightWallAvailable;
extern int leftWallAvailable;
extern bool frontWallState;  // Renamed from 'F' to 'frontWallState'
extern bool leftWallState;   // Renamed from 'L' to 'leftWallState'
extern bool rightWallState;  // Renamed from 'R' to 'rightWallState'

extern int tof[5];

#define T1_L 29  // Control pin for PCA9517 to power sensor 1
#define T2_LF 28 // Control pin for PCA9517 to power sensor 2
#define T3_F 24
#define T4_RF 23
#define T5_R 22

const uint8_t SENSOR1_ADDRESS = 0x30; // New I2C address for sensor 1
const uint8_t SENSOR2_ADDRESS = 0x31; // New I2C address for sensor 2
const uint8_t SENSOR3_ADDRESS = 0x32; 
const uint8_t SENSOR4_ADDRESS = 0x33; 
const uint8_t SENSOR5_ADDRESS = 0x34; 

void initializeSensor(VL6180X &sensor, uint8_t address);
void powerOnSensor(int pin);
void powerOffSensors();
void addresschange();
void tofPid();
void tofStart();
void printTof();
void printWallState();
void powerallSensors();
void checkWallsCell();
void toffront();
void cerberusstart();

#endif // TOFCONFIG_H

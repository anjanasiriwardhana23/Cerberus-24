#ifndef WALLPID_H
#define WALLPID_H

#include "tofconfig.h"

// Declare encoder-related variables as extern
extern long leftEncoder;
extern long rightEncoder;
extern int encoderError;
extern int encoderLastError;
extern float encoderCorrection;
extern float encoderP;
extern float encoderD;
extern int leftEncoderPin;
extern int rightEncoderPin;

extern float leftP;
extern float leftD;

extern float leftError;
extern float leftLastError;
extern float leftDiff;
extern float correction;

extern float rightP;
extern float rightD;

extern float rightError;
extern float rightLastError;
extern float rightDiff;

extern float wallP;
extern float wallD; 

extern float wallError;
extern float wallLastError;
extern float wallDiff;

extern int jump;
extern int preState;
extern int selectMode;

extern int state;

void initencoders();
void handleLeftEncoder();  // Interrupt handler for left encoder
void handleRightEncoder(); // Interrupt handler for right encoder

// Function prototype for encoder PID control
void encoderPid();
void leftPid();
void rightPid();
void wallPid();
void wallFollow();
#endif
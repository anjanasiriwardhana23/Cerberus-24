#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

// Pin definitions
#define PWM_FREQ 10000 // PWM frequency in Hz

// Enable pin
#define ENABLE_PIN 7

// Declare variables as extern, meaning they are defined elsewhere
extern int rightBase;
extern int leftBase;
extern int rightBase1;
extern int leftBase1;
extern int leftPwm;
extern int rightPwm;

// Channel A (Motor A) pins
#define INA1 5
#define INA2 4
#define PWMA 6

// Channel B (Motor B) pins
#define INB1 9
#define INB2 10
#define PWMB 8

// Function prototypes
void initMotors();
void forward_m(int speed);
void backward_m(int speed);
void turnleft_m(int speed);
void turnright_m(int speed);
void shortbreak_m();
void hardbreak_m();
// new
void stbyHigh();
void stbyLow();
void leftForward();
void leftReverse();
void leftBrake();
void leftForwardBase();
void leftReverseBase();
void rightForward();
void rightReverse();
void rightBrake();
void rightForwardBase();
void rightReverseBase();
void writePwm();
void writeBasePwm();
void forward();
void reverse();
void brake();
void brakeNo();
void forwardBase();
void reverseBase();
void turnRight();
void turnLeft();
void softbreak();


#endif

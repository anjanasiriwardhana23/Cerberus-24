#include "motor.h"
#include "wallpid.h"

// Define the variables here
int rightBase = 128; //128
int leftBase = 130; //133
int rightBase1 = 128; //128
int leftBase1 = 136; //136
int leftPwm = 0;
int rightPwm = 0;

// Initialize motor control pins
void initMotors() {
    // Enable pin
    pinMode(ENABLE_PIN, OUTPUT);
    
    // Channel A pins
    pinMode(INA1, OUTPUT);
    pinMode(INA2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    // Channel B pins
    pinMode(INB1, OUTPUT);
    pinMode(INB2, OUTPUT);
    pinMode(PWMB, OUTPUT);

    // Start with motors off
    digitalWrite(ENABLE_PIN, LOW);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
}

void stbyHigh()
{
    digitalWrite(ENABLE_PIN, HIGH);
}

void softbreak(){
    analogWrite(PWMA,0);
    analogWrite(PWMB,0);

}

void stbyLow()
{
    digitalWrite(ENABLE_PIN, LOW);
}

void leftForward()
{
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, LOW);
}

void leftReverse()
{
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);
}

void leftBrake()
{
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, HIGH);
}

void leftForwardBase()
{
    stbyHigh();
    leftForward();
    analogWrite(PWMA, leftBase);
}

void leftReverseBase()
{
    stbyHigh();
    leftReverse();
    analogWrite(PWMA, leftBase);
}

void rightForward()
{
    digitalWrite(INB1, HIGH);
    digitalWrite(INB2, LOW);
}

void rightReverse()
{
    digitalWrite(INB1, LOW);
    digitalWrite(INB2, HIGH);
}

void rightBrake()
{
    digitalWrite(INB1, HIGH);
    digitalWrite(INB2, HIGH);
}

void rightForwardBase()
{
    stbyHigh();
    rightForward();
    analogWrite(PWMB, rightBase);
}

void rightReverseBase()
{
    stbyHigh();
    rightReverse();
    analogWrite(PWMB, rightBase);
}

void writePwm()
{
    analogWrite(PWMA, leftPwm);
    analogWrite(PWMB, rightPwm);
}

void writeBasePwm()
{
    analogWrite(PWMA, leftBase);
    analogWrite(PWMB, rightBase);
}

void forward()
{
    stbyHigh();
    leftForward();
    rightForward();
    writePwm();
}

void reverse()
{
    stbyHigh();
    leftReverse();
    rightReverse();
    writePwm();
}

void brake()
{
    stbyHigh();
    leftBrake();
    rightBrake();
    delay(100);
}

void brakeNo()
{
    stbyHigh();
    leftBrake();
    rightBrake();
    //delay(100);
}

void forwardBase()
{
    stbyHigh();
    leftForward();
    rightForward();
    writeBasePwm();
}

void reverseBase()
{
    stbyHigh();
    leftReverse();
    rightReverse();
    writeBasePwm();
}

void turnRight()
{
    stbyHigh();
    leftForward();
    rightReverse();
    writeBasePwm();
}

void turnLeft()
{
    stbyHigh();
    leftReverse();
    rightForward();
    writeBasePwm();
}

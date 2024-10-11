#include "motor.h"
#include "tofconfig.h"

// Define the GPIO pins for the encoders
const int leftEncoderPin = 12; 
const int rightEncoderPin = 15;

// Define the variables here
int encoderError = 0;
volatile long leftEncoder = 0;
volatile long rightEncoder = 0;
int encoderCorrection = 0;
int encoderLastError = 0;
//PID values
float encoderP = 0.2;
float encoderD = 0.0;

//left
float leftP = 2.4;  //0.8 upto 7 tryied (4*0.6 = 2.4)
float leftD = 1.1; //3.4 (1 working)

float leftError = 0;
float leftLastError = 0;
float leftDiff = 0;
float correction;

//right
float rightP = 2.4;  //0.8
float rightD = 1.1;  //3.4

float rightError = 0;
float rightLastError = 0;
float rightDiff = 0;

//wall
float wallP = 0.8 ;
float wallD = 2.7; 

float wallError = 0;
float wallLastError = 0;
float wallDiff = 0;

//wall fallow
int jump = 0;
int preState = 0;
int selectMode = -1;
int state = 0;

//interrupt functions for encorder
void handleLeftEncoder() {
    leftEncoder++;
}

void handleRightEncoder() {
    rightEncoder++;
}


//init encorders
void initencoders() {
    // Set up encoder pins
    pinMode(12, INPUT_PULLUP);
    pinMode(15, INPUT_PULLUP);

    // Attach interrupts
    attachInterrupt(digitalPinToInterrupt(12), handleLeftEncoder, RISING);
    attachInterrupt(digitalPinToInterrupt(15), handleRightEncoder, RISING);
}

void encoderPid()
{
    encoderError = leftEncoder - rightEncoder;
    if (encoderError > 30 )
    {
        encoderError = 15;
    }
    else if (encoderError < -30)
    {
        encoderError = -15;
    }
    encoderCorrection = float(encoderError * encoderP) + float(encoderLastError * encoderD);
    encoderLastError = encoderError;
    leftPwm = leftBase - encoderCorrection;
    rightPwm = rightBase + encoderCorrection;
    forward();
}

void leftPid()
{
    leftError = 98 - tof[0];  //85
    leftDiff = leftError - leftLastError;
    
    if (leftDiff > 30 )
    {
        leftError = 10;
        leftDiff = 5;
    }

    else if (leftDiff < -30)
    {
        leftError = -10;
        leftDiff = -5;
    }
    
    correction = (leftError * leftP) + (leftDiff * leftD);
    leftLastError = leftError;
    
    if (correction > 30 )
    {
        correction = 8;
    }

    else if (correction < -30)
    {
        correction = -8;
    }
    
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 80 - tof[4];
    rightDiff = rightError - rightLastError;
    if (rightDiff > 30 )
    {
        rightError = 8;
        rightDiff = 3;
    }

    else if (rightDiff < -30)
    {
        rightError = -8;
        rightDiff = -3;
    }
    
    correction  = (rightError * rightP) + (rightDiff * rightD);
    rightLastError = rightError;
    
    if (correction > 30 )
    {
        correction = 15;
    }

    else if (correction < -30)
    {
        correction = -15;
    }
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}


void wallPid()
{
    wallError = tof[0] - (tof[4]-8);
    rightLastError = 40 - tof[4]; //58
    leftLastError = 40 - tof[0];  //50
    wallDiff = wallError - wallLastError;
    
    if (wallDiff > 30 )
    {
        wallError = 10;
        wallDiff = 5;
    }

    else if (wallDiff < -30)
    {
        wallError = -10;
        wallDiff = -5;
    }
    
    correction = (wallError * wallP) + (wallDiff * wallD);
    wallLastError = wallError;
    
    if (correction > 30 )
    {
        correction = 10;
    }

    else if (correction < -30)
    {
        correction = -10;
    }
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}
void wallFollow()
{
    tofPid();
    if (tof[0] <= 175 && tof[4] <= 175)
    {
        wallPid();
        forward();
        
    }

    else if (tof[0] > 175 && tof[4] <= 175)
    {
        rightPid();
        forward();
    }

    else if (tof[0] <= 175 && tof[4] > 175)
    {
        leftPid();
        forward();
    }
    else if(tof[0] > 175 && tof[4] > 175)
    {
        encoderPid();
    }
} 
/*
void wallFollow()
{
    tofPid();
    if (tof[0] <= 135 && tof[4] <= 135)
    {
        state = 0;
        if (state != preState)
        {
          jump = 3;
          wallLastError = 0;
        }
        if (jump>0)
        {
          //forwardBase();
          encoderPid();
          jump = jump-1;
        }
        else
        {
          wallPid();
          forward();
        }
    }

    else if (tof[0] > 135 && tof[4] <= 135)
    {
        state = 1;
        if (state != preState)
        {
          jump = 3;
          rightLastError = 0;
        }
        if (jump>0)
        {
          encoderPid();
          //forwardBase();
          jump = jump-1;
        }
        else
        {
          rightPid();
          forward();
        }
    }

    else if (tof[0] <= 135 && tof[4] > 135)
    {
        state = 2;
        if (state != preState)
        {
          jump = 3;
          leftLastError = 0;
        }
        if (jump>0)
        {
          encoderPid();
          //forwardBase();
          jump = jump-1;
        }
        else
        {
          leftPid();
          forward();
        }
    }
    else if(tof[0] > 135 && tof[4] > 135)
    {
        state = 3;
        encoderPid();
        //forwardBase();
        wallLastError = 0;
    }
    preState = state;
}  */
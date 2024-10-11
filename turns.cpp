#include "motor.h"
#include "tofconfig.h"
#include "wallpid.h"

int encoderLeftCount;
int encoderRightCount;
int dif = 0;


void rightAboutTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    rightBase = 70;   //motor speed
    leftBase = 70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 105; // tested but not accurate //98 changed night at 11.3v
    encoderLeftCount= encoderLeftCount + 105;
    while(rightEncoder <= encoderRightCount)
    {
        turnRight();
    }
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();  
    }
    brake();
    leftBase = 130;
    rightBase = 128;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void leftAboutTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    rightBase = 70;
    leftBase = 70;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnLeft();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 150;
    encoderLeftCount= encoderLeftCount + 150;
    while(rightEncoder <= encoderRightCount)
    {
        turnLeft();
    }
    
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        turnLeft();  
    }
    brake();
    leftBase = 130;
    rightBase = 128;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void rightHalfTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    rightBase = 70;
    leftBase = 70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    while(rightEncoder <= encoderRightCount)
    {
        turnRight();
    }
    encoderRightCount= encoderRightCount + 80;
    encoderLeftCount= encoderLeftCount + 80;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void turnBack()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnLeft();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 590;
    encoderLeftCount= encoderLeftCount + 590;
    while(rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        turnLeft();
    }
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        turnLeft();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}
#include "motor.h"
#include "tofconfig.h"
#include "wallpid.h"
#include "turns.h"


void cellStart()
{
    leftWallAvailable = 0;
    rightWallAvailable = 0;
    frontWallAvailable = 0;
    encoderRightCount = encoderRightCount + 70;
    encoderLeftCount = encoderLeftCount + 70;
    rightBase=70;
    leftBase=70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 60;
        rightBase = 60 + int(dif/2);
        leftBase = 60 + int(dif/2);
        forwardBase();
    }
    rightBase=128;
    leftBase=130;
    /*
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        wallFollow();
    }
    */
    encoderLeftCount = encoderLeftCount + 50;
    encoderRightCount = encoderRightCount + 50;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
        //encoderPid();
        if (tof[2] <= 180)
        {
          frontWallAvailable = frontWallAvailable + 1;
        }
        else
        {
          frontWallAvailable = frontWallAvailable - 1;
        }
        if (tof[0] <= 150)
        {
          leftWallAvailable= leftWallAvailable + 1;
        }
        else
        {
          leftWallAvailable= leftWallAvailable - 1;
        }
        if (tof[4] <= 150)
        {
          rightWallAvailable= rightWallAvailable + 1;
        }
        else
        {
          rightWallAvailable= rightWallAvailable - 1;
        }
    }
}

void cellBrake()
{
    encoderRightCount= encoderRightCount + 20;
    encoderLeftCount= encoderLeftCount + 20;
    rightBase=128;
    leftBase=130;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        wallFollow();
    }
    encoderRightCount= encoderRightCount + 20;
    encoderLeftCount= encoderLeftCount + 20;
    //checkWallsCell();    // manually added for testing
    if (frontWallState == true)
    {
        toffront();
      //tof[2] = tof3.readRangeSingleMillimeters();
      while (tof[2] > 52)
      {   
         // tof[2] = tof3.readRangeSingleMillimeters();
          toffront();
          dif = leftEncoder - encoderLeftCount + 70;
          rightBase = 128 - int(dif*0.75);
          leftBase = 130 - int(dif*0.85);
          if (rightBase <= 70)
          {
            rightBase = 70;
          }
          if (leftBase <= 70)
          {
            leftBase = 70;
          }
          forwardBase();
      }
    }
    else
    {
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {   
          dif = leftEncoder - encoderLeftCount + 70;
          rightBase = 128 - int(dif/2);
          leftBase = 130 - int((dif*3)/5);
          if (rightBase <= 70)
          {
            rightBase = 70;
          }
          if (leftBase <= 70)
          {
            leftBase = 70;
          }
          forwardBase();
      }
    }
    brake();
}
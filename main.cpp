#include <Arduino.h>
#include <Wire.h>
#include <FastLED.h>
#include <MPU6500_WE.h>
#include "motor.h"  
#include "wallpid.h"
#include "indication.h"
#include "tofconfig.h"
#include "gyro.h"
#include "turns.h"
#include "speed.h"
#include "flash.h"
#include "moves.h"
#include "mazesolve.h"

void setup() {
    Serial.begin(115200);
    Serial1.begin(9600); 
    delay(10);
    initMotors();  // Initialize motors (from motor.h)
    initencoders();
    initbuzzer();
    gyroinit();
    initrgb();
    
    //powerOffSensors();
    //initpcf();
   // Serial1.println("addresshh changed");
    addresschange();
   // Serial1.println("address changed");
    cerberusstart();
   // initFileSystem();
    
    

}
void loop() {
    // Move the robot forward at 50% speed
    //forward_m(128);  // Assuming forward_m is a function to control motor speed (from motor.h)
   // encoderPid();
    // Display the encoder counts for debugging
    // Serial.print("Left Encoder Count: ");
   //  Serial1.print("Left Encoder Count: ");
   // Serial.print(leftEncoder);
   // Serial1.print(leftEncoder);
   // Serial.print("\tRight Encoder Count: ");
  //  Serial1.print("\tRight Encoder Count: ");
   // Serial.println(rightEncoder);
   // Serial1.println(rightEncoder);
    // tofPid();
   //  encoderPid();
    //wallPid();
   // cellStart();
   // cellBrake();
   // traverse(14,14,true,false,false);
    //searchStates();
   // cellBrake();
   // cellForward();
    //softbreak();
    //checkWallsCell(); 
   // wallrgb();
   // cellStart();
    //cellBrake();
    //leftTurn();
   // rightTurn();
    //rightSmoothTurn();
    //cellFastForward();
   // softbreak();
    //cellOff();
   // brake();
    //for debug
   /// delay(3000); 
   //cellFastForward();
  //  wallFollow();
     //tofPid();
     //leftPid();
     //rightPid();
    // forward();
     //checkWallsCell();
    // wallrgb();
  //  testBasicFileSystem();
   // writeCells();
  //  cellForward();
   // softbreak();
    wallFollow();
   //digitalWrite(LED_BUILTIN, LOW);
   //gyroreading();
   //rightHalfTurn();
  // turnBack();
  // rightAboutTurn();
  // leftAboutTurn();
  // turnBack();
   // rightHalfTurn();
   //tofStart();
  // tofPid();
  // cellStart();
  // cellBrake();
    //forwardBase();
    //tofStart();
    //checkWallsCell();
    //tofStart();
   // printWallState();
   // printTof();
   //delay(3);
    // Add motor control and synchronization logic here
   // delay(3000);  // Small delay to prevent spamming the serial monitor
}

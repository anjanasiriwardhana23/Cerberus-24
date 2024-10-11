#ifndef MOVES_H
#define MOVES_H

#include <Arduino.h>
#include "tofconfig.h"
#include "indication.h"
#include "wallpid.h"
#include "motor.h"
#include "turns.h"
#include "speed.h"

extern int timek;
extern int test;

// Function prototypes for buzzer control
void mazeStart();
void cellForward();
void cellFastForward();
void leftSmoothTurn();
void rightSmoothTurn();
void rightTurn();
void leftTurn();
void cellBack();
void cellOff();
#endif

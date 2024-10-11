#ifndef TURNS_H
#define TURNS_H

#include "motor.h"
#include "tofconfig.h"
#include "wallpid.h"

extern int encoderLeftCount;
extern int encoderRightCount;
extern int dif;

void rightAboutTurn();
void turnBack();
void rightHalfTurn();
void leftAboutTurn();

#endif // GYRO_H
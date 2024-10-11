#ifndef ZLGO_H
#define ZLGO_H

#include <Arduino.h>
#include <QueueArray.h>
#include "tofconfig.h"
#include "zvariables.h"
#include "wallpid.h"
#include "zvariables.h"

extern QueueArray<byte> queue;
extern QueueArray<byte> pathQueue;

// Function prototypes
void appendDestination(byte xdes, byte ydes, boolean middleSquare);
byte orientation(byte orient, char turning);
byte updateCoordinates();
void updateWalls(byte x, byte y, byte orient, boolean L, boolean R, boolean F);
boolean isAccessible(byte x, byte y, byte xNext, byte yNext);
byte getSurrounds(byte x, byte y);
void floodFill2();
void floodFill3();
char toMove(byte x, byte y, byte xprev, byte yprev, byte orient);
char toMove2();
void center();
#endif

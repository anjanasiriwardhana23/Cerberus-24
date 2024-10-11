#ifndef ZVARIABLES_H
#define ZVARIABLES_H

#include <Arduino.h>
#include <QueueArray.h>
#include "tofconfig.h"

// Declare global variables
extern byte x;
extern byte y;
extern byte xprev;
extern byte yprev;
extern byte orient;
extern byte state1;
extern boolean shortPath;
extern boolean middleSquare;
extern byte x_0;
extern byte y_0;
extern byte x_1;
extern byte y_1;
extern byte x_2;
extern byte y_2;
extern byte x_3;
extern byte y_3;
extern byte mazeSize;
extern char dir;
extern char turning;

extern byte xdes;
extern byte searchstate1;  //
extern byte ydes;
extern unsigned long timer;
extern int cellCount;
extern boolean runningNext;

// Declare arrays
extern byte cells[14][14];
extern byte cells1[14][14];
extern byte flood[14][14];
extern byte flood2[14][14];
extern byte sliit[14][14];

// Declare other global variables
extern char bluetoothWalls;
extern byte xrun;
extern byte yrun;

#endif  // ZVARIABLES_H

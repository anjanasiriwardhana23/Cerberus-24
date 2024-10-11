#ifndef MAZESOLVE_H
#define MAZESOLVE_H

#include <Arduino.h>
#include "zvariables.h"
#include <QueueArray.h>
#include "tofconfig.h"
#include "zvariables.h"
#include "wallpid.h"
#include "zlgo.h"
#include "turns.h"
#include "speed.h"
#include "moves.h"

void calculatePath(boolean runningNext);
void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath, boolean smooth);
void fixOrientation();
void loadCells();
void writeCells();
void searchStates();
void eepromClear();


#endif
#ifndef INDICATION_H
#define INDICATION_H

#include <Arduino.h>
#include <FastLED.h>
#include "tofconfig.h"

#define NUM_LEDS 2
#define DATA_PIN 20

// Pin definition for buzzer
extern const int buzzer;
extern const int LEDI;

// Function prototypes for buzzer control
void initbuzzer();
void buzz();
void buzzTwice();
void buzzDone();
void initrgb();
void wallrgb();

#endif

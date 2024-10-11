#include "indication.h"
#include "tofconfig.h"

const int buzzer = 13;
const int LEDI = 25;

CRGB leds[NUM_LEDS];


void initrgb(){
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void wallrgb(){

    if(rightWallState == true && frontWallState == true && leftWallState == true){
        leds[1] = CRGB::White;
        FastLED.show();
    }
    else if(rightWallState == true && frontWallState == false && leftWallState == true){
        leds[1] = CRGB::Green;
        FastLED.show();
    }
    else if(rightWallState == true && frontWallState == false && leftWallState == false){
        leds[1] = CRGB::Blue;
        FastLED.show();
    }
    else if(rightWallState == false && frontWallState == false && leftWallState == true){
        leds[1] = CRGB::Red;
        FastLED.show();
    }
    else{
        leds[1] = CRGB::Black;
        FastLED.show();
    }
}  //fordebug

void initbuzzer(){
    pinMode(buzzer, OUTPUT);
    digitalWrite(buzzer, LOW);

    //led
    pinMode(LEDI, OUTPUT);
    digitalWrite(LEDI, LOW);
}


void buzz()
{
    digitalWrite(buzzer, HIGH);
    digitalWrite(LEDI, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    digitalWrite(LEDI, LOW);
    delay(200);
}

void buzzTwice()
{
    digitalWrite(buzzer, HIGH);
    digitalWrite(LEDI, HIGH);
    delay(75);
    digitalWrite(buzzer, LOW);
    digitalWrite(LEDI, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LEDI, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    digitalWrite(LEDI, LOW);
}

void buzzDone()
{
    digitalWrite(buzzer, HIGH);
    digitalWrite(LEDI, HIGH);
    delay(75);
    digitalWrite(buzzer, LOW);
    digitalWrite(LEDI, LOW);
    delay(30);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LEDI, HIGH);
    delay(75);
    digitalWrite(buzzer, LOW);
    digitalWrite(LEDI, LOW);
    delay(30);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LEDI, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    digitalWrite(LEDI, LOW);
}
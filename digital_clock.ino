// Arduino Clock

#include "SevSeg.h"

#define d1 13
#define d2 12
#define d3 11
#define d4 10
#define a 9
#define b 8
#define c 7
#define d 6
#define e 5
#define f 4
#define g 1
#define dp 0
#define HOUR_BUTTON 2

volatile int hour = 1;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(HOUR_BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(HOUR_BUTTON), hourUp, RISING);

  byte numDigits = 4;
  byte digitPins[] = {d1, d2, d3, d4};
  byte segmentPins[] = {a, b, c, d, e, f, g, dp};
  sevseg.begin(COMMON_CAODE, numDigits, digitPins, segmentPins);
}

void loop() {
  // put your main code here, to run repeatedly:
  sevseg.setNumber(hour * 100, 3);
  refreshDisplay();
}

void hourUp() {
  hour = hour + 1;
  if (hour > 12) {
    hour = 1;
  }
}

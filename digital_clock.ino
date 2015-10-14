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
#define HOUR_BUTTON A0
#define TICK_LENGTH 250

SevSeg sevseg;

int hour = 1;
int ticks = 0;
unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Bootup");
  pinMode(HOUR_BUTTON, INPUT);
  
  byte numDigits = 4;
  byte digitPins[] = {d1, d2, d3, d4};
  byte segmentPins[] = {a, b, c, d, e, f, g, dp};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  checkTick();
  sevseg.setNumber(hour * 100, 3);
  sevseg.refreshDisplay(); 
}

void checkTick() {
   unsigned long currentMillis = millis();
 
   // How much time has passed, accounting for rollover with subtraction!
   if ((unsigned long)(currentMillis - previousMillis) >= TICK_LENGTH) {
      // It's time to do something!
      tick();
 
      // Use the snapshot to set track time until next event
      previousMillis = currentMillis;
   }
}

void tick() {
  Serial.println("TICK!");
  ticks = ticks + 1;
  readHourButton();
}

void readHourButton() {
  if (digitalRead(HOUR_BUTTON) == HIGH) {
    hourUp();
  }
}

void hourUp() {
  Serial.print("Hour up: ");
  Serial.println(hour);
  hour = hour + 1;
  if (hour > 12) {
    hour = 1;
  }
}

// Arduino Clock
//

#include "SevSeg.h"

#define d1 13
#define a 2

void setup() {
  // put your setup code here, to run once:
  pinMode(d1, OUTPUT);
  pinMode(a, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(d1, LOW);
  digitalWrite(a, HIGH);
}

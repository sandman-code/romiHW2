#include "Romi32U4.h"
#include <Arduino.h>
#include "Chassis.h"

Romi32U4Motors motors;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Chassis c; 
  c.driveDistance(10);
  c.turnAngle(90);
}
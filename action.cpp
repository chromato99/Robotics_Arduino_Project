// this is about action of robot
#include"Arduino.h"
#include"Arduino_Project2018.h"

void sprayingWater(int input) {
    analogWrite(PUMP, 255);
    delay(input);
    analogWrite(PUMP, 0);
}


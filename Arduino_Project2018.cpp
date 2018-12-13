#include"Arduino_Project2018.h"
#include"Arduino.h"
#include"communication.h"
#include"action.h"

char mode = '0';

void setup()
{
    // communication with the host computer
    Serial.begin(9600);
    Serial1.begin(9600);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(TRIG_L, OUTPUT);
    pinMode(ECHO_L, INPUT);
    pinMode(TRIG_R, OUTPUT);
    pinMode(ECHO_R, INPUT);

    pinMode(DriveModulePin1, OUTPUT);       // Motor A 방향설정1
    pinMode(DriveModulePin2, OUTPUT);       // Motor A 방향설정2
    pinMode(DriveModulePin3, OUTPUT);       // Motor B 방향설정1
    pinMode(DriveModulePin4, OUTPUT);       // Motor B 방향설정2
    pinMode(PUMP, OUTPUT);
    pinMode(FLAME, OUTPUT);
}

void loop()
{
  mode = takeSerial1Char();
  if(mode == '0') {
    remoteDriving();
  }
  else if(mode == '1') {
    selfDriving();
  }
  else if(mode == 'w') {
    sprayingWater(50);
  }
  delay(10);
}
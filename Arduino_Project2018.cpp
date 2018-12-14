#include"Arduino_Project2018.h"
#include<SoftwareSerial.h>
#include"Arduino.h"
#include"communication.h"
#include"action.h"
#include"driving.h"

char mode = '0';
char c = '0';
int servoBaseP = 0;
int servoShoulderP=0;
int servoElbowP=0;

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

    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);

    pinMode(DriveModulePin1, OUTPUT);    
    pinMode(DriveModulePin2, OUTPUT);  
    pinMode(DriveModulePin3, OUTPUT);   
    pinMode(DriveModulePin4, OUTPUT);       
    pinMode(PUMP, OUTPUT);
    pinMode(FLAME_D, INPUT);
    pinMode(pinSpeaker, OUTPUT);
}

void loop()
{
  c = takeSerial1Char();
  if(c=='1' && mode == '0') {
    mode = '1';
  }
  else if(c=='1' && mode == '1') {
    mode = '0';
  }

  if(mode == '0') {
    remoteDriving(c);
  }
  else if(mode == '1') {
    selfDriving();
  }
  
  if(c == 'w') {
    sprayingWater(250);
  }
  else if(c=='n') {
    sprayingWater(0);
  }
  else {
    robotArm(c);
  }
  
  checkFlameSensor();

  int distance = checkDistance(TRIG_L, ECHO_L);
  

  if (distance<25) {
    analogWrite(LED_Y, 255);
  }
  else {
    analogWrite(LED_Y, 0);
  }
  delay(10);
}

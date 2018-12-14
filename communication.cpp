#include"communication.h"
#include"Arduino_Project2018.h"
#include"Arduino.h"
#include<SoftwareSerial.h>

char takeSerial1Char() {
  char readData = '0';
  if(Serial1.available()>0) {
    readData = Serial1.read();
  }
  Serial.println(readData);
  return readData;
}

int checkDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  return (pulseIn(echo,HIGH) * 0.017); 
}

int checkFlameSensor() {
  int val = analogRead(FLAME_A);
  if(val < 500) {
    analogWrite(LED_R, 255);
    analogWrite(pinSpeaker, 150);
  }
  else if(val > 500) {
    analogWrite(LED_R, 0);
    analogWrite(pinSpeaker, 0);
  }
  return val;
}

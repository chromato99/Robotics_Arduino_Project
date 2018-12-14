// this is about action of robot
#include"Arduino.h"
#include"Arduino_Project2018.h"
#include<Servo.h>

Servo servoBase;
Servo servoShoulder;
Servo servoElbow;

extern int servoBaseP;
extern int servoShoulderP;
extern int servoElbowP;

void sprayingWater(int input) {
    digitalWrite(36, HIGH); 
    digitalWrite(37, LOW); 
    analogWrite(PUMP, input);
}

void playTone(long duration, int freq) {
  duration *= 1000;
  int period = (1.0 / freq) * 1000000;
  long elapsed_time = 0;
  while (elapsed_time < duration) {
    digitalWrite(pinSpeaker,HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(pinSpeaker, LOW);
    delayMicroseconds(period / 2);
    elapsed_time += (period);
  }
}

void robotArm(char input) {
    servoBase.attach(7);
    servoShoulder.attach(5);
    servoElbow.attach(6);

    if(input == '3') {
        servoShoulderP += 5; 
        servoShoulder.write(servoShoulderP); 
        delay(15);                 
    } else if(input == '4') {
        servoShoulderP -= 5; 
        servoShoulder.write(servoShoulderP);       
        delay(15);
    }
    else if(input == '5') {
        servoElbowP += 5; 
        servoElbow.write(servoElbowP);    
        delay(15);
    }
    else if(input == '6') {
        servoElbowP -= 5; 
        servoElbow.write(servoElbowP); 
        delay(15);
    }
    else if(input == '7') {
        servoBaseP += 5; 
        servoBase.write(servoBaseP);  
    } 
    else if(input == '8') {
        servoBaseP -= 5; 
        servoBase.write(servoBaseP);   
        delay(15);
    }
}

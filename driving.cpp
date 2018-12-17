#include"Arduino.h"
#include"Arduino_Project2018.h"
#include"communication.h"

void movingBackward(int input_time) {
    digitalWrite(DriveModulePin1, HIGH); 
    digitalWrite(DriveModulePin2, LOW); 
    digitalWrite(DriveModulePin3, HIGH); 
    digitalWrite(DriveModulePin4, LOW);
    analogWrite(DrivePin1, 250); 
    analogWrite(DrivePin2, 250);
    delay(input_time);
}

void movingTurnLeft(int input_time) {
    digitalWrite(DriveModulePin2, HIGH); 
    digitalWrite(DriveModulePin1, LOW); 
    digitalWrite(DriveModulePin3, HIGH); 
    digitalWrite(DriveModulePin4, LOW);
    analogWrite(DrivePin1, 250); 
    analogWrite(DrivePin2, 250);
    delay(input_time);
}

void movingTurnRight(int input_time) {
    digitalWrite(DriveModulePin1, HIGH); 
    digitalWrite(DriveModulePin2, LOW); 
    digitalWrite(DriveModulePin4, HIGH); 
    digitalWrite(DriveModulePin3, LOW);
    analogWrite(DrivePin1, 250); 
    analogWrite(DrivePin2, 250);
    delay(input_time);
}

void movingFoward(int input_time) {
    digitalWrite(DriveModulePin2, HIGH); 
    digitalWrite(DriveModulePin1, LOW); 
    digitalWrite(DriveModulePin4, HIGH); 
    digitalWrite(DriveModulePin3, LOW);
    analogWrite(DrivePin1, 250); 
    analogWrite(DrivePin2, 250);
    delay(input_time);
}

void movingStop(int input_time) {
    analogWrite(DrivePin1, 0); 
    analogWrite(DrivePin2, 0);
    delay(input_time);
}

int selfDriving() {
    int distance = checkDistance(TRIG ,ECHO);
    int distance_l = checkDistance(TRIG_L ,ECHO_L);
    int distance_r = checkDistance(TRIG_R, ECHO_R);

    if(distance > 30) {
        movingFoward(50);
    }
    else if(distance < 30) {
        movingStop(10);
        if(distance_l>distance_r) {
            movingTurnLeft(100);
        }
        else if(distance_l<distance_r) {
            movingTurnRight(100);
        }
    }
    movingStop(5);
    return 0;
}

int remoteDriving(char input) { 

    if(input == 'f') {
    movingFoward(20);
    }
    else if(input == 'l') {
    movingTurnLeft(20); 
    }
    else if(input == 'r') {
    movingTurnRight(20);
    }
    else if(input == 'b') {
    movingBackward(20);
    }
    else if(input == 's') {
    movingStop(20);
    }
    delay(20);
    return 0;
}

#include<arduino.h>

#define TRIG 22
#define ECHO 2
#define TRIG_L 24
#define ECHO_L 3
#define TRIG_R 26
#define ECHO_R 4
#define PUMP 5

int check_distance(int ,int);

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
    pinMode(30, OUTPUT);       // Motor A ë°©í–¥?„¤? •1
    pinMode(31, OUTPUT);       // Motor A ë°©í–¥?„¤? •2
    pinMode(32, OUTPUT);       // Motor B ë°©í–¥?„¤? •1
    pinMode(33, OUTPUT);       // Motor B ë°©í–¥?„¤? •2
    pinMode(PUMP, OUTPUT);
 
}

char c='0';
int distance = 0;
int distance_l = 0;
int distance_r = 0;

void loop()
{
  // listen for communication from the BT module and then write it to the serial monitor
  if(Serial1.available()>0) {
    c = Serial1.read();
  }
  Serial.println(c);
  
  distance = check_distance(TRIG ,ECHO);

  distance_l = check_distance(TRIG_L ,ECHO_L);
 
  distance_r = check_distance(TRIG_R, ECHO_R);
  
  Serial.print("Front : ");
  Serial.println(distance);
  Serial.print("Left : ");
  Serial.println(distance_l);
  Serial.print("Right : ");
  Serial.println(distance_r);



    if(c=='w') {
    analogWrite(PUMP, 250);
    delay(20);
  }
  else if(c=='n') {
    analogWrite(PUMP, 0);
    delay(20);
  }
  
    if(c == 'f') {
    digitalWrite(31, HIGH); 
    digitalWrite(30, LOW); 
    digitalWrite(32, HIGH); 
    digitalWrite(33, LOW);
    analogWrite(9, 250); 
    analogWrite(10, 250);
    delay(50);  
    }
    else if(c == 'l') {
    digitalWrite(30, HIGH); 
    digitalWrite(31, LOW); 
    digitalWrite(32, HIGH); 
    digitalWrite(33, LOW);
    analogWrite(9, 250); 
    analogWrite(10,250);
    delay(50);  
    }
    else if(c == 'r') {
    digitalWrite(31, HIGH); 
    digitalWrite(30, LOW); 
    digitalWrite(33, HIGH); 
    digitalWrite(32, LOW);
    analogWrite(9, 250); 
    analogWrite(10,250);
    delay(50);  
    }
    else if(c == 'b') {
    digitalWrite(30, HIGH); 
    digitalWrite(31, LOW); 
    digitalWrite(33, HIGH); 
    digitalWrite(32, LOW);
    analogWrite(9, 250); 
    analogWrite(10,250);
    delay(50);  
    }
    else {
    digitalWrite(30, HIGH); 
    digitalWrite(31, LOW); 
    digitalWrite(32, HIGH); 
    digitalWrite(33, LOW);
    analogWrite(9, 0); 
    analogWrite(10,0);
    delay(50);
    }
    delay(20);
}

int check_distance(int trig, int echo) {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  return (pulseIn(echo,HIGH) * 0.017); 
}

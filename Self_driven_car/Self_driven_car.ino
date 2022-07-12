
//MOTOR1 PINS
int ena = 0;
int in1 = 1;
int in2 = 2;
int in3 = 3;
int in4 = 4;
int enb = 5;

//LED PINS
int BLUE = 13;
int YELLOW = A0;
 
#include <NewPing.h>
#define TRIG_PIN A3 
#define ECHO_PIN A2 
#define MAX_DISTANCE 200 


NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 



 

boolean goesForward=false;
int distance = 100;
int speedSet = 0;

void setup() {
  
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);




 

//MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 160);
  delay(1000);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);
 
//MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enb, 235);
  delay(700);
  
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000);





  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {

 digitalWrite(BLUE,HIGH);
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=15)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    moveStop();
  }else
  {
    turnLeft();
    moveStop();
  }
 }else
 {
  moveForward();
 }
 distance = readPing();
}

int lookRight()
{
  

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, 160);
  delay(1000);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);
 

  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enb, 235);
  delay(700);
  
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000);

    int distance = readPing();
    delay(100);
   
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 235);
  delay(700);
  
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000); 
    return distance;
}

int lookLeft()
{

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, 160);
  delay(1000);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);
 

  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(enb, 235);
  delay(700);
  
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000);
  
    int distance = readPing();
    delay(100);
   
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 235);
  delay(700);
  
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000);  
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
   digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000);

  } 
  
void moveForward() {

 if(!goesForward)
  {

 
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, 160);
  delay(1000);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enb, 235);
  }
}

void moveBackward() {
    goesForward=false;
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(enb, 235);
}  

void turnRight() {
  digitalWrite(YELLOW,HIGH);
  delay(500);

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(ena, 160);
  delay(1000);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);
 

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 235);
  delay(700);
  
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000);      
} 
 
void turnLeft() {

  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 160);
  delay(1000);
  
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);
 

  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 235);
  delay(700);
  
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000);

}  

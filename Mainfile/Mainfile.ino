#include "SimpleTimer.h"

int btn1 = 2;
int btn2 = 4;
int btn3 = 6;

int led1 = 3;
int led2 = 5;
int led3 = 7;
int led = 0; // random værdi
int rdm = 0; //random værdi

int counter = 0;

void setup() {
  Serial.begin(9600);

    pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  randomSeed(analogRead(0));
}

void loop() {
  while (counter < 20){
  loopshiz();
  } 
  
  }

  
  /////
 void newLight(int knapval, int ledval) {
   
 }
 ////
 void loopshiz(){
   rdm = random(3,8);
  
  
  if(rdm == led){ // check om at den samme LED ikke lyser igen
    led = random(3,8);
  }
  else{
    led = rdm;
  }

  if(led % 2 == 0){
    led = led + 1;
    }
    delay(200);
  
  while(digitalRead(led - 1) == HIGH) {

    digitalWrite(led,HIGH);

  }
  Serial.print(" knap: ");
  Serial.println(digitalRead(led -1));
  delay(200);
  digitalWrite(led,LOW);
  counter++;
 }

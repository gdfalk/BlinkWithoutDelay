#include <analogWrite.h>

int state = 1;
int stateRed = 1;
int stateGreen = 2;
int stateBlue = 3;
int stateAll = 4;

unsigned long interval = 1000;
unsigned long prevMillis = 0;

int redLED = 12;
int greenLED = 27;
int blueLED = 33;

void setup() {
pinMode(12, OUTPUT);
pinMode(27, OUTPUT);
pinMode(33, OUTPUT);


}

void loop() {

unsigned long currentMillis = millis();

if(state==stateRed)
  {
    analogWrite(redLED,HIGH);
    analogWrite(greenLED,LOW);
    analogWrite(blueLED,LOW);

  }else if(state==stateGreen)
  {
    analogWrite(redLED,LOW);
    analogWrite(greenLED,HIGH);
    analogWrite(blueLED,LOW);
  }else if(state==stateBlue)
  {
    analogWrite(redLED,LOW);
    analogWrite(greenLED,LOW);
    analogWrite(blueLED,HIGH);
  }else if(state==stateAll)
  {
    analogWrite(redLED,HIGH);
    analogWrite(greenLED,HIGH);
    analogWrite(blueLED,HIGH);

  }

if((currentMillis - prevMillis) >= interval)
  {
    state++;
    if(state==5)
      {
        state=1;
      }
    prevMillis=millis();
  }
}

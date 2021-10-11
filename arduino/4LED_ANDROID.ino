//Project Cotroll 4 LED Light using Android 

const int PIN_LED1 = 2;
const int PIN_LED2 = 3;
const int PIN_LED3 = 4;
const int PIN_LED4 = 5;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8);
char val;

void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
if( mySerial.available() >0){
  val = mySerial.read();
  Serial.println(val);
}
if ( val == '1' ){
  digitalWrite(PIN_LED1,HIGH);}
  else if( val == '2' ) {
    digitalWrite(PIN_LED2,HIGH);}
     else if( val == '3' ) {
    digitalWrite(PIN_LED3,HIGH);}
     else if( val == '4' ) {
    digitalWrite(PIN_LED4,HIGH);}
  
  else if( val == '9' ){
    digitalWrite(PIN_LED1,HIGH);
    digitalWrite(PIN_LED2,HIGH);
    digitalWrite(PIN_LED3,HIGH);
    digitalWrite(PIN_LED4,HIGH);
  }
    else if( val == 'A' ){
    digitalWrite(PIN_LED1,LOW);}
    else if( val == 'B' ){  
    digitalWrite(PIN_LED2,LOW);}
     else if( val == 'C' ){
    digitalWrite(PIN_LED3,LOW);}
    else if( val == 'D' ){  
    digitalWrite(PIN_LED4,LOW);
    }

    else if( val == 'I' ){
      digitalWrite(PIN_LED1,LOW);
      digitalWrite(PIN_LED2,LOW);
      digitalWrite(PIN_LED3,LOW);
      digitalWrite(PIN_LED4,LOW);
    }
  }
  
  
    


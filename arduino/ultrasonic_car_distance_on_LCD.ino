#include<LiquidCrystal.h>

int trigPin = 9;
int echoPin = 10;

int revleft = 4;
int fwdleft = 5;
int revright = 6;
int fwdright = 7;

long duration, distance;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  //delay(random(500,2000));
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(revleft, OUTPUT);
  pinMode(fwdleft, OUTPUT);
  pinMode(revright, OUTPUT);
  pinMode(fwdright, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  lcd.setCursor(0,0);
  lcd.print("DISTANCE = ");
  lcd.setCursor(12,0);
  lcd.print(distance);
  delay(10);
  if (distance>19) {
    digitalWrite(fwdright, HIGH);
    digitalWrite(revright, LOW);
    digitalWrite(fwdleft, HIGH);
    digitalWrite(revleft, LOW);
  }
  if (distance<18) { 
    digitalWrite(fwdright, LOW);  //STOP
    digitalWrite(revright, LOW);
    digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, LOW);
    delay(500);
    digitalWrite(fwdright, LOW);  //backward
    digitalWrite(revright, HIGH);
    digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, HIGH);
    delay(500);
    digitalWrite(fwdright, LOW);  //stop
    digitalWrite(revright, LOW);
    digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, LOW);
    delay(100);
    digitalWrite(fwdright, HIGH);
    digitalWrite(revright, LOW);
    digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, LOW);
    delay(500);
  }
}

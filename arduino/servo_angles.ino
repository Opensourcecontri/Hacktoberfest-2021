#include<Servo.h>
const int servoPin = 9;

Servo servo1;

void setup() {
  servo1.attach(servoPin);
}

void loop() {
  servo1.write(0);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);
}

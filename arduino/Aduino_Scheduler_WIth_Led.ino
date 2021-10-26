#define _TASK_SLEEP_ON_IDLE_RUN
#include <TaskScheduler.h>

Scheduler ts;

void ledOnCallback();
void ledOffCallback();
void ledPauseCallback();

Task tLedBlinker (500, 10, &ledOnCallback, &ts, true);
Task tLedAlwaysOn (5000, TASK_FOREVER, &ledPauseCallback, &ts, true);

void ledOnCallback(){
  turnLedOn();
  tLedBlinker.setCallback(&ledOffCallback);
}

void ledOffCallback(){
  turnLedOff();
  tLedBlinker.setCallback(&ledOnCallback);
}

void ledPauseCallback(){
  turnLedOn();
  tLedAlwaysOn.setCallback(&ledOffCallback);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Test Program");

}

void loop() {
  // put your main code here, to run repeatedly:
  ts.execute();

}

void turnLedOn(){
  digitalWrite(LED_BUILTIN, HIGH);
}

void turnLedOff(){
  digitalWrite(LED_BUILTIN, LOW);
}

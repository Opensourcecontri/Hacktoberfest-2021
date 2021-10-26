long randNumber;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));

}

void loop() {
  // print a random number from 0 to 299
  Serial.print("random1 = ");
  randNumber = random(300);
  Serial.println(randNumber); // print a random number from 0 to 299
  Serial.print("random2 = ");
  randNumber = random(10, 30); // print a random number from 10 to 19
  Serial.println(randNumber);
  delay(500);
}

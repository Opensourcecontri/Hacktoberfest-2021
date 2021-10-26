#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; //(BME_CS, BME_MOSI, BME_MISO, BME_SCK)

unsigned long currentMillis = 0;

unsigned long previousMillis = 0;




  byte Column1 = 1;

  byte Column2 = 2;

  byte Column3 = 3;

  byte Column4 = 4;
  
float deltaT = 0;



char startMarker = '<';

char endMarker = '>';

char initializeMarker = '^';





void setup() {

  Serial.begin(9600);
  bool status;

  status = bme.begin();
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");

  }
  while (!Serial);

  Serial.print(initializeMarker);   //inializes the entire transmition

  previousMillis = millis();

}



void loop() {

  serialOutput();

  currentMillis = millis();

  deltaT = (currentMillis - previousMillis) * .001;

  previousMillis = millis();

  delay(500);                        //keep from overloading Serial port

}



void serialOutput() {

  Serial.print(startMarker);

  Serial.print(Serial.print(bme.readTemperature()));

  Serial.print(",");

  Serial.print(Serial.print(bme.readPressure() / 100.0F));

  Serial.print(",");

  Serial.print(Serial.print(bme.readHumidity()));

  Serial.print(",");

  Serial.print(Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA)));

  Serial.print(",");

  Serial.print(deltaT, 3);          //sends the time it takes the loop to run in seconds down to 3 decimal places

  Serial.print(endMarker);

}

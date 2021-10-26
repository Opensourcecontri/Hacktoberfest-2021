#include <TimeLib.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

char timestamp[20]; // declare a character variable that contains time-stamp

void setup()
{
  Serial.begin(9600);
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");
}

void loop()
{

  sprintf (timestamp, "%4d-%02d-%02d %02d:%02d:%02d", year(), month(),day(), hour(), minute(), second());
  Serial.println(timestamp);
  delay(1000);
 

}

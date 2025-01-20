//i2c Slave

#include <Wire.h>
#include "MAX6675.h"
#include <Arduino.h>

int thermoDO2 = 7;
int thermoD01 = 4;
int thermoCS2 = 8;
int thermoCS1 = 5;
int thermoCLK = 6;
int vccPin = 3;
int gndPin = 2;


 MAX6675 thermocouple1(thermoCLK, thermoCS1, thermoD01); 
 MAX6675 thermocouple2(thermoCLK, thermoCS2, thermoDO2);
 
void setup(){
  Serial.begin(9600);
  // Use Arduino pins
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);

  delay(500);
  
  //Wire.begin(5);
  //Wire.onRequest(requestEvent);

}
void loop(){
  
  double temp = thermocouple1.readCelsius(); 
  Serial.println(temp);
  char &value=int2str(temp);
  Serial.println(value);
delay(1000);
}

char *int2str( double num ) {
    static char retnum[21];       // Enough for 20 digits plus NUL from a 64-bit uint.
    sprintf( retnum, "%ul", num );
    return retnum;
}

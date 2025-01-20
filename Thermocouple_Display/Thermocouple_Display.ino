#include "max6675.h"
#include <LiquidCrystal.h>

int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 3;
int gndPin = 2;

uint8_t degree[8] = {140,146,146,140,128,128,128,128};  

void setup() {
  
  Serial.begin(9600);
  // use Arduino pins
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  
  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
    // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.createChar(0, degree);
}

void loop() {
  // basic readout test, just print the current temp
  
   Serial.print("C = ");
   Serial.println(thermocouple.readCelsius());
   lcd.write((byte)0);
   lcd.print("C=");
   lcd.print(thermocouple.readCelsius());
   delay(1000);
   lcd.clear();
}

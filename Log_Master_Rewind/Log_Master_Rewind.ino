//i2c Master

#include <Wire.h>
#include <LiquidCrystal.h>
#include <Time.h> 


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// make a cute degree symbol
uint8_t degree[8] = {140,146,146,140,128,128,128,128};

void setup()

{
 
  Wire.begin();                            
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(0, degree);
  delay(500);                       
}

void loop()

{
  Wire.requestFrom(2, 16);    // request 6 bytes from slave device #2

  while(Wire.available())    // slave may send less than requested
  {
    char c = Wire.read(); // receive a byte as character
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(c);
  }
delay(500);
}


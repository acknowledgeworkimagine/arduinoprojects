#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:

pinMode(8,INPUT);
Serial.begin(9600);

lcd.begin(16,2);
lcd.print("Hey buddy!");

}

void loop() {
  // put your main code here, to run repeatedly:
int buttonState = digitalRead(8);
Serial.println(buttonState);
delay(1000);
}

int sensorValue;


void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(8,HIGH);
delay(1000);
digitalWrite(8,LOW);
sensorValue = analogRead(A0);
Serial.println(sensorValue);
delay(1000);

}

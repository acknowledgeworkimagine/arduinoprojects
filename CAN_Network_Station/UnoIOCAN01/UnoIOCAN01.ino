
#include <SPI.h>
#include <mcp_can.h>


const int SPI_CS_PIN = 9;
const int LED=8;
int sensorValue;
unsigned char stmp[8]={0,0,0,0,0,0,0,0};
int cntr;

MCP_CAN CAN(SPI_CS_PIN);




void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);

 while (CAN_OK != CAN.begin(CAN_500KBPS))
 {
    Serial.println("CAN BUS Shield init fail");
    Serial.println("Init CAN BUS Shield again");
    delay(1000);
 }

 Serial.println("CAN BUS Shield init ok!");

}

void loop() {

 //VARIABLES
unsigned char len = 0;
unsigned char buf[8];
unsigned long canId = 0;

 //RECEIVING MESSAGES
if(CAN_MSGAVAIL == CAN.checkReceive())  //check if data coming

  {
    CAN.readMsgBuf(&len,buf); //read incoming data
    canId = CAN.getCanId();

    // check for push buttin status message (70)
    if (canId == 70) {

      if(buf[0] == 1){
        digitalWrite(LED,HIGH);
      }
      else {
        digitalWrite(LED,LOW);
      }
    }
  }

  delay(50);

  //SENDING CAN MESSAGES
  cntr = cntr + 1;
  if (cntr > 10) {
    cntr = 0;

    sensorValue = analogRead(A0);

    stmp[0]=lowByte(sensorValue);
    stmp[1]=highByte(sensorValue);

    CAN.sendMsgBuf(71,0,8,stmp); // 0:standard CAN frame 1:extended CAN frame
  }
  
}

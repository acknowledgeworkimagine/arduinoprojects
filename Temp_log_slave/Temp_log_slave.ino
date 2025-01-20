//i2c Slave

#include <Wire.h>
#include <max6675.h>
#include <Arduino.h>

int thermoDO2 = 7;
int thermoD01 = 4;
int thermoCS2 = 8;
int thermoCS1 = 5;
int thermoCLK = 6;
int vccPin = 3;
int gndPin = 2;
int x=1;
void setup(){
  Serial.begin(9600);
  // Use Arduino pins
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);

}
void loop()

{

if (x==1)
{
  Wire.begin(5);
  Wire.onRequest(requestEvent1); 
  x=2;
  delay(500);
}
else if(x==2)
{
  Wire.begin(5);
  Wire.onRequest(requestEvent2);
  x=1;
  delay(500);
}
  
}


void requestEvent2(){

 MAX6675 thermocouple2(thermoCLK, thermoCS2, thermoDO2);
 delay(500); 
 int unsigned temp2=int(thermocouple2.readCelsius()*100);
 Serial.println("Th02");
 Serial.println(temp2);
 int digits2=countdigits(temp2); 
 byte my_array_temp_2[] = {0};
 my_array_temp_2[0]=2;
 buffMake(temp2, digits2, my_array_temp_2);

 Wire.write(my_array_temp_2,digits2+1); //Envia datos.
 memset(my_array_temp_2,0, sizeof(my_array_temp_2));
 digits2=0;

}

void requestEvent1(){
 MAX6675 thermocouple1(thermoCLK, thermoCS1, thermoD01); 
 delay(500); 
 int unsigned temp1=int(thermocouple1.readCelsius()*100);
 Serial.println("Th01");
 Serial.println(temp1);
 int digits1=countdigits(temp1); 
 byte my_array_temp_1[] = {0};
 my_array_temp_1[0]=1;
 buffMake(temp1, digits1, my_array_temp_1);

 
 Wire.write(my_array_temp_1,digits1+1); //Envia datos. 
 memset(my_array_temp_1,0, sizeof(my_array_temp_1));
 digits1=0;
}


// Funciones //
int countdigits(int unsigned val){ //Cuentas nÃƒÂºmero de dÃƒÂ­gitos en el nÃƒÂºero
  int digits;                      //leido por el MAX6675.
 for(int i=1; val>0; i++){
   val=int(val/10);
   digits=i;
 }
 return digits;
 digits=0;
}

int tenpow(int val,int pow){  //Genera valores multiplos de 10.                           
 for (int i=pow; i>0 ; i--){   //Ã‚Â¿Realmente necesia int val?.
   val=val*10;
 }
  return val;
  val=0;
}

byte buffMake(unsigned int valx, int digits, byte dataA[]){  //Genera un arreglo tipo 
int k=1; //byte que contiene un digito por posiciÃƒÂ³n.
unsigned int valz=0;
unsigned int vald=0;
int valy=0, d_count=digits;
//byte dataA[]={0};
 for(int j=digits-1; valx>0 || d_count>0; j--){
   valy=int(valx/tenpow(1,j));
   dataA[k]=valy;
   //Serial.println("Buffer data");
   //Serial.println(dataA[k]);
   valz= tenpow(valy,j);
   vald= valx - valz;
   valx=vald;
   k++;
   d_count=d_count-1;
 }
 
}



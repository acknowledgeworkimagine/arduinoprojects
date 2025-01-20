//i2c Master

#include <Wire.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// make a cute degree symbol
uint8_t degree[8] = {140,146,146,140,128,128,128,128};
int *sens_1, *sens_2;   
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
      lcd.clear();
      lcd.setCursor(0, 0);
      int count1 = Count_TempRequest();
      lcd.print("Sensor ");
      float final_temp1=TempRequest(count1);
      lcd.print(*sens_1);
      lcd.setCursor(0,1);
      lcd.print(final_temp1);
      lcd.write((byte)0);
      lcd.print("C ");
      delay(1000);

}

// Funciones //

float TempRequest(int temp_size){ //Recibe datos del esclavo y re-
int digit;                        //reconstruye el valor final.
int temp[temp_size];
int i=0;
int j=temp_size-1;                
unsigned int total=0;             //Modifica capacidad de int
Wire.requestFrom(5,temp_size);    // -32,768 to 32,767  >>  0 to 65,535

while(Wire.available())
  {
  digit = Wire.read();
  //Serial.println(digit);
  temp[i]=digit;
  i=i+1;
  }

 sens_1=&temp[0];

  for (i=0;i<temp_size-1;i++)
  {
   int valz=temp[i+1]*tenpow(1,j);
   //Serial.println(temp[i]);
   total=total+valz;
   //Serial.println(total);
   j--;
  }
  float final_temp=float(total)/tenpow(1,temp_size-2);
  return final_temp;
}

int tenpow(int val, int pow){  //Genera valores multiplos de 10.                           
 for (int i=pow; i>0 ; i--){   //¿Realmente necesia int val?.
   val=val*10;
 }
  return val;
}

int Count_TempRequest(){       //Cuenta el número de digitos que
int count[]={0};               //el esclavo manda al master.
int i=0;
Wire.requestFrom(5,10);
while(Wire.available())
  {  
   count[i] = Wire.read();  
   if (count[i]==255)
   {}
   else
   {
   i++;
   }
  }
  return i;
}




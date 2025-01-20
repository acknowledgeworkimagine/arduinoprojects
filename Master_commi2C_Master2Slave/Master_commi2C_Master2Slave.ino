/*i2c Master code: Mandar un caracter al Arduino esclavo, para
que encienda un led.*/

#include <Wire.h>
/*This library allows you to communicate with I2C / TWI (Two
wire interface) devices.*/

void setup()
{
  Serial.begin(9600); /* abre el puerto serie y establece 
                          la velocidad en 9600 bps para mandar
                          el caracter del master al esclavo*/
                          
  Wire.begin();       /* Initiate the Wire library and join 
                      the I2C bus as a master or slave. This 
                      should normally be called only once. 
                      Usualmente el master no lleva dirección*/ 
  
}

void loop()
{
  
 while(Serial.available())     /*Serial.available(): Devuelve el número de bytes (caracteres)
                               disponibles para ser leidos por el puerto serie. Se refiere a datos 
                                ya recibidos y disponibles en el buffer de recepción del puerto 
                                (que tiene una capacidad de 128 bytes). */
 {
   char c = Serial.read();     //Serial.read(): Lee los datos entrantes del puerto serie.
   
   if (c == 'H')
   {
     Wire.beginTransmission(5); //Begin a transmission to the I2C slave device with the given address.
     
     Wire.write('H');          /*Writes data from a slave device in response to a request from a master, 
                               or queues bytes for transmission from a master to slave device (in-between 
                               calls to beginTransmission() and endTransmission()). */
    
     Wire.endTransmission();  /*Ends a transmission to a slave device that was begun by beginTransmission() 
                              and transmits the bytes that were queued by write().*/
   }
   else if (c =='L')
   {
     Wire.beginTransmission(5);
     Wire.write('L');
     Wire.endTransmission();
   }
 }
}


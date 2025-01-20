//i2c Master

#include <Wire.h>

void setup()
{
  Wire.begin();    /* Initiate the Wire library and join 
                      the I2C bus as a master or slave. This 
                      should normally be called only once. 
                      Usualmente el master no lleva dirección*/ 
                      
  Serial.begin(9600);  /* abre el puerto serie y establece 
                          la velocidad en 9600 bps para mandar
                          el caracter del master al esclavo*/
                          
                         
  Wire.requestFrom(5,10); /*Used by the master to request bytes from a 
                          slave device. The bytes may then be retrieved 
                           with the available() and read() functions. */

  while(Wire.available())  /*Wire.available(): Returns the number of bytes available 
                           for retrieval with receive(). This should be called on a 
                           master device after a call to requestFrom() or on a slave
                           inside the onReceive() handler. */
  {
  char c = Wire.read();     /*Reads a byte that was transmitted from a slave device to 
                            a master after a call to requestFrom() or was transmitted
                            from a master to a slave. read() inherits from the Stream 
                            utility class.*/
  Serial.print(c);
  }
}

void loop()
{
}



//i2c Slave code.

#include <Wire.h>
/*This library allows you to communicate with I2C / TWI (Two
wire interface) devices.*/

void setup()
{
 Wire.begin(5);     /* Initiate the Wire library and join 
                      the I2C bus as a master or slave. This 
                      should normally be called only once. 
                      Usualmente el master no lleva dirección*/ 
 
 Wire.onReceive(receiveEvent); /*Registers a function to be 
                               called when a slave device 
                               receives a transmission from 
                               a master.*/ 
 
 pinMode(13,OUTPUT); /*Configures the specified pin to behave 
                       either as an input or an output.*/
 digitalWrite(13,LOW); /*Write a HIGH or a LOW value to a 
                       digital pin.*/ 
 
}

void loop()
{
 
}

void receiveEvent(int howMany) /*Creamos un evento > handler: the function to be called
                                when the slave receives data; this should take a single 
                                int parameter (the number of bytes read from the master)
                                and return nothing, e.g.: void myHandler(int numBytes)*/ 
{
  while(Wire.available())      /*Wire.available(): Returns the number of bytes available 
                                for retrieval with receive(). This should be called on a 
                                master device after a call to requestFrom() or on a slave
                                inside the onReceive() handler. */
  {
    char c = Wire.read();      /*Reads a byte that was transmitted from a slave device to 
                               a master after a call to requestFrom() or was transmitted
                               from a master to a slave. read() inherits from the Stream 
                               utility class.*/
    
    if (c== 'H')
    {
     digitalWrite(13,HIGH); 
    }
    else if(c=='L')
    {
     digitalWrite(13,LOW); 
    }
  }
}

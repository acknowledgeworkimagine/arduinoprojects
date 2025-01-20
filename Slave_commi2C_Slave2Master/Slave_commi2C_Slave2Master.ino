//i2c Slave

#include <Wire.h>

void setup()
{
  Wire.begin(5);
  Wire.onRequest(requestEvent); /*Register a function to be called when a master 
                                requests data from this slave device*/
}

void loop()
{
  delay(100);            //Stabilize transmission.
}
  
void requestEvent()      /*Creamos un evennto > handler: the function to be called, 
                          takes no parameters and returns nothing, e.g.: void myHandler()*/
{
  Wire.write("1234567890");  /*Writes data from a slave device in response to a request from a master, 
                               or queues bytes for transmission from a master to slave device (in-between 
                               calls to beginTransmission() and endTransmission()). */
}



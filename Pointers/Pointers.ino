void setup(){
  Serial.begin(9600);
}

void loop() {
int k;
int *ptr; //Adress type variable of type int

ptr=&k;  //Storing and adress on the adress variable.
*ptr=7;  /*Storing a value on the adress stored in ptr (
          the adress variable), which is k's adress. 
          The value is 7.*/
delay(500);
Serial.println(k);

}

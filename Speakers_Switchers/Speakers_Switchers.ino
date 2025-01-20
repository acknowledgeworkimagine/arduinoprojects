
int mode_select[] = {2,12,13};
int mode_soundall[] = {3,4,5,6,7,8,9,10,11};
int mode_soundsys[] = {3,4,5,6,7,8,9};
int mode_soundsysout[] = {3,4,5,6,7,8,9,10};
int mode_soundsysin[] = {3,4,5,6,7,8,9,11};
int mode_soundout[] = {8,10};
int mode_soundin[] =  {8,11};
int mode_soundoutin[] = {8,10,11};

void setup()
{
  
   Serial.begin(9600);
   
   for(int index = 0; index<3;index++)
  {
   pinMode(mode_select[index],INPUT);
  }
  
  for(int index = 0; index<9;index++)
  {
   pinMode(mode_soundall[index],OUTPUT);
  }

  for(int index = 0; index<7;index++)
  {
   pinMode(mode_soundsys[index],OUTPUT);
  }
  
    for(int index = 0; index<2;index++)
  {
   pinMode(mode_soundout[index],OUTPUT);
  }
  
    for(int index = 0; index<2;index++)
  {
   pinMode(mode_soundin[index],OUTPUT);
  }
  

}

void loop()
{
 int in1=digitalRead(mode_select[0]);
 int in2=digitalRead(mode_select[1]);
 int in3=digitalRead(mode_select[2]);
 
 
  if (in1==LOW && in2==HIGH && in3==HIGH)
  {
    for(int index=0; index<7;index++)
    {
     digitalWrite(mode_soundsys[index],HIGH); 
    }
  }
 
  else if (in1==HIGH && in2==LOW && in3==HIGH)
  {
   for(int index=0; index<2;index++)
    {
     digitalWrite(mode_soundout[index],HIGH); 
    }
  }
  
  else if (in1==HIGH && in2==HIGH && in3==LOW)
  {
    for(int index=0; index<2;index++)
    {
     digitalWrite(mode_soundin[index],HIGH); 
    }
  }
 
    else 
  {
    
   for(int index=0; index<9;index++)
    {
     digitalWrite(mode_soundall[index],LOW); 
    }
  
  }
  
}


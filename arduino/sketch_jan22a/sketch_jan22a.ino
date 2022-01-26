#include <Servo.h>
#include <stdio.h>

Servo servo;
int vel = 30;
char in_data;

void setup() {
  // put your setup code here, to run once:
  servo.attach(6);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    in_data = Serial.read();
    
    if(in_data == 'a')
    {
      vel += 10 ;
            
    }
    else if(in_data == 'b')
    {
      vel -= 10;
    }

    if(vel <= 30)
    {
      vel=30;
    }

    if(vel >= 150)
    {
      vel = 150;
    }
  }
  for(vel = 30; vel <= 150; vel ++)
  {
    servo.write(vel);
  } 

  
}

 

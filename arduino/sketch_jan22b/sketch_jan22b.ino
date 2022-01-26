#include <Servo.h>

Servo servo;
int value = 120;
void setup() {
  // put your setup code here, to run once:
  servo.attach(11);
  Serial.begin(9600);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    char in_data;
    in_data = Serial.read();
    if(in_data == '1')       
    {
      value +=30;
      if(value == 210)
      {
        value = 0;
      }
    }
    
    else
    {
      value = 0;
    }
    
  }
  servo.write(value);
}

#include <Servo.h>
Servo s1;
int ir = D0;
int servopin = D1;
int relay = D4;
int x;

void setup() 
{
Serial.begin(9600);
pinMode(ir,INPUT);
pinMode(relay,OUTPUT);
s1.attach(servopin);
s1.write(90);
}

void loop() 
{
x = digitalRead(ir);
Serial.println(x);
if(x = 0)
{
  for(int angle = 45; angle <= 150; angle += 3)
  {
    s1.write(angle);
    digitalWrite(relay,HIGH);
    delay(50);
  }
}
else 
{
  for(int angle = 150; angle >= 45 ; angle -= 3)
  {
    s1.write(angle);
    digitalWrite(relay,LOW);
    delay(50);
  }
}
}

#include <Servo.h>
Servo s1;
const int flame = A0;
int servo_pin = 9;
int relay = 6;
int x ;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(flame, INPUT);
 pinMode(relay, OUTPUT);
 s1.attach(servo_pin);
 s1.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(flame);
  Serial.println(x);
  if(x <= 250)
  {
  for(int angle = 45 ; angle <= 150; angle += 3 )
  {
  s1.write(angle);
  digitalWrite(relay, HIGH);
  delay(50);
  }
 // delay(100);
  } 

  else if(x >= 250 && x <= 500) 
  {
    for(int angle = 150 ; angle >= 45 ; angle -= 3)
    {
      s1.write(angle);
      digitalWrite(relay, LOW);
      delay(50);
    }
    //delay(100);
  }

 if(x >= 500 && x<=1023)
  {
    for(int angle = 180 ; angle >= 90 ; angle -= 3)
    {
      s1.write(angle);
      digitalWrite(relay, LOW);
      delay(50);
    }
    //delay(1000);
  }
}

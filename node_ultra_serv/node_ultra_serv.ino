#include <Servo.h>

Servo s1;
int distance;
unsigned long duration;
float disInch;


int servopin =2 ;
const int trigPin = 0;
const int echoPin = 4;

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
s1.attach(servopin);
s1.write(90);
}

void loop() 
{
  // put your main code here, to run repeatedly:
for(int angle = 90; angle <= 180; angle += 5)
{ s1.write(angle);
  ultra_working();
}
}

void ultra_working()
{
digitalWrite(trigPin, LOW);
delay(10);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = duration*SOUND_VELOCITY/2;
delayMicroseconds(10);
disInch = distance * CM_TO_INCH;

Serial.print("distance :");
Serial.println(distance);

Serial.print("dist_inch =");
Serial.println(disInch);

delay(1000);
} 


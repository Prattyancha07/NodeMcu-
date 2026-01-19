
int distance;
unsigned long duration;
float disInch;

const int trigPin = D6;
const int echoPin = D5;

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
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

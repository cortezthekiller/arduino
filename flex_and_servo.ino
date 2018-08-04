#include <Servo.h>

Servo myServo;
int flexSensorPin = 0; //analog pin 0
int flexSensorReading // Value read from analog pin A0

void setup() {
  Serial.begin(9600);
  myServo.attach(9)
}

void loop() {

  flexSensorReading = analogRead(flexSensorPin); // valor en A0 entre 0 - 1023

  //Serial.println(flexSensorReading);

  //In my tests I was getting a reading on the arduino between 12, and 580 aprox.
  //Using map(), you can convert that to a different scale like 0-179 for the angle.
  int angle = map(flexSensorReading, 0, 600, 0, 179);
  
  Serial.println(angle);
  myServo.write(angle);


  delay(500); //just here to slow down the output for easier reading
}

#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND
/*
// Motor driver
// digital pins
const int leftForward = 2;
const int leftBackward = 4;
const int rightForward = 7;
const int rightBackward = 8;

const int leftSpeed = 3; // PWM
const int rightSpeed = 6; // PWM

void drive_car(boolean forward, int speed) {
  
      digitalWrite(leftForward, !forward);
      digitalWrite(leftBackward, forward);
      digitalWrite(rightForward, forward);
      digitalWrite(rightBackward, !forward);

      analogWrite(leftSpeed, speed);
      analogWrite(rightSpeed, speed);
      
}

void stop_car() {
  
      digitalWrite(leftForward, LOW);
      digitalWrite(leftBackward, LOW);
      digitalWrite(rightForward, LOW);
      digitalWrite(rightBackward, LOW);
      
}

void turn_car(boolean right, boolean forward, int speed) {

  if (right) {
      digitalWrite(leftForward, LOW);
      digitalWrite(leftBackward, LOW);
      digitalWrite(rightForward, forward);
      digitalWrite(rightBackward, !forward);

      analogWrite(rightSpeed, speed);
      delay(200);
  } else { // left
    
      digitalWrite(leftForward, !forward);
      digitalWrite(leftBackward, forward);
      digitalWrite(rightForward, LOW);
      digitalWrite(rightBackward, LOW);

      analogWrite(leftSpeed, speed);
      delay(200);
  }

  stop_car();
}
*/

void setup() {

  BT.begin(9600);
  Serial.begin(9600);
  Serial.println("Calentando motores ...");

/*
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(rightSpeed, OUTPUT);
  pinMode(leftSpeed, OUTPUT);
*/
  pinMode(13, OUTPUT);
}


boolean forward = true;   // forward (true) or backwards (false)
int     speed = 0; // Speed (0-255): initialize to 0

void loop() {
  if (BT.available() >= 2)  {
    unsigned int a = BT.read(); // 1st byte
    unsigned int b = BT.read(); // 2nd byte
    unsigned int val = (b * 256) + a;
    
    if ( val == 1) {
      digitalWrite(13, HIGH);
    } else if (val == 2) {
      digitalWrite(13, LOW);
    }
  } 
  /*
  if (BT.available() >= 2) { // if at least 2 bytes arrived in from BT serial

  
    unsigned int a = BT.read(); // First byte
    unsigned int b = BT.read(); // Second byte
    unsigned int val = (b * 256) + a;

    if (val >= 1000 && val <= 1255) { // This value comes from the slider

      speed = val - 1000;
      Serial.print("Speed: ");
      Serial.println(speed);
      //drive_car(forward, speed); // Al cambiar la velocidad que siga conduciendo a la nueva velocidad

    } else if (val == 1) {

      Serial.println("FWD received");
      digitalWrite(13, HIGH);
      forward = true;
      //drive_car(forward, speed);

    } else if (val == 0) {

      Serial.println("OFF received");
      //stop_car();

    } else if (val == 2) {

      Serial.println("BACKWARDS received");
      digitalWrite(13, LOW);
      forward = false; // direction backwards
      //drive_car(forward, speed);

    } else if (val == 3) {

      Serial.print("RIGHT received - speed: "); 
      Serial.println(speed);
      //turn_car(true, forward, speed); // right = true

    } else if (val == 4) {

      Serial.print("LEFT received - speed: "); 
      Serial.println(speed);
      //turn_car(false, forward, speed); // right = false (left)

    }
  }*/

}

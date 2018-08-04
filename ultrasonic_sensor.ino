int  echoPin    = 9;
int  triggerPin = 5;
long pulseDelay, dist;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  //                 _
  // Trigger pulse _| |_____
 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);

  // pulseIn(): reads a pulse (either HIGH or LOW) on a pin. 
  // For example, if value is HIGH, pulseIn() waits for the 
  // pin to go HIGH, starts timing, then waits for the pin 
  // to go LOW and stops timing. Returns the length of the 
  // pulse in microseconds. Gives up and returns 0 if no pulse 
  // starts within a specified time out.
  
  pulseDelay = pulseIn(echoPin, HIGH);

  dist = pulseDelay/58.2; // Distance in cm.
  //Serial.println(dist);
  if (dist <= 10) {
    for (int i=0; i < 5; i++) {
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);

    }
  }

  delay(50); // Delay 50 ms before next reading.
}

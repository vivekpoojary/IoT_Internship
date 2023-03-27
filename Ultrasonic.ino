digitalWrite(9, HIGH);
delayMicroseconds(10);
digitalWrite(9, LOW);
duration_us = pulseIn(8, HIGH);
distance_cm = 0.017 * duration_us;

int trigPin = 9;  // TRIG pin
int echoPin = 8;  // ECHO pin

float duration_us, distance_cm;

void setup() {
  // begin serial port
  Serial.begin(9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}

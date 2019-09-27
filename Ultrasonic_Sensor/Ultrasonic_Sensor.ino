#define TRIG_PIN 2
#define ECHO_PIN 3

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Clear the trigger pin for 5 microseconds:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  
  // Trigger the sensor by setting the trigger pin high for 10 microseconds:
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // The distance is equal to half of the duration because it travelled to the object and back
  // divided by the speed of sound (approximately 340 m/s).
  distance = duration / 2 * 0.034;
  
  // Print the distance on the Serial Monitor:
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);
}

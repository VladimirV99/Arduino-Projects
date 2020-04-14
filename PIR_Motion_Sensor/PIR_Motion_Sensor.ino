#define INPUT_PIN 2

int status = LOW;
int new_status;

void setup() {
  pinMode(INPUT_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Read the motion sensor output
  new_status = digitalRead(INPUT_PIN);

  // If the sensor status changed send information about the change
  if(new_status == HIGH && status == LOW) {
    Serial.println("Motion detected");
  } else if(new_status == LOW && status == HIGH) {
    Serial.println("Motion ended");
  }

  status = new_status;
  
  delay(100);
}
#define PASSIVE_BUZZER_PIN 5
#define ACTIVE_BUZZER_PIN 6

void setup() {
  pinMode(PASSIVE_BUZZER_PIN, OUTPUT);
  pinMode(ACTIVE_BUZZER_PIN, OUTPUT);
}

void loop() {
  /*
   * Passive buzzer
   */
  // Frequency loop from 200 to 800
  for(int i = 200; i <= 800; i = i + 5) {
    tone(PASSIVE_BUZZER_PIN, i); // Set buzzer frequency to i
    delay(10);
  }
  
  delay(1000); // Wait for 4 seconds on highest frequency
  
  // Frequency loop from 800 down to 200
  for(int i = 800; i >= 200; i = i - 5) {
    tone(PASSIVE_BUZZER_PIN,i);
    delay(10);
  }
  noTone(PASSIVE_BUZZER_PIN); // Stop the buzzer

  delay(1000);

  /*
   * Active buzzer
   */
  for(int i = 0; i < 100; i++) {
    digitalWrite(ACTIVE_BUZZER_PIN, HIGH);
    delay(1);
    digitalWrite(ACTIVE_BUZZER_PIN, LOW);
    delay(1);
  }

  delay(1000);
}

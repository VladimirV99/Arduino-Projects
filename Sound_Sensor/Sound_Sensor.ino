#define SENSOR_PIN 3
#define LIGHT_PIN 2

int claps = 0;
long detection_start = 0;
long detection_last = 0;
boolean lights = false;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  int sensor_data = digitalRead(SENSOR_PIN);

  // Count the number of claps
  if(sensor_data == 1) {
    if(claps == 0) {
      detection_start = millis();
      detection_last = millis();
      claps++;
    }else if (claps > 0 && millis() - detection_last >= 50) {
      detection_last = millis();
      claps++;
    }
  }

  // Wait for 400ms to pass since the first clap
  if (millis() - detection_start >= 400) {
    // Trigger the light if the number of claps is 2
    if (claps == 2) {
      if (!lights) {
        lights = true;
        digitalWrite(LIGHT_PIN, HIGH);
      } else {
        lights = false;
        digitalWrite(LIGHT_PIN, LOW);
      }
    }
    // Reset the number of claps
    claps = 0;
  }
  
}

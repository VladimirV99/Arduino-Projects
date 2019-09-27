#include <Servo.h>

#define SERVO_PIN 8

Servo servo;

int angle = 10;

void setup() {
  servo.attach(SERVO_PIN); // Attach servo to pin 8
  servo.write(angle); // Move servo to specified angle
}

void loop() {
  // scan from 0 to 180 degrees
  for(angle = 10; angle < 180; angle++) {                                  
    servo.write(angle);
    delay(15);
  }
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 10; angle--) {
    servo.write(angle);
    delay(15);
  }
}

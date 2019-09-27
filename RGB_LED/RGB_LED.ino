#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
    // Basic colors: 
  color(255, 0, 0); // red 
  delay(1000);
  color(0,255, 255); // green  
  delay(1000);
  color(0, 0, 255); // blue  
  delay(1000);
  
  // Example blended colors:  
  color(255,0,0); // red  
  delay(1000);
  color(237,109,0); // orange  
  delay(1000);
  color(255,215,0); // yellow  
  delay(1000);
  color(34,139,34); // green  
  delay(1000);
  color(0,0,255); // blue  
  delay(1000);
  color(0,46,90); // indigo 
  delay(1000);
  color(128,0,128); // purple  
  delay(1000);
}

void color (unsigned char red, unsigned char green, unsigned char blue) {    
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

#define VR_X_PIN A0
#define VR_Y_PIN A1
#define SW_PIN 2

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VR_X_PIN, INPUT);
  pinMode(VR_Y_PIN, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(SW_PIN, INPUT_PULLUP); 
}

void loop() {
  xPosition = analogRead(VR_X_PIN);
  yPosition = analogRead(VR_Y_PIN);
  buttonState = digitalRead(SW_PIN);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(100);
}

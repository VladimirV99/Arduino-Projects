#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

// Set to your tag UID
#define TAG_UID ""

// Create an MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);   
 
void setup() {
  Serial.begin(9600);

  // Initialize SPI bus
  SPI.begin();
  // Initialize MFRC522
  mfrc522.PCD_Init();

  Serial.println("Scan your tag...");
}

void loop() {
  // Search for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Print the cards UID
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  
  // Try to match to known cards
  content.toUpperCase();
  if(content.substring(1) == TAG_UID) {
    Serial.println("Access granted");
  } else {
    Serial.println("Access denied");
  }

  delay(3000);
}
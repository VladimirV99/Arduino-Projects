#include <IRremote.h>

#define RECV_PIN 7

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
     Serial.println(results.value);
     
    delay(100);
    irrecv.resume();
  }
}

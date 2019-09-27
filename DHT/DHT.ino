#include "DHT.h"

#define DHT_TYPE DHT11 // DHT 11
//#define DHT_TYPE DHT21 // DHT 21
//#define DHT_TYPE DHT22 // DHT 22

#define DHT_PIN 2 // Pin sensor is connected to
 
DHT dht(DHT_PIN, DHT_TYPE);
 
void setup(){
  Serial.begin(9600);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
}
 
void loop(){
  delay(2000); // Wait at least 2 seconds between measurements

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float tc = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float tf = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(tc) || isnan(tf)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(tf, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(tc, h, false);
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(tc);
  Serial.print("°C / ");
  Serial.print(tf);
  Serial.print("°F\t"); 
  Serial.println("Heat Index");
  Serial.print(hic);
  Serial.print("°C / ");
  Serial.print(hif);
  Serial.println("°F");
}

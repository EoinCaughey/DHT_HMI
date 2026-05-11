#include <Arduino.h>
#include <DHT.h>

// sets DHT pin and model!
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int LED = 2;

float temperature = 0;
float humidity = 0;

void setup() {
  
  Serial.begin(115200);
  dht.begin();
  delay(1000);

  digitalWrite(LED, LOW);

}

void loop() {

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Error 001: NaN");
    return;
  }

  digitalWrite(LED, HIGH);
  Serial.print(temperature);
  Serial.print(",");
  Serial.println(humidity);
  

  delay(700);
  digitalWrite(LED, LOW);
  delay(300);

}
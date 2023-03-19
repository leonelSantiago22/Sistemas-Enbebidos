#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h>
#include <DHT_U.h>

int SENSOR = 2; 
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT11);
void setup() {
    Serial.begin(9600);
    dht.begin();
}

void loop() {
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA);

  Serial.print("  Humedad :");
  Serial.println(HUMEDAD);

  delay(5000);

}

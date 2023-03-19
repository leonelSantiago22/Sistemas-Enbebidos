#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_BMP280.h>


Adafruit_BMP280 bmp;
void setup() {
    Serial.begin(9600);
    if(!bmp.begin())
    {
      Serial.print("no se encontro el sensor BMP280, revise su conexion");
      while(1){}
    }
}

void loop() {
  Serial.println("Temepratura = ");
  Serial.println(bmp.readTemperature());
  Serial.println(" *C");

  Serial.println("Presion =");
  Serial.println(bmp.readAltitude());
  Serial.println("metros");
/*
  Serial.println("Presion calculada sobre el nivel del mar = ");
  Serial.println(bmp.readSealevelPressure());
  Serial.println("Pa");
*/ //Este pedazo de lineas de codigo esta mal 
  Serial.println("Altitud real = ");
  Serial.println(bmp.readAltitude(101500));
  Serial.println("metros");

  Serial.println();
  delay(500);



}

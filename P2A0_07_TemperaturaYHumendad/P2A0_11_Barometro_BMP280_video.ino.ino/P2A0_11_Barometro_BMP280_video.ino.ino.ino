#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>

#include <Adafruit_Sensor.h>

#include <Adafruit_BMP280.h>

#include <Wire.h>
#include <SPI.h>

Adafruit_BMP280 bmp;
void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
    if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
}
void loop() 
{
    Serial.print(F("Temperatura = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    Serial.print(F("Presión = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    Serial.print(F("Altitud = "));
    Serial.print(bmp.readAltitude(1013.25));
    Serial.println(" m");
    Serial.println();
    delay(2000);
}
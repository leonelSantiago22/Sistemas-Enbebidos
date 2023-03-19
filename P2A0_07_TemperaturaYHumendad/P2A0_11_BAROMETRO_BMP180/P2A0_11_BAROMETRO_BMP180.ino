#include <Adafruit_BMP085.h>



#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>


//conectar VCC a 3.3V
//conectar GND a Ground
//conectar SCL  a i2c clock - en Analog 5
//conectar SDA a i2c data - en Aanalog 4
//EOC no es usado
//XCLR es el pin de reset

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  if(!bmp.begin()){
    Serial.println("No se encontró el sentor BMP180, revise sus conexiones!");
    while(1){}
  }
}

void loop() {
  Serial.print("Temperatura = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Presión = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  //Calcula la altitud 
  Serial.print("Altitud = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" metros");

  Serial.print("Presión calculada sobre el nivel del mar = ");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");

  //
  Serial.print("Altitud real = ");
  Serial.print(bmp.readAltitude(101500));
  Serial.println(" metros");

  Serial.println();
  delay(500);

}

#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal_I2C.h> //DESCARGAR LIBRERÍA:https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip
#include <OneWire.h>                
#include <DallasTemperature.h>
 
OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire
 
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

LiquidCrystal_I2C lcd(0x27,16,2) ; // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {

  Serial.begin(9600);
  sensors.begin();   //Se inicia el sensor
  lcd.init();
  lcd.backlight();
  lcd.clear();

  
}

void loop() { 
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC

  lcd.setCursor(4,0);
  lcd.print("Temperatura: ");
  lcd.setCursor(0,1);
  lcd.print(temp);
  delay(300);   
  
}
#include <GravityTDS.h>

#include <EEPROM.h>
#include "GravityTDS.h"
#include <LiquidCrystal.h>

// Definimos el pin analógico donde irá conectado el medidor de partículas TDS 
// y también los pines digitales donde irán conectaos los LEDS
#define TdsSensorPin A0
#define GreenLED 10
#define YellowLED 9
#define RedLED 8

// Instanciamos el objeto GravityTDS y LiquidCrystal para poder usar los sensores
GravityTDS gravityTds;
// LiquidCrystal(rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// El valor ppm leído por el sensor TDS varía en función de la temperatura
// por lo que es esencial definir la temperatura del agua o añadir un sensor
// de temperatura

// Definimos temperatura del agua a medir y el valor ppm en seco (0 ppm)
float temperature = 15, tdsValue = 0;

// Configuración inicial 
void setup()
{
  Serial.begin(115200);

  // Inicializamos la pantalla LCD 
  lcd.begin(16,2);

  // Configuramos el pin donde irá conectado el sensor TDS
  gravityTds.setPin(TdsSensorPin);
  // Definimos voltaje de referencia del ADC (5V en Arduino UNO)
  gravityTds.setAref(5.0);  
  // Definimos el rango del ADC (1024 en Arduino UNO)
  gravityTds.setAdcRange(1024);  
  // Inicializamos el sensor
  gravityTds.begin();  
  
  // Configuramos como salida los pines donde están conectados loso LEDS
  pinMode(RedLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
}

// Ejecución contínua
void loop()
{
  // Ejecutamos la compensación por temperatura indicando la temperatura del agua a testear
  gravityTds.setTemperature(temperature);  
  // Ejecutar una lectura
  gravityTds.update();  
  // Obtener el valor en PPM 
  tdsValue = gravityTds.getTdsValue(); 

  // Imprimimos por consola el valor leído
  Serial.print(tdsValue,0);
  Serial.println("ppm");

  // Limpiamos la pantalla 
  lcd.clear();

  // Ponemos el cursor en la columna y fila deseada y escribimos la información
  lcd.setCursor(4, 0);
  lcd.print("Calidad Agua");
  lcd.setCursor(4, 1);
  lcd.print(tdsValue, 0);
  lcd.print(" ppm");
 
  // En función al valor leído por el sensor TDS, encendemos un LED u otro 
  // para indicar la calidad del agua. Valores extraídos de la OMS.

  /* Según la OMS, el nivel de TDS ideal en agua (mg/l):
      Menos de 300: Excelente
      300 – 600: Bueno
      600 – 900: Regular
      900 – 1,200: Pobre
      Más de 1,200: Inaceptable
   */
  if(tdsValue > 0 && tdsValue <= 300){
    digitalWrite(GreenLED, HIGH);
    delay(200);
    digitalWrite(GreenLED, LOW);
    delay(200);
  }else if(tdsValue > 300 && tdsValue <= 600){
    digitalWrite(YellowLED, HIGH);
    delay(200);
    digitalWrite(YellowLED, LOW);
    delay(200);
  }else if(tdsValue > 600){
    digitalWrite(RedLED, HIGH);
    delay(200);
    digitalWrite(RedLED, LOW);
    delay(200);
  }

  delay(100);
}


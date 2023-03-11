int LED_ROJO = 9;
int LED_VERDE = 10;
int LED_AZUL = 11;

int BRILLO;
int POT = A0;

void setup() {
  pinMode(LED_ROJO, OUTPUT); //Se configura el pin 9 como salida
  pinMode(LED_VERDE, OUTPUT); //Se configura el pin 10 como salida
  pinMode(LED_AZUL, OUTPUT); //Se configura el pin 11 como salida

}

void loop() {
  //Se despliega el color amarillo
  analogWrite(LED_ROJO, 255 - 255);
  analogWrite(LED_VERDE, 255 - 255);
  analogWrite(LED_AZUL, 255 - 0);
  delay(2000);
  //Se despliega el color cian
  analogWrite(LED_ROJO, 255 - 0);
  analogWrite(LED_VERDE, 255 - 255);
  analogWrite(LED_AZUL, 255 - 255);
  delay(2000);
  //Se despliega el color magenta
  analogWrite(LED_ROJO, 255 - 255);
  analogWrite(LED_VERDE, 255 - 0);
  analogWrite(LED_AZUL, 255 - 255);
  delay(2000);

}

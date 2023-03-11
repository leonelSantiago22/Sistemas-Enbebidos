int LED_ROJO = 9;
int LED_VERDE = 10;
int LED_AZUL = 11;

int BRILLO;
int POT = A0;
void setup() {
  pinMode(LED_ROJO, OUTPUT);//Se configura el pin 9 como salida
  pinMode(LED_VERDE, OUTPUT); //Se configura el pin 10 como salida
  pinMode(LED_AZUL, OUTPUT); //Se configura al pin 11 como salida
}

void loop() {
  miColor(255, 255, 0); //Se despliega el color amarillo
  delay(2000);

  miColor(255, 118, 192); //Se despliega el color rosa
  delay(2000);

  miColor(0, 255, 255); //Se despliega el color cian
  delay(2000);

  miColor(255, 0, 255); //Se despliega el color magenta
  delay(2000);
}

void miColor(int rojo, int verde, int azul){
  analogWrite(LED_ROJO, rojo);
  analogWrite(LED_VERDE, verde);
  analogWrite(LED_AZUL, azul);
}

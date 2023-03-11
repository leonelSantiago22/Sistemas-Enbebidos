int LED_ROJO = 9;
int LED_VERDE = 10;
int LED_AZUL = 11;

int BRILLO;
int POT = A0;

void setup() {
  pinMode(LED_ROJO, OUTPUT);// Se configura el pin9 como salida
  pinMode(LED_VERDE, OUTPUT);//Se configura el pin10 como salida
  pinMode(LED_AZUL, OUTPUT); //Se configura el pin 11 como salida
}

void loop() {
   //Se despliega el color rojo
  analogWrite(LED_ROJO, 255);
  analogWrite(LED_VERDE, 0);
  analogWrite(LED_AZUL, 0);
  delay(2000);
  //Se despliega el color verde
  analogWrite(LED_ROJO,0);
  analogWrite(LED_VERDE,255);
  analogWrite(LED_AZUL,0);
  delay(2000);
  //Se despliega el color azul
  analogWrite(LED_ROJO,0);
  analogWrite(LED_VERDE,0);
  analogWrite(LED_AZUL,255);
  delay(2000);
 

}

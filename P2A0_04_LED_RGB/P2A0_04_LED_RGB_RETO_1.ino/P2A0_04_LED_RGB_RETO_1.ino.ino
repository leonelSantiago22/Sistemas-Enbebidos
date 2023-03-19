int LED_ROJO = 9;
int LED_VERDE = 10;
int LED_AZUL = 11;
int POT_ROJO = A0;
int POT_VERDE = A1; 
int POT_AZUL = A2;
int BRILLO_ROJO;
int BRILLO_VERDE;
int BRILLO_AZUL;

void setup() {
    pinMode(LED_ROJO, OUTPUT);// Se configura el pin9 como salida
    pinMode(LED_VERDE, OUTPUT);//Se configura el pin10 como salida
    pinMode(LED_AZUL, OUTPUT); //Se configura el pin 11 como salida
  // put your setup code here, to run once:
}

void loop() {
  BRILLO_ROJO = analogRead(POT_ROJO)/4;
  analogWrite(LED_ROJO, BRILLO_ROJO);
  BRILLO_VERDE = analogRead(POT_VERDE)/4;
  analogWrite(LED_VERDE, BRILLO_VERDE);
  BRILLO_AZUL = analogRead(POT_AZUL)/4;
  analogWrite(LED_AZUL, BRILLO_AZUL);
}

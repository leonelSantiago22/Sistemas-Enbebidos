int PIR = 2;
int RELE = 3;
int ESTADO = 0;

void setup() {
  pinMode(PIR,INPUT);
  pinMode(RELE, OUTPUT);
  delay(20000);
}

void loop() {
  ESTADO= digitalRead(PIR);

  if (ESTADO == HIGH){
    digitalWrite(RELE,LOW);
    delay(4000);
  }
  else
  {
        digitalWrite(RELE,HIGH);
  }
}

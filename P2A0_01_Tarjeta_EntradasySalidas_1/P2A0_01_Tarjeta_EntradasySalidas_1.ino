void setup() {
  
  pinMode(2, INPUT); //PIN 2 configurado como ENTRADA
  pinMode(3, OUTPUT); //PIN 3 configurado como SALIDA

}

void loop() {
  if(digitalRead (2) == HIGH)
  {
    digitalWrite(3, HIGH);
  }else
  {
    digitalWrite(3, LOW);
  }
}
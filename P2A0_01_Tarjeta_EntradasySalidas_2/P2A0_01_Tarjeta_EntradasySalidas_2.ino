int PULSADOR = 2;
int LED = 3;
int ESTADO = LOW;

void setup()
{
  pinMode(PULSADOR, INPUT);
  pinMode(LED, OUTPUT);
}
void loop()
{
  while(digitalRead(PULSADOR)==LOW)
  {

  }
  ESTADO = digitalRead(LED);
  digitalWrite(LED, !ESTADO);

  while(digitalRead(PULSADOR)==HIGH)
  {
    
  }
}
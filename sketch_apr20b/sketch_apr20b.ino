int TRIG = 10;
int ECO = 9;
int LED_R = 3;
int LED_G = 5;
int LED_B = 6;

float DURACION;
float DISTANCIA;

void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  DURACION = pulseIn(ECO, HIGH);

  DISTANCIA = DURACION / 58.0;

  Serial.print("Distancia: ");
  Serial.println(DISTANCIA);

  if (DISTANCIA >= 100)
  { // distancia lejana
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  }
  else if (DISTANCIA > 50 && DISTANCIA <= 100)
  { // distancia media
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  }
  else
  { // distancia cercana
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_R, HIGH);
    delay(map(DISTANCIA, 0, 50, 20, 200)); // Parpadeo más rápido conforme se acerca el objeto
    digitalWrite(LED_R, LOW);
    delay(map(DISTANCIA, 0, 50, 20, 200));
  }
}
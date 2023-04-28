// Definir pines
#define trigPin 3
#define echoPin 2
#define redPin 9
#define greenPin 10
#define bluePin 11
int TRIG = 3;
int ECO = 2;
int LED_R = 9;
int LED_G = 10;
int LED_B = 11;

float DURACION;
float DISTANCIA;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Generar pulso de disparo para el sensor ultrasónico
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Leer el tiempo de eco del sensor ultrasónico
  DURACION = pulseIn(ECO, HIGH);

  // Calcular la distancia en centímetros
  DISTANCIA = DURACION / 58.0;

  // Imprimir la distancia en la consola serial
  Serial.print("Distancia: ");
  Serial.println(DISTANCIA);

  // Configurar los valores del LED RGB en función de la distancia medida
  if(DISTANCIA >= 30) { // distancia lejana
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
     delay(map(DISTANCIA, 2, 10, 20, 100));
    digitalWrite(LED_G, LOW);
    delay(map(DISTANCIA, 2, 10, 20, 100));

    
 
  } else if(DISTANCIA > 10 && DISTANCIA < 30){ // distancia media
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, 0);
    digitalWrite(LED_B, 255);
    
    delay(map(DISTANCIA, 2, 10, 20, 100));
    digitalWrite(LED_B, LOW);
    delay(map(DISTANCIA, 2, 10, 20, 100));
  } else if(DISTANCIA >= 2 && DISTANCIA <= 10){ // distancia cercana
    digitalWrite(LED_G, 0);
    digitalWrite(LED_B, 0);
    digitalWrite(LED_R, HIGH);
    delay(map(DISTANCIA, 2, 10, 20, 100)); // Parpadeo más rápido conforme se acerca el objeto
    digitalWrite(LED_R, LOW);
    delay(map(DISTANCIA, 2, 10, 20, 100));
  } else { // demasiado cerca
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  }
}

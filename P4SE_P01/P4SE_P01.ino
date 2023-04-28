// Definición de los pines para el sensor ultrasónico y el LED RGB
#define trigPin 3
#define echoPin 2
#define redPin 9
#define greenPin 10
#define bluePin 11

// Variables para el tiempo y la distancia
long duration;
int distance;

// Variables para los colores
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  // Configuración de los pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Comunicación serial para la depuración
  Serial.begin(9600);
}

void loop() {
  // Generación del pulso de disparo para el sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lectura del tiempo de eco del sensor ultrasónico
  duration = pulseIn(echoPin, HIGH);
  
  // Cálculo de la distancia en centímetros
  distance = duration * 0.034 / 2;

  // Ajuste del color del LED RGB en función de la distancia medida
  if (distance >= 20) {
    // Verde si la distancia es mayor o igual a 20 cm
    redValue = 0;
    greenValue = 255;
    blueValue = 0;
  } else if (distance < 20 && distance >= 10) {
    // Azul si la distancia es menor a 20 cm y mayor o igual a 10 cm
    redValue = 0;
    greenValue = 0;
    blueValue = 255;
  } else {
    // Rojo si la distancia es menor a 10 cm
    redValue = 255;
    greenValue = 0;
    blueValue = 0;
  }
  
  // Ajuste de la velocidad del parpadeo del LED RGB en función de la distancia medida
  int blinkSpeed = map(distance, 0, 20, 100, 500);
  
  // Parpadeo del LED RGB
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  delay(blinkSpeed);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  delay(blinkSpeed);
  
  // Impresión de la distancia en la consola serial
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

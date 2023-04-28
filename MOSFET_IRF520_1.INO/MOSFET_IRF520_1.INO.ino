#define MOSFET 3

int BRILLO;

void setup() {
  pinMode(MOSFET, OUTPUT);// put your setup code here, to run once:
}

void loop() {
  digitalWrite(MOSFET, HIGH);
  delay(1000);
  digitalWrite(MOSFET, LOW);
  delay(1000);// put your main code here, to run repeatedly:
}

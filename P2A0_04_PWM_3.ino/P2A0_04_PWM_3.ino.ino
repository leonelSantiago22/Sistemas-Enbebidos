int LED = 3;
int BRILLO;
int POT = A0;

void setup() {
  pinMode(LED, OUTPUT);// put your setup code here, to run once:

}

void loop() {
  BRILLO= analogRead(POT)/4;
  analogWrite(LED, BRILLO);// put your main code here, to run repeatedly:

}

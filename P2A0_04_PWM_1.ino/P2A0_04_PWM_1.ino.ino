int LED = 3;
int BRILLO;

void setup() {
  pinMode(LED, OUTPUT); // Se configura al pin 3

}

void loop() {
  
    analogWrite(LED, 32);  //Se genera PWM, 
    delay(10);   
}

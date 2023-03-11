int LED = 3;
int BRILLO;


void setup() {
  pinMode(LED, OUTPUT);// put your setup code here, to run once:

}

void loop() {
  for(BRILLO=0; BRILLO<256; BRILLO++){
    analogWrite(LED, BRILLO);
    delay(50);
  }
  for(BRILLO=255; BRILLO>=0; BRILLO--){
    analogWrite(LED, BRILLO);
    delay(50);
  }
}



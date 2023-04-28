#define MOSFET 3;

int BRILLO;

void setup() {
  pinMode(MOSFET, OUTPUT);// put your setup code here, to run once:

}

void loop() {
  for(BRILLO=0; BRILLO<256; BRILLO++){
    analogWrite(MOSFET, BRILLO);
    delay(25);
  }
   
   for(BRILLO=255; BRILLO>=0; BRILLO--){
     analogWrite(MOSFET, BRILLO);
     delay(25);
   }

}

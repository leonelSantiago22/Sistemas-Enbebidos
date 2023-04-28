int LED_TARJ_ESP32 = 2; 

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_TARJ_ESP32, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_TARJ_ESP32, HIGH);
  delay(300);
  digitalWrite(LED_TARJ_ESP32, LOW);
  delay(50);
  
}

void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(350);
  digitalWrite(2, LOW);
  delay(350);
}

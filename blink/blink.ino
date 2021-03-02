void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(5000);
  digitalWrite(2, LOW);
  delay(5000);
}

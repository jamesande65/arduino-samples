void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  delay(20000);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  delay(100);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  delay(20000);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  delay(100);
}

int analogPin = A3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analog = analogRead(A3);
  Serial.println(analog);
  delay(1000);
}

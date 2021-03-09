int analogPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analog = analogRead(A0);
  Serial.println(analog);
  delay(1000);
}

int musicArr[3] = {1, 2, 3};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    Serial.println(musicArr[i]);
    delay(1000);
  }
}

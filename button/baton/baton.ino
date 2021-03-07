int val;
int buttonsPin = 34;

void setup() {
  Serial.begin(9600);
  pinMode (buttonsPin, INPUT);
}

void loop() {
  val = analogRead(buttonsPin);
  if (val > 3900){
    Serial.println(1);
  } else if (val > 2900) {
    Serial.println(2);
  } else if (val > 2100) {
    Serial.println(3);
  } else if (val > 1500) {
    Serial.println(4);
  } else if (val > 900) {
    Serial.println(5);
  } else if (val > 400) {
    Serial.println(6);
  } else {
    Serial.println("Push the button motherfacker");
  }
  delay(150);
}

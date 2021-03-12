
const byte interruptPin2 = 2;
//volatile byte state2 = LOW;
int sensorVal1;

void manageBack() {
  sensorVal1 = LOW;
  digitalWrite(6, LOW);
  //if (!state2) {
   // digitalWrite(6, LOW);  
  //}
  //state2 = !state2;
}

void setup() {
  // put your setup code here, to run once:

  pinMode (2, INPUT);  //first sensor
  pinMode (6, OUTPUT);  //train moove back
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), manageBack, CHANGE);
  
  sensorVal1 = digitalRead(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (sensorVal1 == HIGH) {  // читаем значение сенсора
    digitalWrite(6, HIGH);
  }
}

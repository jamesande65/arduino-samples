int val; 

void setup() {
  pinMode (5, INPUT);  
  pinMode(2, OUTPUT);
  //pinMode(4, OUTPUT);
}

void loop() {
  val = digitalRead (5) ; // читаем сенсор
  
  if (val == LOW) {
    digitalWrite(2, LOW);
    //digitalWrite(4, HIGH);
  } else {
    //digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
  }
}

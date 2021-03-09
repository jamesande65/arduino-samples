int val1; 
int val2; 

void setup() {
  pinMode (9, INPUT);  
  pinMode (8, INPUT);
  pinMode (2, OUTPUT);  
  pinMode (3, OUTPUT);
  //pinMode(4, OUTPUT);
}

void loop() {
  val1 = digitalRead (9);
  val2 = digitalRead (8); // читаем сенсор
  
  if (val1 == HIGH) {
    //digitalWrite(, LOW);
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
   // digitalWrite(, HIGH);
  }

}

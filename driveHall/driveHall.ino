int val(1); 
int val(2); 

void setup() {
  pinMode (9, INPUT);  
  pinMode (8, OUTPUT);
  pinMode (2, INPUT);  
  pinMode (3, OUTPUT);
  //pinMode(4, OUTPUT);
}

void loop() {
  val(1) = digitalRead (9);
  val(2) = digitalRead (8); // читаем сенсор
  
  if (val(1) == HIGH) {
    //digitalWrite(, LOW);
    digitalWrite(2, LOW);
  } 
  else {
    digitalWrite(2, HIGH);
   // digitalWrite(, HIGH);
  }
  if (val(2) == HIGH) {
    //digitalWrite(, LOW);
    digitalWrite(3, LOW);
  } 
  else {
    digitalWrite(3, HIGH);
   // digitalWrite(, HIGH);
  }
}

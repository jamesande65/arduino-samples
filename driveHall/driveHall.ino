int val(1); 
int val(2); 

void setup() {
<<<<<<< HEAD
  pinMode (9, INPUT);  
  pinMode (8, OUTPUT);
  pinMode (2, INPUT);  
  pinMode (3, OUTPUT);
=======
  Serial.begin(9600);
  pinMode (5, INPUT);  
 // pinMode(2, OUTPUT);
>>>>>>> 1942d6823b0b230e54d61e1eccd2d5f5a94055ed
  //pinMode(4, OUTPUT);
}

void loop() {
<<<<<<< HEAD
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
=======
  val = analogRead (5) ; // читаем сенсор
  
   if (val == LOW) {
   // digitalWrite(2, LOW);
    //digitalWrite(4, HIGH);
  } else {
    Serial.println("tyt");
    //digitalWrite(4, LOW);
   // digitalWrite(2, HIGH);
>>>>>>> 1942d6823b0b230e54d61e1eccd2d5f5a94055ed
  }
}

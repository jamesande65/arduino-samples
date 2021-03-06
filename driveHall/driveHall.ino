int val; 

void setup() {
  Serial.begin(9600);
  pinMode (5, INPUT);  
 // pinMode(2, OUTPUT);
  //pinMode(4, OUTPUT);
}

void loop() {
  val = analogRead (5) ; // читаем сенсор
  
   if (val == LOW) {
   // digitalWrite(2, LOW);
    //digitalWrite(4, HIGH);
  } else {
    Serial.println("tyt");
    //digitalWrite(4, LOW);
   // digitalWrite(2, HIGH);
  }
}

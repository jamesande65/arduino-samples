
void setup() {
  pinMode (4, INPUT);  
  pinMode (5, INPUT);
  //pinMode(4, OUTPUT);
}

void loop() {  
    delay(5000);
    digitalWrite(4, HIGH);
    delay(3700);  //1650 children ticket  3700 adult ticket
    digitalWrite(4, LOW);
    delay(1000);
    digitalWrite(5, HIGH);
    delay(1850);
    digitalWrite(5, LOW);
    delay(1000);
    
  }

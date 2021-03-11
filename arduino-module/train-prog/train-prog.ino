int val;  

void setup() {
  // put your setup code here, to run once:
pinMode (11, OUTPUT);   //blue light
pinMode (12, OUTPUT);   //whight light
pinMode (13, OUTPUT);   //red light
pinMode (14, OUTPUT);   //green light
pinMode (2, OUTPUT);  // train moove forvard
pinMode (3, OUTPUT);  //train moove back
pinMode (4, OUTPUT);  //pump forvard
pinMode (5, OUTPUT);  // pump back
pinMode (6, INPUT);  //first sensor
pinMode (7, INPUT); //second sensor
pinMode (8, INPUT);  // third sensor

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,HIGH); //blue light
  digitalWrite(13,HIGH); //red light
  val = digitalRead (7); // читаем сенсор
  if (val == LOW) {
    //digitalWrite(, LOW);
    digitalWrite(3, LOW);
  } else {
    digitalWrite(3, HIGH);
   // digitalWrite(, HIGH);
  }

}

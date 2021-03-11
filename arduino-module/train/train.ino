void setup() {
  // put your setup code here, to run once:
pinMode (11, OUTPUT);   //hall back
pinMode (13, OUTPUT);   //hall back
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,HIGH); //blue light
  digitalWrite(13,HIGH); //red light
}
//pinMode (12, OUTPUT);   //whight light
//pinMode (14, OUTPUT);   //green light
//pinMode (11, OUTPUT);   //blue light
//pinMode (13, OUTPUT);   //red light

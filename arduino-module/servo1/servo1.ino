#include <Servo.h>


//Servo servo1;
Servo servo1;
//Servo myservo2;
//int pos = 0;
//int deg1 = 180;
//int deg2 = 250;

void setup() {
  servo1.attach(7);
  
}

void loop() {
  servo1.write(107);
  delay(2000);
  servo1.write(23);
  delay(2000);
  servo1.write(107);
  delay(2000);
}

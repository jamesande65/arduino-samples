#include <Servo.h>


//Servo servo1;
Servo servo1;
Servo servo2;
//Servo myservo2;
//int pos = 0;
//int deg1 = 180;
//int deg2 = 250;

void setup() {
  //servo1.attach(6);
  servo1.attach(9);
  servo2.attach(10);
  //servo1.write(23);
}

void loop() {
  servo1.write(107);
  delay(2000);
  servo2.write(190);
  delay(2000);
  servo2.write(0);
  delay(2000);
  servo1.write(23);
  delay(2000);
}

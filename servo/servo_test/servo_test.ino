#include <Servo.h>


//Servo myservo1;
Servo myservo2;
int pos = 0;
int deg1 = 180;
int deg2 = 180;

void setup() {
//  myservo1.attach(6);
  myservo2.attach(7);
}

void loop() {
//  for (pos = 0; pos <= deg1; pos += 1) {
//    myservo1.write(pos);
//    delay(5);
//  }
//  for (pos = deg1; pos >= 0; pos -= 1) {
//    myservo1.write(pos);
//    delay(5);
//  }
  for (pos = 0; pos <= deg2; pos += 1) {
    myservo2.write(pos);
    delay(5);
  }
  for (pos = deg2; pos >= 0; pos -= 1) {
    myservo2.write(pos);
    delay(5);
  }
}

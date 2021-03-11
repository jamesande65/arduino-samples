
#include "GyverButton.h"
#include <Servo.h>
GButton myButt1;
GButton myButt2;
GButton myButt3;
GButton myButt4;
GButton myButt5;
GButton myButt6;

Servo servo1;
Servo servo2;

 void setup() {
  Serial.begin(9600);
  // меняем тип на LOW_PULL, потому что по умолчанию стоит HIGH_PULL
  myButt1.setType(LOW_PULL);
  myButt2.setType(LOW_PULL);
  myButt3.setType(LOW_PULL);
  myButt4.setType(LOW_PULL);
  myButt5.setType(LOW_PULL);
  myButt6.setType(LOW_PULL);
  
  servo1.attach(9);
  servo2.attach(10);
  servo2.write(0);
  servo1.write(23);
}
void loop() {
  int analog = analogRead(A1);
  // для начала нужно вывести и запомнить значение для каждой кнопки
//  Serial.println(analog);
  // проверяем у каждой кнопки свой диапазон (+- 20 от полученного значения)
  myButt1.tick(analog < 775 && analog > 735);
  myButt2.tick(analog < 595 && analog > 555);
  myButt3.tick(analog < 460 && analog > 390);
  myButt4.tick(analog < 350 && analog > 310);
  myButt5.tick(analog < 245 && analog > 200);
  myButt6.tick(analog < 140 && analog > 100);

  if (myButt1.isHolded()) {
    taskFunc(1);
  } else if (myButt2.isHolded()) {
    taskFunc(2);
  } else if (myButt3.isHolded()) {
    taskFunc(3);
  } else if (myButt4.isHolded()) {
    taskFunc(4);
  } else if (myButt5.isHolded()) {
    taskFunc(5);
  } else if (myButt6.isHolded()) {
    taskFunc(6);
  }
}


void taskFunc(int num) {
  servo1.write(107);
  delay(1000);
  for (int i = 0; i < num; i++) {
    servo2.write(210);
    delay(1000);
    servo2.write(0);
    delay(1000);
  }
  servo1.write(23); 
  delay(1000);
}

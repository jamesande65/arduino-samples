#include <Servo.h>
#include "GyverButton.h"

int val1; 
int val2; 

Servo servo1;
Servo servo2;
// создаём кнопки без привязки к пину

GButton myButt1;
GButton myButt2;
GButton myButt3;
GButton myButt4;
GButton myButt5;
GButton myButt6;

void setup() {
  pinMode (2, OUTPUT);  //run forvard
  pinMode (3, OUTPUT); //run back
  pinMode (4, OUTPUT);  //pump forvard
  pinMode (5, OUTPUT); //pump back
  pinMode (8, INPUT);   //hall back
  pinMode (9, INPUT);  //hall pump
  //pinMode (-, OUTPUT);  //hall forward
  pinMode(A0, INPUT); //keyboard
  //pinMode(, OUTPUT); //blue light
  //pinMode(, OUTPUT); //white light
  //pinMode(, OUTPUT); //red light
  //pinMode(, OUTPUT); //green light
  Serial.begin(9600);
  // меняем тип на LOW_PULL, потому что по умолчанию стоит HIGH_PULL
  myButt1.setType(LOW_PULL);
  myButt2.setType(LOW_PULL);
  myButt3.setType(LOW_PULL);
  myButt4.setType(LOW_PULL);
  myButt5.setType(LOW_PULL);
  myButt6.setType(LOW_PULL);
  
  servo1.attach(6);
  servo2.attach(7);
  servo2.write(0);
  servo1.write(23);
}

void loop() {
  digitalWrite(2, HIGH); //blue light
  digitalWrite(2, HIGH); //red light
  delay (5000);
  val1 = digitalRead (8); // читаем сенсор
  if (val1 == HIGH) {
    //digitalWrite(, LOW)
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
  }
  int analog = analogRead(A0);
  // проверяем у каждой кнопки свой диапазон (+- 20 от полученного значения)
  myButt1.tick(analog < 775 && analog > 735);
  myButt2.tick(analog < 595 && analog > 555);
  myButt3.tick(analog < 460 && analog > 390);
  myButt4.tick(analog < 350 && analog > 310);
  myButt5.tick(analog < 245 && analog > 200);
  myButt6.tick(analog < 140 && analog > 100);
  // проверка на удержание, например
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

  digitalWrite( LOW);
  delay(2000);
  digitalWrite( HIGH); //светофор маленький разрешающий
  val1 = digitalRead (8); // читаем сенсор
  if (val1 == HIGH) {
    //digitalWrite(, LOW)
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
  }
}


void taskFunc(int num) 
  servo1.write(107);
  delay(1000);
  for (int i = 0; i < num; i++) {
    servo2.write(210);
    delay(1000);
    digitalWrite(2, HIGH);
    delay (5000);
    digitalWrite(2, HIGH); // pump work
    delay (5000);
    servo2.write(0);
    delay(1000);
  }
  servo1.write(23);
  delay(1000);
}
digitalWrite( LOW);
  delay(2000);
  digitalWrite( HIGH); //светофор маленький запрещающий
  delay(2000);
  digitalWrite( LOW);
  delay(2000);
  digitalWrite( HIGH); //светофор большой разрешающий
  delay(2000);
val1 = digitalRead (8); // читаем сенсор
  if (val == HIGH) {
    //digitalWrite(, LOW)
    digitalWrite(2, LOW);
  } else {
    digitalWrite(2, HIGH);
  }

#include "GyverButton.h"
// создаём кнопки без привязки к пину
GButton myButt1;
GButton myButt2;
GButton myButt3;
GButton myButt4;
GButton myButt5;
GButton myButt6;
void setup() {
  Serial.begin(9600);
  // меняем тип на LOW_PULL, потому что по умолчанию стоит HIGH_PULL
  myButt1.setType(LOW_PULL);
  myButt2.setType(LOW_PULL);
  myButt3.setType(LOW_PULL);
  myButt4.setType(LOW_PULL);
  myButt5.setType(LOW_PULL);
  myButt6.setType(LOW_PULL);
}
void loop() {
  // читаем значение
  int analog = analogRead(A0);
  // для начала нужно вывести и запомнить значение для каждой кнопки
  //Serial.println(analog);
  // проверяем у каждой кнопки свой диапазон (+- 20 от полученного значения)
  myButt1.tick(analog < 775 && analog > 735);
  myButt2.tick(analog < 595 && analog > 555);
  myButt3.tick(analog < 460 && analog > 390);
  myButt4.tick(analog < 350 && analog > 310);
  myButt5.tick(analog < 245 && analog > 200);
  myButt6.tick(analog < 140 && analog > 100);
  // проверка на удержание, например
  if (myButt1.isHolded()) {
    Serial.println("hold 1");
  } else if (myButt2.isHolded()) {
    Serial.println("hold 2");
  } else if (myButt3.isHolded()) {
    Serial.println("hold 3");
  } else if (myButt4.isHolded()) {
    Serial.println("hold 4");
  } else if (myButt5.isHolded()) {
    Serial.println("hold 5");
  } else if (myButt6.isHolded()) {
    Serial.println("hold 6");
  } else {
    Serial.println("hold on, pacanchik");
  }
  delay(300);  // задержка тут не нужна, чисто для вывода
  
}

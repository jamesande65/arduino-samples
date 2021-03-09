#include "GyverButton.h"
// создаём кнопки без привязки к пину
GButton myButt1;
GButton myButt2;
GButton myButt3;
void setup() {
  Serial.begin(9600);
  // меняем тип на LOW_PULL, потому что по умолчанию стоит HIGH_PULL
  myButt1.setType(LOW_PULL);
  myButt2.setType(LOW_PULL);
  myButt3.setType(LOW_PULL);
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
  // проверка на удержание, например
  if (myButt1.isHolded()) {
    Serial.println("hold 1");
  }
  if (myButt2.isHolded()) {
    Serial.println("hold 2");
  }
  if (myButt3.isHolded()) {
    Serial.println("hold 3");
  }
  delay(10);  // задержка тут не нужна, чисто для вывода
  
}

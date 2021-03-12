
#include <Servo.h>
#include <GyverButton.h>
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
  //if (sensorVal1 == HIGH) {  // читаем значение сенсора
    //digitalWrite(6, HIGH);
  //}
  int analog = analogRead(A1);
  // для начала нужно вывести и запомнить значение для каждой кнопки
  //Serial.println(analog);
  // проверяем у каждой кнопки свой диапазон (+- 20 от полученного значения)
  myButt1.tick(analog < 780 && analog > 700);
  myButt2.tick(analog < 650 && analog > 500);
  myButt3.tick(analog < 480 && analog > 390);
  myButt4.tick(analog < 350 && analog > 310);
  myButt5.tick(analog < 245 && analog > 200);
  myButt6.tick(analog < 140 && analog > 100);

  // проверка на удержание, например
  if (myButt1.isHolded()) {
    servo1.write(107);
    delay(2000);
    servo2.write(190);
    delay(2000);
    servo2.write(0);
    delay(2000);
    servo1.write(23);
    delay(2000);
  }
  if (myButt2.isHolded()) {
      servo1.write(107);
    delay(2000);
    servo2.write(190);
    delay(2000);
    servo2.write(0);
    delay(2000);
    servo2.write(190);
    delay(2000);
    servo2.write(0);
    delay(2000);
    servo1.write(23);
    delay(2000);
  }
  if (myButt3.isHolded()) {
    Serial.println("hold 3");
  }
  if (myButt4.isHolded()) {
    Serial.println("hold 4");
  }
  if (myButt5.isHolded()) {
    Serial.println("hold 5");
  }
  if (myButt6.isHolded()) {
    Serial.println("hold 6");
  }
  
  delay(10);  // задержка тут не нужна, чисто для вывода
}

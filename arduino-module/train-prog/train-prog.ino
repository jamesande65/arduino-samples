#include <Servo.h>
#include <AnalogKey.h>
#include <GyverButton.h>
GButton myButt1;
GButton myButt2;
GButton myButt3;
GButton myButt4;
GButton myButt5;
GButton myButt6;

Servo servo1;
Servo servo2;

const byte interruptPin = 2;
volatile byte state = LOW;


int sensorVal1;
int sensorVal2;
int sensorVa13;  
bool flag = false;
int iterations = 0;
int passengers;


void manageButton(int num) {
  passengers = num;
  digitalWrite(7, HIGH);
  
  for (int i = 0; i <= num; i++) {
    servo2.write(210);
    delay(1000);
    servo2.write(0);
    delay(1000);
  }
  
  servo1.write(23); 
  delay(1000);
}

void managePump () {
  digitalWrite(7, LOW);

  if (!interations) {
    servo1.write(107);
    delay(1000);
  }

  iterations++;
}

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

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), managePump, CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,HIGH); //blue light
  digitalWrite(13,HIGH); //red light
  
  sensorVal1 = digitalRead(6);
                                                    // BACK TRAIN TO START POSITION
  if (!flag) {
    digitalWrite(3, HIGH);
    flag = true;
  }
  
  if (sensorVal1 == LOW) {  // читаем значение сенсора
   digitalWrite(3, LOW);
  }
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
    manageButton(1);
  } else if (myButt2.isHolded()) {
    manageButton(2);
  } else if (myButt3.isHolded()) {
    manageButton(3);
  } else if (myButt4.isHolded()) {
    manageButton(4);
  } else if (myButt5.isHolded()) {
    manageButton(5);
  } else if (myButt6.isHolded()) {
    manageButton(6);
  }

}

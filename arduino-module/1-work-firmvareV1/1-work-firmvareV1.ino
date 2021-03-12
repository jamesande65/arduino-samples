#include <Servo.h>
#include <GyverButton.h>
GButton myButt1(A1);
GButton myButt2(A1);
GButton myButt3(A1);
GButton myButt4(A1);
GButton myButt5(A1);
GButton myButt6(A1);

int analog;
int analogDose = 1650;

//LIGHTS
int lightBlue = 11;
int lightWhite = 12;
int lightRed = 13;
int lightGreen = 14;

Servo servo1;
Servo servo2;

void manageButton(int num) {
  digitalWrite(lightBlue, LOW); //blue light
  //delay(1000);
  digitalWrite(lightWhite, HIGH); //white light
  //delay(1000);
  digitalWrite(7, HIGH);  // drive forward
  //delay(3000);
  servoOpen();
  delay(100);
  for (int i = 0; i <= num; i++) {
    if (i < num){
      pumpForw();
    } else {
      digitalWrite(7, HIGH);
    }
  }
  delay(5000);
  servoClose();
}

int doseCounter = 1;

void managePump () {
  if (doseCounter <= analog) {
    digitalWrite(7, LOW);
  } else if (doseCounter > 3) {    // fix when we'll have 6 doses !!!!
    digitalWrite(7, LOW);
  } else {
    digitalWrite(7, HIGH);  
  }
  doseCounter++;
}

void pumpForw () {
  digitalWrite(4, HIGH);
  delay(analogDose);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(5, HIGH);
  delay(1850);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  delay(2000);
}

void servoOpen () {
  servo1.write(107);
  delay(2000);
  servo2.write(190);
  delay(2000);
}

void servoClose () {
  servo2.write(0);
  delay(2000);
  servo1.write(23);
  delay(2000);
}

void manageBack () {
  digitalWrite(6, LOW);
}

void setup() {
  pinMode (lightBlue, OUTPUT);   //blue light
  pinMode (lightWhite, OUTPUT);   //white light
  pinMode (lightRed, OUTPUT);   //red light
  pinMode (lightGreen, OUTPUT);   //green light
  pinMode (7, OUTPUT);  // train moove forvard
  pinMode (6, OUTPUT);  //train moove back
  pinMode (4, OUTPUT);  //pump forvard
  pinMode (5, OUTPUT);  // pump back
  pinMode (3, INPUT);  //first sensor
  pinMode (2, INPUT); //second sensor
  //pinMode (8, INPUT);  // third sensor
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
  
  digitalWrite(6, HIGH);

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), managePump, CHANGE);
  
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), manageBack, CHANGE);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(lightBlue, HIGH); //blue light
  digitalWrite(lightRed, HIGH); //red light


  analog = analogRead(A1);
  if (analogRead(A3) > 950) {
    analogDose = 3700;
  }
  
  // для начала нужно вывести и запомнить значение для каждой кнопки
  Serial.println(analog);
  // проверяем у каждой кнопки свой диапазон (+- 20 от полученного значения)
  myButt1.tick(analog < 780 && analog > 700);
  myButt2.tick(analog < 650 && analog > 500);
  myButt3.tick(analog < 480 && analog > 390);
  myButt4.tick(analog < 350 && analog > 310);
  myButt5.tick(analog < 245 && analog > 200);
  myButt6.tick(analog < 140 && analog > 100);

  // проверка на удержание, например
  if (myButt1.isHolded()) {
    manageButton(1);
  } else if (myButt2.isHolded()) {
    manageButton(2);
  } else if (myButt3.isHolded()) {
    manageButton(3);
//  } else if (myButt4.isHolded()) {
//    manageButton(4);
//  } else if (myButt5.isHolded()) {
//    manageButton(5);
//  } else if (myButt6.isHolded()) {
//    manageButton(6);
  }
}

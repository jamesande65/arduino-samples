#include <Servo.h>
#include <AnalogKey.h>
#include <GyverButton.h>
GButton myButt1;
GButton myButt2;
GButton myButt3;
GButton myButt4;
GButton myButt5;
GButton myButt6;

//LIGHTS
int lightBlue = 11;
int lightWhite = 12;
int lightRed = 13;
int lightGreen = 14;

int dose = 1650;

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

  digitalWrite(lightBlue, LOW); //blue light
  digitalWrite(lightWhite, HIGH); //white light
  delay(100);

  digitalWrite(7, HIGH);
  delay(1000);
  servo1.write(107);
  delay(1000);
  servo2.write(210);
  delay(1000);
}

void managePump () {
  digitalWrite(7, LOW);

  if (iterations < passengers) {

    digitalWrite(4, HIGH);
    delay(dose);  //1650 children ticket  3700 adult ticket
    digitalWrite(4, LOW);
    delay(1000);
    digitalWrite(5, HIGH);
    delay(1850);
    digitalWrite(5, LOW);
    delay(1000);

    if (iterations == passengers - 1) {
      servo2.write(0);
      delay(1000);
      servo1.write(23); 
      delay(1000);

      digitalWrite(lightWhite, LOW); //white light
      delay(100);
      digitalWrite(lightBlue, HIGH); //blue light
      delay(100);
      digitalWrite(lightRed, LOW); //red light
      delay(100);
      digitalWrite(lightGreen, HIGH); //green light
    } 
    
    iterations++;
    digitalWrite(7, HIGH);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode (lightBlue, OUTPUT);   //blue light
  pinMode (lightWhite, OUTPUT);   //white light
  pinMode (lightRed, OUTPUT);   //red light
  pinMode (lightGreen, OUTPUT);   //green light
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
  digitalWrite(lightBlue, HIGH); //blue light
  digitalWrite(lightRed, HIGH); //red light
  
  sensorVal1 = digitalRead(6);

  if (!flag) {  // BACK TRAIN TO START POSITION
    digitalWrite(3, HIGH);
    flag = true;
  }
  
  if (sensorVal1 == LOW) {  // читаем значение сенсора
   digitalWrite(3, LOW);
  }
  int analogBtns = analogRead(A1);
  int analogDose = analogRead(A3);
  if (analogDose > 700) {
    dose = 3700;
  }
  // для начала нужно вывести и запомнить значение для каждой кнопки
  // проверяем у каждой кнопки свой диапазон (+- 20 от полученного значения)
  myButt1.tick(analogBtns < 775 && analogBtns > 735);
  myButt2.tick(analogBtns < 595 && analogBtns > 555);
  myButt3.tick(analogBtns < 460 && analogBtns > 390);
  myButt4.tick(analogBtns < 350 && analogBtns > 310);
  myButt5.tick(analogBtns < 245 && analogBtns > 200);
  myButt6.tick(analogBtns < 140 && analogBtns > 100);

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

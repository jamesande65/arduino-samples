// including libs
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <ESP32Servo.h>

//for bratan


bool firstStart = true;
TaskHandle_t Sensors;
TaskHandle_t Main;


// тумблер дозы
int doseTicket;
int doseTicketPin = 27;

// кнопки
int ticketsVal;
int ticketsCount;
int buttonsPin = 14;


// music variables TODO
//SoftwareSerial mySoftwareSerial(16, 17); // RX, TX
//DFRobotDFPlayerMini myDFPlayer;
//void printDetail(uint8_t type, int value);


// lights 4 pins TODO
int lightWhite = 33;
int lightBlue = 25;
int lightGreen = 13;
int lightRed = 32;


// stop sensor variables
int stopSensorBack = 17;
const byte interruptPin = 5;
volatile byte state = LOW;
int val=0;
int stopSensorForward = 18;


// drive variables
int driveForward = 0;
int driveBack = 2;


// servo drives variables
Servo servoFirst;
int servoFirstPin = 19;
int servoFirstdeg = 110;

Servo servoSecond;
int servoSecondPin = 21;
int servoSeconddeg = 180;

int delayDrive = 20;
int pos;



// pump drive
int pumpForward = 4;
int pumpBack = 16;


// functions
void moveTrain (int drivePin) 
{
    digitalWrite(drivePin, HIGH);
}
void stopTrain (int drivePin) 
{
    digitalWrite(drivePin, LOW);
}
void suck (int drivePin) 
{
    digitalWrite(drivePin, HIGH);
}
void stopSucking (int drivePin) 
{
    digitalWrite(drivePin, LOW);
}

//void playTrack (int track) 
//{
//    myDFPlayer.play(track);
//}




// program setup
void setup() {
//    mySoftwareSerial.begin(9600);
//    Serial.begin(115200);
//    myDFPlayer.volume(30);

    //сенсоры + движки
    pinMode (stopSensorBack, INPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), test, CHANGE);
    pinMode(driveForward, OUTPUT);
    pinMode(driveBack, OUTPUT);

    //насоси на дачу
    pinMode(pumpForward, OUTPUT);
    pinMode(pumpBack, OUTPUT);

    //сервачки
    servoFirst.attach(servoFirstPin);
    servoSecond.attach(servoSecondPin);

    // buttons
    Serial.begin(9600);
    pinMode (buttonsPin, INPUT);

    xTaskCreatePinnedToCore(
      Task1code,   /* Функция задачи */
      "Sensors",     /* Название задачи */
      10000,       /* Размер стека задачи */
      NULL,        /* Параметр задачи */
      2,           /* Приоритет задачи */
      &Sensors,      /* Идентификатор задачи, чтобы ее можно было отслеживать */
      0
    );          /* Ядро для выполнения задачи (0) */                  
    delay(5000); 

    xTaskCreatePinnedToCore(
      Task2code,   /* Функция задачи */
      "Main",     /* Название задачи */
      10000,       /* Размер стека задачи */
      NULL,        /* Параметр задачи */
      3,           /* Приоритет задачи */
      &Main,      /* Идентификатор задачи, чтобы ее можно было отслеживать */
      1
    );          /* Ядро для выполнения задачи (1) */
    delay(500);
}

void Task1code( void * pvParameters ){
  for(;;){
    //проверка стоит ли паровоз на исходной и доводка до исходной (если нет)
    if (firstStart) {
      if (digitalRead(stopSensorBack) == HIGH) {
        moveTrain(driveBack);  
      } else {
        stopTrain(driveBack);
      }
      firstStart = false;
    } else {
      // ожидание сигнала остановки от датчика
      if (digitalRead(stopSensorBack) == LOW) {
        stopTrain(driveBack);  
      } else if (digitalRead(stopSensorForward) == LOW) {
        stopTrain(driveForward); 
      } else {
        stopTrain(driveBack);
        stopTrain(driveForward);
      }
    }
//vTaskDelete(NULL);
  } 
}

void Task2code( void * pvParameters ){
  for(;;){
    // режим ожидания (лампы, величина дозы, ожидание кнопки)
    ticketsVal = analogRead(buttonsPin);
    //doseTicket = analogRead(doseTicketPin);
    if (analogRead(doseTicketPin) == HIGH) {
      doseTicket = 600;  
    } else {
      doseTicket = 300;
    }
    if (ticketsVal > 3900){
      ticketsCount = 1;
    } else if (ticketsVal > 2900) {
      ticketsCount = 2;
    } else if (ticketsVal > 2100) {
      ticketsCount = 3;
    } else if (ticketsVal > 1500) {
      ticketsCount = 4;
    } else if (ticketsVal > 900) {
      ticketsCount = 5;
    } else if (ticketsVal > 400) {
      ticketsCount = 6;
    }

    Serial.println(ticketsCount);
    
    delay(100);

    // после сбора данных запускаем поезд с полученными данными
    if (ticketsCount) {
      // разворачиваем кран
      for (pos = 20; pos <= servoFirstdeg; pos += 1) {
        servoFirst.write(pos);
        delay(delayDrive);
      }
      delay(500);
    
      for (pos = 0; pos <= servoSeconddeg; pos += 1) {
        servoSecond.write(pos);
        delay(delayDrive);
      }

    
      //сворачиваем кран
      for (pos = servoSeconddeg; pos >= 1; pos -= 1) {
        servoSecond.write(pos);
        delay(delayDrive);
      }
      delay(500);
    
      for (pos = servoFirstdeg; pos >= 20; pos -= 1) {
        servoFirst.write(pos);
        delay(delayDrive - 10);
      }
    }
  }
}

void test() {
  state = !state;
  val++;
  if (val < ticketsCount) {
    stopTrain(driveForward);
    suck(pumpForward);
    delay(doseTicket);
    stopSucking(pumpForward);
    delay(300);
    suck(pumpBack);
    delay(doseTicket + 30);
    stopSucking(pumpBack);
    moveTrain(driveForward);
  } else {
    moveTrain(driveForward);
  }
}


// program start
void loop() {
}

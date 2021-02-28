// including libs
#include "Arduino.h"
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"
#include <ESP32Servo.h>


bool firstStart = true;
TaskHandle_t Sensors;
TaskHandle_t Main;


// тумблер дозы
int doseTicket;
int doseTicketPin = 27;

// кнопки
int ticketsVal;
int ticketsCount;
int buttonsPin = 23;


// music variables TODO
SoftwareSerial mySoftwareSerial(16, 17); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);


// lights 4 pins TODO
int lightWhite;
int lightBlue;
int lightGreen;
int lightRed;


// stop sensor variables
int stopSensorBack = 17;
int stopSensors = 5;
int stopSensorForward;  // TODO


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

void playTrack (int track) 
{
    myDFPlayer.play(track);
}




// program setup
void setup() {
    mySoftwareSerial.begin(9600);
    myDFPlayer.volume(30);

    //сенсоры + движки
    pinMode (stopSensorBack, INPUT);
    pinMode (stopSensors, INPUT);
    pinMode(driveForward, OUTPUT);
    pinMode(driveBack, OUTPUT);

    //насоси на дачу
    pinMode(pumpForward, OUTPUT);
    pinMode(pumpBack, OUTPUT);

    //сервачки
    servoFirst.attach(servoFirstPin);
    servoSecond.attach(servoSecondPin);

    // buttons
    pinMode (buttonsPin, INPUT);

    // trainSound
    playTrack(1);

    xTaskCreatePinnedToCore(
      Task1code,   /* Функция задачи */
      "Sensors",     /* Название задачи */
      10000,       /* Размер стека задачи */
      NULL,        /* Параметр задачи */
      1,           /* Приоритет задачи */
      &Sensors,      /* Идентификатор задачи, чтобы ее можно было отслеживать */
      0
    );          /* Ядро для выполнения задачи (0) */                  
    delay(5000); 

    xTaskCreatePinnedToCore(
      Task2code,   /* Функция задачи */
      "Main",     /* Название задачи */
      10000,       /* Размер стека задачи */
      NULL,        /* Параметр задачи */
      1,           /* Приоритет задачи */
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
      if (digitalRead(stopSensorBack) == HIGH) {
        moveTrain(driveBack);  
      } else if (digitalRead(stopSensorForward) == LOW) {
        stopTrain(driveForward); 
      }
    }
  } 
}


void Task2code( void * pvParameters ){
  for(;;){
    // режим ожидания (лампы, величина дозы, ожидание кнопки)
    ticketsVal = analogRead(buttonsPin);
    //doseTicket = analogRead(doseTicketPin);
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

      moveTrain(driveForward);
      
      for (int i = 0; i < ticketsCount; i++) {
        if (digitalRead(stopSensors) == LOW) {
          stopTrain(driveForward);
          suck(pumpForward);
          delay(100);
          stopSucking(pumpForward);
          suck(pumpBack);
          delay(100);
          stopSucking(pumpBack);
        }
      }
      
      moveTrain(driveForward);
    
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
    } else {
      playTrack(2);
    }
  }
}


// program start
void loop() {

}

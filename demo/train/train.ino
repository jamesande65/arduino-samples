// including libs
#include "Arduino.h"
//#include <SoftwareSerial.h>
//#include "DFRobotDFPlayerMini.h"
#include <ESP32Servo.h>


bool firstStart = true;
TaskHandle_t Sensors;
TaskHandle_t Main;


// music variables
//SoftwareSerial mySoftwareSerial(16, 17); // RX, TX
//DFRobotDFPlayerMini myDFPlayer;
//void printDetail(uint8_t type, int value);


// lights
int greenLights;
int redLights;


// stop sensor variables
int stopSensorPos = 17;
int stopSensors = 5;


// drive variables
int drivePin;
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


// functions
void moveTrain (int drivePin) 
{
    digitalWrite(drivePin, HIGH);
}
void stopTrain (int drivePin) 
{
    digitalWrite(drivePin, LOW);
}
//int playTrack (track) {
//    myDFPlayer.play(track);
//}




// program setup
void setup() {
//    mySoftwareSerial.begin(9600);
//    Serial.begin(115200);
//    myDFPlayer.volume(30);
    pinMode(13, OUTPUT);

    //сенсоры + движки
    pinMode (stopSensorPos, INPUT);
    pinMode (stopSensors, INPUT);
    pinMode(driveForward, OUTPUT);
    pinMode(driveBack, OUTPUT);

    //сервачки
    servoFirst.attach(servoFirstPin);
    servoSecond.attach(servoSecondPin);

    xTaskCreatePinnedToCore(
    Task1code,   /* Функция задачи */
    "Sensors",     /* Название задачи */
    10000,       /* Размер стека задачи */
    NULL,        /* Параметр задачи */
    1,           /* Приоритет задачи */
    &Sensors,      /* Идентификатор задачи,
                    чтобы ее можно было отслеживать */
    0
  );          /* Ядро для выполнения задачи (0) */                  
  delay(5000); 

  xTaskCreatePinnedToCore(
    Task2code,   /* Функция задачи */
    "Main",     /* Название задачи */
    10000,       /* Размер стека задачи */
    NULL,        /* Параметр задачи */
    1,           /* Приоритет задачи */
    &Main,      /* Идентификатор задачи,
                    чтобы ее можно было отслеживать */
    1
  );          /* Ядро для выполнения задачи (1) */
  delay(500);
}
 

  // Функция Task1code: мигает светодиодом каждые 1000 мс:
void Task1code( void * pvParameters ){
  for(;;){
    //проверка стоит ли паровоз на исходной и доводка до исходной (если нет):
    if (firstStart) {
      if (digitalRead(stopSensorPos) == HIGH) {
        moveTrain(driveBack);  
      } else {
        stopTrain(driveBack);
      }
      firstStart = false;
    } else {
      if (digitalRead(stopSensorPos) == LOW) {
        stopTrain(driveBack);
      } else if (digitalRead(stopSensors) == LOW) {
        stopTrain(driveBack);
        stopTrain(driveForward);
      }
    }
  } 
}

// Функция Task2code: мигает светодиодом каждые 700 мс:
void Task2code( void * pvParameters ){
  for(;;){
    // разворачиваем кран
    //  for (pos = 20; pos <= servoFirstdeg; pos += 1) {
    //    servoFirst.write(pos);
    //    delay(delayDrive);
    //  }
    //  delay(500);
    //
    //  for (pos = 0; pos <= servoSeconddeg; pos += 1) {
    //    servoSecond.write(pos);
    //    delay(delayDrive);
    //  }
    //  delay(500);
    //
    //
    //  //сворачиваем кран
    //  for (pos = servoSeconddeg; pos >= 1; pos -= 1) {
    //    servoSecond.write(pos);
    //    delay(delayDrive);
    //  }
    //  delay(500);
    //
    //  for (pos = servoFirstdeg; pos >= 20; pos -= 1) {
    //    servoFirst.write(pos);
    //    delay(delayDrive - 10);
    //  }
    //  delay(500);
  }
}


// program start
void loop() {

}

#include "Arduino.h"
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(16, 17); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)")); // Инициализация модуля
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!")); // Проверьте соединение
    Serial.println(F("2.Please insert the SD card!")); // Вставьте SD карту
    while(true);
  }
  Serial.println(F("DFPlayer Mini online.")); // Готов к работе
  myDFPlayer.volume(30);  // Установка громкости от 0 до 30
  myDFPlayer.play(1);  // Проигрывать с первого MP3 файла
}

void loop()
{
    myDFPlayer.next(); // Следующий трек
    delay (2000); // пуза 10 секунд
}

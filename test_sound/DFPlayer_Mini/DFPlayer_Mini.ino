// Источник: РОБОТЕХНИКА18.РФ 

#include <SoftwareSerial.h>    // библиотека для для обмена данными 
#include <DFPlayer_Mini_Mp3.h> // подключаем библиотеку для DFPlayer Mini

void setup() // процедура setup
{
    Serial.begin(9600);
    mp3_set_serial(Serial); // включаем передачу данных с DFPlayer mini mp3
    delay(1);               // задержка в 1ms для установки громкости
    mp3_set_volume(1.3);     // устанавливаем громкость от 0 до 30
    mp3_set_EQ(4);          // устанавливаем эквалайзер от 0 до 5
}

void loop() // процедура loop
{
    mp3_play(1); // проигрываем файл mp3/0001.mp3
    delay(30000); // задержка 5 секунд

    mp3_next();  // проигрываем следующий файл
    delay(30000); // задержка 5 секунд

    mp3_play(4); // проигрываем файл mp3/0004.mp3
    delay(30000); // задержка 5 секунд

    mp3_prev();  // проигрываем предыдущий файл
    delay(30000); // задержка 5 секунд
}

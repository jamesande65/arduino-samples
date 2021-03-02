// volatile boolean intFlag = false;   // флаг

// void setup() {
//   Serial.begin(9600); // открыли порт для связи
//   // подключили кнопку на D2 и GND
//   pinMode(5, INPUT);
//   // D2 это прерывание 0
//   // обработчик - функция sensorRead
//   // FALLING - при нажатии на кнопку будет сигнал 0, его и ловим
//   attachInterrupt(0, sensorRead, LOW);
// }
// void sensorRead() {
//   intFlag = true;   // подняли флаг прерывания
// }
// void loop() {
//   if (intFlag) {
//     intFlag = false;    // сбрасываем
//     // совершаем какие-то действия
//     Serial.println("Interrupt!");
//   }  
// }



unsigned long lastflash;
int RPM;

void setup() {
  Serial.begin(9600);  //открыть порт
  attachInterrupt(0,sens,RISING); //подключить прерывание на 2 пин при повышении сигнала
}
void sens() {
  RPM=(1000000.0/(float)(micros()-lastflash))*60;  //расчет
  lastflash=micros();  //запомнить время последнего оборота
}

void loop() {
  if ((micros()-lastflash)>1000000){ //если сигнала нет больше секунды
    RPM=0;  //считаем что RPM 0
  }
   //вывод в порт
    Serial.println(RPM);
  delay(50);  //задержка для стабильности
}
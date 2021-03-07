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



const byte interruptPin = 3;
volatile byte state = LOW;
int val=0;
void setup() {
pinMode(interruptPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptPin), test, CHANGE);
Serial.begin(9600);
}
void loop() {
Serial.println(val/2);
}
void test() {
state = !state;
val++;
}

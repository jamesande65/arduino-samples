const byte interruptPin = 2;
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

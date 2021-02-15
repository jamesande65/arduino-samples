// including libs
#include "Arduino.h"
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"
#include <ESP32Servo.h>

// music variables
SoftwareSerial mySoftwareSerial(16, 17); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

// stop sensors variables
int stopSensor1;
int stopSensor2;
int stopSensor3;

// lights
int greenLights;
int redLights;

// drive variables
int driveForward;
int driveBack;

// servo drives variables
Servo servoFirst;
Servo servoSecond;

// functions
int moveTrain (drive) {
    digitalWrite(drive, HIGH);
}
int stopTrain (drive) {
    digitalWrite(drive, LOW);
}
int playTrack (track) {
    myDFPlayer.play(track);
}

// program setup
void setup() {
    mySoftwareSerial.begin(9600);
    Serial.begin(115200);
    myDFPlayer.volume(30);


}

// program start
void loop() {

}
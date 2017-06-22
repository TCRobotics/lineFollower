#include "Arduino.h"

//DOWN////////////////////////////////
//0 RX bluetooth_____________
//1 TX bluetooth______________
int irReceivePin        = 2;
int encoderR1Pin        = 3;
int encoderR2Pin        = 4;
int oledDCPin           = 5;
int buzzerPin           = 6;
int debugPin            = 7;

int sensBarLedOnPin     = 8;
int edfPWMPin           = 9;
int oledCSPin           =10;
int oledMOSIPin         =11;
int motorDriverFaultPin =12;

int motorR1Pin          =23;
int motorR2Pin          =22;
int motorL1Pin          =21;
int motorL2Pin          =20;
unsigned char sensorBar4Pin       =19;
unsigned char sensorBar3Pin       =18;
unsigned char sensorBar2Pin       =17;
unsigned char sensorBar1Pin       =16;
int oledResetPin        =15;
int battSensPin         =14;
int oledSCKPin          =13;

unsigned char sensorBar6Pin       =28;
unsigned char sensorBar8Pin       =27;
int sideSensorLeftPin   =26;
int encoderL2Pin        =25;
int usrSW2Pin           =24;
//int frontSensorLeftPin  =A12;

unsigned char sensorBar5Pin       =29;
unsigned char sensorBar7Pin       =30;
int sideSensorRightPin  =31;
int encoderL1Pin        =32;
int usrSW1Pin           =33;
//int frontSensorRightPin = A13;
//int backSensorRightPin  = A11;
//int backSensorLeftPin

///////////////////////////////////////


void setupPins(){
  pinMode(irReceivePin,INPUT);
  pinMode(encoderR1Pin,INPUT);
  pinMode(encoderR2Pin,INPUT);
  //pinMode(oledDCPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(debugPin,OUTPUT);


  //digitalWrite(ledPin, HIGH);
}

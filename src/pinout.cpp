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
int sensorBar4Pin       =19;
int sensorBar3Pin       =18;
int sensorBar2Pin       =17;
int sensorBar1Pin       =16;
int oledResetPin        =15;
int battSensPin         =14;
int oledSCKPin          =13;

int sensorBar6Pin       =28;
int sensorBar8Pin       =27;
int sideSensorLeftPin   =26;
int encoderL2Pin        =25;
int usrSW2Pin           =24;
//int frontSensorLeftPin  =A12;

int sensorBar5Pin       =29;
int sensorBar7Pin       =30;
int sideSensorRightPin  =31;
int encoderL1Pin        =32;
int usrSW1Pin           =33;
//int frontSensorRightPin = A13;
//int backSensorRightPin  = A11;
//int backSensorLeftPin

///////////////////////////////////////

void setupPins(){
  pinMode(encoderR1Pin       ,INPUT);
  pinMode(encoderR2Pin       ,INPUT);
  pinMode(encoderL1Pin       ,INPUT);
  pinMode(encoderL2Pin       ,INPUT);
  pinMode(motorDriverFaultPin,INPUT);
  pinMode(usrSW1Pin          ,INPUT);
  pinMode(usrSW2Pin          ,INPUT);
  pinMode(irReceivePin       ,INPUT);

  pinMode(motorR1Pin         ,OUTPUT);
  pinMode(motorR2Pin         ,OUTPUT);
  pinMode(motorL1Pin         ,OUTPUT);
  pinMode(motorL2Pin         ,OUTPUT);
  pinMode(edfPWMPin          ,OUTPUT);
  pinMode(sensBarLedOnPin    ,OUTPUT);
  pinMode(buzzerPin          ,OUTPUT);
  pinMode(debugPin           ,OUTPUT);
}

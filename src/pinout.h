#ifndef PINOUT_H
#define PINOUT_H

// set this to the hardware serial port you wish to use
#define HWSERIAL Serial1
#define DEBUG1ON  digitalWrite(debugPin,HIGH);
#define DEBUG1OFF digitalWrite(debugPin,LOW);
//#define DEBUG2ON  digitalWrite(ledPin,HIGH);
//#define DEBUG2OFF digitalWrite(ledPin,LOW);
//DOWN////////////////////////////////
//0 RX bluetooth_____________
//1 TX bluetooth______________
extern int irReceivePin;
extern int encoderR1Pin;
extern int encoderR2Pin;
extern int oledDCPin;
extern int buzzerPin;
extern int debugPin;

extern int sensBarLedOnPin;
extern int edfPWMPin;
extern int oledCSPin;
extern int oledMOSIPin;
extern int motorDriverFaultPin;

extern int motorR1Pin;
extern int motorR2Pin;
extern int motorL1Pin;
extern int motorL2Pin;
extern unsigned char sensorBar4Pin;
extern unsigned char sensorBar3Pin;
extern unsigned char sensorBar2Pin;
extern unsigned char sensorBar1Pin;
extern int oledResetPin;
extern int battSensPin;
extern int oledSCKPin;

extern unsigned char sensorBar6Pin;
extern unsigned char sensorBar8Pin;
extern int sideSensorLeftPin;
extern int encoderL2Pin;
extern int usrSW2Pin;
//int frontSensorLeftPin;

extern unsigned char sensorBar5Pin;
extern unsigned char sensorBar7Pin;
extern int sideSensorRightPin;
extern int encoderL1Pin;
extern int usrSW1Pin;
//int frontSensorRightPin;
//int backSensorRightPin;
//int backSensorLeftPin;
///////////////////////////////////////

extern void setupPins();

#endif

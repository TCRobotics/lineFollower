#include "Arduino.h"
#include "pinout.h"
#include "tone.h"
#include <QTRSensors.h> //sensor bar
#include "oled.h"


//wheel diameter 32
//100.5309649 mm/ 1 wheel rev
//1 wheel rev /75.81 motor rev
//1 motor rev/10 encoder ticks
//100.5309649/758.1 mm/ encoder ticks = 0,1326091082 mm/encoder tick
//0.1326091082 mm/encoder tick
//7.540960147 encoder ticks/mm
//double countsPer360 = 2057.196;

double mmPerTick  = 0.113;
double ticksPerMM = 8.849;
double countsPer360 = 2057.196;

volatile long encoderR = 0;
volatile long encoderL = 0;

boolean encoderR1Set = false;
boolean encoderR2Set = false;
boolean encoderL1Set = false;
boolean encoderL2Set = false;

double encoderRTick = 0;
double encoderLTick = 0;

volatile long oldEncoderRin = 0;
volatile long oldEncoderLin = 0;
volatile long encoderRin = 0;
volatile long encoderLin = 0;

int frontSensorRightValue=0;
int frontSensorLeftValue=0;
int sideSensorRightValue=0;
int sideSensorLeftValue=0;

int distance_mm = 0;
int distance_deg = 0;

#define NUM_SENSORS             8  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             8//sensBarLedOnPin  // emitter is controlled by digital pin 2
QTRSensorsAnalog qtra((unsigned char[]){16,17,18,19,29,28,30,27},
NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
unsigned int linePosition = 0;

float BattVoltage = 0;

void encoderR1Count(){
  // Test transition
  encoderR1Set = digitalRead(encoderR1Pin) == HIGH;
  // and adjust counter + if A leads B
  encoderR += (encoderR1Set != encoderR2Set) ? +1 : -1;
}

void encoderR2Count(){
  // Test transition
  encoderR2Set = digitalRead(encoderR2Pin) == HIGH;
  // and adjust counter + if B follows A
  encoderR += (encoderR1Set == encoderR2Set) ? +1 : -1;
}

void encoderL1Count(){
  // Test transition
  encoderL1Set = digitalRead(encoderL1Pin) == HIGH;
  // and adjust counter + if A leads B
  encoderL += (encoderL1Set != encoderL2Set) ? -1 : +1;
}

void encoderL2Count(){
  // Test transition
  encoderL2Set = digitalRead(encoderL2Pin) == HIGH;
  // and adjust counter + if B follows A
  encoderL += (encoderL1Set == encoderL2Set) ? -1 : +1;
}

void setupInterrupts(){
  attachInterrupt(encoderR1Pin, encoderR1Count, CHANGE);
  attachInterrupt(encoderR2Pin, encoderR2Count, CHANGE);
  attachInterrupt(encoderL1Pin, encoderL1Count, CHANGE);
  attachInterrupt(encoderL2Pin, encoderL2Count, CHANGE);
}

void updateEncoderData(){
  oldEncoderRin = encoderRin;
  oldEncoderLin = encoderLin;
  encoderRin = encoderR;
  encoderLin = encoderL;
  encoderRTick = encoderRin - oldEncoderRin;
  encoderLTick = encoderLin - oldEncoderLin;

  distance_mm = mmPerTick * (encoderRin + encoderLin) / 2;
  distance_deg = (360/countsPer360) * (encoderRin - encoderLin) / 2;
  //distance_deg = COUNTS_TO_DEG((encoderRin - encoderLin) / 2);
}

void encoderReset(){
  encoderR1Set = false;
  encoderR2Set = false;
  encoderL1Set = false;
  encoderL2Set = false;

  encoderR = 0;
  encoderL = 0;

  oldEncoderRin = 0;
  oldEncoderLin = 0;

  encoderRin = 0;
  encoderLin = 0;

  encoderRTick = 0;
  encoderLTick = 0;

  distance_mm = 0;
  distance_deg = 0;
}

void setupSensors(){
  oled.clear(PAGE);  // Clear the page
  oled.setCursor(0,0); // move cursor
  oled.println("Calibrating sensor bar");
  oled.display();  // Send the PAGE to the OLED memory
  for (int i = 0; i < 400; i++)  // make the calibration take about 10 seconds
  {
    qtra.calibrate();       // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
  }
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    oled.print(qtra.calibratedMinimumOn[i]);
    oled.print(" ");
  }
  oled.print("/n");
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    oled.print(qtra.calibratedMaximumOn[i]);
    oled.print(" ");
  }
  oled.display();  // Send the PAGE to the OLED memory
}

int readSensors(){
  // read calibrated sensor values and obtain a measure of the line position from 0 to 5000
  // To get raw sensor values, call:
  //  qtra.read(sensorValues); instead of unsigned int position = qtra.readLine(sensorValues);
  linePosition = qtra.readLine(sensorValues);
  /*
  // print the sensor values as numbers from 0 to 1000, where 0 means maximum reflectance and
  // 1000 means minimum reflectance, followed by the line position
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  //Serial.println(); // uncomment this line if you are using raw values
  Serial.println(position); // comment this line out if you are using raw values
  */
}

void checkBattery(){
  BattVoltage = analogRead(battSensPin)*0.003222656*3;
  //  if(BattVoltage <= 7.4) toneBattery();
  //else stopPlaying();
}

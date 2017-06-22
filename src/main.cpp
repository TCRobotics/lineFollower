#include "arduino.h"
#include "main.h"
#include "pinout.h"
#include "motors.h"
#include "sensors.h"
#include "profiler.h"
#include "speedController.h"
#include "tone.h"
#include "oled.h"
#include "elapsedMillis.h"
#include "IntervalTimer.h"
//


unsigned long sysTickCounts = 0;
elapsedMicros systickMicros;

IntervalTimer sysTimer;
unsigned int sysTickMilisPeriod = 10;
unsigned int sysTickSecond = 1000/sysTickMilisPeriod;

int wallsDetected = 0;
bool activateController = false;

void sysTick() {
DEBUG1ON;
//DEBUG1OFF;
  systickMicros =0;
  wallsDetected = readSensors();
  updateEncoderData();
  if(activateController)
  {
    PIDcontroller();
    motorSpeedUpdate(RSpeedOUT,LSpeedOUT);
    //serialDebug();
  }
  else
  {
    //showData();
  }
  sysTickCounts++;
  //DEBUG1ON
  //showData();
  //DEBUG1OFF;
  DEBUG1OFF;
}

void setup() {
  HWSERIAL.begin(115200);
  HWSERIAL.println("\n\n\n\n\n\n\n\nHI!");
  setupPins();
  //setupSensors();
  setupPWM();
  setupOLED();
  checkBattery();
  showData();
  setupInterrupts();
  //tonePlay();
  //while ((readSensors() & 0b010) == 0){}
  delay(1000);
  sysTimer.begin(sysTick, sysTickMilisPeriod*100);
}



void loop() {
  /*
  if(sysTickCounts > 0)                 {RSpeedSet = 25; LSpeedSet = 25;}
  if(sysTickCounts > 1*sysTickSecond)   {RSpeedSet = 40; LSpeedSet = 40;}
  if(sysTickCounts > 2*sysTickSecond)   {RSpeedSet = 25; LSpeedSet = 25;}
  if(sysTickCounts > 3*sysTickSecond)   {RSpeedSet = 0; LSpeedSet = 0;}
  if(sysTickCounts > 4*sysTickSecond)   {RSpeedSet = 70; LSpeedSet = 70;}
  //if(sysTickCounts > (4*sysTickSecond)) {sysTimer.end();}
  */
/*
  //activateController = true;
  //Serial.println(0);
  //frontMove(CELL / 2);
  //activateController = false;
  //motorBrake(RLMOTOR);
  while(1);
  Serial.println(1);
  turna(90);
  Serial.println(2);
  frontMove(CELL / 2);
  Serial.println(3);
  turna(90);
  Serial.println(4);
  frontMove(CELL / 2);
  Serial.println(5);
  turna(90);
  Serial.println(6);
  frontMove(CELL / 2);
  Serial.println(7);
  turna(90);
  Serial.println(8);

  frontMove(CELL / 2);
  Serial.println(9);
  turna(-90);
  Serial.println(10);
  frontMove(CELL / 2);
  Serial.println(11);
  turna(-90);
  Serial.println(12);
  frontMove(CELL / 2);
  Serial.println(13);
  turna(-90);
  Serial.println(14);
  frontMove(CELL / 2);
  Serial.println(15);
  turna(-90);
  Serial.println(16);

  frontMove(CELL / 2);
  Serial.println(17);
  turna(180);
  Serial.println(18);
  frontMove(CELL / 2);
  Serial.println(19);
  turna(180);
  Serial.println(20);
  frontMove(CELL / 2);
  Serial.println(21);
  turna(-180);
  Serial.println(22);
  frontMove(CELL / 2);
  Serial.println(23);
  turna(-180);
  Serial.println(24);

  while(1)
  {
    pivotTurn(360);
    Serial.println(25);
    pivotTurn(-360);
    Serial.println(26);
  }

  DEBUG2ON;
  activateController = true;
  frontMove(STARTMIDLECELL);
  activateController = false;
  motorBrake(RLMOTOR);
  //serialDebug();
  DEBUG2OFF;
  while ((readSensors() & 0b010) == 0){}

  activateController = true;
  pivotTurn(90);
  activateController = false;
  motorBrake(RLMOTOR);

  while ((readSensors() & 0b010) == 0){}

  activateController = true;
  pivotTurn(-90);
  activateController = false;
  motorBrake(RLMOTOR);

  while ((readSensors() & 0b010) == 0){}
*/

/*
  activateController = true;
  frontMove(STARTMIDLECELL);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  frontMove(2*CELL);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  pivotTurn(90);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  frontMove(CELL);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  pivotTurn(90);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  frontMove(CELL);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  pivotTurn(90);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  frontMove(CELL);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  pivotTurn(90);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  frontMove(-CELL);
  activateController = false;
  motorBrake(RLMOTOR);

  activateController = true;
  frontMove(-STARTMIDLECELL);
  activateController = false;
  motorBrake(RLMOTOR);

  while ((readSensors() & 0b010) == 0){}
*/




  if(sysTickCounts>= 100)
  {
    //serialDebug();
    checkBattery();
    showData();
    //serialDebug();
    sysTickCounts = 0;
  }

}

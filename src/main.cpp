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

unsigned long sysTickCounts = 0;
elapsedMicros systickMicros;

IntervalTimer sysTimer;
unsigned int sysTickMilisPeriod = 10;
unsigned int sysTickSecond = 1000/sysTickMilisPeriod;

bool activateController = false;

void sysTick() {
DEBUG1ON;
//DEBUG1OFF;
  systickMicros =0;
  readSensors();
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
  oledShowData();
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
  if(sysTickCounts>= 100)
  {
    //serialDebug();
    checkBattery();
    oledShowData();
    //serialDebug();
    sysTickCounts = 0;
  }

}

#include "Arduino.h"
#include "sensors.h"
#include "pinout.h"
#include "speedController.h"
#include "profiler.h"
#include "main.h"

void serialDebug(){
  HWSERIAL.print(sysTickCounts);
//  Serial.print(" V:");
//  Serial.print(BattVoltage);

  HWSERIAL.print(" SET:");
  HWSERIAL.print(RSpeedSet,0);
  HWSERIAL.print(",");
  HWSERIAL.print(LSpeedSet,0);

  HWSERIAL.print(" OUT:");
  HWSERIAL.print(RSpeedOUT, 0);
  HWSERIAL.print(",");
  HWSERIAL.print(LSpeedOUT, 0);
/*
  Serial.print(" EncLRraw:");
  Serial.print(encoderRTick);
  Serial.print(",");
  Serial.print(encoderLTick);
*/
  HWSERIAL.print(" EncLR:");
  HWSERIAL.print(encoderR * mmPerTick, 0);
  HWSERIAL.print(",");
  HWSERIAL.print(encoderL * mmPerTick, 0);

  HWSERIAL.print(" Set:");
  HWSERIAL.print(distanceSet);

  HWSERIAL.print(" mm:");
  HWSERIAL.print(distance_mm);
  HWSERIAL.print(" dg:");
  HWSERIAL.print(distance_deg);
/*
  HWSERIAL.print(" mm:");
  HWSERIAL.print(encoderRTick * mmPerTick * 0.001 * sysTickSecond);
  HWSERIAL.print(",");
  HWSERIAL.print(encoderLTick * mmPerTick * 0.001 * sysTickSecond);

  Serial.print(" FrontR:");
  Serial.print(frontSensorRightValue);

  Serial.print(" FrontL:");
  Serial.print(frontSensorLeftValue);

  Serial.print(" SideR:");
  Serial.print(sideSensorRightValue);

  Serial.print(" SideL:");
  Serial.print(sideSensorLeftValue);
*/
  HWSERIAL.print(" U:");
  HWSERIAL.print(systickMicros);

  HWSERIAL.println();
}

void printMaze(){
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
  Serial.println("| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |");
  Serial.println(" --- --- --- --- --- --- --- --- --- --- --- --- --- ");
}

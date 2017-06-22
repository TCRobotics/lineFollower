#include "Arduino.h"
#include "speedController.h"
#include "sensors.h"

double RSpeedSet = 0;
double LSpeedSet = 0;

double RSpeedOUT = 0;
double LSpeedOUT = 0;

int moveType = 0;
int distanceSetpoint = 0;
int oldRightError = 0;
int oldLeftError = 0;
bool useSensors = false;

void PIDcontroller(){
  int rightError = 0;
  int leftError = 0;
/*
  //sensor aligment error
  if(useSensors)
  {
    int sensorFeedback = int(getAligmentError()) / K_SENSORS;
    rightError += sensorFeedback;
    leftError  -= sensorFeedback;
  }

  //speed error
  leftError +=  (LSpeedSet - encoderLTick);
  rightError += (RSpeedSet - encoderRTick);

  // PD controller right wheel
  RSpeedOUT += (KP * rightError) +
        (KD * (rightError - oldRightError));

  // PD controller left wheel
  LSpeedOUT += (KP * leftError) +
        (KD * (leftError - oldLeftError));

  // shift values
  oldRightError = rightError;
  oldLeftError = leftError;
  */
}


void controllerReset(void)
{
  RSpeedOUT = 0;
  LSpeedOUT = 0;

  oldRightError = 0;
  oldLeftError = 0;

  RSpeedSet = 0;
  LSpeedSet = 0;
}

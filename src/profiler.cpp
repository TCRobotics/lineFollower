#include "Arduino.h"
#include "speedController.h"
#include "profiler.h"
#include "sensors.h"
#include "motors.h"

int distanceSet = 0;

void setMove(int radius, int distanceORradius, int speed){
/*
  if (radius == 0)
  {
    moveType = TRANSLATIONAL;

    RSpeedSet = SPEED_TO_COUNTS(speed);
    LSpeedSet = RSpeedSet;
  }
  else
  {
    moveType = ROTATIONAL;

    float speedX_mm_s = (float)speed;
    float speedW_rad_s = speedX_mm_s / (float)radius;

    int speedX_cnt = SPEED_TO_COUNTS(abs(speed));
    int speedW_cnt = RAD_S_TO_COUNTS(speedW_rad_s);

    if (radius < W_DISTANCE)
    {
      speedX_cnt -= (abs(speedW_cnt) / 2);
      speedW_cnt /= 2;
    }

    RSpeedSet = speedX_cnt + speedW_cnt;
    LSpeedSet = speedX_cnt - speedW_cnt;
  }

  distanceSet = distanceORradius;
  */
}


bool isFinalMove(void)
{
/*
  if (moveType == TRANSLATIONAL && distance_mm >= distanceSet)
  {
    return true;
  }
  else if (moveType == ROTATIONAL && abs(distance_deg) >= distanceSet)
  {
    return true;
  }
  else if ((moveType == TRANSLATIONAL)
      && (frontSensorLeftValue > CENTER_FRONTAL && frontSensorRightValue > CENTER_FRONTAL))
  {
    return true;
  }
*/
  return false;
}



void frontMove(int mm)
{
  /*
  if (mm != 0)
  {
    //useSensors = true;
    encoderReset();
    controllerReset();
    setMove(0, mm, STRAIGHT_SPEED);
    do
    {
      delay(1);
    }
    while (isFinalMove() == false);
  }
  else
  {
    //useSensors = true;
    setMove(0, mm, STRAIGHT_SPEED);
    delay(1);
  }
  */
}

void pivotTurn(int deg)
{
  /*
  useSensors = false;
  encoderReset();
  controllerReset();
  motorSpeed(RLMOTOR,0,0);
  //delay(100);

  if (deg > 0) setMove(W_DISTANCE / 2, deg, TURN_SPEED);
  else setMove(W_DISTANCE / 2, -deg, -TURN_SPEED);

  do
  {
    delay(1);
  }
  while (isFinalMove() == false);
  */
}


void turna(int deg)
{
  /*frontMove(CELL / 2);
  pivotTurn(deg);
  frontMove(CELL / 2);*/
}

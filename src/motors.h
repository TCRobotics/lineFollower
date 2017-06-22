#ifndef MOTORS_H
#define MOTORS_H

#include "Arduino.h"

#define RMOTOR  0
#define LMOTOR  1
#define RLMOTOR 2

extern void setupPWM();
extern void motorSpeed(char motor, boolean direction, int speed);
extern void motorSpeedUpdate(int Rspeed, int Lspeed);
extern void motorSpeedPercent(char motor, int speed);
extern void motorBrake(char motor);
extern void motorCoast(char motor);

#endif

#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

extern double RSpeedSet;
extern double LSpeedSet;

extern double RSpeedOUT;
extern double LSpeedOUT;

extern int moveType;
extern int distanceSetpoint;
extern bool useSensors;

extern void PIDcontroller();
extern void controllerReset(void);

#define TS               10 // Sample time [ms]
#define KP                5 // proportional gain
#define KD               10 // derivative gain
#define K_SENSORS       1000 // Sensor weight at controller

#endif

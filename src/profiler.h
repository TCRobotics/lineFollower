#ifndef PROFILER_H
#define PROFILER_H

#define STRAIGHT_SPEED  100 // straigth speed [mm/s]
#define TURN_SPEED      50 // turn speed [mm/s]

#define TRANSLATIONAL 0
#define ROTATIONAL    1

#define SPEED_TO_COUNTS(speed)  ((ticksPerMM * (speed) * TS) / 1000)
#define RAD_S_TO_COUNTS(rad_s)  (SPEED_TO_COUNTS(rad_s * W_DISTANCE))

extern int distanceSet;

extern void frontMove(int mm);
extern void pivotTurn(int deg);
extern void turna(int deg);

#endif

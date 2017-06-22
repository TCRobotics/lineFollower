#ifndef sensors_H
#define sensors_H

//100.531 mm/ 1 wheel rev
//1 wheel rev /75.81 motor rev
//1 motor rev/12 encoder ticks

//100.531/758.1 mm/ encoder ticks = 0,1326091545 mm/encoder tick
//0,1326091545 mm/encoder tick
//7.540957514 encoder ticks/mm
extern double ticksPerMM;
extern double mmPerTick;

// Robot params
//#define ENCODER_PPR    909    // PPR 909.72
//#define WHEEL_DIAMETER 32     // wheel diameter [mm]
#define W_DISTANCE   74       // wheels distance [mm]
//#define CNT_POR_1000MM  9049  // = (1000*ENCODER_PPR) / (WHEEL_DIAMETER*PI)
#define CNT_POR_360DEG  2103   // = ((PI*W_DISTANCE)*CNT_PER_1000MM)/(1000)
//#define COUNTS_TO_MM(cnt)  (((cnt) * 1000) / CNT_POR_1000MM)
#define COUNTS_TO_DEG(cnt)  (((cnt) * 360) / CNT_POR_360DEG)
//#define DIST_TO_COUNTS(mm)  (((mm) * CNT_POR_1000MM) / 1000)

extern volatile long encoderR;
extern volatile long encoderL;

extern double encoderRTick;
extern double encoderLTick;

extern int frontSensorRightValue;
extern int frontSensorLeftValue;
extern int sideSensorRightValue;
extern int sideSensorLeftValue;

extern int distance_mm;
extern int distance_deg;

extern unsigned int linePosition;

extern float BattVoltage;

extern void setupInterrupts();
extern void setupSensors();
extern void updateEncoderData();
extern int readSensors();
extern void encoderReset();
extern void checkBattery();

#endif

//#include "Arduino.h"
#include "motors.h"
#include "pinout.h"

void setupPWM(){
  analogWriteResolution(16);         // analogWrite value 0 to 65535
  analogWriteFrequency(3, 732.4218); // Teensy 3.0 pin 4 also changes to 732.4218 kHz
  analogWriteFrequency(5, 732.4218); // Teensy 3.0 pin 56,9,10,20,21,22,23 also changes to 732.4218 kHz
  motorCoast(RLMOTOR);
}


void motorSpeed(char motor, boolean direction, int speed) { //speed from 0 to 65535
  if (speed > 65535) speed = 65535;
  if (motor == RLMOTOR)
  {
    if (direction == 0)
    {
      analogWrite(motorR1Pin,speed);
      analogWrite(motorR2Pin,0);
      analogWrite(motorL1Pin,speed);
      analogWrite(motorL2Pin,0);
    }
    else //direction == 1
    {
      analogWrite(motorR1Pin,0);
      analogWrite(motorR2Pin,speed);
      analogWrite(motorL1Pin,0);
      analogWrite(motorL2Pin,speed);
    }
  }
  else if (motor == RMOTOR)
  {
    if (direction == 0)
    {
      analogWrite(motorR1Pin,speed);
      analogWrite(motorR2Pin,0);
    }
    else //direction == 1
    {
      analogWrite(motorR1Pin,0);
      analogWrite(motorR2Pin,speed);
    }
  }
  else //motor == LMOTOR
  {
    if (direction == 0)
    {
      analogWrite(motorL1Pin,speed);
      analogWrite(motorL2Pin,0);
    }
    else //direction == 1
    {
      analogWrite(motorL1Pin,0);
      analogWrite(motorL2Pin,speed);
    }
  }
}

void motorSpeedPercent(char motor, int speed) { //speed from -100 to 100
  int PWMvalue=0;
  PWMvalue = map(abs(speed),0,100,0,65535); //anything below 50 is very weak
  if (speed > 0)
    motorSpeed(motor,0,PWMvalue);
  else if (speed < 0)
    motorSpeed(motor,1,PWMvalue);
  else {
    motorCoast(motor);
  }
}

void motorSpeedUpdate(int Rspeed, int Lspeed) { //speed from -65535 to 65535
  if (Rspeed > 0)
    motorSpeed(RMOTOR,0,Rspeed);
  else if (Rspeed < 0)
    motorSpeed(RMOTOR,1,-Rspeed);
  else {
    motorBrake(RMOTOR);
  }

  if (Lspeed > 0)
    motorSpeed(LMOTOR,0,Lspeed);
  else if (Lspeed < 0)
    motorSpeed(LMOTOR,1,-Lspeed);
  else {
    motorBrake(LMOTOR);
  }
}

void motorBrake(char motor) {
  if (motor == RLMOTOR)
  {
    analogWrite(motorR1Pin,65535);
    analogWrite(motorR2Pin,65535);
    analogWrite(motorL1Pin,65535);
    analogWrite(motorL2Pin,65535);
  }
  else if (motor == RMOTOR)
  {
    analogWrite(motorR1Pin,65535);
    analogWrite(motorR2Pin,65535);
  }
  else //motor == LMOTOR
  {
    analogWrite(motorL1Pin,65535);
    analogWrite(motorL2Pin,65535);
  }
}

void motorCoast(char motor) {
  if (motor == RLMOTOR)
  {
    analogWrite(motorR1Pin,0);
    analogWrite(motorR2Pin,0);
    analogWrite(motorL1Pin,0);
    analogWrite(motorL2Pin,0);
  }
  else if (motor == RMOTOR)
  {
    analogWrite(motorR1Pin,0);
    analogWrite(motorR2Pin,0);
  }
  else //motor == LMOTOR
  {
    analogWrite(motorL1Pin,0);
    analogWrite(motorL2Pin,0);
  }
}

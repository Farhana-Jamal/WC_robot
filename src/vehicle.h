#ifndef VEHICLE_H
#define VEHICLE_H

#include <Arduino.h>


// Motor A
#define motor1Pin1  25
#define motor1Pin2  26
#define enable1Pin  33 

// Motor B
#define motor2Pin1 27 
#define motor2Pin2 14 
#define enable2Pin 12



void motorSetup();

void robotMovement(bool INA1,bool INA2 , bool INA3 , bool INA4);
// void moveFwd();
// void moveBwd();
// void Stop();
// void moveLeft();
// void moveRight();

#endif
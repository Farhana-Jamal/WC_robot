#ifndef VEHICLE_H
#define VEHICLE_H

// Motor A
#define motor1Pin1  13
#define motor1Pin2  12 
#define enable1Pin  14 

// Motor B
#define motor2Pin1 27 
#define motor2Pin2 26 
#define enable2Pin 25

void motorSetup();
void moveFwd();
void moveBwd();
void Stop();
void moveLeft();
void moveRight();

#endif
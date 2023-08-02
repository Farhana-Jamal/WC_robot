#ifndef VEHICLE_H
#define VEHICLE_H




// Motor A
#define motor1Pin1  27
#define motor1Pin2  26
// #define enable1Pin  33 



// Motor B
#define motor2Pin1 25
#define motor2Pin2 33 
// #define enable2Pin 12



void motorSetup();

void robotMovement(int INA1,int INA2 , int INA3 , int INA4);
// void moveFwd();
// void moveBwd();
// void Stop();
// void moveLeft();
// void moveRight();

#endif
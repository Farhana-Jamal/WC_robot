#ifndef lidar_H
#define lidar_H

#include "Adafruit_VL53L0X.h"
#include<ESP32Servo.h>



void rotatingOne();
void lidarSetup();
int lidarDistance();
void obstacleAvoidance();

#endif

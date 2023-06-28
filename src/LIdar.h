#ifndef lidar_H
#define lidar_H

#include <Wire.h>
#include <VL53L0X.h>

void rotatingOne();
void lidarSetup();
int lidarDistance();
void obstacleAvoidance();

#endif

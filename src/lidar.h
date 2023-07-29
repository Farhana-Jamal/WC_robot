#ifndef LIDAR_H
#define LIDAR_H

#include <Wire.h>
#include <VL53L0X.h>
#include "vehicle.h"
#include "servomtr.h"
#include "beacon.h"
#include "compass.h"


void rotatingOne();
void lidarSetup();
int lidarDistance();
void obstacleAvoidance();

#endif

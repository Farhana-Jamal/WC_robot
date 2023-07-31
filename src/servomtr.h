#ifndef SERVOMTR_H
#define SERVOMTR_H

#include "lidar.h"
#include <ESP32Servo.h>

#define obstacleServoPin  17
#define bottomBioServoPin 18
#define bottomNonBioServoPin 19

void servoSetup();
int lookRight();
int lookLeft();
void bottomOpenAndClose();

#endif
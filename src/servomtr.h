#ifndef SERVOMTR_H
#define SERVOMTR_H

#include "lidar.h"
#include <ESP32Servo.h>

#define servoPin  17

void servoSetup();
int lookRight();
int lookLeft();

#endif
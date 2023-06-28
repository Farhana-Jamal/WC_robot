#ifndef SERVOMTR_H
#define SERVOMTR_H

#include "lidar.h"

#define servoPin  15

void servoSetup();
void servoRotate(int pulseWidth);
int lookRight();
int lookLeft();

#endif
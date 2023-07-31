#ifndef COMPASS_H
#define COMPASS_H


#include <DFRobot_QMC5883.h>
#include "vehicle.h"

void compassSetup();
void rotate_CompassDirection();
void compassDirection();
bool compareDirections();


#endif
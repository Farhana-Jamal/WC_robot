#include <Arduino.h>
#include "lidar.h"
#include "vehicle.h"
#include "servomtr.h"
#include "beacon.h"
#include "compass.h"

void setup() 
{
  servoSetup();
  lidarSetup();
  motorSetup();
  bleBeaconSetup();
  compassSetup();


}



void loop()
{ 
 
  
  obstacleAvoidance();
  // moveFwd();
 
}
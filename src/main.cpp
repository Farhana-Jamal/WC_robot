#include <Arduino.h>
#include "lidar.h"
#include "vehicle.h"
#include "servomtr.h"
#include "beacon.h"

void setup() 
{
  servoSetup();
  lidarSetup();
  motorSetup();
  bleBeaconSetup();


}



void loop()
{ 
 
  
  obstacleAvoidance();
  // moveFwd();
 
}
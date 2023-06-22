#include <Arduino.h>
#include <LIdar.h>
#include <vehicle.h>
#include <servomtr.h>
#include <beacon.h>

void setup() 
{
  servoSetup();
  lidarSetup();
  motorSetup();
  bleBeaconSetup();
  wifiBeaconSetup();

}



void loop()
{ 
 
  
  obstacleAvoidance();
  // moveFwd();
 
}
#include <Arduino.h>
#include <LIdar.h>
#include <vehicle.h>
#include <servomtr.h>

void setup() 
{
  servoSetup();
  lidarSetup();
  motorSetup();
  
  
}

void loop()
{
  obstacleAvoidance();
  // moveFwd();
  


  
  
}
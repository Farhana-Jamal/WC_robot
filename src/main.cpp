#include <Arduino.h>
#include <LIdar.h>
#include <vehicle.h>

void setup() 
{
  lidarSetup();
  motorSetup();
  
}

void loop()
{
  lidarDistance();
  getDistance();
  
  
}
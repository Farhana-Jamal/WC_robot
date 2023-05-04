#include <Arduino.h>
#include "LIdar.h"

void setup() 
{
  lidarSetup();
}

void loop()
{
  lidarDistance();
  
}
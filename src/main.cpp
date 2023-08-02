#include <Arduino.h>
#include "lidar.h"
#include "vehicle.h"
#include "servomtr.h"
#include "beacon.h"
#include "compass.h"
#include "master.h"


bool wasteCollecting = false;
void setup() 
{
  servoSetup();
  lidarSetup();
  motorSetup();
  bleBeaconSetup();
  compassSetup();
  // robotStartSetup();


}



void loop()
{ 
  if(wasteCollecting == false)
  {
     if(moveToCollectingWaste()==true)
     {
      wasteCollecting = true;
     }
  }
  if(wasteCollecting == true)
  {
    if(moveToDepositingWaste() == true)
    {
      wasteCollecting = true;
    }
    
  }
}
#include "lidar.h"




 
int distance ;

VL53L0X lidar;

int lidarDistance() 
{
 
  Serial.println("Reading a measurement... ");
  
  distance = lidar.readRangeSingleMillimeters();
  Serial.print("Distance : "); 
    
  delay(100);
  return distance ;
  
}

void lidarSetup() 
{
  Serial.begin(115200);

  Wire.begin();

  while (! Serial) {                                          // wait until serial port opens for native USB devices
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lidar.init()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  Serial.println("success to boot lidar");

  #if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  sensor.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
  #endif

   #if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  sensor.setMeasurementTimingBudget(20000);
   #elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  sensor.setMeasurementTimingBudget(200000);
  #endif

  distance = lidarDistance();
}



 void obstacleAvoidance()
 { 
  
  int distance_R;
  int distance_L;

  Serial.print("got :"); Serial.println(distance);

  if(distance >400)
  {
    robotMovement(145,0,250,0)
    ;   //forward
    Serial.println("forward");
  }
  else
  {
    robotMovement(0,0,0,0);   //stop
    delay(300);

    robotMovement(0,145,0,250);   //backward
    delay(400);

    robotMovement(0,0,0,0);
    delay(300);

    distance_R = lookRight();
    delay (300);

    distance_L = lookLeft();
    delay (300);

    if(distance_R >= distance_L)
    {
      robotMovement(0,250,250,0);      //right
      delay(500);
      robotMovement(145,0,250,0);      //forward
      robotMovement(0,0,0,0);      //stop
    }
    else
    {
      robotMovement(250,0,0,250);   //left
      delay(500);
      robotMovement(145,0,250,0);      //forward
      robotMovement(0,0,0,0);      //stop

    }
  }

  
  distance = lidarDistance();

  
 }
 




 
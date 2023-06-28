#include "LIdar.h"
#include <vehicle.h>
#include <servomtr.h>
#include <beacon.h>


unsigned long rotationDuration = 30000;
unsigned long currentTime;

bool rotate = false;
 
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

void rotatingOne()
{
  currentTime = millis();
  Serial.print("ctime1     "); Serial.println(currentTime);
  // if(rotate = false)
  // {  
  //     Serial.println("rotating");
  //     robotMovement(1,0,0,1);
      
  //     Serial.print("ctime2     "); Serial.println(currentTime);

  //     prvsTime = currentTime;

  //     Serial.print("ctime3     "); Serial.println(currentTime);
  //     Serial.print("ptime1     "); Serial.println(prvsTime);

  // }

  if(currentTime < rotationDuration)
  {
     Serial.print("ctime2     "); Serial.println(currentTime);
      // Serial.print("ptime2     "); Serial.println(prvsTime);
    // Serial.print("ctime - ptime    "); Serial.println(currentTime);
    Serial.println("rotating with ");
    robotMovement(1,0,0,1);
    bleDataS();
    wifiScanDatas();
  }
  else
  {
    rotate = true;
    Serial.println("rotation stopped");
  }
  
}


 void obstacleAvoidance()
 { 
   rotatingOne(); 
 
if(rotate == true)
{
  int distance_R;
  int distance_L;

  Serial.print("got :"); Serial.println(distance);

  if(distance >400)
  {
    robotMovement(0,1,0,1);   //forward
  }
  else
  {
    robotMovement(0,0,0,0);   //stop
    delay(300);

    robotMovement(1,0,1,0);   //backward
    delay(400);

    robotMovement(0,0,0,0);
    delay(300);

    distance_R = lookRight();
    delay (300);

    distance_L = lookLeft();
    delay (300);

    if(distance >= distance_L)
    {
      robotMovement(0,1,1,0);      //right
      delay(500);
      robotMovement(0,1,0,1);      //forward
      robotMovement(0,0,0,0);      //stop
    }
    else
    {
      robotMovement(1,0,0,1);   //left
      delay(500);
      robotMovement(0,1,0,1);      //forward
      robotMovement(0,0,0,0);      //stop

    }
  }

  bleDataS();
  wifiScanDatas();
  distance = lidarDistance();
   
 }
 }

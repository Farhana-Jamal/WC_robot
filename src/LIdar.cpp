#include "LIdar.h"
#include <vehicle.h>
#include <servomtr.h>

 
int distance ;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void lidarSetup() 
{
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  Serial.println("success to boot lidar");
}

VL53L0X_RangingMeasurementData_t measure;

int lidarDistance() 
{
 
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    
    distance = measure.RangeMilliMeter;
    Serial.print("Distance (mm): "); Serial.println(distance);
  } else {
    distance = 0;
  }
    
  delay(100);
  return distance ;
  
}
 void obstacleAvoidance()
 {
  int distance_R;
  int distance_L;

  Serial.print("got :"); Serial.println(distance);

  if (distance <= 400)
  {
    Stop();
    delay(300);

    moveBwd();
    delay(400);

    Stop();
    delay(300);

    distance_R = lookRight();
    delay (300);

    distance_L = lookLeft();
    delay (300);

    if(distance >= distance_L)
    {
      moveRight();
      Stop();
    }
    else
    {
      moveLeft();
      Stop();
    }
  }
  else
  {
    moveFwd();
  }

  distance = lidarDistance();
    
 }

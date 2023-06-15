#include "LIdar.h"
#include <vehicle.h>
#include <servomtr.h>
#include <beacon.h>




 
int distance ;

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

VL53L0X_RangingMeasurementData_t measure;

int lidarDistance() 
{
 
  Serial.println("Reading a measurement... ");
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

  distance = lidarDistance();
}




 void obstacleAvoidance()
 {
   rotatingOne(); 

  int distance_R;
  int distance_L;

  Serial.print("got :"); Serial.println(distance);

  if( distance == 0 || distance >400)
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

  dataS();
  distance = lidarDistance();
   
 }

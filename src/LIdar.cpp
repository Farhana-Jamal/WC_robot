#include "LIdar.h"
#include <vehicle.h>


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
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}

VL53L0X_RangingMeasurementData_t measure;

void lidarDistance() 
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
  
}
 void getDistance()
 {
  Serial.print("got :"); Serial.println(distance);

  if(distance == 0)
  {
    Serial.println("move forward");
    moveFwd();
  }
       
 }

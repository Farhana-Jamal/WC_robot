#include "compass.h"

QueueHandle_t queue = NULL;
DFRobot_QMC5883 compass(&Wire, QMC5883_ADDRESS);
void compassSetup()
{
    Serial.begin(115200);
    while (!compass.begin())
    {
      Serial.println("Could not find a valid 5883 sensor, check wiring!");
      delay(500);
    }
   queue = xQueueCreate(15,sizeof(float));
   if (queue != NULL)
   {
    Serial.println("queue is created");
   }
   
}

void rotate_CompassDirection()
{
 float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);
  sVector_t mag = compass.readRaw();
  compass.getHeadingDegrees();
//   Serial.print("X:");
//   Serial.print(mag.XAxis);
//   Serial.print(" Y:");
//   Serial.print(mag.YAxis);
//   Serial.print(" Z:");
//   Serial.println(mag.ZAxis);
  Serial.print("Degress = ");
  float headingDegree = mag.HeadingDegress;
  Serial.println(headingDegree);

 xQueueSend(queue,&headingDegree ,TickType_t(10/portTICK_PERIOD_MS));
   delay(100);

}

void compassDirection()
{
    float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);
  sVector_t mag = compass.readRaw();
  compass.getHeadingDegrees();
//   Serial.print("X:");
//   Serial.print(mag.XAxis);
//   Serial.print(" Y:");
//   Serial.print(mag.YAxis);
//   Serial.print(" Z:");
//   Serial.println(mag.ZAxis);
  Serial.print("Degress = ");
  float headingDegreeFinal = mag.HeadingDegress;
  Serial.println(headingDegreeFinal);
   xQueueSend(queue , &headingDegreeFinal , TickType_t(10/portTICK_PERIOD_MS));
  delay(2000);
  


}

bool compareDirections()
{
    float headingDegree, headingDegreeFinal;
    xQueueReceive(queue ,&headingDegree , TickType_t(10/portTICK_PERIOD_MS));
    xQueueReceive(queue, &headingDegreeFinal , TickType_t(10/portTICK_PERIOD_MS));

    if(headingDegree == headingDegreeFinal)
    {
        robotMovement(0,0,0,0);
        Serial.println("directions are same ..rotation stopped");
        delay(1000);

        return true;
    }
    else
    {
       robotMovement(1,0,0,1);
       Serial.println("directions are not same ... still rotating");

       return false;
    }
}
#include "master.h"

unsigned long rotationDuration = 2000;
unsigned long currentTime;

bool rotate = false;



void rotatingOne()
{
  currentTime = millis();
  Serial.print("ctime1     "); Serial.println(currentTime);
  

  if(currentTime < rotationDuration)
  {
     Serial.print("ctime2     "); Serial.println(currentTime);  
    Serial.println("rotating with ");
    robotMovement(250,0,0,250);                 //left
    bleDataS();
   
   
  }
  else
  {
    compassDirection();
    if(compareDirections() == true)
    {
    rotate = true;
    Serial.println("rotation stopped");
    }
  }
  
}

bool moveToCollectingWaste()
{
    if(rotate == false)
    {
       rotatingOne(); 
    }
    if(rotate == true)
    {
        obstacleAvoidance();
        bleDataS();
        // collectWaste();
        if(collectWaste()==true)
        {
            rotate = false;        
        }
       
    }
     return true ;
    
}

bool moveToDepositingWaste()
{ 
  if(moveToCollectingWaste() ==  true)
  {

  
    if(rotate == false)
    {
        rotatingOne();
    }
    if(rotate == true)
    {
        obstacleAvoidance();
        bleDataS();
        depositWaste();
    }
  }
    return true;

}
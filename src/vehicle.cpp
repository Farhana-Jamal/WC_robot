#include <vehicle.h>
#include <Arduino.h>
#include <beacon.h>

bool rotate = false;

unsigned long prvsTime = 0;
unsigned long rotationDuration = 30000;
unsigned long currentTime;


void motorSetup()
{
    // sets the pins as outputs:
  
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  
  
  Serial.begin(115200);

  // testing
  Serial.print("Testing DC Motor..."); 

analogWrite(enable1Pin,80);
analogWrite(enable2Pin , 80);

}

void rotatingOne()
{
  currentTime = millis();
  if(!rotate)
  {  
      Serial.println("rotating");
      robotMovement(1,0,0,1);
      rotate = true;
      prvsTime = currentTime;
  }

  if(rotate && currentTime-prvsTime < rotationDuration)
  {
    Serial.println("rotating with ");
    robotMovement(1,0,0,1);
    dataS();
  }
  else
  {
    rotate = true;
  }
  
}

void robotMovement(bool INA1,bool INA2 , bool INA3 , bool INA4)
{
  digitalWrite (motor1Pin1 , INA1);
  digitalWrite (motor1Pin2 , INA2);
  digitalWrite (motor2Pin1 , INA3);
  digitalWrite (motor2Pin2 , INA4);
   
  

}

  


#include <vehicle.h>




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



void robotMovement(bool INA1,bool INA2 , bool INA3 , bool INA4)
{
  digitalWrite (motor1Pin1 , INA1);
  digitalWrite (motor1Pin2 , INA2);
  digitalWrite (motor2Pin1 , INA3);
  digitalWrite (motor2Pin2 , INA4);
   
  

}

  


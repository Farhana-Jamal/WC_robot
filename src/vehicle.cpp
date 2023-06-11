#include <vehicle.h>
#include <Arduino.h>

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

// boolean INA1,INA2,INA3 ,INA4;

void robotMovement(bool INA1,bool INA2 , bool INA3 , bool INA4)
{
  digitalWrite (motor1Pin1 , INA1);
  digitalWrite (motor1Pin2 , INA2);
  digitalWrite (motor2Pin1 , INA3);
  digitalWrite (motor2Pin2 , INA4);

}

  

// void moveFwd()
// {
// // Move the DC motor forward at maximum speed
//   Serial.println("Moving forward");
//   digitalWrite(motor1Pin1, LOW);
//   digitalWrite(motor1Pin2, HIGH);
//   digitalWrite(motor2Pin1, LOW);
//   digitalWrite(motor2Pin2, HIGH);
   
 
// }



//  void moveBwd()
//  {
//   // Move DC motor backwards at maximum speed
//   Serial.println("Moving backwards");
//   digitalWrite(motor1Pin1, HIGH);
//   digitalWrite(motor1Pin2, LOW);

//   digitalWrite(motor2Pin1, HIGH);
//   digitalWrite(motor2Pin2, LOW); 
  

//  }
//  void Stop()
//  {
//   // Stop the DC motor
//   Serial.println("Motor stopped");
//   digitalWrite(motor1Pin1, LOW);
//   digitalWrite(motor1Pin2, LOW);

//   digitalWrite(motor2Pin1, LOW);
//   digitalWrite(motor2Pin2, LOW);
  
//  }

//  void moveLeft()
// {
//   Serial.println("Motor left");
//   digitalWrite(motor1Pin1 , LOW);
//   digitalWrite(motor1Pin2 , LOW);
//   digitalWrite(motor2Pin1 , HIGH);
//   digitalWrite(motor2Pin2 , LOW);

//   delay(2000);

//   // digitalWrite(motor1Pin1, LOW);
//   // digitalWrite(motor1Pin2, HIGH);
//   // digitalWrite(motor2Pin1, LOW);
//   // digitalWrite(motor2Pin2, HIGH);

//   moveFwd();
   



// }

// void moveRight()
// {
//   Serial.println("Motor right");
//   digitalWrite(motor1Pin1 , LOW);
//   digitalWrite(motor1Pin2 , HIGH);
//   digitalWrite(motor2Pin1 , LOW);
//   digitalWrite(motor2Pin2 , LOW);

//   delay(2000);

//   moveFwd();

//   // digitalWrite(motor1Pin1, LOW);
//   // digitalWrite(motor1Pin2, HIGH);
//   // digitalWrite(motor2Pin1, LOW);
//   // digitalWrite(motor2Pin2, HIGH);
   

// }
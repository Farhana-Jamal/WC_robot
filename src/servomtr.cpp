#include "servomtr.h"


void servoRotate(int pulseWidth)
{
    digitalWrite(servoPin , HIGH);
    delayMicroseconds(pulseWidth);         
    digitalWrite(servoPin, LOW);
    delay(20);                      //20ms (50 Hz) PWM period (pulsecycle)
}

void servoSetup()
{
    Serial.begin(115200);
    pinMode(servoPin , OUTPUT);
    
    servoRotate(1500);
}



int lookRight()
{
    servoRotate(500);               //500 - 0deg
    delay(500);
    int distance = lidarDistance();
    delay(100);
    servoRotate(1500);              //1500 - 90deg

    return distance;

}

int lookLeft()
{
    servoRotate(2200);             //2200 - 180deg
    delay(500);
    int distance = lidarDistance();
    delay(100);
    servoRotate(1500);

    return distance;
}



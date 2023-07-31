#include "servomtr.h"


Servo obstacleServo;
Servo bottomBioServo;
Servo bottomNonBioServo;

void servoSetup()
{
    Serial.begin(115200);
    obstacleServo.setPeriodHertz(50);
    bottomBioServo.setPeriodHertz(50);
    bottomNonBioServo.setPeriodHertz(50);

    obstacleServo.attach(obstacleServoPin,500,2400);
    bottomBioServo.attach(bottomBioServoPin , 500,2400);
    bottomNonBioServo.attach(bottomNonBioServoPin , 500,2400);

    if(obstacleServo.attached())
    {
      Serial.println("servo attached");
    }
    obstacleServo.write(115);
    bottomBioServo.write(0);
    bottomNonBioServo.write(0);

}

int lookRight()
{
    obstacleServo.write(50);
    delay(500);
    int distance = lidarDistance();
    delay(100);
    obstacleServo.write(115);

    return distance;

}

int lookLeft()
{
    obstacleServo.write(170);
    delay(500);
    int distance = lidarDistance();
    delay(100);
    obstacleServo.write(115);

    return distance;
}

void bottomOpenAndClose()
{
    bottomBioServo.write(90);
    delay(2000);
    bottomBioServo.write(0);
    bottomNonBioServo.write(90);
    delay(2000);
    bottomNonBioServo.write(0);

}



#include <servomtr.h>
#include <LIdar.h>

Servo servo;

void servoSetup()
{
    Serial.begin(115200);
    servo.setPeriodHertz(50);
    servo.attach(servoPin,500,2400);

    if(servo.attached())
    {
      Serial.println("servo attached");
    }
    servo.write(115);

}

int lookRight()
{
    servo.write(50);
    delay(500);
    int distance = lidarDistance();
    delay(100);
    servo.write(115);

    return distance;

}

int lookLeft()
{
    servo.write(170);
    delay(500);
    int distance = lidarDistance();
    delay(100);
    servo.write(115);

    return distance;
}




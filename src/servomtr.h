#ifndef SERVO_H
#define SERVO_H


#define servoPin  15

void servoSetup();
void servoRotate(int pulseWidth);
int lookRight();
int lookLeft();

#endif
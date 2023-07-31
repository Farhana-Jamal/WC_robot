#ifndef MASTER_H
#define MASTER_H


#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <WiFi.h>

#define ssid  "farhana"
#define password "1234567890"

#define robotStartLed 2

#include "beacon.h"
#include "compass.h"
#include "lidar.h"
#include "servomtr.h"
#include "vehicle.h"


void rotatingOne();
bool moveToCollectingWaste();
bool moveToDepositingWaste();
void robotStartSetup();
void robotStart();


#endif
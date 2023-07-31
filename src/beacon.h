#ifndef BEACON_H
#define BEACON_H

#include <Arduino.h>
#include <BluetoothSerial.h>
#include "compass.h"
#include "vehicle.h"


 void rssiRead(int rssiRaw);
 void bleDataS();
 void bleBeaconSetup();
 void collectWaste();

#endif
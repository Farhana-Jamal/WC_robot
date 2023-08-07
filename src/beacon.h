// #ifndef BEACON_H
// #define BEACON_H

// #include <BluetoothSerial.h>
// #include "compass.h"
// #include "vehicle.h"
// #include "servomtr.h"

// void rssiRead();
// bool compareRSSIDatas();
// void bleDataS();
// void bleBeaconSetup();
// bool collectWaste();
// void depositWaste();

// #endif
#ifndef BEACON_H
#define BEACON_H


#include <BluetoothSerial.h>
#include "compass.h"
#include "vehicle.h"
#include "servomtr.h"


 void rssiRead(int rssiRaw);
 void bleDataS();
 void bleBeaconSetup();
 bool collectWaste();
 void depositWaste();

#endif
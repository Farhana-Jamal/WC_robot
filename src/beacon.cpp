#include <Arduino.h>
#include <beacon.h>
#include <BluetoothSerial.h>
#include <WiFi.h>
#include <LIdar.h>


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;


#define BT_DISCOVER_TIME	2000


static bool btScanAsync = true;
static bool btScanSync = true;

int rssiData = -100 ;
void rssiRead(int rssiRaw)
{
  
    Serial.println(rssiRaw);
    Serial.println(rssiData);
    

   
   
    if(rssiRaw >= rssiData)
    {
        Serial.print("greater rssiraw");  Serial.println(rssiRaw);
        rssiData = rssiRaw; 
          
    }
    else{
      Serial.print("greater rssidata");  Serial.println(rssiData);
    }
   
}




void btAdvertisedDeviceFound(BTAdvertisedDevice* pDevice) {
	Serial.printf("Found a device asynchronously: %s\n", pDevice->toString().c_str());

    String deviceName = pDevice->getName().c_str();
    const char* deviceAddress = pDevice->getAddress().toString().c_str();
    int cod = pDevice->getCOD();
    int rssi = pDevice->getRSSI();

    Serial.print("Device Name: ");
    Serial.println(deviceName);
    Serial.print("Device Address: ");
    Serial.println(deviceAddress);
    Serial.print("COD: ");
    Serial.println(cod);
    Serial.print("RSSI: ");
    Serial.println(rssi);
    Serial.println();

    rssiRead(rssi);

    
}
 void bleDataS()
{
     if (btScanAsync) {
    Serial.print("Starting discoverAsync...");
    if (SerialBT.discoverAsync(btAdvertisedDeviceFound)) {
      delay(2000);
      Serial.print("Stopping discoverAsync... ");
      SerialBT.discoverAsyncStop();
      Serial.println("stopped");
    } else {
      Serial.println("Error on discoverAsync f.e. not workin after a \"connect\"");
    }
  } 
 

}



void bleBeaconSetup() 
{
  
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

}

void wifiBeaconSetup()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println(" wifi Setup done");

}

void wifiScanDatas()
{
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID());
      Serial.print("    RSSI :");
      Serial.println(WiFi.RSSI());
     
      // Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
    //   delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(2000);
}
  



 
   

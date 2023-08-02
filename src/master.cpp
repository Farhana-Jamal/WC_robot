#include "master.h"

unsigned long rotationDuration = 2000;
unsigned long currentTime;

bool rotate = false;

// WiFiServer server(80);

// String header;                                             // Variable to store the HTTP request
// String robot = "start";

// void robotStartSetup()
// {
    
//     pinMode(robotStartLed, OUTPUT);                               // Initialize the output variables as outputs
//     digitalWrite(robotStartLed, LOW);                               // Set outputs to LOW

//   // Connect to Wi-Fi network with SSID and password
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   // Print local IP address and start web server
//   Serial.println("");
//   Serial.println("WiFi connected.");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
//   server.begin();

// }

// void robotStart()
// {
//     WiFiClient client = server.available();   // Listen for incoming clients

//   if (client) {                             // If a new client connects,
//     Serial.println("New Client.");          // print a message out in the serial port
//     String currentLine = "";                // make a String to hold incoming data from the client
//     while (client.connected()) {            // loop while the client's connected
//       if (client.available()) {             // if there's bytes to read from the client,
//         char c = client.read();             // read a byte, then
//         Serial.write(c);                    // print it out the serial monitor
//         header += c;
//         if (c == '\n') {                    // if the byte is a newline character
//           // if the current line is blank, you got two newline characters in a row.
//           // that's the end of the client HTTP request, so send a response:
//           if (currentLine.length() == 0) {
//             // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
//             // and a content-type so the client knows what's coming, then a blank line:
//             client.println("HTTP/1.1 200 OK");
//             client.println("Content-type:text/html");
//             client.println("Connection: close");
//             client.println();
            
//             // turns the GPIOs on and off
//             if (header.indexOf("GET /2/on") >= 0) {
//               Serial.println("robot Starts");
//               robot = "start";
//               // digitalWrite(FBled, HIGH);
            
//             // } else if (header.indexOf("GET /2/off") >= 0) {
//             //   Serial.println("robot stop");
//             //   robot = "stop";
//               // digitalWrite(FBled, LOW);
            
//             }

//             client.println("<!DOCTYPE html><html>");
//             client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
//             client.println("<link rel=\"icon\" href=\"data:,\">");
//             // CSS to style the on/off buttons 
//             // Feel free to change the background-color and font-size attributes to fit your preferences
//             client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
//             client.println(".button1 { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
//             client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
//             client.println(".button2 {background-color: #555555;}</style></head>");

//             client.println("<body><h1>Remote</h1>");
            
//             // Display current state, and ON/OFF buttons for GPIO 2 
//             client.println("<p>robot " + robot + "</p>"); 

//             // If the output2 State is off, it displays the ON button       
//             if (robot=="stop") {
//               client.println("<p><a href=\"/27/on\"><button1 class=\"button1\">START</button1></a></p>");
//             } else {
//               client.println("<p><a href=\"/27/off\"><button1 class=\"button1 button2\">STOP</button1></a></p>");
//             }
//             client.println("</body></html>");
//             client.println();
//             // Break out of the while loop
//             break;
//           } else { // if you got a newline, then clear currentLine
//             currentLine = "";
//           }
//         } else if (c != '\r') {  // if you got anything else but a carriage return character,
//           currentLine += c;      // add it to the end of the currentLine
//         }
//       }
//     }
//     // Clear the header variable
//     header = "";
//     // Close the connection
//     client.stop();
//     Serial.println("Client disconnected.");
//     Serial.println("");
//   }
// }



void rotatingOne()
{
  currentTime = millis();
  Serial.print("ctime1     "); Serial.println(currentTime);
  

  if(currentTime < rotationDuration)
  {
     Serial.print("ctime2     "); Serial.println(currentTime);  
    Serial.println("rotating with ");
    robotMovement(250,0,0,250);                 //left
    bleDataS();
   
   
  }
  else
  {
    compassDirection();
    if(compareDirections() == true)
    {
    rotate = true;
    Serial.println("rotation stopped");
    }
  }
  
}

bool moveToCollectingWaste()
{
    if(rotate == false)
    {
       rotatingOne(); 
    }
    if(rotate == true)
    {
        obstacleAvoidance();
        bleDataS();
        // collectWaste();
        if(collectWaste()==true)
        {
            rotate = false;        
        }
       
    }
     return true ;
    
}

bool moveToDepositingWaste()
{ 
  if(moveToCollectingWaste() ==  true)
  {

  
    if(rotate == false)
    {
        rotatingOne();
    }
    if(rotate == true)
    {
        obstacleAvoidance();
        bleDataS();
        depositWaste();
    }
  }
    return true;

}

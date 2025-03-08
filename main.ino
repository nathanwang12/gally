#include <WiFi.h>
#include "Gally.h"

const char *ssid = "GALLY";
const char *password = "lusciouseyebrows";

// address: http://192.168.4.1/
WiFiServer server(80);

Gally gally;

void setup() {
  delay(500);
  Serial.begin(115200);

  WiFi.softAP(ssid, password);

  server.begin();

  gally.init();
}

void loop() {
  int frontDistance = gally.getFrontDistance();
  int right1Distance = gally.getRight1Distance();
  int right2Distance = gally.getRight2Distance();

  // Serial.print("Front Distance: ");
  // Serial.println(frontDistance);
  // Serial.print("Right Distance: ");
  // Serial.println(rightDistance);
  if ((right1Distance >= 150) || (right1Distance < 0)) {
    gally.turnRight();
  } else if (frontDistance <= 150) {
    gally.turnLeft();
  } else {
    if (right1Distance - right2Distance >= 20) {
      gally.straightenRight();
    } else if (right2Distance - right1Distance >= 20) {
      gally.straightenLeft();
    } else {
      gally.moveForward();
    }
  }
  delay(250);
}


// void loop() {
//   WiFiClient client = server.available();
//   if (client) {
//     Serial.println("New Client connected.");
//     String request = "";

//     while (client.connected()) {
//       if (client.available()) {
//         char c = client.read();
//         request += c;
//         Serial.write(c);
//         if (c == '\n') break;
//       }
//     }

//     if (request.indexOf("GET /L") != -1) {
//       gally.turnLeft();
//     } else if (request.indexOf("GET /R") != -1) {
//       gally.turnRight();
//     } else if (request.indexOf("GET /X") != -1) {
//       gally.straightenLeft();
//     } else if (request.indexOf("GET /Y") != -1) {
//       gally.straightenRight();
//     } else if (request.indexOf("GET /F") != -1) {
//       gally.moveForward();
//     } else if (request.indexOf("GET /D") != -1) {
//       int frontDistance = gally.getFrontDistance();
//       int right1Distance = gally.getRight1Distance();
//       int right2Distance = gally.getRight2Distance();

//       Serial.print("Front Distance: ");
//       Serial.println(frontDistance);
//       Serial.print("Right1 Distance: ");
//       Serial.println(right1Distance);
//       Serial.print("Right2 Distance: ");
//       Serial.println(right2Distance);
//     } 

//     client.println("HTTP/1.1 200 OK");
//     client.println("Content-type:text/html");
//     client.println();
//     client.println("Command received!");
//     client.println();
//     client.stop();
//   }
// }


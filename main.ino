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
  int front1Distance = gally.getFront1Distance();
  int front2Distance = gally.getFront2Distance();
  int right1Distance = gally.getRight1Distance();
  int right2Distance = gally.getRight2Distance();

  // if (right1Distance - right2Distance >= 6) {
  //   // gally.stop();
  //   gally.straightenRight();
  // } else if (right2Distance - right1Distance >= 6) {
  //   // gally.stop();
  //   gally.straightenLeft();
  // }


  if ((right1Distance >= 250) || (right1Distance < 0)) {
    // gally.stop();
    gally.inchForward();
    gally.turnRight();
  } else if ((front1Distance <= 250) || (front2Distance <= 250)) {

    // gally.stop();
    gally.turnLeft();
  } else if (
    (right1Distance - right2Distance >= 8) ||
    (front2Distance - front1Distance >= 4)
  ) {
    // gally.stop();
    gally.straightenRight();
  } else if (
    (right2Distance - right1Distance >= 8) ||
    (front1Distance - front2Distance >= 4)
  ) {
    // gally.stop();
    gally.straightenLeft();
  } else {
    gally.moveForward();
  }
}
// void loop() {
//   int frontDistance = gally.getFrontDistance();
//   int right1Distance = gally.getRight1Distance();
//   int right2Distance = gally.getRight2Distance();

//   // Serial.print("Front Distance: ");
//   // Serial.println(frontDistance);
//   // Serial.print("Right Distance: ");
//   // Serial.println(rightDistance);
//   if ((right1Distance >= 200) || (right1Distance < 0)) {
//     gally.turnRight();
//   } else if (frontDistance <= 200) {
//     gally.turnLeft();
//   } else {
//     if (right1Distance - right2Distance >= 20) {
//       gally.straightenRight();
//     } else if (right2Distance - right1Distance >= 20) {
//       gally.straightenLeft();
//     } else {
//       gally.moveForward();
//     }
//   }
// }


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
//       int front1Distance = gally.getFront1Distance();
//       int front2Distance = gally.getFront2Distance();
//       int right1Distance = gally.getRight1Distance();
//       int right2Distance = gally.getRight2Distance();

//       Serial.print("Front1 Distance: ");
//       Serial.println(front1Distance);
//       Serial.print("Front2 Distance: ");
//       Serial.println(front2Distance);
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


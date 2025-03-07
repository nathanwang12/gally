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
  int rightDistance = gally.getRightDistance();
  Serial.print("Front Distance: ");
  Serial.println(frontDistance);
  Serial.print("Right Distance: ");
  Serial.println(rightDistance);
  // gally.servoLeft();
  // delay(500);
  // gally.servoRight();
  // delay(500);
  // gally.servoForward();
  // delay(500);
  // gally.moveForward();
  // delay(500);
  // int frontDistance = gally.getFrontDistance();
  // int rightDistance = gally.getRightDistance();
  // Serial.println(frontDistance);
  // Serial.println(rightDistance);
}

// void loop() {
//   // Get the front and right sensor distances
//   int frontDistance = gally.getFrontDistance();
//   int rightDistance = gally.getRightDistance();

//   // Print the distances for debugging (optional)
//   Serial.print("Front Distance: ");
//   Serial.println(frontDistance);
//   Serial.print("Right Distance: ");
//   Serial.println(rightDistance);

//   // Check the conditions and make decisions
//   if (frontDistance < 20 && rightDistance < 20) {
//     // If both front and right distances are less than 20 mm, turn left
//     Serial.println("Turning Left...");
//     gally.turnLeft();
//   } 
//   else if (frontDistance > 200 && rightDistance > 200) {
//     // If both front and right distances are greater than 200 mm, turn right
//     Serial.println("Turning Right...");
//     gally.turnRight();
//   } 
//   else {
//     // If none of the above conditions are met, move forward
//     Serial.println("Moving Forward...");
//     gally.moveForward();
//   }

//   // Add a small delay to avoid flooding the Serial Monitor with too many readings
//   delay(500);
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
//     } else if (request.indexOf("GET /F") != -1) {
//       gally.moveForward();
//     }

//     client.println("HTTP/1.1 200 OK");
//     client.println("Content-type:text/html");
//     client.println();
//     client.println("Command received!");
//     client.println();
//     client.stop();
//   }
// }


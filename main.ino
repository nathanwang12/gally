#include <WiFi.h>

#include "Gally.h"

const char *ssid = "GALLY";
const char *password = "lusciouseyebrows";

// address: http://192.168.4.1/
WiFiServer server(80);

Gally gally;

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);

  server.begin();

  gally.init();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client connected.");
    String request = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        Serial.write(c);
        if (c == '\n') break;
      }
    }

    if (request.indexOf("GET /L") != -1) {
      gally.turnLeft();
    } else if (request.indexOf("GET /R") != -1) {
      gally.turnRight();
    } else if (request.indexOf("GET /F") != -1) {
      gally.moveForward();
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("Command received!");
    client.println();
    client.stop();
  }
}


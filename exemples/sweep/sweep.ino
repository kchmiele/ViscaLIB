#include <WiFi.h>
#include <WiFiUdp.h>
#include "ViscaLib.h"  // Include the updated ViscaLib library

// WiFi credentials
const char* ssid = "your_SSID";
const char* password = "your_password";

// Camera's IP and port
IPAddress cameraIP(192, 168, 1, 100);  // Replace with your camera's IP address
const uint16_t cameraPort = 52381;     // Default VISCA IP port for Sony cameras

// UDP object and VISCA library instance
WiFiUDP udp;
ViscaLib visca(udp);

void setup() {
  Serial.begin(115200);  // Start Serial for debugging

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Example VISCA commands:
  visca.PAN_TILT_LEFT(0x05, 0x05, cameraIP, cameraPort);  // Pan left with speed 5
  delay(1000);

  visca.PAN_TILT_RIGHT(0x05, 0x05, cameraIP, cameraPort);  // Pan right with speed 5
  delay(1000);

  visca.PAN_TILT_UP(0x05, 0x05, cameraIP, cameraPort);    // Pan up with speed 5
  delay(1000);

  visca.PAN_TILT_DOWN(0x05, 0x05, cameraIP, cameraPort);  // Pan down with speed 5
  delay(1000);

  visca.PAN_TILT_HOME(cameraIP, cameraPort);  // Stop pan-tilt motion
  delay(2000);

  // You can add more commands here as needed
}

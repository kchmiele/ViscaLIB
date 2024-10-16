#include <WiFi.h>
#include <WiFiUdp.h>
#include "ViscaLib.h"            // Include the updated ViscaLib library

// WiFi credentials
const char* ssid = "SSID";
const char* password = "PASS";

// Camera IP and VISCA port
IPAddress visca_ip(192, 168, 1, 100);  // Replace with the camera's IP
uint16_t visca_port = 52381;           // Default VISCA port

WiFiUDP udp;             // Instantiate the UDP object
ViscaLib myVisca(udp);   // Create a ViscaLib object, passing the UDP object

void setup() {
  Serial.begin(115200);  // Start Serial for debugging

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi.");
}

void loop() {
  // Send commands as needed
  myVisca.PAN_TILT_LEFT(5, visca_ip, visca_port);  // Adjust speed as needed
  delay(1000);  // Wait 1 second

  myVisca.PAN_TILT_RIGHT(5, visca_ip, visca_port); // Adjust speed as needed
  delay(1000);  // Wait 1 second
}

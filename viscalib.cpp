#include "ViscaLib.h"

// Constructor to initialize the UDP object
ViscaLib::ViscaLib(WiFiUDP &udp) : _udp(udp) {}

// Sends the VISCA command as a UDP packet
void ViscaLib::sendList(byte list[], size_t listsize, IPAddress ip, uint16_t port) {
    _udp.beginPacket(ip, port);
    _udp.write(0x81);  // Start byte

    for (size_t i = 0; i < listsize; i++) {
        _udp.write(list[i]);  // Write each byte
    }

    _udp.write(0xFF);  // End byte
    _udp.endPacket();  // Send the packet

    // Print the packet for debugging
    Serial.print("Sent Packet: ");
    Serial.print("0x81 ");
    for (size_t i = 0; i < listsize; i++) {
        Serial.print(list[i], HEX);
        Serial.print(" ");
    }
    Serial.println("0xFF");
}

// Movement Commands
// Movement Commands
void ViscaLib::PAN_TILT_LEFT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x01, 0x03};  // Pan Tilt Left
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_RIGHT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x02, 0x03};  // Pan Tilt Right
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_UP(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x03, 0x01};  // Pan Tilt Up
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_DOWN(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x03, 0x02};  // Pan Tilt Down
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_UPLEFT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x01, 0x01};  // Pan Tilt Up Left
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_UPRIGHT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x02, 0x01};  // Pan Tilt Up Right
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_DOWNLEFT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x01, 0x02};  // Pan Tilt Down Left
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_DOWNRIGHT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x02, 0x02};  // Pan Tilt Down Right
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_STOP(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x01, panSpeed, tiltSpeed, 0x03, 0x03};  // Pan Tilt Stop
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_HOME(IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, 0x04};  // Pan Tilt Home
    sendList(command, sizeof(command), ip, port);
}

// Zoom Commands
void ViscaLib::ZOOM_IN(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x04, speed};  // ZOOM_IN command
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::ZOOM_OUT(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x05, speed};  // ZOOM_OUT command
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::ZOOM_STOP(IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x03};  // ZOOM_STOP command
    sendList(command, sizeof(command), ip, port);
}

// Focus Commands
void ViscaLib::FOCUS_NEAR(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x0A, speed};  // FOCUS_NEAR command
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::FOCUS_FAR(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x0B, speed};  // FOCUS_FAR command
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::FOCUS_STOP(IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x0E};  // FOCUS_STOP command
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::AUTO_FOCUS_ON(IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x04, 0x38, 0x02};  // AUTO_FOCUS_ON command
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::MANUAL_FOCUS_ON(IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x04, 0x38, 0x03};  // MANUAL_FOCUS_ON command
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::ONE_TOUCH_FOCUS(IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x04, 0x18, 0x01};  // ONE_TOUCH_FOCUS command
    sendList(command, sizeof(command), ip, port);
}

// Preset Commands
void ViscaLib::SET_PRESET(uint8_t presetNumber, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x30, presetNumber};  // SET_PRESET command
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::GO_TO_PRESET(uint8_t presetNumber, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x31, presetNumber};  // GO_TO_PRESET command
    sendList(command, sizeof(command), ip, port);
}

// Additional Command
void ViscaLib::START_AUTO_FLIP(IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x33};  // START_AUTO_FLIP command
    sendList(command, sizeof(command), ip, port);
}

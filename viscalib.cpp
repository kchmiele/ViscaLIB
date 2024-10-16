#include "ViscaLib.h"

ViscaLib::ViscaLib(WiFiUDP &udp) : _udp(udp) {}  // Constructor implementation

void ViscaLib::sendList(byte list[], size_t listsize, IPAddress ip, uint16_t port) {
    // Start sending the UDP packet
    _udp.beginPacket(ip, port);
    _udp.write(0x81);  // Start byte

    for (size_t i = 0; i < listsize; i++) {
        _udp.write(list[i]);  // Write each byte
    }

    _udp.write(0xFF);  // End byte
    _udp.endPacket();  // Send the packet
}

void ViscaLib::PAN_TILT_LEFT(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x06, speed};  // Example command structure for PAN_TILT_LEFT
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::PAN_TILT_RIGHT(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x07, speed};  // Example command structure for PAN_TILT_RIGHT
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::ZOOM_IN(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x04, speed};  // Example command structure for ZOOM_IN
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::ZOOM_OUT(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x05, speed};  // Example command structure for ZOOM_OUT
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::FOCUS_NEAR(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x0A, speed};  // Example command structure for FOCUS_NEAR
    sendList(command, sizeof(command), ip, port);
}

void ViscaLib::FOCUS_FAR(uint8_t speed, IPAddress ip, uint16_t port) {
    byte command[] = {0x01, 0x0B, speed};  // Example command structure for FOCUS_FAR
    sendList(command, sizeof(command), ip, port);
}

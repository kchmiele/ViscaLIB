#ifndef VISCALIB_H
#define VISCALIB_H

#include <WiFi.h>
#include <WiFiUdp.h>

class ViscaLib {
public:
    ViscaLib(WiFiUDP &udp);  // Constructor to initialize the UDP object

    // Movement Commands
    void PAN_TILT_LEFT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_RIGHT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_UP(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_DOWN(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_UPLEFT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_UPRIGHT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_DOWNLEFT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_DOWNRIGHT(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_STOP(uint8_t panSpeed, uint8_t tiltSpeed, IPAddress ip, uint16_t port);
    void PAN_TILT_HOME(IPAddress ip, uint16_t port);

    // Zoom Commands
    void ZOOM_IN(uint8_t speed, IPAddress ip, uint16_t port);
    void ZOOM_OUT(uint8_t speed, IPAddress ip, uint16_t port);
    void ZOOM_STOP(IPAddress ip, uint16_t port);

    // Focus Commands
    void FOCUS_NEAR(uint8_t speed, IPAddress ip, uint16_t port);
    void FOCUS_FAR(uint8_t speed, IPAddress ip, uint16_t port);
    void FOCUS_STOP(IPAddress ip, uint16_t port);
    void AUTO_FOCUS_ON(IPAddress ip, uint16_t port);
    void MANUAL_FOCUS_ON(IPAddress ip, uint16_t port);
    void ONE_TOUCH_FOCUS(IPAddress ip, uint16_t port);

    // Preset Commands
    void SET_PRESET(uint8_t presetNumber, IPAddress ip, uint16_t port);
    void GO_TO_PRESET(uint8_t presetNumber, IPAddress ip, uint16_t port);

    // Additional Command
    void START_AUTO_FLIP(IPAddress ip, uint16_t port);

private:
    WiFiUDP &_udp;  // Reference to the WiFiUDP object
    void sendList(byte list[], size_t listsize, IPAddress ip, uint16_t port);
};

#endif // VISCALIB_H

#ifndef VISCALIB_H
#define VISCALIB_H

#include <WiFi.h>
#include <WiFiUdp.h>

class ViscaLib {
public:
    ViscaLib(WiFiUDP &udp);  // Constructor to initialize the UDP object

    void PAN_TILT_LEFT(uint8_t speed, IPAddress ip, uint16_t port);
    void PAN_TILT_RIGHT(uint8_t speed, IPAddress ip, uint16_t port);
    void ZOOM_IN(uint8_t speed, IPAddress ip, uint16_t port);
    void ZOOM_OUT(uint8_t speed, IPAddress ip, uint16_t port);
    void FOCUS_NEAR(uint8_t speed, IPAddress ip, uint16_t port);
    void FOCUS_FAR(uint8_t speed, IPAddress ip, uint16_t port);

private:
    WiFiUDP &_udp;  // Reference to the WiFiUDP object
    void sendList(byte list[], size_t listsize, IPAddress ip, uint16_t port);
};

#endif // VISCALIB_H

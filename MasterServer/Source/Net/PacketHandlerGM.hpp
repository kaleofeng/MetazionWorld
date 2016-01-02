#ifndef _MASTERSERVER_PACKETHANDLERGM_HPP_
#define _MASTERSERVER_PACKETHANDLERGM_HPP_

#include "Net/Sockets.hpp"

class PacketHandlerGM {

public:
    PacketHandlerGM() {}

    ~PacketHandlerGM() {}

public:
    void Handle(int command, const void* data, int length);

private:
    void HandleConnected(const void* data, int length);

    void HandleDisconnected(const void* data, int length);
};

#endif // _MASTERSERVER_PACKETHANDLERGM_HPP_

#ifndef _CLIENT_PACKETHANDLERGC_HPP_
#define _CLIENT_PACKETHANDLERGC_HPP_

#include "Net/Sockets.hpp"

class PacketHandlerGC {
public:
    PacketHandlerGC() {}

    ~PacketHandlerGC() {}

public:
    void Handle(int command, const void* data, int length);

private:
     void HandleConnected(const void* data, int length);

     void HandleDisconnected(const void* data, int length);
};

#endif // _CLIENT_PACKETHANDLERGC_HPP_

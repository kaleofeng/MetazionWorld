#ifndef _CLIENT_PACKETHANDLERLC_HPP_
#define _CLIENT_PACKETHANDLERLC_HPP_

#include "Net/Sockets.hpp"

class PacketHandlerLC {
public:
    PacketHandlerLC() {}

    ~PacketHandlerLC() {}

public:
    void Handle(int command, const void* data, int length);

private:
     void HandleConnected(const void* data, int length);

     void HandleDisconnected(const void* data, int length);

    void HandlePlayerLogin(const void* data, int length);

    void HandleServerList(const void* data, int length);
};

#endif // _CLIENT_PACKETHANDLERLC_HPP_

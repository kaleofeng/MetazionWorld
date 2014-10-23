#ifndef _GATEWAYSERVER_PACKETHANDLERCG_HPP_
#define _GATEWAYSERVER_PACKETHANDLERCG_HPP_

#include <Metazion/Overall.hpp>

#include "Sockets.hpp"

class PacketHandlerCG {
public:
    PacketHandlerCG() {}

    ~PacketHandlerCG() {}

public:
    void Handle(ServerSocketCG* socket
        , int command, const void* data, int length);

private:
    void HandleConnected(ServerSocketCG* socket
        , const void* data, int length);

    void HandleDisconnected(ServerSocketCG* socket
        , const void* data, int length);
};

#endif // _GATEWAYSERVER_PACKETHANDLERCG_HPP_

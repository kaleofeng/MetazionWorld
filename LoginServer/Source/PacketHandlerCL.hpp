#ifndef _LOGINSERVER_PACKETHANDLERCL_HPP_
#define _LOGINSERVER_PACKETHANDLERCL_HPP_

#include <Metazion/Overall.hpp>

#include "Sockets.hpp"

class PacketHandlerCL {
public:
    PacketHandlerCL() {}

    ~PacketHandlerCL() {}

public:
    void Handle(ServerSocketCL* socket
        , int command, const void* data, int length);

private:
    void HandleConnected(ServerSocketCL* socket
        , const void* data, int length);

    void HandleDisconnected(ServerSocketCL* socket
        , const void* data, int length);

    void HandlePlayerLogin(ServerSocketCL* socket
        , const void* data, int length);
};

#endif // _LOGINSERVER_PACKETHANDLERCL_HPP_

#ifndef _LOGINSERVER_PACKETHANDLERCL_HPP_
#define _LOGINSERVER_PACKETHANDLERCL_HPP_

#include <Metazion/Overall.hpp>

#include "Sockets.hpp"

class PacketHandlerCL {
    DISALLOW_COPY_AND_ASSIGN(PacketHandlerCL)

public:
    PacketHandlerCL() {}

    ~PacketHandlerCL() {}

public:
    void Handle(GameServerSocket* socket
        , int command, const void* data, int length);

private:
    void HandleLogin(GameServerSocket* socket, const void* data, int length);
};

#endif // _LOGINSERVER_PACKETHANDLERCL_HPP_

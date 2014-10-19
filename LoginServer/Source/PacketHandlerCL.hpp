#ifndef _LOGINSERVER_PACKETHANDLERCL_HPP_
#define _LOGINSERVER_PACKETHANDLERCL_HPP_

#include <Metazion/Overall.hpp>

#include "SocketCL.hpp"

class PacketHandlerCL {
    DISALLOW_COPY_AND_ASSIGN(PacketHandlerCL)

public:
    PacketHandlerCL() {}

    ~PacketHandlerCL() {}

public:
    void Handle(ServerSocketCL* socket
        , int command, const void* data, int length);

private:
    void HandleLogin(ServerSocketCL* socket, const void* data, int length);
};

#endif // _LOGINSERVER_PACKETHANDLERCL_HPP_

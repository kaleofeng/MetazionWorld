#ifndef _MASTERSERVER_PACKETHANDLERWM_HPP_
#define _MASTERSERVER_PACKETHANDLERWM_HPP_

#include <Metazion/Overall.hpp>

#include "Sockets.hpp"

class PacketHandlerWM {
    DISALLOW_COPY_AND_ASSIGN(PacketHandlerWM)

public:
    PacketHandlerWM() {}

    ~PacketHandlerWM() {}

public:
    void Handle(ServerSocketWM* socket
        , int command, const void* data, int length);

private:
    void HandleZMConnected(ServerSocketWM* socket, const void* data, int length);

    void HandleZMDisconnected(ServerSocketWM* socket, const void* data, int length);
};

#endif // _MASTERSERVER_PACKETHANDLERWM_HPP_

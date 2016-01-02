#ifndef _MASTERSERVER_PACKETHANDLERWM_HPP_
#define _MASTERSERVER_PACKETHANDLERWM_HPP_

#include "Net/Sockets.hpp"

class PacketHandlerWM {

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

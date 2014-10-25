#ifndef _LOGINSERVER_PACKETHANDLERWL_HPP_
#define _LOGINSERVER_PACKETHANDLERWL_HPP_

#include "Net/Sockets.hpp"

class PacketHandlerWL {
public:
    PacketHandlerWL() {}

    ~PacketHandlerWL() {}

public:
    void Handle(ServerSocketWL* socket
        , int command, const void* data, int length);

private:
    void HandleMLConnected(ServerSocketWL* socket
        , const void* data, int length);

    void HandleMLDisconnected(ServerSocketWL* socket
        , const void* data, int length);
};

#endif // _LOGINSERVER_PACKETHANDLERWL_HPP_

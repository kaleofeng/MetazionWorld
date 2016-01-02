#ifndef _GATEWAYSERVER_PACKETHANDLERWG_HPP_
#define _GATEWAYSERVER_PACKETHANDLERWG_HPP_

#include "Net/Sockets.hpp"

class PacketHandlerWG {

public:
    PacketHandlerWG() {}

    ~PacketHandlerWG() {}

public:
    void Handle(ServerSocketWG* socket
        , int command, const void* data, int length);

private:
    void HandleMGConnected(ServerSocketWG* socket
        , const void* data, int length);

    void HandleMGDisconnected(ServerSocketWG* socket
        , const void* data, int length);
};

#endif // _GATEWAYSERVER_PACKETHANDLERWG_HPP_

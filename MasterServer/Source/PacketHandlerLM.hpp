#ifndef _MASTERSERVER_PACKETHANDLERLM_HPP_
#define _MASTERSERVER_PACKETHANDLERLM_HPP_

#include <Metazion/Overall.hpp>

#include "Sockets.hpp"

class PacketHandlerLM {
    DISALLOW_COPY_AND_ASSIGN(PacketHandlerLM)

public:
    PacketHandlerLM() {}

    ~PacketHandlerLM() {}

public:
    void Handle(int command, const void* data, int length);

private:
    void HandleConnected(const void* data, int length);

    void HandleDisconnected(const void* data, int length);
};

#endif // _MASTERSERVER_PACKETHANDLERLM_HPP_

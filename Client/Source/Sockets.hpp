#pragma once

#include <Metazion/Net/AppClientSocket.hpp>

class ClientSocketCL
    : public NS_MZ_NET::AppClientSocket {
public:
    ClientSocketCL() {}

    ~ClientSocketCL() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};
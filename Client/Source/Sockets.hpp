#pragma once

#include <Metazion/Net/AppClientSocket.hpp>

class GameClientSocket
    : public NS_MZ_NET::AppClientSocket {
public:
    GameClientSocket() {}

    ~GameClientSocket() {}

public:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};
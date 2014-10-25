#ifndef _CLIENT_SOCKETS_HPP_
#define _CLIENT_SOCKETS_HPP_

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


class ClientSocketCG
    : public NS_MZ_NET::AppClientSocket {
public:
    ClientSocketCG() {}

    ~ClientSocketCG() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};

#endif // _CLIENT_SOCKETS_HPP_

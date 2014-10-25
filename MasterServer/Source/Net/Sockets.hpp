#ifndef _MASTERSERVER_SOCKETS_HPP_
#define _MASTERSERVER_SOCKETS_HPP_

#include <Metazion/Net/AppClientSocket.hpp>
#include <Metazion/Net/AppListenSocket.hpp>
#include <Metazion/Net/AppServerSocket.hpp>
#include <Metazion/Share/Memory/ObjectPool.hpp>

class ServerSocketWM
    : public NS_MZ_NET::AppServerSocket {
public:
    ServerSocketWM() {}

    ~ServerSocketWM() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};


class ListenSocketWM
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketWM
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

public:
    ListenSocketWM() {}

    ~ListenSocketWM() {}

protected:
    void OnWatched() override final;

    void OnUnwatched() override final;

    ServerSocketWM* CreateServerSocket() override final;

private:
    ServerSocketPool_t m_socketPool;
};


class ClientSocketML
    : public NS_MZ_NET::AppClientSocket {
public:
    ClientSocketML() {}

    ~ClientSocketML() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};


class ClientSocketMG
    : public NS_MZ_NET::AppClientSocket {
public:
    ClientSocketMG() {}

    ~ClientSocketMG() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};

#endif // _MASTERSERVER_SOCKETS_HPP_

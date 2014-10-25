#ifndef _GATEWAYSERVER_SOCKETS_HPP_
#define _GATEWAYSERVER_SOCKETS_HPP_

#include <Metazion/Net/AppListenSocket.hpp>
#include <Metazion/Net/AppServerSocket.hpp>
#include <Metazion/Share/Memory/ObjectPool.hpp>

class ServerSocketCG
    : public NS_MZ_NET::AppServerSocket {
public:
    ServerSocketCG() {}

    ~ServerSocketCG() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};


class ListenSocketCG
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketCG
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

public:
    ListenSocketCG() {}

    ~ListenSocketCG() {}

protected:
    void OnWatched() override final;

    void OnUnwatched() override final;

    ServerSocketCG* CreateServerSocket() override final;

private:
    ServerSocketPool_t m_socketPool;
};


class ServerSocketWG
    : public NS_MZ_NET::AppServerSocket {
public:
    ServerSocketWG() {}

    ~ServerSocketWG() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};


class ListenSocketWG
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketWG
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

public:
    ListenSocketWG() {}

    ~ListenSocketWG() {}

protected:
    void OnWatched() override final;

    void OnUnwatched() override final;

    ServerSocketWG* CreateServerSocket() override final;

private:
    ServerSocketPool_t m_socketPool;
};

#endif // _GATEWAYSERVER_SOCKETS_HPP_

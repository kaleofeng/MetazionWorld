#ifndef _LOGINSERVER_SOCKETS_HPP_
#define _LOGINSERVER_SOCKETS_HPP_

#include <Metazion/Net/AppListenSocket.hpp>
#include <Metazion/Net/AppServerSocket.hpp>
#include <Metazion/Share/Memory/ObjectPool.hpp>

class ServerSocketCL
    : public NS_MZ_NET::AppServerSocket {
public:
    ServerSocketCL() {}

    ~ServerSocketCL() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};


class ListenSocketCL
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketCL
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

public:
    ListenSocketCL() {}

    ~ListenSocketCL() {}

protected:
    void OnWatched() override final;

    void OnUnwatched() override final;

    ServerSocketCL* CreateServerSocket() override final;

private:
    ServerSocketPool_t m_socketPool;
};


class ServerSocketWL
    : public NS_MZ_NET::AppServerSocket {
public:
    ServerSocketWL() {}

    ~ServerSocketWL() {}

protected:
    void OnConnected() override final;

    void OnDisconnected() override final;

    void OnValidPacket(int command, const void* data, int length) override final;

    void OnInvalidPacket() override final;
};


class ListenSocketWL
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketWL
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

public:
    ListenSocketWL() {}

    ~ListenSocketWL() {}

protected:
    void OnWatched() override final;

    void OnUnwatched() override final;

    ServerSocketWL* CreateServerSocket() override final;

private:
    ServerSocketPool_t m_socketPool;
};

#endif // _LOGINSERVER_SOCKETS_HPP_

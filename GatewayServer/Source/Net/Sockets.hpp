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
    void DerivedReset() override final;

    void DerivedOnConnected() override final;

    void DerivedOnDisconnected() override final;
};


class ListenSocketCG
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketCG
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

private:
    ServerSocketPool_t m_socketPool;

public:
    ListenSocketCG() {}

    ~ListenSocketCG() {}

protected:
    void DerivedReset() override final;

    void DerivedOnWatched() override final;

    void DerivedOnUnwatched() override final;
};


class ServerSocketWG
    : public NS_MZ_NET::AppServerSocket {

public:
    ServerSocketWG() {}

    ~ServerSocketWG() {}

protected:
    void DerivedReset() override final;

    void DerivedOnConnected() override final;

    void DerivedOnDisconnected() override final;
};


class ListenSocketWG
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketWG
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

private:
    ServerSocketPool_t m_socketPool;

public:
    ListenSocketWG() {}

    ~ListenSocketWG() {}

protected:
    void DerivedReset() override final;

    void DerivedOnWatched() override final;

    void DerivedOnUnwatched() override final;
};

#endif // _GATEWAYSERVER_SOCKETS_HPP_

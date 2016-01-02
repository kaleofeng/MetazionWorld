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
    void DerivedReset() override final;

    void DerivedOnConnected() override final;

    void DerivedOnDisconnected() override final;
};


class ListenSocketWM
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketWM
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

private:
    ServerSocketPool_t m_socketPool;

public:
    ListenSocketWM() {}

    ~ListenSocketWM() {}

protected:
    void DerivedReset() override final;

    void DerivedOnWatched() override final;

    void DerivedOnUnwatched() override final;
};


class ClientSocketML
    : public NS_MZ_NET::AppClientSocket {

public:
    ClientSocketML() {}

    ~ClientSocketML() {}

protected:
    void DerivedReset() override final;

    void DerivedOnConnected() override final;

    void DerivedOnDisconnected() override final;
};


class ClientSocketMG
    : public NS_MZ_NET::AppClientSocket {

public:
    ClientSocketMG() {}

    ~ClientSocketMG() {}

protected:
    void DerivedReset() override final;

    void DerivedOnConnected() override final;

    void DerivedOnDisconnected() override final;
};

#endif // _MASTERSERVER_SOCKETS_HPP_

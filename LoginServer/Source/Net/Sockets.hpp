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
    void DerivedReset() override final;

    void DerivedOnConnected() override final;

    void DerivedOnDisconnected() override final;
};


class ListenSocketCL
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketCL
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

private:
    ServerSocketPool_t m_socketPool;

public:
    ListenSocketCL() {}

    ~ListenSocketCL() {}

protected:
    void DerivedReset() override final;

    void DerivedOnWatched() override final;

    void DerivedOnUnwatched() override final;
};


class ServerGroup;

class ServerSocketWL
    : public NS_MZ_NET::AppServerSocket {

private:
    ServerGroup* m_serverGroup;

public:
    ServerSocketWL()
        : m_serverGroup(nullptr) {}

    ~ServerSocketWL() {}

public:
    ServerGroup* GetObject();

    void BindObject(ServerGroup* object);

protected:
    void DerivedReset() override final;

    void DerivedOnConnected() override final;

    void DerivedOnDisconnected() override final;
};


class ListenSocketWL
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<ServerSocketWL
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

private:
    ServerSocketPool_t m_socketPool;

public:
    ListenSocketWL() {}

    ~ListenSocketWL() {}

protected:
    void DerivedReset() override final;

    void DerivedOnWatched() override final;

    void DerivedOnUnwatched() override final;
};

#endif // _LOGINSERVER_SOCKETS_HPP_

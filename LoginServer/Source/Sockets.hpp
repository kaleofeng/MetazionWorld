#ifndef _LOGINSERVER_SOCKETCL_HPP_
#define _LOGINSERVER_SOCKETCL_HPP_

#include <Metazion/Net/AppListenSocket.hpp>
#include <Metazion/Net/AppServerSocket.hpp>
#include <Metazion/Share/Memory/ObjectPool.hpp>

class GameServerSocket
    : public NS_MZ_NET::AppServerSocket {
public:
    GameServerSocket() {}

    ~GameServerSocket() {}

public:
    void OnConnected() override;

    void OnDisconnected() override;

    void OnValidPacket(int command, const void* data, int length) override;

    void OnInvalidPacket() override;
};


class GameListenSocket
    : public NS_MZ_NET::AppListenSocket {

    typedef NS_MZ_SHARE::ObjectPool<GameServerSocket
        , NS_MZ_SHARE::StepAllocator<512>> ServerSocketPool_t;

public:
    GameListenSocket() {}

    ~GameListenSocket() {}

public:
    void OnStart() override;

    void OnClose() override;

protected:
    GameServerSocket* CreateServerSocket() override;

private:
    ServerSocketPool_t m_socketPool;
};

#endif // _LOGINSERVER_SOCKETCL_HPP_

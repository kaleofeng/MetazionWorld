#ifndef _MASTERSERVER_SERVERAPP_HPP_
#define _MASTERSERVER_SERVERAPP_HPP_

#include <Metazion/Net/AppNetworkService.hpp>

#include "Common/Server/ServerConfigManager.hpp"

#include "Net/PacketHandlerGM.hpp"
#include "Net/PacketHandlerLM.hpp"
#include "Net/PacketHandlerWM.hpp"
#include "Net/Sockets.hpp"

class ServerApp {
public:
    ServerApp();

    ~ServerApp();

public:
    void Initialize();

    void Finalize();

    void Tick();

private:
    void ListenFromWorld();

    void ConnectToGateway();

    void ConnectToLogin();

public:
    ServerConfigManager m_serverConfigManager;

    ClientSocketMG* m_socketMG;
    ClientSocketML* m_socketML;

    PacketHandlerGM m_packetHandlerGM;
    PacketHandlerLM m_packetHandlerLM;
    PacketHandlerWM m_packetHandlerWM;

private:
    NS_MZ_NET::AppNetworkService m_networkService;
    NS_MZ_NET::AppNetworkService::SocketArray_t m_socketArray;
    NS_MZ_NET::Socket* m_sockets[1024];
};

extern ServerApp* g_serverApp;

#endif // _MASTERSERVER_SERVERAPP_HPP_

#ifndef _MASTERSERVER_SERVERAPP_HPP_
#define _MASTERSERVER_SERVERAPP_HPP_

#include <Metazion/Net/NetworkService.hpp>

#include "Common/Server/ServerConfigManager.hpp"

#include "Net/PacketHandlerGM.hpp"
#include "Net/PacketHandlerLM.hpp"
#include "Net/PacketHandlerWM.hpp"
#include "Net/Sockets.hpp"

class ServerApp {

public:
    ServerConfigManager m_serverConfigManager;

    ClientSocketMG* m_socketMG;
    ClientSocketML* m_socketML;

    PacketHandlerGM m_packetHandlerGM;
    PacketHandlerLM m_packetHandlerLM;
    PacketHandlerWM m_packetHandlerWM;

private:
    NS_MZ_NET::NetworkService m_networkService;

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
};

extern ServerApp* g_serverApp;

#endif // _MASTERSERVER_SERVERAPP_HPP_

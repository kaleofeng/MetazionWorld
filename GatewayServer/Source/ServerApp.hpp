#ifndef _GATEWAYSERVER_SERVERAPP_HPP_
#define _GATEWAYSERVER_SERVERAPP_HPP_

#include <Metazion/Net/AppNetworkService.hpp>

#include "Common/Server/ServerConfigManager.hpp"

#include "Net/PacketHandlerCG.hpp"
#include "Net/PacketHandlerWG.hpp"

class ServerApp {
public:
    ServerApp();

    ~ServerApp();

public:
    void Initialize();

    void Finalize();

    void Tick();

public:
    ServerConfigManager m_serverConfigManager;

    PacketHandlerCG m_packetHandlerCG;
    PacketHandlerWG m_packetHandlerWG;

private:
    NS_MZ_NET::AppNetworkService m_networkService;
    NS_MZ_NET::AppNetworkService::SocketArray_t m_socketArray;
    NS_MZ_NET::Socket* m_sockets[1024];
};

extern ServerApp* g_serverApp;

#endif // _GATEWAYSERVER_SERVERAPP_HPP_

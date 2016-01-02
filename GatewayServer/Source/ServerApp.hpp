#ifndef _GATEWAYSERVER_SERVERAPP_HPP_
#define _GATEWAYSERVER_SERVERAPP_HPP_

#include <Metazion/Net/NetworkService.hpp>

#include "Common/Server/ServerConfigManager.hpp"

#include "Net/PacketHandlerCG.hpp"
#include "Net/PacketHandlerWG.hpp"

class ServerApp {

public:
    ServerConfigManager m_serverConfigManager;

    PacketHandlerCG m_packetHandlerCG;
    PacketHandlerWG m_packetHandlerWG;

private:
    NS_MZ_NET::NetworkService m_networkService;

public:
    ServerApp();

    ~ServerApp();

public:
    void Initialize();

    void Finalize();

    void Tick();
};

extern ServerApp* g_serverApp;

#endif // _GATEWAYSERVER_SERVERAPP_HPP_

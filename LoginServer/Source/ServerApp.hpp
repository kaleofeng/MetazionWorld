#ifndef _LOGINSERVER_SERVERAPP_HPP_
#define _LOGINSERVER_SERVERAPP_HPP_

#include <Metazion/Net/NetworkService.hpp>

#include "Common/Server/ServerConfigManager.hpp"

#include "ServerGroupManager.hpp"
#include "Net/PacketHandlerCL.hpp"
#include "Net/PacketHandlerWL.hpp"

class ServerApp {

public:
    ServerConfigManager m_serverConfigManager;
    ServerGroupManager m_serverGroupManager;

    PacketHandlerCL m_packetHandlerCL;
    PacketHandlerWL m_packetHandlerWL;

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

#endif // _LOGINSERVER_SERVERAPP_HPP_

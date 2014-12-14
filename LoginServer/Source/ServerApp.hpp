#ifndef _LOGINSERVER_SERVERAPP_HPP_
#define _LOGINSERVER_SERVERAPP_HPP_

#include <Metazion/Net/AppNetworkService.hpp>

#include "Common/Server/ServerConfigManager.hpp"

#include "ServerGroupManager.hpp"
#include "Net/PacketHandlerCL.hpp"
#include "Net/PacketHandlerWL.hpp"

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
    ServerGroupManager m_serverGroupManager;

    PacketHandlerCL m_packetHandlerCL;
    PacketHandlerWL m_packetHandlerWL;

private:
    NS_MZ_NET::AppNetworkService m_networkService;
    NS_MZ_NET::AppNetworkService::SocketArray_t m_socketArray;
    NS_MZ_NET::Socket* m_sockets[1024];
};

extern ServerApp* g_serverApp;

#endif // _LOGINSERVER_SERVERAPP_HPP_

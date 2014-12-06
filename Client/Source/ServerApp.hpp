#ifndef _CLIENT_SERVERAPP_HPP_
#define _CLIENT_SERVERAPP_HPP_

#include <Metazion/Net/AppNetworkService.hpp>

#include "Common/Server/ServerConfigManager.hpp"

#include "ConsoleThread.hpp"
#include "Net/PacketHandlerLC.hpp"
#include "Net/Sockets.hpp"

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

    ClientSocketCL* m_socketCL;
    ClientSocketCG* m_socketCG;

    PacketHandlerLC m_packetHandlerLC;
    PacketHandlerLC m_packetHandlerGC;

private:
    NS_MZ_NET::AppNetworkService m_networkService;
    NS_MZ_NET::AppNetworkService::SocketArray_t m_socketArray;
    NS_MZ_NET::Socket* m_sockets[64];
    ConsoleThread m_consoleThread;
};

extern ServerApp* g_serverApp;

#endif // _CLIENT_SERVERAPP_HPP_

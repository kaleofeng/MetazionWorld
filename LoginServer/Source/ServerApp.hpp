#ifndef _LOGINSERVER_SERVERAPP_HPP_
#define _LOGINSERVER_SERVERAPP_HPP_

#include <Metazion/Net/AppSocketServer.hpp>

#include "Common/Server/ServerManager.hpp"

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
    ServerManager m_serverManager;

    PacketHandlerCL m_packetHandlerCL;
    PacketHandlerWL m_packetHandlerWL;

private:
    NS_MZ_NET::AppSocketServer m_socketServer;
    NS_MZ_NET::AppSocketServer::SocketFilter m_socketFilter;
    NS_MZ_NET::AppSocketServer::SocketArray_t m_socketArray;
    NS_MZ_NET::Socket* m_sockets[1024];
};

extern ServerApp* g_serverApp;

#endif // _LOGINSERVER_SERVERAPP_HPP_

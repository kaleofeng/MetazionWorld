#ifndef _MASTERSERVER_SERVERAPP_HPP_
#define _MASTERSERVER_SERVERAPP_HPP_

#include <Metazion/Net/AppSocketServer.hpp>

#include "Common/Server/ServerManager.hpp"

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

public:
    ServerManager m_serverManager;

    ClientSocketMG* m_socketMG;
    ClientSocketML* m_socketML;

    PacketHandlerGM m_packetHandlerGM;
    PacketHandlerLM m_packetHandlerLM;
    PacketHandlerWM m_packetHandlerWM;

private:
    NS_MZ_NET::AppSocketServer m_socketServer;
    NS_MZ_NET::AppSocketServer::SocketFilter m_socketFilter;
    NS_MZ_NET::AppSocketServer::SocketArray_t m_socketArray;
    NS_MZ_NET::Socket* m_sockets[1024];
};

extern ServerApp* g_serverApp;

#endif // _MASTERSERVER_SERVERAPP_HPP_

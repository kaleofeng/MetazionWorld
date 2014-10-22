#ifndef _CLIENT_SERVERAPP_HPP_
#define _CLIENT_SERVERAPP_HPP_

#include <Metazion/Share/Pattern/Singleton.hpp>
#include <Metazion/Net/AppSocketServer.hpp>

#include "ConsoleThread.hpp"
#include "PacketHandlerLC.hpp"
#include "Sockets.hpp"

class ServerApp : public NS_MZ_SHARE::Singleton<ServerApp> {
public:
    ServerApp();

    ~ServerApp();

public:
    void Initialize();

    void Finalize();

    void Tick();

public:
    ClientSocketCL* m_socketCL;
    ClientSocketCG* m_socketCG;

    PacketHandlerLC m_packetHandlerLC;
    PacketHandlerLC m_packetHandlerGC;

private:
    NS_MZ_NET::AppSocketServer m_socketServer;
    NS_MZ_NET::AppSocketServer::SocketFilter m_socketFilter;
    NS_MZ_NET::AppSocketServer::SocketArray_t m_socketArray;
    NS_MZ_NET::Socket* m_sockets[64];
    ConsoleThread m_consoleThread;
};

extern ServerApp* g_serverApp;

#endif // _CLIENT_SERVERAPP_HPP_

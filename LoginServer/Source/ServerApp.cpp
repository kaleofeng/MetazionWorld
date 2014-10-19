#include "ServerApp.hpp"

#include <Metazion/Net/Network.hpp>

#include "SocketCL.hpp"

USING_NAMESPACE_MZ_NET

ServerApp* g_serverApp = nullptr;

ServerApp::ServerApp() {}

ServerApp::~ServerApp() {}

void ServerApp::Initialize() {
    Network::Startup();

    m_socketServer.Initialize(10240, 8);

    ListenSocketCL* listenSocket = new ListenSocketCL();
    listenSocket->Retain();
    listenSocket->SetLocalHost("0.0.0.0", 22001);
    listenSocket->Listen(100);
    m_socketServer.Attach(listenSocket);

    memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 10240, 0);

    ::printf("Server startd.\n");
}

void ServerApp::Finalize() {
    m_socketArray.Detach();

    m_socketServer.Finalize();

    Network::Cleanup();

    ::printf("Server stoped.\n");
}

void ServerApp::Tick() {
    const int size = m_socketServer.LockSockets(m_socketFilter, m_socketArray);
    for (int i = 0; i < size; ++i) {
        Socket* socket = m_socketArray[i];
        ASSERT_TRUE(!NS_MZ::IsNull(socket));
        socket->Dispatch();
    }
    m_socketServer.UnlockSockets(m_socketArray);
}
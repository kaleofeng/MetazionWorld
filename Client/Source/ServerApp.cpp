#include "ServerApp.hpp"

#include <Metazion/Net/Network.hpp>

USING_NAMESPACE_MZ_NET

ServerApp* g_serverApp = nullptr;

ServerApp::ServerApp() {}

ServerApp::~ServerApp() {}

void ServerApp::Initialize() {
    Network::Startup();

    m_socketServer.Initialize(64, 2);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 64, 0);

    m_loginSocket = new ClientSocketCL();
    m_loginSocket->Retain();
    m_loginSocket->SetRemoteHost("192.168.3.75", 22001);
    m_loginSocket->SetReconnectInterval(5000);
    m_loginSocket->Connect();
    m_socketServer.Attach(m_loginSocket);

    m_consoleThread.Initialize();
    m_consoleThread.Run();
}

void ServerApp::Finalize() {
    m_consoleThread.Finalize();

    m_socketArray.Detach();

    m_socketServer.Finalize();

    Network::Cleanup();
}

void ServerApp::Tick() {
    const auto size = m_socketServer.LockSockets(m_socketFilter, m_socketArray);
    for (auto i = 0; i < size; ++i) {
        auto socket = m_socketArray[i];
        ASSERT_TRUE(!NS_MZ::IsNull(socket));
        socket->Dispatch();
    }
    m_socketServer.UnlockSockets(m_socketArray);
}
#include "ServerApp.hpp"

#include <Metazion/Net/Network.hpp>

USING_NAMESPACE_MZ_NET

ServerApp* g_serverApp = nullptr;

ServerApp::ServerApp()
    : m_socketCL(nullptr)
    , m_socketCG(nullptr) {}

ServerApp::~ServerApp() {}

void ServerApp::Initialize() {
    ::printf("Client start.\n");

    Network::Startup();

    m_socketServer.Initialize(64, 2);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 64, 0);

    m_socketCL = new ClientSocketCL();
    m_socketCL->Retain();
    m_socketCL->SetRemoteHost("192.168.3.75", 22001);
    m_socketCL->SetReconnectInterval(10000);
    m_socketCL->Connect();
    m_socketServer.Attach(m_socketCL);

    m_socketCG = new ClientSocketCG();
    m_socketCG->Retain();
    m_socketCG->SetRemoteHost("192.168.3.75", 23001);
    m_socketCG->SetReconnectInterval(10000);
    m_socketCG->Connect();
    m_socketServer.Attach(m_socketCG);

    m_consoleThread.Initialize();
    m_consoleThread.Run();
}

void ServerApp::Finalize() {
    m_consoleThread.Finalize();

    m_socketArray.Detach();

    m_socketServer.Finalize();

    Network::Cleanup();

    ::printf("Client stop.\n");
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
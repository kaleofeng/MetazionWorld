#include "ServerApp.hpp"

#include <Metazion/Net/Network.hpp>

#include "Sockets.hpp"

USING_NAMESPACE_MZ_NET

ServerApp* g_serverApp = nullptr;

ServerApp::ServerApp() {}

ServerApp::~ServerApp() {}

void ServerApp::Initialize() {
    ::printf("LoginServer start.\n");

    Network::Startup();

    m_socketServer.Initialize(1024, 8);

    ListenSocketCL* listenSocketCL = new ListenSocketCL();
    listenSocketCL->Retain();
    listenSocketCL->SetLocalHost("0.0.0.0", 22001);
    listenSocketCL->Listen(100);
    m_socketServer.Attach(listenSocketCL);

    ListenSocketWL* listenSocketWL = new ListenSocketWL();
    listenSocketWL->Retain();
    listenSocketWL->SetLocalHost("0.0.0.0", 22002);
    listenSocketWL->Listen(100);
    m_socketServer.Attach(listenSocketWL);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 1024, 0);
}

void ServerApp::Finalize() {
    m_socketArray.Detach();

    m_socketServer.Finalize();

    Network::Cleanup();

    ::printf("LoginServer stop.\n");
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
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

    m_serverConfigManager.Initialize();

    m_networkService.Initialize(64, 2);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 64, 0);

    const auto& loginConfig = m_serverConfigManager.GetLoginConfig();
    const auto& gatewayConfig = m_serverConfigManager.GetGatewayConfig(1);
    ASSERT_TRUE(!NS_MZ::IsNull(gatewayConfig));

    Host hostCL;
    hostCL.FromAddress(loginConfig.m_publicAddress);

    m_socketCL = new ClientSocketCL();
    m_socketCL->Retain();
    m_socketCL->SetRemoteHost(hostCL);
    m_socketCL->SetReconnectInterval(10000);
    m_socketCL->Connect();
    m_networkService.Attach(m_socketCL);

    Host hostCG;
    hostCG.FromAddress(gatewayConfig->m_publicAddress);

    m_socketCG = new ClientSocketCG();
    m_socketCG->Retain();
    m_socketCG->SetRemoteHost(hostCG);
    m_socketCG->SetReconnectInterval(10000);
    m_socketCG->Connect();
    m_networkService.Attach(m_socketCG);

    m_consoleThread.Initialize();
    m_consoleThread.Run();
}

void ServerApp::Finalize() {
    m_consoleThread.Finalize();

    m_socketArray.Detach();

    m_networkService.Finalize();

    m_serverConfigManager.Finalize();

    Network::Cleanup();

    ::printf("Client stop.\n");
}

void ServerApp::Tick() {
    const auto size = m_networkService.LockSockets([](Socket* socket) {
            return socket->GetType() != SOCKET_TCP_LISTEN;
        }, m_socketArray);

    for (auto i = 0; i < size; ++i) {
        auto socket = m_socketArray[i];
        ASSERT_TRUE(!NS_MZ::IsNull(socket));
        socket->Dispatch();
    }

    m_networkService.UnlockSockets(m_socketArray);
}
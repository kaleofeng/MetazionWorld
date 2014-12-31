#include "ServerApp.hpp"

#include <Metazion/Net/Network.hpp>

#include "Net/Sockets.hpp"

USING_NAMESPACE_MZ_NET

ServerApp* g_serverApp = nullptr;

ServerApp::ServerApp() {}

ServerApp::~ServerApp() {}

void ServerApp::Initialize() {
    ::printf("GatewayServer start.\n");

    Network::Startup();

    m_serverConfigManager.Initialize();

    m_networkService.Initialize(1024, 8);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 1024, 0);

    const auto& gatewayConfig = m_serverConfigManager.GetGatewayConfig();

    Host hostCG;
    hostCG.FromAddress(gatewayConfig.m_publicAddress);

    ListenSocketCG* listenSocketCG = new ListenSocketCG();
    listenSocketCG->Retain();
    listenSocketCG->SetLocalHost(hostCG);
    listenSocketCG->Listen(100);
    m_networkService.Attach(listenSocketCG);

    Host hostWG;
    hostWG.FromAddress(gatewayConfig.m_privateAddress);

    ListenSocketWG* listenSocketWG = new ListenSocketWG();
    listenSocketWG->Retain();
    listenSocketWG->SetLocalHost(hostWG);
    listenSocketWG->Listen(100);
    m_networkService.Attach(listenSocketWG);
}

void ServerApp::Finalize() {
    m_socketArray.Detach();

    m_networkService.Finalize();

    m_serverConfigManager.Finalize();

    Network::Cleanup();

    ::printf("GatewayServer stop.\n");
}

void ServerApp::Tick() {
    const auto size = m_networkService.LockSockets([](Socket* socket) {
            return socket->GetType() != SOCKET_TCP_LISTEN;
        }, m_socketArray);

    for (auto i = 0; i < size; ++i) {
        auto socket = m_socketArray[i];
        MZ_ASSERT_TRUE(!NS_MZ::IsNull(socket));
        socket->Dispatch();
    }

    m_networkService.UnlockSockets(m_socketArray);
}
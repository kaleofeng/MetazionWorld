#include "ServerApp.hpp"

#include <Metazion/Net/Network.hpp>

USING_NAMESPACE_MZ_NET

ServerApp* g_serverApp = nullptr;

ServerApp::ServerApp()
    : m_socketMG(nullptr)
    , m_socketML(nullptr) {}

ServerApp::~ServerApp() {}

void ServerApp::Initialize() {
    ::printf("MasterServer start.\n");

    Network::Startup();

    m_serverConfigManager.Initialize();

    m_networkService.Initialize(1024, 8);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 1024, 0);
    
    const auto& loginConfig = m_serverConfigManager.GetLoginConfig();
    const auto& masterConfig = m_serverConfigManager.GetMasterConfig();
    const auto& gatewayConfig = m_serverConfigManager.GetGatewayConfig(1);
    ASSERT_TRUE(!NS_MZ::IsNull(gatewayConfig));

    NS_MZ_NET::Host hostWM;
    hostWM.FromAddress(masterConfig.m_privateAddress);

    auto listenSocket = new ListenSocketWM();
    listenSocket->Retain();
    listenSocket->SetLocalHost(hostWM);
    listenSocket->Listen(100);
    m_networkService.Attach(listenSocket);

    NS_MZ_NET::Host hostMG;
    hostMG.FromAddress(gatewayConfig->m_privateAddress);

    m_socketMG = new ClientSocketMG();
    m_socketMG->Retain();
    m_socketMG->SetRemoteHost(hostMG);
    m_socketMG->SetReconnectInterval(10000);
    m_socketMG->Connect();
    m_networkService.Attach(m_socketMG);

    NS_MZ_NET::Host hostML;
    hostML.FromAddress(loginConfig.m_privateAddress);

    m_socketML = new ClientSocketML();
    m_socketML->Retain();
    m_socketML->SetRemoteHost(hostML);
    m_socketML->SetReconnectInterval(10000);
    m_socketML->Connect();
    m_networkService.Attach(m_socketML);
}

void ServerApp::Finalize() {
    m_socketArray.Detach();

    m_networkService.Finalize();

    m_serverConfigManager.Finalize();

    Network::Cleanup();

    ::printf("MasterServer stop.\n");
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
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

    ListenFromWorld();
    ConnectToGateway();
    ConnectToLogin();
}

void ServerApp::Finalize() {
    m_networkService.Finalize();

    m_serverConfigManager.Finalize();

    Network::Cleanup();

    ::printf("MasterServer stop.\n");
}

void ServerApp::Tick() {
    m_networkService.Tick();
}

void ServerApp::ListenFromWorld() {
    const auto& masterConfig = m_serverConfigManager.GetMasterConfig();

    NS_MZ_NET::Host hostWM;
    hostWM.FromAddress(masterConfig.m_privateAddress);

    auto listenSocket = new ListenSocketWM();
    listenSocket->Retain();
    listenSocket->SetLocalHost(hostWM);
    listenSocket->Listen(100);
    m_networkService.Manage(listenSocket);
}

void ServerApp::ConnectToGateway() {
    const auto& gatewayConfig = m_serverConfigManager.GetGatewayConfig();

    NS_MZ_NET::Host hostMG;
    hostMG.FromAddress(gatewayConfig.m_privateAddress);

    m_socketMG = new ClientSocketMG();
    m_socketMG->Retain();
    m_socketMG->m_connecter.SetRemoteHost(hostMG);
    m_socketMG->m_connecter.SetReconnectInterval(10000);
    m_socketMG->m_connecter.Connect();
    m_networkService.Manage(m_socketMG);
}

void ServerApp::ConnectToLogin() {
    const auto& loginConfig = m_serverConfigManager.GetLoginConfig();

    NS_MZ_NET::Host hostML;
    hostML.FromAddress(loginConfig.m_privateAddress);

    m_socketML = new ClientSocketML();
    m_socketML->Retain();
    m_socketML->m_connecter.SetRemoteHost(hostML);
    m_socketML->m_connecter.SetReconnectInterval(10000);
    m_socketML->m_connecter.Connect();
    m_networkService.Manage(m_socketML);
}
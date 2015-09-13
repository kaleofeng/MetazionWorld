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

    const auto& gatewayConfig = m_serverConfigManager.GetGatewayConfig();

    Host hostCG;
    hostCG.FromAddress(gatewayConfig.m_publicAddress);

    ListenSocketCG* listenSocketCG = new ListenSocketCG();
    listenSocketCG->Retain();
    listenSocketCG->SetLocalHost(hostCG);
    listenSocketCG->Listen(100);
    m_networkService.Manage(listenSocketCG);

    Host hostWG;
    hostWG.FromAddress(gatewayConfig.m_privateAddress);

    ListenSocketWG* listenSocketWG = new ListenSocketWG();
    listenSocketWG->Retain();
    listenSocketWG->SetLocalHost(hostWG);
    listenSocketWG->Listen(100);
    m_networkService.Manage(listenSocketWG);
}

void ServerApp::Finalize() {
    m_networkService.Finalize();

    m_serverConfigManager.Finalize();

    Network::Cleanup();

    ::printf("GatewayServer stop.\n");
}

void ServerApp::Tick() {
    m_networkService.Tick();
}
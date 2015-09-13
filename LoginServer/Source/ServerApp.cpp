#include "ServerApp.hpp"

#include <Metazion/Net/Network.hpp>

#include "Net/Sockets.hpp"

USING_NAMESPACE_MZ_NET

ServerApp* g_serverApp = nullptr;

ServerApp::ServerApp() {}

ServerApp::~ServerApp() {}

void ServerApp::Initialize() {
    ::printf("LoginServer start.\n");

    Network::Startup();

    m_serverConfigManager.Initialize();
    m_serverGroupManager.Initialize();

    m_networkService.Initialize(1024, 8);
    
    const auto& loginConfig = m_serverConfigManager.GetLoginConfig();

    Host hostCl;
    hostCl.FromAddress(loginConfig.m_publicAddress);

    auto listenSocketCL = new ListenSocketCL();
    listenSocketCL->Retain();
    listenSocketCL->SetLocalHost(hostCl);
    listenSocketCL->Listen(100);
    m_networkService.Manage(listenSocketCL);

    Host hostWL;
    hostWL.FromAddress(loginConfig.m_privateAddress);

    auto listenSocketWL = new ListenSocketWL();
    listenSocketWL->Retain();
    listenSocketWL->SetLocalHost(hostWL);
    listenSocketWL->Listen(100);
    m_networkService.Manage(listenSocketWL);
}

void ServerApp::Finalize() {
    m_networkService.Finalize();

    m_serverGroupManager.Finalize();
    m_serverConfigManager.Finalize();

    Network::Cleanup();

    ::printf("LoginServer stop.\n");
}

void ServerApp::Tick() {
    m_networkService.Tick();
}
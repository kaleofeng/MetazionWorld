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

    m_networkService.Initialize(1024, 8);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 1024, 0);
    
    const auto& loginConfig = m_serverConfigManager.GetLoginConfig();

    Host hostCl;
    hostCl.FromAddress(loginConfig.m_publicAddress);

    auto listenSocketCL = new ListenSocketCL();
    listenSocketCL->Retain();
    listenSocketCL->SetLocalHost(hostCl);
    listenSocketCL->Listen(100);
    m_networkService.Attach(listenSocketCL);

    Host hostWL;
    hostWL.FromAddress(loginConfig.m_privateAddress);

    auto listenSocketWL = new ListenSocketWL();
    listenSocketWL->Retain();
    listenSocketWL->SetLocalHost(hostWL);
    listenSocketWL->Listen(100);
    m_networkService.Attach(listenSocketWL);
}

void ServerApp::Finalize() {
    m_socketArray.Detach();

    m_networkService.Finalize();

    m_serverConfigManager.Finalize();

    Network::Cleanup();

    ::printf("LoginServer stop.\n");
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
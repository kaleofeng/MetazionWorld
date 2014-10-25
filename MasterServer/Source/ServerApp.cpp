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

    m_serverManager.Initialize();

    m_socketServer.Initialize(1024, 8);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 1024, 0);
    
    const auto loginInfo = m_serverManager.GetLoginInfo();
    const auto masterInfo = m_serverManager.GetMasterInfo();
    const auto gatewayInfo = m_serverManager.GetGatewayInfo(1);
    ASSERT_TRUE(!NS_MZ::IsNull(gatewayInfo));

    NS_MZ_NET::Host hostWM;
    hostWM.FromAddress(masterInfo.m_privateAddress);

    auto listenSocket = new ListenSocketWM();
    listenSocket->Retain();
    listenSocket->SetLocalHost(hostWM);
    listenSocket->Listen(100);
    m_socketServer.Attach(listenSocket);

    NS_MZ_NET::Host hostMG;
    hostMG.FromAddress(gatewayInfo->m_privateAddress);

    m_socketMG = new ClientSocketMG();
    m_socketMG->Retain();
    m_socketMG->SetRemoteHost(hostMG);
    m_socketMG->SetReconnectInterval(10000);
    m_socketMG->Connect();
    m_socketServer.Attach(m_socketMG);

    NS_MZ_NET::Host hostML;
    hostML.FromAddress(loginInfo.m_privateAddress);

    m_socketML = new ClientSocketML();
    m_socketML->Retain();
    m_socketML->SetRemoteHost(hostML);
    m_socketML->SetReconnectInterval(10000);
    m_socketML->Connect();
    m_socketServer.Attach(m_socketML);
}

void ServerApp::Finalize() {
    m_socketArray.Detach();

    m_socketServer.Finalize();

    m_serverManager.Finalize();

    Network::Cleanup();

    ::printf("MasterServer stop.\n");
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
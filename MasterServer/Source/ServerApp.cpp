#include "ServerApp.hpp"

#include <Metazion/Net/Network.hpp>

#include "Sockets.hpp"

USING_NAMESPACE_MZ_NET

ServerApp* g_serverApp = nullptr;

ServerApp::ServerApp()
    : m_socketMG(nullptr)
    , m_socketML(nullptr) {}

ServerApp::~ServerApp() {}

void ServerApp::Initialize() {
    ::printf("MasterServer start.\n");

    Network::Startup();

    m_socketServer.Initialize(10240, 8);

    ListenSocketWM* listenSocket = new ListenSocketWM();
    listenSocket->Retain();
    listenSocket->SetLocalHost("0.0.0.0", 24001);
    listenSocket->Listen(100);
    m_socketServer.Attach(listenSocket);

    m_socketMG = new ClientSocketMG();
    m_socketMG->Retain();
    m_socketMG->SetRemoteHost("192.168.1.101", 23001);
    m_socketMG->SetReconnectInterval(10000);
    m_socketMG->Connect();
    m_socketServer.Attach(m_socketMG);

    m_socketML = new ClientSocketML();
    m_socketML->Retain();
    m_socketML->SetRemoteHost("192.168.1.101", 22002);
    m_socketML->SetReconnectInterval(10000);
    m_socketML->Connect();
    m_socketServer.Attach(m_socketML);

    ::memset(m_sockets, 0, sizeof(m_sockets));
    m_socketArray.Attach(m_sockets, 10240, 0);
}

void ServerApp::Finalize() {
    m_socketArray.Detach();

    m_socketServer.Finalize();

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
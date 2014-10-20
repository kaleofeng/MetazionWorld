#include "Sockets.hpp"

#include "ServerApp.hpp"

void GameServerSocket::OnConnected() {
    AppServerSocket::OnConnected();
}

void GameServerSocket::OnDisconnected() {
    AppServerSocket::OnDisconnected();
}

void GameServerSocket::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerCL.Handle(this, command, data, length);
}

void GameServerSocket::OnInvalidPacket() {
    Close();
}

void GameListenSocket::OnStart() {
    AppListenSocket::OnStart();
}

void GameListenSocket::OnClose() {
    AppListenSocket::OnClose();
}

GameServerSocket* GameListenSocket::CreateServerSocket() {
    auto socket = m_socketPool.Obtain();
    socket->Reset();
    socket->Retain();
    return socket;
}
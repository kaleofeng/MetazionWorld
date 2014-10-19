#include "Sockets.hpp"

#include "ServerApp.hpp"

void GameClientSocket::OnConnected() {
    AppClientSocket::OnConnected();
}

void GameClientSocket::OnDisconnected() {
    AppClientSocket::OnDisconnected();
}

void GameClientSocket::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerLC.Handle(command, data, length);
}

void GameClientSocket::OnInvalidPacket() {
    Close();
}
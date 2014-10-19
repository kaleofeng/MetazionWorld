#include "SocketCL.hpp"

#include "ServerApp.hpp"

void ServerSocketCL::OnConnected() {
    AppServerSocket::OnConnected();
}

void ServerSocketCL::OnDisconnected() {
    AppServerSocket::OnDisconnected();
}

void ServerSocketCL::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerCL.Handle(this, command, data, length);
}

void ServerSocketCL::OnInvalidPacket() {
    Close();
}

void ListenSocketCL::OnStart() {
    AppListenSocket::OnStart();
}

void ListenSocketCL::OnClose() {
    AppListenSocket::OnClose();
}

ServerSocketCL* ListenSocketCL::CreateServerSocket() {
    auto socket = m_socketPool.Obtain();
    socket->Reset();
    socket->Retain();
    return socket;
}
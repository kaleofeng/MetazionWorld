#include "Sockets.hpp"

#include "ServerApp.hpp"

void ServerSocketCL::OnConnected() {
    ::printf("ServerSocket from Client Connected\n");
}

void ServerSocketCL::OnDisconnected() {
    ::printf("ServerSocket from Client Disconnected\n");
}

void ServerSocketCL::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerCL.Handle(this, command, data, length);
}

void ServerSocketCL::OnInvalidPacket() {
    Close();
}


void ListenSocketCL::OnWatched() {
    ::printf("ListenSocket for Client Watched\n");
}

void ListenSocketCL::OnUnwatched() {
    ::printf("ListenSocket for Client Unwatched\n");
}

ServerSocketCL* ListenSocketCL::CreateServerSocket() {
    auto socket = m_socketPool.Obtain();
    socket->Reset();
    socket->Retain();
    return socket;
}
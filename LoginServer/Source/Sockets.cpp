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


void ServerSocketWL::OnConnected() {
    ::printf("ServerSocket from World Connected\n");
}

void ServerSocketWL::OnDisconnected() {
    ::printf("ServerSocket from World Disconnected\n");
}

void ServerSocketWL::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerWL.Handle(this, command, data, length);
}

void ServerSocketWL::OnInvalidPacket() {
    Close();
}


void ListenSocketWL::OnWatched() {
    ::printf("ListenSocket for World Watched\n");
}

void ListenSocketWL::OnUnwatched() {
    ::printf("ListenSocket for World Unwatched\n");
}

ServerSocketWL* ListenSocketWL::CreateServerSocket() {
    auto socket = m_socketPool.Obtain();
    socket->Reset();
    socket->Retain();
    return socket;
}
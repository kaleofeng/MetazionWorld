#include "Sockets.hpp"

#include "ServerApp.hpp"

void ServerSocketCG::OnConnected() {
    ::printf("ServerSocket from Client Connected\n");
}

void ServerSocketCG::OnDisconnected() {
    ::printf("ServerSocket from Client Disconnected\n");
}

void ServerSocketCG::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerCG.Handle(this, command, data, length);
}

void ServerSocketCG::OnInvalidPacket() {
    Close();
}


void ListenSocketCG::OnWatched() {
    ::printf("ListenSocket for Client Watched\n");
}

void ListenSocketCG::OnUnwatched() {
    ::printf("ListenSocket for Client Unwatched\n");
}

ServerSocketCG* ListenSocketCG::CreateServerSocket() {
    auto socket = m_socketPool.Obtain();
    socket->Reset();
    socket->Retain();
    return socket;
}


void ServerSocketWG::OnConnected() {
    ::printf("ServerSocket from World Connected\n");
}

void ServerSocketWG::OnDisconnected() {
    ::printf("ServerSocket from World Disconnected\n");
}

void ServerSocketWG::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerWG.Handle(this, command, data, length);
}

void ServerSocketWG::OnInvalidPacket() {
    Close();
}


void ListenSocketWG::OnWatched() {
    ::printf("ListenSocket for World Watched\n");
}

void ListenSocketWG::OnUnwatched() {
    ::printf("ListenSocket for World Unwatched\n");
}

ServerSocketWG* ListenSocketWG::CreateServerSocket() {
    auto socket = m_socketPool.Obtain();
    socket->Reset();
    socket->Retain();
    return socket;
}
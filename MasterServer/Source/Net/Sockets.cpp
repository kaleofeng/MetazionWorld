#include "Sockets.hpp"

#include "Common/Packet/PacketLM.hpp"
#include "Common/Packet/PacketGM.hpp"

#include "ServerApp.hpp"

void ServerSocketWM::OnConnected() {
    ::printf("ServerSocket from World Connected\n");
}

void ServerSocketWM::OnDisconnected() {
    ::printf("ServerSocket from World Disconnected\n");
}

void ServerSocketWM::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerWM.Handle(this, command, data, length);
}

void ServerSocketWM::OnInvalidPacket() {
    Close();
}


void ListenSocketWM::OnWatched() {
    ::printf("ListenSocket for World Watched\n");
}

void ListenSocketWM::OnUnwatched() {
    ::printf("ListenSocket for World Unwatched\n");
}

ServerSocketWM* ListenSocketWM::CreateServerSocket() {
    auto socket = m_socketPool.Obtain();
    socket->Reset();
    socket->Retain();
    return socket;
}


void ClientSocketML::OnConnected() {
    ::printf("ClientSocket to Login Connected\n");
    PostData(COMMAND_LM_CONNECTED, nullptr, 0);
}

void ClientSocketML::OnDisconnected() {
    ::printf("ClientSocket to Login Disconnected\n");
    PostData(COMMAND_LM_DISCONNECTED, nullptr, 0);
}

void ClientSocketML::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerLM.Handle(command, data, length);
}

void ClientSocketML::OnInvalidPacket() {
    Close();
}


void ClientSocketMG::OnConnected() {
    ::printf("ClientSocket to Gateway Connected\n");
    PostData(COMMAND_GM_CONNECTED, nullptr, 0);
}

void ClientSocketMG::OnDisconnected() {
    ::printf("ClientSocket to Gateway Disconnected\n");
    PostData(COMMAND_GM_DISCONNECTED, nullptr, 0);
}

void ClientSocketMG::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerGM.Handle(command, data, length);
}

void ClientSocketMG::OnInvalidPacket() {
    Close();
}
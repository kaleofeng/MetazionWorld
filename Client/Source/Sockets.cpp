#include "Sockets.hpp"

#include "ServerApp.hpp"

void ClientSocketCL::OnConnected() {
    ::printf("ClientSocket to Login Connected\n");
}

void ClientSocketCL::OnDisconnected() {
    ::printf("ClientSocket to Login Disconnected\n");
}

void ClientSocketCL::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerLC.Handle(command, data, length);
}

void ClientSocketCL::OnInvalidPacket() {
    Close();
}
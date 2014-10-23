#include "Sockets.hpp"

#include "ServerApp.hpp"

#include "Common/Packet/PacketLC.hpp"
#include "Common/Packet/PacketGC.hpp"

void ClientSocketCL::OnConnected() {
    ::printf("ClientSocket to Login Connected\n");
    PostData(COMMAND_LC_CONNECTED, nullptr, 0);
}

void ClientSocketCL::OnDisconnected() {
    ::printf("ClientSocket to Login Disconnected\n");
    PostData(COMMAND_LC_DISCONNECTED, nullptr, 0);
}

void ClientSocketCL::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerLC.Handle(command, data, length);
}

void ClientSocketCL::OnInvalidPacket() {
    Close();
}


void ClientSocketCG::OnConnected() {
    ::printf("ClientSocket to Gateway Connected\n");
    PostData(COMMAND_GC_CONNECTED, nullptr, 0);
}

void ClientSocketCG::OnDisconnected() {
    ::printf("ClientSocket to Gateway Disconnected\n");
    PostData(COMMAND_GC_DISCONNECTED, nullptr, 0);
}

void ClientSocketCG::OnValidPacket(int command, const void* data, int length) {
    g_serverApp->m_packetHandlerGC.Handle(command, data, length);
}

void ClientSocketCG::OnInvalidPacket() {
    Close();
}
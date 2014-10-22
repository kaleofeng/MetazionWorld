#include "PacketHandlerLC.hpp"

#include "Common/Packet/PacketLC.hpp"

void PacketHandlerLC::Handle(int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_LC_CONNECTED:
        HandleConnected(data, length);
        break;
    case COMMAND_LC_DISCONNECTED:
        HandleDisconnected(data, length);
        break;
    case COMMAND_LC_PLAYERLOGIN:
        HandlePlayerLogin(data, length);
        break;
    case COMMAND_LC_SERVERLIST:
        HandleServerList(data, length);
        break;
    default: break;
    }
}

void PacketHandlerLC::HandleConnected(const void* data, int length) {

}

void PacketHandlerLC::HandleDisconnected(const void* data, int length) {

}

void PacketHandlerLC::HandlePlayerLogin(const void* data, int length) {
    const auto req = static_cast<const PlayerLoginLC*>(data);
    ::printf("Login: sucess[%d]\n", req->m_success);
}

void PacketHandlerLC::HandleServerList(const void* data, int length) {
    const auto req = static_cast<const ServerListLC*>(data);
}
#include "PacketHandlerLC.hpp"

#include <Metazion/Share/Misc/MemoryInputStream.hpp>

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
    NS_MZ_SHARE::MemoryInputStream inputStream;
    inputStream.Attach(data, length);

    int8_t gatewaySize = 0;
    inputStream.ReadInt8(gatewaySize);
    ::printf("Gateway Size: %d\n", gatewaySize);

    for (auto index = 0; index < gatewaySize; ++index) {
        int8_t gatewayId = 0;
        inputStream.ReadInt8(gatewayId);
        ::printf("Gateway Id: %d\n", gatewayId);

        NS_MZ_NET::Address gatewayAddress;
        inputStream.ReadUint32(gatewayAddress.m_ip);
        inputStream.ReadUint16(gatewayAddress.m_port);
        ::printf("Gateway Address: ip[%u] port[%d]\n", gatewayAddress.m_ip, gatewayAddress.m_port);
    }
}
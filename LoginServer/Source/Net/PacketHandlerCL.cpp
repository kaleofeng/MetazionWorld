#include "PacketHandlerCL.hpp"

#include <Metazion/Share/Misc/MemoryOutputStream.hpp>

#include "Common/Packet/PacketCL.hpp"
#include "Common/Packet/PacketLC.hpp"

#include "ServerApp.hpp"

void PacketHandlerCL::Handle(ServerSocketCL* socket
    , int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_CL_CONNECTED:
        HandleConnected(socket, data, length);
        break;
    case COMMAND_CL_DISCONNECTED:
        HandleDisconnected(socket, data, length);
        break;
    case COMMAND_CL_PLAYERLOGIN:
        HandlePlayerLogin(socket, data, length);
        break;
    default: break;
    }
}
void PacketHandlerCL::HandleConnected(ServerSocketCL* socket
    , const void* data, int length) {

}

void PacketHandlerCL::HandleDisconnected(ServerSocketCL* socket
    , const void* data, int length) {
    
}

void PacketHandlerCL::HandlePlayerLogin(ServerSocketCL* socket
    , const void* data, int length) {
    const auto req = static_cast<const PlayerLoginCL*>(data);
    ::printf("Login: username[%s] password[%s]\n", req->m_username, req->m_password);

    PlayerLoginLC rsp;
    rsp.m_success = true;
    socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));

    NS_MZ_SHARE::MemoryOutputStream<> outputStream;
    const auto gatewaySize = g_serverApp->m_serverConfigManager.GetGatewayConfigSize();
    outputStream.WriteInt8(gatewaySize);
    const auto& gatewayMap = g_serverApp->m_serverConfigManager.GetAllGatewayConfig();
    for (auto gateway : gatewayMap) {
        const auto id = gateway.second.m_id;
        const auto publicAddress = gateway.second.m_publicAddress;
        outputStream.WriteInt8(id);
        outputStream.WriteUint32(publicAddress.m_ip);
        outputStream.WriteUint16(publicAddress.m_port);
    }
    socket->SendData(COMMAND_LC_SERVERLIST, outputStream.GetBuffer(), outputStream.GetLength());
}
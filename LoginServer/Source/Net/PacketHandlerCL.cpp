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

    const auto success = _stricmp(req->m_username, "meta") == 0;
    if (!success) {
        PlayerLoginLC rsp;
        rsp.m_success = false;
        socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));
        return;
    }

    PlayerLoginLC rsp;
    rsp.m_success = true;
    socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));

    NS_MZ_SHARE::MemoryOutputStream<> outputStream;
    const auto serverGroupSize = g_serverApp->m_serverGroupManager.GetServerGroupSize();
    outputStream.WriteInt8(serverGroupSize);
    const auto& serverGroupMap = g_serverApp->m_serverGroupManager.GetAllServerGroup();
    for (auto pair : serverGroupMap) {
        const auto& serverGroup = pair.second;
        const auto id = serverGroup.GetId();
        const auto name = serverGroup.GetName();
        const auto status = serverGroup.GetStatus();
        const auto address = serverGroup.GetARandomAddress();

        const auto ip = NS_MZ::IsNull(address) ? 0 : address->m_ip;
        const auto port = NS_MZ::IsNull(address) ? 0 : address->m_port;

        outputStream.WriteInt8(id);
        outputStream.WriteString(name, NS_MZ_SHARE::mzstrlen(name));
        outputStream.WriteInt8(status);
        outputStream.WriteUint32(ip);
        outputStream.WriteUint16(port);
    }
    socket->SendData(COMMAND_LC_SERVERLIST, outputStream.GetBuffer(), outputStream.GetLength());
}
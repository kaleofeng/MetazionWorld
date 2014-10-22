#include "PacketHandlerCL.hpp"

#include "Common/Packet/PacketCL.hpp"
#include "Common/Packet/PacketLC.hpp"

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
}
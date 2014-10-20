#include "PacketHandlerCL.hpp"

#include "Common/Packet/PacketCL.hpp"
#include "Common/Packet/PacketLC.hpp"

void PacketHandlerCL::Handle(GameServerSocket* socket
    , int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_CL_LOGIN:
        HandleLogin(socket, data, length);
        break;
    default: break;
    }
}

void PacketHandlerCL::HandleLogin(GameServerSocket* socket, const void* data, int length) {
    auto req = static_cast<const LoginCL*>(data);
    ::printf("Login: username[%s] password[%s]\n", req->m_username, req->m_password);

    LoginLC rsp;
    rsp.m_success = true;
    socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));
}
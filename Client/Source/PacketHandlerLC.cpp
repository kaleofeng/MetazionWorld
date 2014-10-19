#include "PacketHandlerLC.hpp"

#include "Common/Packet/PacketLC.hpp"

void PacketHandlerLC::Handle(int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_LC_LOGIN:
        HandleLogin(data, length);
        break;
    default: break;
    }
}

void PacketHandlerLC::HandleLogin(const void* data, int length) {
    auto req = static_cast<const LoginLC*>(data);
    ::printf("Login: sucess[%d]\n", req->m_success);
}
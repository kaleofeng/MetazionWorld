#ifndef _COMMON_PACKET_PACKETCL_HPP_
#define _COMMON_PACKET_PACKETCL_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandCL {
    COMMAND_CL_CONNECTED = COMMAND_CL_BEGIN,
    COMMAND_CL_DISCONNECTED,
    COMMAND_CL_PLAYERLOGIN,
    COMMAND_CL_END,
};

struct PlayerLoginCL {
    enum { COMMAND = COMMAND_CL_PLAYERLOGIN, };

    PlayerLoginCL() {
        ::memset(m_username, '\0', sizeof(m_username));
        ::memset(m_password, '\0', sizeof(m_password));
    }

    char m_username[32];
    char m_password[32];
};

#endif // _COMMON_PACKET_PACKETCL_HPP_

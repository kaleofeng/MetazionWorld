#ifndef _COMMON_PACKETCL_HPP_
#define _COMMON_PACKETCL_HPP_

#include "Common/Struct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandCL {
    COMMAND_CL_CONNECTED = COMMAND_CL_BEGIN,
    COMMAND_CL_DISCONNECTED,
    COMMAND_CL_PLAYERLOGIN,
    COMMAND_CL_SELECTSERVER,
    COMMAND_CL_END,
};

#pragma pack(push, 1)

struct PlayerLoginCL {
    enum { COMMAND = COMMAND_CL_PLAYERLOGIN, };

    PlayerLoginCL() {
        ::memset(m_username, '\0', sizeof(m_username));
        ::memset(m_password, '\0', sizeof(m_password));
    }

    char m_username[32];
    char m_password[32];
};

struct SelectServerCL {
    enum { COMMAND = COMMAND_CL_SELECTSERVER };

    int8_t m_serverId = 0;
};

#pragma pack(pop)

#endif // _COMMON_PACKETCL_HPP_

#ifndef _COMMON_MESSAGE_PACKETCL_HPP_
#define _COMMON_MESSAGE_PACKETCL_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandCL {
    COMMAND_CL_LOGIN = COMMAND_CL_BEGIN,
    COMMAND_CL_END,
};

struct LoginCL {
    enum { COMMAND = COMMAND_CL_LOGIN };

    LoginCL() {
        ::memset(m_username, '\0', sizeof(m_username));
        ::memset(m_password, '\0', sizeof(m_password));
    }

    char m_username[32];
    char m_password[32];
};

#endif // _COMMON_MESSAGE_PACKETCL_HPP_

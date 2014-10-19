#ifndef _COMMON_MESSAGE_PACKETLC_HPP_
#define _COMMON_MESSAGE_PACKETLC_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandLC {
    COMMAND_LC_LOGIN = COMMAND_LC_BEGIN,
    COMMAND_LC_SERVERLIST,
    COMMAND_LC_END,
};

struct LoginLC {
    enum { COMMAND = COMMAND_LC_LOGIN };

    bool m_success = false;
};

struct ServerListLC {
    enum { COMMAND = COMMAND_LC_SERVERLIST };
};

#endif // _COMMON_MESSAGE_PACKETLC_HPP_

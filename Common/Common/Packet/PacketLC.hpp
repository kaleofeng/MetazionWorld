#ifndef _COMMON_PACKETLC_HPP_
#define _COMMON_PACKETLC_HPP_

#include "Common/Struct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandLC {
    COMMAND_LC_CONNECTED = COMMAND_LC_BEGIN,
    COMMAND_LC_DISCONNECTED,
    COMMAND_LC_CONNECTFAILED,
    COMMAND_LC_PLAYERLOGIN,
    COMMAND_LC_SERVERLIST,
    COMMAND_LC_END,
};

#pragma pack(push, 1)

struct PlayerLoginLC {
    enum { COMMAND = COMMAND_LC_PLAYERLOGIN };

    bool m_success = false;
};

struct ServerListLC {
    enum { COMMAND = COMMAND_LC_SERVERLIST };
};

#pragma pack(pop)

#endif // _COMMON_PACKETLC_HPP_

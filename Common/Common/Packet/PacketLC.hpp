#ifndef _COMMON_PACKET_PACKETLC_HPP_
#define _COMMON_PACKET_PACKETLC_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandLC {
    COMMAND_LC_CONNECTED = COMMAND_LC_BEGIN,
    COMMAND_LC_DISCONNECTED,
    COMMAND_LC_PLAYERLOGIN,
    COMMAND_LC_SERVERLIST,
    COMMAND_LC_END,
};

struct PlayerLoginLC {
    enum { COMMAND = COMMAND_LC_PLAYERLOGIN };

    bool m_success = false;
};

struct ServerListLC {
    enum { COMMAND = COMMAND_LC_SERVERLIST };
};

#endif // _COMMON_PACKET_PACKETLC_HPP_

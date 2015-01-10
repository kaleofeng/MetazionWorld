#ifndef _COMMON_PACKETLC_HPP_
#define _COMMON_PACKETLC_HPP_

#include "Common/Struct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandLC {
    COMMAND_LC_CONNECTED = COMMAND_LC_BEGIN,
    COMMAND_LC_DISCONNECTED,
    COMMAND_LC_CONNECTFAILED,
    COMMAND_LC_USERLOGIN,
    COMMAND_LC_SERVERLIST,
    COMMAND_LC_SELECTSERVER,
    COMMAND_LC_END,
};

#pragma pack(push, 1)

struct UserLoginLC {
    enum { COMMAND = COMMAND_LC_USERLOGIN };

    int64_t m_userId = 0;
    bool m_success = false;
};

struct SelectServerLC {
    enum { COMMAND = COMMAND_LC_SELECTSERVER };

    int64_t m_authCode = 0;
    int8_t m_serverId = 0;
    NS_MZ_NET::Address m_address;
};

#pragma pack(pop)

#endif // _COMMON_PACKETLC_HPP_

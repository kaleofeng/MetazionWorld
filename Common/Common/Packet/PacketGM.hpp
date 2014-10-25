#ifndef _COMMON_PACKETGM_HPP_
#define _COMMON_PACKETGM_HPP_

#include "Common/Struct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandGM {
    COMMAND_GM_CONNECTED = COMMAND_GM_BEGIN,
    COMMAND_GM_DISCONNECTED,
    COMMAND_GM_END,
};

#endif // _COMMON_PACKETGM_HPP_

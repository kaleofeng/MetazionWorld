#ifndef _COMMON_PACKETMZ_HPP_
#define _COMMON_PACKETMZ_HPP_

#include "Common/Struct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandMZ {
    COMMAND_MZ_CONNECTED = COMMAND_MZ_BEGIN,
    COMMAND_MZ_DISCONNECTED,
    COMMAND_MZ_END,
};

#endif // _COMMON_PACKETMZ_HPP_

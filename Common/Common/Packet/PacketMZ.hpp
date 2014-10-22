#ifndef _COMMON_PACKET_PACKETMZ_HPP_
#define _COMMON_PACKET_PACKETMZ_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandMZ {
    COMMAND_MZ_CONNECTED = COMMAND_MZ_BEGIN,
    COMMAND_MZ_DISCONNECTED,
    COMMAND_MZ_END,
};

#endif // _COMMON_PACKET_PACKETMZ_HPP_

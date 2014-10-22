#ifndef _COMMON_PACKET_PACKETMG_HPP_
#define _COMMON_PACKET_PACKETMG_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandMG {
    COMMAND_MG_CONNECTED = COMMAND_MG_BEGIN,
    COMMAND_MG_DISCONNECTED,
    COMMAND_MG_END,
};

#endif // _COMMON_PACKET_PACKETMG_HPP_

#ifndef _COMMON_PACKET_PACKETCG_HPP_
#define _COMMON_PACKET_PACKETCG_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandCG {
    COMMAND_CG_CONNECTED = COMMAND_CG_BEGIN,
    COMMAND_CG_DISCONNECTED,
    COMMAND_CG_END,
};

#endif // _COMMON_PACKET_PACKETCG_HPP_

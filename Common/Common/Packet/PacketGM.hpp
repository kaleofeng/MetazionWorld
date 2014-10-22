#ifndef _COMMON_PACKET_PACKETGM_HPP_
#define _COMMON_PACKET_PACKETGM_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandGM {
    COMMAND_GM_CONNECTED = COMMAND_GM_BEGIN,
    COMMAND_GM_DISCONNECTED,
    COMMAND_GM_END,
};

#endif // _COMMON_PACKET_PACKETGM_HPP_

#ifndef _COMMON_PACKET_PACKETZM_HPP_
#define _COMMON_PACKET_PACKETZM_HPP_

#include "Common/CommonStruct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandZM {
    COMMAND_ZM_CONNECTED = COMMAND_ZM_BEGIN,
    COMMAND_ZM_DISCONNECTED,
    COMMAND_ZM_END,
};

#endif // _COMMON_PACKET_PACKETZM_HPP_

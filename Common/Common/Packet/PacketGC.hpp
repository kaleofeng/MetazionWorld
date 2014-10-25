#ifndef _COMMON_PACKETGC_HPP_
#define _COMMON_PACKETGC_HPP_

#include "Common/Struct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandGC {
    COMMAND_GC_CONNECTED = COMMAND_GC_BEGIN,
    COMMAND_GC_DISCONNECTED,
    COMMAND_GC_END,
};

#endif // _COMMON_PACKETGC_HPP_

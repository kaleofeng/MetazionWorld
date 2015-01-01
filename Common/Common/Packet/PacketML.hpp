#ifndef _COMMON_PACKETML_HPP_
#define _COMMON_PACKETML_HPP_

#include "Common/Struct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandML {
    COMMAND_ML_CONNECTED = COMMAND_ML_BEGIN,
    COMMAND_ML_DISCONNECTED,
    COMMAND_ML_SERVERREGISTER,
    COMMAND_ML_END,
};

#endif // _COMMON_PACKETML_HPP_

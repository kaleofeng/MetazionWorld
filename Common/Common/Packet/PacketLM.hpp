#ifndef _COMMON_PACKETLM_HPP_
#define _COMMON_PACKETLM_HPP_

#include "Common/Struct.hpp"
#include "Common/Packet/Command.hpp"

enum CommandLM {
    COMMAND_LM_CONNECTED = COMMAND_LM_BEGIN,
    COMMAND_LM_DISCONNECTED,
    COMMAND_LM_USERCANDIDATE,
    COMMAND_LM_END,
};

struct UserCandidateLM {

};

#endif // _COMMON_PACKETLM_HPP_

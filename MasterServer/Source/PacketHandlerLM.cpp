#include "PacketHandlerLM.hpp"

#include "Common/Packet/PacketML.hpp"
#include "Common/Packet/PacketLM.hpp"

void PacketHandlerLM::Handle(int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_LM_CONNECTED:
        HandleConnected(data, length);
        break;
    case COMMAND_LM_DISCONNECTED:
        HandleDisconnected(data, length);
        break;
    default: break;
    }
}

void PacketHandlerLM::HandleConnected(const void* data, int length) {
    
}

void PacketHandlerLM::HandleDisconnected(const void* data, int length) {
    
}
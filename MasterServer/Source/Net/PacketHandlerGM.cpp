#include "PacketHandlerGM.hpp"

#include "Common/Packet/PacketMG.hpp"
#include "Common/Packet/PacketGM.hpp"

void PacketHandlerGM::Handle(int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_GM_CONNECTED:
        HandleConnected(data, length);
        break;
    case COMMAND_GM_DISCONNECTED:
        HandleDisconnected(data, length);
        break;
    default: break;
    }
}

void PacketHandlerGM::HandleConnected(const void* data, int length) {

}

void PacketHandlerGM::HandleDisconnected(const void* data, int length) {

}
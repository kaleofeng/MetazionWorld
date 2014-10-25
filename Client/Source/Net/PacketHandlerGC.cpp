#include "PacketHandlerGC.hpp"

#include "Common/Packet/PacketGC.hpp"

void PacketHandlerGC::Handle(int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_GC_CONNECTED:
        HandleConnected(data, length);
        break;
    case COMMAND_GC_DISCONNECTED:
        HandleDisconnected(data, length);
        break;
    default: break;
    }
}

void PacketHandlerGC::HandleConnected(const void* data, int length) {

}

void PacketHandlerGC::HandleDisconnected(const void* data, int length) {

}
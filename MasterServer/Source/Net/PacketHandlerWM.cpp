#include "PacketHandlerWM.hpp"

#include "Common/Packet/PacketZM.hpp"
#include "Common/Packet/PacketMZ.hpp"

void PacketHandlerWM::Handle(ServerSocketWM* socket
    , int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_ZM_CONNECTED:
        HandleZMConnected(socket, data, length);
        break;
    case COMMAND_ZM_DISCONNECTED:
        HandleZMDisconnected(socket, data, length);
        break;
    default: break;
    }
}

void PacketHandlerWM::HandleZMConnected(ServerSocketWM* socket, const void* data, int length) {

}

void PacketHandlerWM::HandleZMDisconnected(ServerSocketWM* socket, const void* data, int length) {

}
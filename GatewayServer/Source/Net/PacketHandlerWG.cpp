#include "PacketHandlerWG.hpp"

#include "Common/Packet/PacketMG.hpp"
#include "Common/Packet/PacketGM.hpp"

void PacketHandlerWG::Handle(ServerSocketWG* socket
    , int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_MG_CONNECTED:
        HandleMGConnected(socket, data, length);
        break;
    case COMMAND_MG_DISCONNECTED:
        HandleMGDisconnected(socket, data, length);
        break;
    default: break;
    }
}
void PacketHandlerWG::HandleMGConnected(ServerSocketWG* socket
    , const void* data, int length) {

}

void PacketHandlerWG::HandleMGDisconnected(ServerSocketWG* socket
    , const void* data, int length) {

}

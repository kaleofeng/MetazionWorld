#include "PacketHandlerCG.hpp"

#include "Common/Packet/PacketCG.hpp"
#include "Common/Packet/PacketGC.hpp"

void PacketHandlerCG::Handle(ServerSocketCG* socket
    , int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_CG_CONNECTED:
        HandleConnected(socket, data, length);
        break;
    case COMMAND_CG_DISCONNECTED:
        HandleDisconnected(socket, data, length);
        break;
    default: break;
    }
}
void PacketHandlerCG::HandleConnected(ServerSocketCG* socket
    , const void* data, int length) {

}

void PacketHandlerCG::HandleDisconnected(ServerSocketCG* socket
    , const void* data, int length) {
    
}
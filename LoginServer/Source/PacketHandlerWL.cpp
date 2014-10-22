#include "PacketHandlerWL.hpp"

#include "Common/Packet/PacketML.hpp"
#include "Common/Packet/PacketLM.hpp"

void PacketHandlerWL::Handle(ServerSocketWL* socket
    , int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_ML_CONNECTED:
        HandleMLConnected(socket, data, length);
        break;
    case COMMAND_ML_DISCONNECTED:
        HandleMLDisconnected(socket, data, length);
        break;
    default: break;
    }
}
void PacketHandlerWL::HandleMLConnected(ServerSocketWL* socket
    , const void* data, int length) {

}

void PacketHandlerWL::HandleMLDisconnected(ServerSocketWL* socket
    , const void* data, int length) {

}

#include "PacketHandlerCL.hpp"

#include <Metazion/Share/Misc/MemoryOutputStream.hpp>
#include <Metazion/Share/Utility/Random.hpp>

#include "Common/Packet/PacketCL.hpp"
#include "Common/Packet/PacketLC.hpp"
#include "Common/Packet/PacketLM.hpp"

#include "ServerApp.hpp"
#include "UserManager.hpp"

void PacketHandlerCL::Handle(ServerSocketCL* socket
    , int command, const void* data, int length) {
    ::printf("Command[%d] data[%p] length[%d]\n", command, data, length);

    switch (command) {
    case COMMAND_CL_CONNECTED:
        HandleConnected(socket, data, length);
        break;
    case COMMAND_CL_DISCONNECTED:
        HandleDisconnected(socket, data, length);
        break;
    case COMMAND_CL_USERLOGIN:
        HandleUserLogin(socket, data, length);
        break;
    case COMMAND_CL_SELECTSERVER:
        HandleSelectServer(socket, data, length);
        break;
    default: break;
    }
}
void PacketHandlerCL::HandleConnected(ServerSocketCL* socket
    , const void* data, int length) {

}

void PacketHandlerCL::HandleDisconnected(ServerSocketCL* socket
    , const void* data, int length) {
    
}

void PacketHandlerCL::HandleUserLogin(ServerSocketCL* socket
    , const void* data, int length) {
    const auto req = static_cast<const UserLoginCL*>(data);
    ::printf("UserLogin: username[%s] password[%s]\n", req->m_username, req->m_password);

    const auto success = _stricmp(req->m_username, "meta") == 0;
    if (!success) {
        UserLoginLC rsp;
        rsp.m_success = false;
        socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));
        return;
    }

    UserLoginLC rsp;
    rsp.m_userId = 1000000000001;
    rsp.m_success = true;
    socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));

    NS_MZ_SHARE::MemoryOutputStream<> outputStream;
    const auto serverGroupSize = g_serverApp->m_serverGroupManager.GetServerGroupSize();
    outputStream.WriteInt8(serverGroupSize);
    const auto& serverGroupMap = g_serverApp->m_serverGroupManager.GetAllServerGroup();
    for (auto pair : serverGroupMap) {
        const auto& serverGroup = pair.second;
        const auto id = serverGroup.GetId();
        const auto name = serverGroup.GetName();
        const auto status = serverGroup.GetStatus();
     
        outputStream.WriteInt8(id);
        outputStream.WriteString(name, NS_MZ_SHARE::mzstrlen(name));
        outputStream.WriteInt8(status);
    }
    socket->SendData(COMMAND_LC_SERVERLIST, outputStream.GetBuffer(), outputStream.GetLength());

    User user;
    user.SetUserId(rsp.m_userId);
    UserManager::Instance().AppendUser(user);
}

void PacketHandlerCL::HandleSelectServer(ServerSocketCL* socket
    , const void* data, int length) {
    const auto req = static_cast<const SelectServerCL*>(data);
    ::printf("SelectServer: userId[%lld] serverId[%d]\n", req->m_userId, req->m_serverId);

    SelectServerLC rsp;

    const auto userId = req->m_userId;
    User* user = UserManager::Instance().GetUser(userId);
    if (NS_MZ::IsNull(user)) {
        rsp.m_authCode = -1;
        socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));
        return;
    }

    const auto serverId = req->m_serverId;
    const auto serverGroup = g_serverApp->m_serverGroupManager.GetServerGroup(serverId);
    if (NS_MZ::IsNull(serverGroup)) {
        rsp.m_authCode = -2;
        socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));
        return;
    }

    const auto status = serverGroup->GetStatus();
    if (status == 0) {
        rsp.m_authCode = -3;
        socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));
        return;
    }

    const auto address = serverGroup->SelectRandomAddress();
    if (NS_MZ::IsNull(address)) {
        rsp.m_authCode = -4;
        socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));
        return;
    }

    static NS_MZ_SHARE::Random s_random;
    const auto authCode = s_random.GetRangeInt(1000000, 1000000000);

    rsp.m_authCode = authCode;
    rsp.m_address = *address;
    socket->SendData(rsp.COMMAND, &rsp, sizeof(rsp));

    UserCandidateLM reqLM;
    reqLM.m_userId = userId;
    reqLM.m_authCode = authCode;
    serverGroup->GetSocket()->SendData(reqLM.COMMAND, &reqLM, sizeof(reqLM));

    UserManager::Instance().RemoveUser(userId);
}
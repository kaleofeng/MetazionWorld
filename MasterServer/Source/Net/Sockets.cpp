#include "Sockets.hpp"

#include "Common/Packet/PacketLM.hpp"
#include "Common/Packet/PacketGM.hpp"

#include "ServerApp.hpp"

void ServerSocketWM::DerivedReset() {
    m_packeter.SetValidPacketCallback([this](int command, const void* data, int length) {
        g_serverApp->m_packetHandlerWM.Handle(this, command, data, length);
    });

    m_packeter.SetInvalidPacketCallback([this]() {
        Close();
    });
}

void ServerSocketWM::DerivedOnConnected() {
    ::printf("ServerSocket from World Connected\n");
}

void ServerSocketWM::DerivedOnDisconnected() {
    ::printf("ServerSocket from World Disconnected\n");
}


void ListenSocketWM::DerivedReset() {
    m_accepter.SetCreateSocketCallback([this]() {
        auto serverSocket = m_socketPool.Obtain();
        serverSocket->Reset();
        serverSocket->Retain();
        serverSocket->SetDestroyCallback([&](Socket* socket) {
            auto dstSocket = static_cast<ServerSocketWM*>(socket);
            m_socketPool.Return(dstSocket);
        });
        return serverSocket;
    });
}

void ListenSocketWM::DerivedOnWatched() {
    ::printf("ListenSocket for World Watched\n");
}

void ListenSocketWM::DerivedOnUnwatched() {
    ::printf("ListenSocket for World Unwatched\n");
}


void ClientSocketML::DerivedReset() {
    m_packeter.SetValidPacketCallback([this](int command, const void* data, int length) {
        g_serverApp->m_packetHandlerLM.Handle(command, data, length);
    });

    m_packeter.SetInvalidPacketCallback([this]() {
        Close();
    });
}

void ClientSocketML::DerivedOnConnected() {
    ::printf("ClientSocket to Login Connected\n");
    m_packeter.PostData(COMMAND_LM_CONNECTED, nullptr, 0);
}

void ClientSocketML::DerivedOnDisconnected() {
    ::printf("ClientSocket to Login Disconnected\n");
    m_packeter.PostData(COMMAND_LM_DISCONNECTED, nullptr, 0);
}


void ClientSocketMG::DerivedReset() {
    m_packeter.SetValidPacketCallback([this](int command, const void* data, int length) {
        g_serverApp->m_packetHandlerGM.Handle(command, data, length);
    });

    m_packeter.SetInvalidPacketCallback([this]() {
        Close();
    });
}

void ClientSocketMG::DerivedOnConnected() {
    ::printf("ClientSocket to Gateway Connected\n");
    m_packeter.PostData(COMMAND_GM_CONNECTED, nullptr, 0);
}

void ClientSocketMG::DerivedOnDisconnected() {
    ::printf("ClientSocket to Gateway Disconnected\n");
    m_packeter.PostData(COMMAND_GM_DISCONNECTED, nullptr, 0);
}
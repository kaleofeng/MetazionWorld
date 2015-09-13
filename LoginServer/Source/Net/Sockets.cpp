#include "Sockets.hpp"

#include "ServerApp.hpp"

void ServerSocketCL::DerivedReset() {
    m_packeter.SetValidPacketCallback([this](int command, const void* data, int length) {
        g_serverApp->m_packetHandlerCL.Handle(this, command, data, length);
    });

    m_packeter.SetInvalidPacketCallback([this]() {
        Close();
    });
}

void ServerSocketCL::DerivedOnConnected() {
    ::printf("ServerSocket from Client Connected\n");
}

void ServerSocketCL::DerivedOnDisconnected() {
    ::printf("ServerSocket from Client Disconnected\n");
}


void ListenSocketCL::DerivedReset() {
    m_accepter.SetCreateSocketCallback([this]() {
        auto serverSocket = m_socketPool.Obtain();
        serverSocket->Reset();
        serverSocket->Retain();
        serverSocket->SetDestroyCallback([&](Socket* socket) {
            auto dstSocket = static_cast<ServerSocketCL*>(socket);
            m_socketPool.Return(dstSocket);
        });
        return serverSocket;
    });
}

void ListenSocketCL::DerivedOnWatched() {
    ::printf("ListenSocket for Client Watched\n");
}

void ListenSocketCL::DerivedOnUnwatched() {
    ::printf("ListenSocket for Client Unwatched\n");
}


ServerGroup* ServerSocketWL::GetObject() {
    return m_serverGroup;
}

void ServerSocketWL::BindObject(ServerGroup* object) {
    m_serverGroup = object;
}

void ServerSocketWL::DerivedReset() {
    m_packeter.SetValidPacketCallback([this](int command, const void* data, int length) {
        g_serverApp->m_packetHandlerWL.Handle(this, command, data, length);
    });

    m_packeter.SetInvalidPacketCallback([this]() {
        Close();
    });
}

void ServerSocketWL::DerivedOnConnected() {
    ::printf("ServerSocket from World Connected\n");
}

void ServerSocketWL::DerivedOnDisconnected() {
    ::printf("ServerSocket from World Disconnected\n");
}


void ListenSocketWL::DerivedReset() {
    m_accepter.SetCreateSocketCallback([this]() {
        auto serverSocket = m_socketPool.Obtain();
        serverSocket->Reset();
        serverSocket->Retain();
        serverSocket->SetDestroyCallback([&](Socket* socket) {
            auto dstSocket = static_cast<ServerSocketWL*>(socket);
            m_socketPool.Return(dstSocket);
        });
        return serverSocket;
    });
}

void ListenSocketWL::DerivedOnWatched() {
    ::printf("ListenSocket for World Watched\n");
}

void ListenSocketWL::DerivedOnUnwatched() {
    ::printf("ListenSocket for World Unwatched\n");
}
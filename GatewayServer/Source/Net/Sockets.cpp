#include "Sockets.hpp"

#include "ServerApp.hpp"

void ServerSocketCG::DerivedReset() {
    m_packeter.SetValidPacketCallback([this](int command, const void* data, int length) {
        g_serverApp->m_packetHandlerCG.Handle(this, command, data, length);
    });

    m_packeter.SetInvalidPacketCallback([this]() {
       Close();
    });
}

void ServerSocketCG::DerivedOnConnected() {
    ::printf("ServerSocket from Client Connected\n");
}

void ServerSocketCG::DerivedOnDisconnected() {
    ::printf("ServerSocket from Client Disconnected\n");
}


void ListenSocketCG::DerivedReset() {
    m_accepter.SetCreateSocketCallback([this]() {
        auto serverSocket = m_socketPool.Obtain();
        serverSocket->Reset();
        serverSocket->Retain();
        serverSocket->SetDestroyCallback([&](Socket* socket) {
            auto dstSocket = static_cast<ServerSocketCG*>(socket);
            m_socketPool.Return(dstSocket);
        });
        return serverSocket;
    });
}

void ListenSocketCG::DerivedOnWatched() {
    ::printf("ListenSocket for Client Watched\n");
}

void ListenSocketCG::DerivedOnUnwatched() {
    ::printf("ListenSocket for Client Unwatched\n");
}


void ServerSocketWG::DerivedReset() {
    m_packeter.SetValidPacketCallback([this](int command, const void* data, int length) {
        g_serverApp->m_packetHandlerWG.Handle(this, command, data, length);
    });

    m_packeter.SetInvalidPacketCallback([this]() {
        Close();
    });
}

void ServerSocketWG::DerivedOnConnected() {
    ::printf("ServerSocket from World Connected\n");
}

void ServerSocketWG::DerivedOnDisconnected() {
    ::printf("ServerSocket from World Disconnected\n");
}


void ListenSocketWG::DerivedReset() {
    m_accepter.SetCreateSocketCallback([this]() {
        auto serverSocket = m_socketPool.Obtain();
        serverSocket->Reset();
        serverSocket->Retain();
        serverSocket->SetDestroyCallback([&](Socket* socket) {
            auto dstSocket = static_cast<ServerSocketWG*>(socket);
            m_socketPool.Return(dstSocket);
        });
        return serverSocket;
    });
}

void ListenSocketWG::DerivedOnWatched() {
    ::printf("ListenSocket for World Watched\n");
}

void ListenSocketWG::DerivedOnUnwatched() {
    ::printf("ListenSocket for World Unwatched\n");
}
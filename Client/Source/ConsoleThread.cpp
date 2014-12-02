#include "ConsoleThread.hpp"

#include <iostream>

#include <Metazion/Share/Utility/StringFunction.hpp>

#include "Common/Packet/PacketCL.hpp"

#include "ServerApp.hpp"

USING_NAMESPACE_MZ_SHARE

ConsoleThread::ConsoleThread()
    : m_stopDesired(false) {}

ConsoleThread::~ConsoleThread() {}

void ConsoleThread::Initialize() {
    m_stopDesired = false;
}

void ConsoleThread::Finalize() {
    m_stopDesired = true;
    Join();
}

void ConsoleThread::Execute() {
    while (!m_stopDesired) {
        ::printf("----------------------------------------------------------------\n");
        ::printf("Input command\n");
        char command[32] = "";
        std::cin.getline(command, sizeof(command));
        Process(command);
    }
}

void ConsoleThread::Process(const char* command) {
    ::printf("command: [%s]\n", command);

    if (strcmp(command, "login") == 0) {
        ::printf("name: ");
        char name[32] = "";
        std::cin.getline(name, sizeof(name));

        ::printf("password: ");
        char password[32] = "";
        std::cin.getline(password, sizeof(password));

        ::printf("Login: name[%s] password[%s]\n", name, password);

        PlayerLoginCL req;
        mzstrcpy(req.m_username, sizeof(req.m_username), name);
        mzstrcpy(req.m_password, sizeof(req.m_password), password);
        g_serverApp->m_socketCL->SendData(req.COMMAND, &req, sizeof(req));
    }
    else if (strcmp(command, "exit") == 0) {
        ::exit(0);
    }
}
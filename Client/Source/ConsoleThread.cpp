#include "ConsoleThread.hpp"

#include <iostream>

#include "Common/Packet/PacketCL.hpp"

#include "ServerApp.hpp"

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

        LoginCL req;
        strcpy(req.m_username, name);
        strcpy(req.m_password, password);
        g_serverApp->m_loginSocket->SendData(req.COMMAND, &req, sizeof(req));
    }
    else if (strcmp(command, "exit") == 0) {
        ::exit(0);
    }
}
#ifndef _CLIENT_CONSOLETHREAD_HPP_
#define _CLIENT_CONSOLETHREAD_HPP_

#include <Metazion/Share/Thread/Thread.hpp>

class ConsoleThread : public NS_MZ_SHARE::Thread {
    DISALLOW_COPY_AND_ASSIGN(ConsoleThread)

public:
    ConsoleThread();

    ~ConsoleThread();

public:
    void Initialize();

    void Finalize();

protected:
    void Execute() override final;

private:
    void Process(const char* command);

private:
    bool m_stopDesired;
};

#endif // _CLIENT_CONSOLETHREAD_HPP_

#include "ServerApp.hpp"

USING_NAMESPACE_MZ_NET

int main() {
    g_serverApp = new ServerApp();
    g_serverApp->Initialize();

    while (true) {
        g_serverApp->Tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    g_serverApp->Finalize();
    NS_MZ::SafeDelete(g_serverApp);
    return 0;
}
#pragma once

#include <Metazion/Overall.hpp>

class PacketHandlerLC {
    DISALLOW_COPY_AND_ASSIGN(PacketHandlerLC)

public:
    PacketHandlerLC() {}

    ~PacketHandlerLC() {}

public:
    void Handle(int command, const void* data, int length);

private:
    void HandleLogin(const void* data, int length);
};
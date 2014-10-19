#ifndef _COMMON_MESSAGE_COMMONSTRUCT_HPP_
#define _COMMON_MESSAGE_COMMONSTRUCT_HPP_

#include <Metazion/Net/Address.hpp>

#include "Common/CommonDefine.hpp"

struct ServerInfo {
    ServerInfo() {
        ::memset(m_name, '\0', sizeof(m_name));
    }
    
    char m_name[32];
    NS_MZ_NET::Address m_address;
};

#endif // _COMMON_MESSAGE_COMMONSTRUCT_HPP_

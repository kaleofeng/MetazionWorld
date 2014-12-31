#ifndef _COMMON_STRUCT_HPP_
#define _COMMON_STRUCT_HPP_

#include <Metazion/Net/Address.hpp>

#include "Common/Define.hpp"

struct ServerConfig {
    int m_id = 0;
    NS_MZ_NET::Address m_privateAddress;
    NS_MZ_NET::Address m_publicAddress;
};

struct ServerInfo {
    int m_id = 0;
    int m_status = 0;
    NS_MZ_NET::Address m_address;
};

#endif // _COMMON_STRUCT_HPP_

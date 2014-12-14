#ifndef _COMMON_STRUCT_HPP_
#define _COMMON_STRUCT_HPP_

#include <Metazion/Net/Address.hpp>

#include "Common/Define.hpp"

struct LoginConfig {
    int m_id = 0;
    NS_MZ_NET::Address m_privateAddress;
    NS_MZ_NET::Address m_publicAddress;
};

struct MasterConfig {
    int m_id = 0;
    NS_MZ_NET::Address m_privateAddress;
    NS_MZ_NET::Address m_publicAddress;
};

struct GatewayConfig {
    int m_id = 0;
    NS_MZ_NET::Address m_privateAddress;
    NS_MZ_NET::Address m_publicAddress;
};

struct ZoneConfig {
    int m_id = 0;
    NS_MZ_NET::Address m_privateAddress;
    NS_MZ_NET::Address m_publicAddress;
};

#endif // _COMMON_STRUCT_HPP_

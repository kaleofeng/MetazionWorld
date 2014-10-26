#ifndef _COMMON_STRUCT_HPP_
#define _COMMON_STRUCT_HPP_

#include <Metazion/Net/Address.hpp>

#include "Common/Define.hpp"

struct LoginConfig {
    NS_MZ_NET::Address m_publicAddress;
    NS_MZ_NET::Address m_privateAddress;
};

struct MasterConfig {
    int m_status = 0;
    NS_MZ_NET::Address m_publicAddress;
    NS_MZ_NET::Address m_privateAddress;
};

struct GatewayConfig {
    int m_id = 0;
    NS_MZ_NET::Address m_publicAddress;
    NS_MZ_NET::Address m_privateAddress;
};

struct ZoneConfig {
    int m_id = 0;
    NS_MZ_NET::Address m_publicAddress;
    NS_MZ_NET::Address m_privateAddress;
};

#endif // _COMMON_STRUCT_HPP_

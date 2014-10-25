#ifndef _COMMON_STRUCT_HPP_
#define _COMMON_STRUCT_HPP_

#include "Common/Define.hpp"

#include <Metazion/Net/Address.hpp>

struct LoginInfo {
    int m_status = 0;
    NS_MZ_NET::Address m_publicAddress;
    NS_MZ_NET::Address m_privateAddress;
};

struct MasterInfo {
    int m_status = 0;
    NS_MZ_NET::Address m_publicAddress;
    NS_MZ_NET::Address m_privateAddress;
};

struct GatewayInfo {
    int m_id = 0;
    int m_status = 0;
    int m_playerCount;
    NS_MZ_NET::Address m_publicAddress;
    NS_MZ_NET::Address m_privateAddress;
};

struct ZoneInfo {
    int m_id = 0;
    int m_status = 0;
    int m_playerCount = 0;
    NS_MZ_NET::Address m_publicAddress;
    NS_MZ_NET::Address m_privateAddress;
};

#endif // _COMMON_STRUCT_HPP_

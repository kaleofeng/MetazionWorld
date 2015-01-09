#include "ServerGroup.hpp"

#include <Metazion/Share/Utility/Random.hpp>

ServerGroup::ServerGroup()
    : m_id(0)
    , m_status(0)
    , m_socket(nullptr) {
    ::memset(m_name, 0, sizeof(m_name));
}

ServerGroup::~ServerGroup() {}

int ServerGroup::GetAddressSize() const {
    return m_addressArray.GetSize();
}

const NS_MZ_NET::Address* ServerGroup::SelectRandomAddress() const {
    const auto size = GetAddressSize();
    if (size < 1) {
        return nullptr;
    }

    static NS_MZ_SHARE::Random s_random;
    const auto index = s_random.GetRangeInt(0, size - 1);
    return GetAddress(index);
}

const NS_MZ_NET::Address* ServerGroup::GetAddress(int index) const {
    if (index >= 0 && index < m_addressArray.GetSize()) {
        return &m_addressArray[index];
    }

    return nullptr;
}

void ServerGroup::AppendAddress(const NS_MZ_NET::Address& value) {
    m_addressArray.Append(value);
}

void ServerGroup::RemoveAllAddress() {
    m_addressArray.Clear();
}

void ServerGroup::BindSocket(ServerSocketWL* socket) {
    m_socket = socket;
}
#include "ServerGroup.hpp"

ServerGroup::ServerGroup()
    : m_id(0)
    , m_status(0) {
    ::memset(m_name, 0, sizeof(m_name));
}

ServerGroup::~ServerGroup() {}
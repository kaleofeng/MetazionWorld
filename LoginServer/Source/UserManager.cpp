#include "UserManager.hpp"

UserManager::UserManager() {}

UserManager::~UserManager() {}

UserManager& UserManager::Instance() {
    static UserManager t;
    return t;
}

int UserManager::GetUserSize() const {
    return m_userMap.GetSize();
}

User* UserManager::GetUser(int64_t id) {
    auto iter = m_userMap.Find(id);
    if (iter != m_userMap.End()) {
        return &iter->second;
    }

    return nullptr;
}

void UserManager::AppendUser(const User& user) {
    m_userMap.Insert(user.GetUserId(), user);
}

void UserManager::RemoveUser(int64_t id) {
    auto iter = m_userMap.Find(id);
    if (iter != m_userMap.End()) {
        m_userMap.Erase(iter);
    }
}

void UserManager::RemoveAllUser() {
    m_userMap.Clear();
}
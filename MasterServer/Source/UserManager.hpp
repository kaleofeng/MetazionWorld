#ifndef _MASTERSERVER_USERMANAGER_HPP_
#define _MASTERSERVER_USERMANAGER_HPP_

#include <Metazion/Share/Collection/Map.hpp>

#include "User.hpp"

class UserManager {

    using UserMap_t = NS_MZ_SHARE::Map<int64_t, User>;

private:
    UserMap_t m_userMap;

public:
    UserManager();

    ~UserManager();

    static UserManager& Instance();

public:
    int GetUserSize() const;

    User* GetUser(int64_t id);

    void AppendUser(const User& user);

    void RemoveUser(int64_t id);

    void RemoveAllUser();
};

#endif // _MASTERSERVER_USERMANAGER_HPP_

#ifndef _LOGINSERVER_USER_HPP_
#define _LOGINSERVER_USER_HPP_

#include <cstdint>

class User {

private:
    int64_t m_userId;
    int64_t m_authCode;

public:
    User();

    ~User();

public:
    int64_t GetUserId() const {
        return m_userId;
    }

    void SetUserId(int64_t value) {
        m_userId = value;
    }

    int64_t GetAuthCode() const {
        return m_authCode;
    }

    void SetAuthCode(int value) {
        m_authCode = value;
    }
};

#endif //_LOGINSERVER_USER_HPP_

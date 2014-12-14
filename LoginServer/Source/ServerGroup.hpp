#ifndef _LOGINSERVER_SERVERGROUP_H_
#define _LOGINSERVER_SERVERGROUP_H_

#include <Metazion/Net/Address.hpp>
#include <Metazion/Net/Host.hpp>
#include <Metazion/Share/Utility/StringFunction.hpp>

class ServerGroup {
public:
    ServerGroup();

    ~ServerGroup();

public:
    int GetId() const {
        return m_id;
    }

    void SetId(int value) {
        m_id = value;
    }

    const char* GetName() const {
        return m_name;
    }

    void SetName(const char* value) {
        NS_MZ_SHARE::mzstrcpy(m_name, sizeof(m_name), value);
    }

    const NS_MZ_NET::Address& GetPublicAddress() const {
        return m_publicAddress;
    }

    void SetPublicAddress(const NS_MZ_NET::Address& value) {
        m_publicAddress = value;
    }

    int GetStatus() const {
        return m_status;
    }

    void SetStatus(int value) {
        m_status = value;
    }

private:
    int m_id;
    char m_name[64];
    NS_MZ_NET::Address m_publicAddress;

    int m_status;
};



#endif // _LOGINSERVER_SERVERGROUP_H_


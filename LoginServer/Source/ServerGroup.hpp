#ifndef _LOGINSERVER_SERVERGROUP_H_
#define _LOGINSERVER_SERVERGROUP_H_

#include <Metazion/Share/Collection/DynamicArray.hpp>
#include <Metazion/Share/Utility/StringFunction.hpp>
#include <Metazion/Net/Address.hpp>
#include <Metazion/Net/Host.hpp>

class ServerGroup {
    using AddressArray_t = NS_MZ_SHARE::DynamicArray<NS_MZ_NET::Address, 4, 4>;

public:
    ServerGroup();

    ~ServerGroup();

public:
    const NS_MZ_NET::Address* SelectRandomAddress() const;

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

    int GetStatus() const {
        return m_status;
    }

    void SetStatus(int value) {
        m_status = value;
    }

    int GetAddressSize() const;
    const NS_MZ_NET::Address* GetAddress(int index) const;
    void AppendAddress(const NS_MZ_NET::Address& value);
    void RemoveAllAddress();

private:
    int m_id;
    char m_name[64];
    int m_status;
    AddressArray_t m_addressArray;
};



#endif // _LOGINSERVER_SERVERGROUP_H_


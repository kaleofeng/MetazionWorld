#ifndef _LOGINSERVER_SERVERGROUPMANAGER_H_
#define _LOGINSERVER_SERVERGROUPMANAGER_H_

#include <Metazion/Share/Collection/Map.hpp>

#include "ServerGroup.hpp"

class ServerGroupManager {
public:
    using ServerGroupMap_t = NS_MZ_SHARE::Map<int, ServerGroup>;

public:
    ServerGroupManager();

    ~ServerGroupManager();

public:
    void Initialize();

    void Finalize();

    int GetServerGroupSize() const;
    ServerGroup* GetServerGroup(int id);
    const ServerGroupMap_t& GetAllServerGroup() const;
    void AddServerGroup(const ServerGroup& serverGroup);
    void RemoveServerGroup(int id);
    void RemoveAllServerGroup();

private:
    void LoadAllServerGroup();

private:
    ServerGroupMap_t m_serverGroupMap;
};


#endif // _LOGINSERVER_SERVERGROUPMANAGER_H_


#ifndef _MASTERSERVER_SERVERMANAGER_HPP_
#define _MASTERSERVER_SERVERMANAGER_HPP_

#include <Metazion/Share/Collection/Map.hpp>

#include "Common/Struct.hpp"

class ServerManager {
    using GatewayInfoMap_t = NS_MZ_SHARE::Map<int, GatewayInfo>;
    using ZoneInfoMap_t = NS_MZ_SHARE::Map<int, ZoneInfo>;

public:
    ServerManager();

    ~ServerManager();

public:
    void Initialize();

    void Finalize();

    MasterInfo& GetMasterInfo();

    LoginInfo& GetLoginInfo();

    int GetGatewayInfoSize() const;
    GatewayInfo* GetGatewayInfo(int id);
    const GatewayInfoMap_t& GetAllGatewayInfo() const;
    void AddGatewayInfo(const GatewayInfo& gatewayInfo);
    void RemoveGatewayInfo(int id);
    void RemoveAllGatewayInfo();

    int GetZoneInfoSize() const;
    ZoneInfo* GetZoneInfo(int id);
    const ZoneInfoMap_t& GetAllZoneInfo() const;
    void AddZoneInfo(const ZoneInfo& gatewayInfo);
    void RemoveZoneInfo(int id);
    void RemoveAllZoneInfo();

private:
    void LoadLoginInfo();

    void LoadMasterInfo();

    void LoadGatewayInfo();

    void LoadZoneInfo();

private:
    LoginInfo m_loginInfo;
    MasterInfo m_masterInfo;
    GatewayInfoMap_t m_gatewayInfoMap;
    ZoneInfoMap_t m_zoneInfoMap;
};

#endif // _MASTERSERVER_SERVERMANAGER_HPP_

#ifndef _MASTERSERVER_SERVERCONFIGMANAGER_HPP_
#define _MASTERSERVER_SERVERCONFIGMANAGER_HPP_

#include <Metazion/Share/Collection/Map.hpp>

#include "Common/Struct.hpp"

class ServerConfigManager {

    using GatewayInfoMap_t = NS_MZ_SHARE::Map<int, ServerInfo>;

private:
    ServerConfig m_loginConfig;
    ServerConfig m_masterConfig;
    ServerConfig m_gatewayConfig;
    ServerConfig m_zoneConfig;
    GatewayInfoMap_t m_gatewayInfoMap;

public:
    ServerConfigManager();

    ~ServerConfigManager();

public:
    void Initialize();

    void Finalize();

    ServerConfig& GetLoginConfig();

    ServerConfig& GetMasterConfig();

    ServerConfig& GetGatewayConfig();

    ServerConfig& GetZoneConfig();

    int GetGatewayInfoSize() const;
    ServerInfo* GetGatewayInfo(int id);
    const GatewayInfoMap_t& GetAllGatewayInfo() const;
    void AddGatewayInfo(const ServerInfo& gatewayInfo);
    void RemoveGatewayInfo(int id);
    void RemoveAllGatewayInfo();

private:
    void LoadLoginConfig();
    void LoadMasterConfig();
    void LoadGatewayConfig();
    void LoadZoneConfig();
    void LoadGatewayList();
};

#endif // _MASTERSERVER_SERVERCONFIGMANAGER_HPP_

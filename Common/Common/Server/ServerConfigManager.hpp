#ifndef _MASTERSERVER_SERVERCONFIGMANAGER_HPP_
#define _MASTERSERVER_SERVERCONFIGMANAGER_HPP_

#include <Metazion/Share/Collection/Map.hpp>

#include "Common/Struct.hpp"

class ServerConfigManager {
    using GatewayConfigMap_t = NS_MZ_SHARE::Map<int, GatewayConfig>;
    using ZoneConfigMap_t = NS_MZ_SHARE::Map<int, ZoneConfig>;

public:
    ServerConfigManager();

    ~ServerConfigManager();

public:
    void Initialize();

    void Finalize();

    LoginConfig& GetLoginConfig();

    MasterConfig& GetMasterConfig();

    int GetGatewayConfigSize() const;
    GatewayConfig* GetGatewayConfig(int id);
    const GatewayConfigMap_t& GetAllGatewayConfig() const;
    void AddGatewayConfig(const GatewayConfig& gatewayConfig);
    void RemoveGatewayConfig(int id);
    void RemoveAllGatewayConfig();

    int GetZoneConfigSize() const;
    ZoneConfig* GetZoneConfig(int id);
    const ZoneConfigMap_t& GetAllZoneConfig() const;
    void AddZoneConfig(const ZoneConfig& gatewayConfig);
    void RemoveZoneConfig(int id);
    void RemoveAllZoneConfig();

private:
    void LoadLoginConfig();
    void LoadMasterConfig();
    void LoadGatewayConfig();
    void LoadZoneConfig();

private:
    LoginConfig m_loginConfig;
    MasterConfig m_masterConfig;
    GatewayConfigMap_t m_gatewayConfigMap;
    ZoneConfigMap_t m_zoneConfigMap;
};

#endif // _MASTERSERVER_SERVERCONFIGMANAGER_HPP_

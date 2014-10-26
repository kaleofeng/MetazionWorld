#include "ServerConfigManager.hpp"

#include <Metazion/Net/Host.hpp>

ServerConfigManager::ServerConfigManager() {}

ServerConfigManager::~ServerConfigManager() {}

void ServerConfigManager::Initialize() {
   LoadLoginConfig();
   LoadMasterConfig();
   LoadGatewayConfig();
   LoadZoneConfig();
}

void ServerConfigManager::Finalize() {
    m_gatewayConfigMap.Clear();
    m_zoneConfigMap.Clear();
}

LoginConfig& ServerConfigManager::GetLoginConfig() {
    return m_loginConfig;
}

MasterConfig& ServerConfigManager::GetMasterConfig() {
    return m_masterConfig;
}

int ServerConfigManager::GetGatewayConfigSize() const {
    return m_gatewayConfigMap.GetSize();
}

GatewayConfig* ServerConfigManager::GetGatewayConfig(int id) {
    auto iter = m_gatewayConfigMap.Find(id);
    if (iter != m_gatewayConfigMap.End()) {
        return &iter->second;
    }
    return nullptr;
}

const ServerConfigManager::GatewayConfigMap_t& ServerConfigManager::GetAllGatewayConfig() const {
    return m_gatewayConfigMap;
}

void ServerConfigManager::AddGatewayConfig(const GatewayConfig& gatewayConfig) {
    m_gatewayConfigMap.Insert(gatewayConfig.m_id, gatewayConfig);
}

void ServerConfigManager::RemoveGatewayConfig(int id) {
    auto iter = m_gatewayConfigMap.Find(id);
    if (iter != m_gatewayConfigMap.End()) {
        m_gatewayConfigMap.Erase(iter);
    }
}

void ServerConfigManager::RemoveAllGatewayConfig() {
    m_gatewayConfigMap.Clear();
}

int ServerConfigManager::GetZoneConfigSize() const {
    return m_zoneConfigMap.GetSize();
}

ZoneConfig* ServerConfigManager::GetZoneConfig(int id) {
    auto iter = m_zoneConfigMap.Find(id);
    if (iter != m_zoneConfigMap.End()) {
        return &iter->second;
    }
    return nullptr;
}

const ServerConfigManager::ZoneConfigMap_t& ServerConfigManager::GetAllZoneConfig() const {
    return m_zoneConfigMap;
}

void ServerConfigManager::AddZoneConfig(const ZoneConfig& zoneConfig) {
    m_zoneConfigMap.Insert(zoneConfig.m_id, zoneConfig);
}

void ServerConfigManager::RemoveZoneConfig(int id) {
    auto iter = m_zoneConfigMap.Find(id);
    if (iter != m_zoneConfigMap.End()) {
        m_zoneConfigMap.Erase(iter);
    }
}

void ServerConfigManager::RemoveAllZoneConfig() {
    m_zoneConfigMap.Clear();
}

void ServerConfigManager::LoadLoginConfig() {
    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);
    publicHost.SetIp("192.168.1.101");
    publicHost.SetPort(21001);

    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);
    privateHost.SetIp("192.168.1.101");
    privateHost.SetPort(21002);

    m_loginConfig.m_publicAddress = publicHost.ToAddress();
    m_loginConfig.m_privateAddress = privateHost.ToAddress();
}

void ServerConfigManager::LoadMasterConfig() {
    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);
    publicHost.SetIp("192.168.1.101");
    publicHost.SetPort(23001);
    
    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);
    privateHost.SetIp("192.168.1.101");
    privateHost.SetPort(23002);

    m_masterConfig.m_publicAddress = publicHost.ToAddress();
    m_masterConfig.m_privateAddress = privateHost.ToAddress();
}

void ServerConfigManager::LoadGatewayConfig() {
    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);
    publicHost.SetIp("192.168.1.101");
    publicHost.SetPort(22001);

    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);
    privateHost.SetIp("192.168.1.101");
    privateHost.SetPort(22002);

    GatewayConfig gatewayConfig;
    gatewayConfig.m_id = 1;
    gatewayConfig.m_publicAddress = publicHost.ToAddress();
    gatewayConfig.m_privateAddress = privateHost.ToAddress();

    AddGatewayConfig(gatewayConfig);
}

void ServerConfigManager::LoadZoneConfig() {
    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);
    publicHost.SetIp("192.168.1.101");
    publicHost.SetPort(24001);

    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);
    privateHost.SetIp("192.168.1.101");
    privateHost.SetPort(24002);

    ZoneConfig zoneConfig;
    zoneConfig.m_id = 1;
    zoneConfig.m_publicAddress = publicHost.ToAddress();
    zoneConfig.m_privateAddress = privateHost.ToAddress();

    AddZoneConfig(zoneConfig);
}
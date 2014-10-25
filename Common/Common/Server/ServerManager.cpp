#include "ServerManager.hpp"

#include <Metazion/Net/Host.hpp>

ServerManager::ServerManager() {}

ServerManager::~ServerManager() {}

void ServerManager::Initialize() {
   LoadLoginInfo();
   LoadMasterInfo();
   LoadGatewayInfo();
   LoadZoneInfo();
}

void ServerManager::Finalize() {
    m_gatewayInfoMap.Clear();
    m_zoneInfoMap.Clear();
}

MasterInfo& ServerManager::GetMasterInfo() {
    return m_masterInfo;
}

LoginInfo& ServerManager::GetLoginInfo() {
    return m_loginInfo;
}

int ServerManager::GetGatewayInfoSize() const {
    return m_gatewayInfoMap.GetSize();
}

GatewayInfo* ServerManager::GetGatewayInfo(int id) {
    auto iter = m_gatewayInfoMap.Find(id);
    if (iter != m_gatewayInfoMap.End()) {
        return &iter->second;
    }
    return nullptr;
}

const ServerManager::GatewayInfoMap_t& ServerManager::GetAllGatewayInfo() const {
    return m_gatewayInfoMap;
}

void ServerManager::AddGatewayInfo(const GatewayInfo& gatewayInfo) {
    m_gatewayInfoMap.Insert(gatewayInfo.m_id, gatewayInfo);
}

void ServerManager::RemoveGatewayInfo(int id) {
    auto iter = m_gatewayInfoMap.Find(id);
    if (iter != m_gatewayInfoMap.End()) {
        m_gatewayInfoMap.Erase(iter);
    }
}

void ServerManager::RemoveAllGatewayInfo() {
    m_gatewayInfoMap.Clear();
}

int ServerManager::GetZoneInfoSize() const {
    return m_zoneInfoMap.GetSize();
}

ZoneInfo* ServerManager::GetZoneInfo(int id) {
    auto iter = m_zoneInfoMap.Find(id);
    if (iter != m_zoneInfoMap.End()) {
        return &iter->second;
    }
    return nullptr;
}

const ServerManager::ZoneInfoMap_t& ServerManager::GetAllZoneInfo() const {
    return m_zoneInfoMap;
}

void ServerManager::AddZoneInfo(const ZoneInfo& zoneInfo) {
    m_zoneInfoMap.Insert(zoneInfo.m_id, zoneInfo);
}

void ServerManager::RemoveZoneInfo(int id) {
    auto iter = m_zoneInfoMap.Find(id);
    if (iter != m_zoneInfoMap.End()) {
        m_zoneInfoMap.Erase(iter);
    }
}

void ServerManager::RemoveAllZoneInfo() {
    m_zoneInfoMap.Clear();
}

void ServerManager::LoadLoginInfo() {
    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);
    publicHost.SetIp("192.168.1.101");
    publicHost.SetPort(21001);

    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);
    privateHost.SetIp("192.168.1.101");
    privateHost.SetPort(21002);

    m_loginInfo.m_publicAddress = publicHost.ToAddress();
    m_loginInfo.m_privateAddress = privateHost.ToAddress();
}

void ServerManager::LoadMasterInfo() {
    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);
    publicHost.SetIp("192.168.1.101");
    publicHost.SetPort(23001);
    
    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);
    privateHost.SetIp("192.168.1.101");
    privateHost.SetPort(23002);

    m_masterInfo.m_publicAddress = publicHost.ToAddress();
    m_masterInfo.m_privateAddress = privateHost.ToAddress();
}

void ServerManager::LoadGatewayInfo() {
    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);
    publicHost.SetIp("192.168.1.101");
    publicHost.SetPort(22001);

    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);
    privateHost.SetIp("192.168.1.101");
    privateHost.SetPort(22002);

    GatewayInfo gatewayInfo;
    gatewayInfo.m_id = 1;
    gatewayInfo.m_publicAddress = publicHost.ToAddress();
    gatewayInfo.m_privateAddress = privateHost.ToAddress();

    AddGatewayInfo(gatewayInfo);
}

void ServerManager::LoadZoneInfo() {
    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);
    publicHost.SetIp("192.168.1.101");
    publicHost.SetPort(24001);

    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);
    privateHost.SetIp("192.168.1.101");
    privateHost.SetPort(24002);

    ZoneInfo zoneInfo;
    zoneInfo.m_id = 1;
    zoneInfo.m_publicAddress = publicHost.ToAddress();
    zoneInfo.m_privateAddress = privateHost.ToAddress();

    AddZoneInfo(zoneInfo);
}
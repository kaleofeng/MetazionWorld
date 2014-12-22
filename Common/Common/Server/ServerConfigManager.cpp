#include "ServerConfigManager.hpp"

#include <Metazion/Net/Host.hpp>

#include "Common/Xml/rapidxml.hpp"
#include "Common/Xml/rapidxml_utils.hpp"

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
    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);

    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);

    rapidxml::file<> file("../Resources/Config/LoginList.xml");
    auto data = file.data();

    rapidxml::xml_document<> doc;
    doc.parse<0>(data);
    auto docName = doc.name();

    rapidxml::xml_node<>* root = doc.first_node();
    auto rootName = root->name();

    auto node = root->first_node("Login");
    if (!NS_MZ::IsNull(node)) {
        auto idAttr = node->first_attribute("id");
        auto privateIpAttr = node->first_attribute("privateIp");
        auto privatePortAttr = node->first_attribute("privatePort");
        auto publicIpAttr = node->first_attribute("publicIp");
        auto publicPortAttr = node->first_attribute("publicPort");

        const auto szId = idAttr->value();
        const auto szPrivateIp = privateIpAttr->value();
        const auto szPrivatePort = privatePortAttr->value();
        const auto szPublicIp = publicIpAttr->value();
        const auto szPublicPort = publicPortAttr->value();

        const auto id = atoi(szId);
        const auto privatePort = atoi(szPrivatePort);
        const auto publicPort = atoi(szPublicPort);

        privateHost.SetIp(szPrivateIp);
        privateHost.SetPort(privatePort);

        publicHost.SetIp(szPublicIp);
        publicHost.SetPort(publicPort);

        m_loginConfig.m_id = id;
        m_loginConfig.m_privateAddress = privateHost.ToAddress();
        m_loginConfig.m_publicAddress = publicHost.ToAddress();
    }
}

void ServerConfigManager::LoadMasterConfig() {
    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);

    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);

    rapidxml::file<> file("../Resources/Config/MasterList.xml");
    auto data = file.data();

    rapidxml::xml_document<> doc;
    doc.parse<0>(data);
    auto docName = doc.name();

    rapidxml::xml_node<>* root = doc.first_node();
    auto rootName = root->name();

    auto node = root->first_node("Master");
    if (!NS_MZ::IsNull(node)) {
        auto idAttr = node->first_attribute("id");
        auto privateIpAttr = node->first_attribute("privateIp");
        auto privatePortAttr = node->first_attribute("privatePort");
        auto publicIpAttr = node->first_attribute("publicIp");
        auto publicPortAttr = node->first_attribute("publicPort");

        const auto szId = idAttr->value();
        const auto szPrivateIp = privateIpAttr->value();
        const auto szPrivatePort = privatePortAttr->value();
        const auto szPublicIp = publicIpAttr->value();
        const auto szPublicPort = publicPortAttr->value();

        const auto id = atoi(szId);
        const auto privatePort = atoi(szPrivatePort);
        const auto publicPort = atoi(szPublicPort);

        privateHost.SetIp(szPrivateIp);
        privateHost.SetPort(privatePort);

        publicHost.SetIp(szPublicIp);
        publicHost.SetPort(publicPort);

        m_masterConfig.m_id = id;
        m_masterConfig.m_privateAddress = privateHost.ToAddress();
        m_masterConfig.m_publicAddress = publicHost.ToAddress();
    }
}

void ServerConfigManager::LoadGatewayConfig() {
    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);

    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);

    rapidxml::file<> file("../Resources/Config/GatewayList.xml");
    auto data = file.data();

    rapidxml::xml_document<> doc;
    doc.parse<0>(data);
    auto docName = doc.name();

    rapidxml::xml_node<>* root = doc.first_node();
    auto rootName = root->name();

    for (auto node = root->first_node("Gateway")
        ; !NS_MZ::IsNull(node); node = node->next_sibling()) {
        auto idAttr = node->first_attribute("id");
        auto privateIpAttr = node->first_attribute("privateIp");
        auto privatePortAttr = node->first_attribute("privatePort");
        auto publicIpAttr = node->first_attribute("publicIp");
        auto publicPortAttr = node->first_attribute("publicPort");

        const auto szId = idAttr->value();
        const auto szPrivateIp = privateIpAttr->value();
        const auto szPrivatePort = privatePortAttr->value();
        const auto szPublicIp = publicIpAttr->value();
        const auto szPublicPort = publicPortAttr->value();

        const auto id = atoi(szId);
        const auto privatePort = atoi(szPrivatePort);
        const auto publicPort = atoi(szPublicPort);

        privateHost.SetIp(szPrivateIp);
        privateHost.SetPort(privatePort);

        publicHost.SetIp(szPublicIp);
        publicHost.SetPort(publicPort);

        GatewayConfig config;
        config.m_id = id;
        config.m_privateAddress = privateHost.ToAddress();
        config.m_publicAddress = publicHost.ToAddress();
        AddGatewayConfig(config);
    }
}

void ServerConfigManager::LoadZoneConfig() {
    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);

    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);

    rapidxml::file<> file("../Resources/Config/ZoneList.xml");
    auto data = file.data();

    rapidxml::xml_document<> doc;
    doc.parse<0>(data);
    auto docName = doc.name();

    rapidxml::xml_node<>* root = doc.first_node();
    auto rootName = root->name();

    for (auto node = root->first_node("Zone")
        ; !NS_MZ::IsNull(node); node = node->next_sibling()) {
        auto idAttr = node->first_attribute("id");
        auto privateIpAttr = node->first_attribute("privateIp");
        auto privatePortAttr = node->first_attribute("privatePort");
        auto publicIpAttr = node->first_attribute("publicIp");
        auto publicPortAttr = node->first_attribute("publicPort");

        const auto szId = idAttr->value();
        const auto szPrivateIp = privateIpAttr->value();
        const auto szPrivatePort = privatePortAttr->value();
        const auto szPublicIp = publicIpAttr->value();
        const auto szPublicPort = publicPortAttr->value();

        const auto id = atoi(szId);
        const auto privatePort = atoi(szPrivatePort);
        const auto publicPort = atoi(szPublicPort);

        privateHost.SetIp(szPrivateIp);
        privateHost.SetPort(privatePort);

        publicHost.SetIp(szPublicIp);
        publicHost.SetPort(publicPort);

        ZoneConfig config;
        config.m_id = id;
        config.m_privateAddress = privateHost.ToAddress();
        config.m_publicAddress = publicHost.ToAddress();
        AddZoneConfig(config);
    }
}
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
   LoadGatewayList();
}

void ServerConfigManager::Finalize() {}

ServerConfig& ServerConfigManager::GetLoginConfig() {
    return m_loginConfig;
}

ServerConfig& ServerConfigManager::GetMasterConfig() {
    return m_masterConfig;
}

ServerConfig& ServerConfigManager::GetGatewayConfig() {
    return m_gatewayConfig;
}

ServerConfig& ServerConfigManager::GetZoneConfig() {
    return m_zoneConfig;
}

int ServerConfigManager::GetGatewayInfoSize() const {
    return m_gatewayInfoMap.GetSize();
}

ServerInfo* ServerConfigManager::GetGatewayInfo(int id) {
    auto iter = m_gatewayInfoMap.Find(id);
    if (iter != m_gatewayInfoMap.End()) {
        return &iter->second;
    }
    return nullptr;
}

const ServerConfigManager::GatewayInfoMap_t& ServerConfigManager::GetAllGatewayInfo() const {
    return m_gatewayInfoMap;
}

void ServerConfigManager::AddGatewayInfo(const ServerInfo& gatewayInfo) {
    m_gatewayInfoMap.Insert(gatewayInfo.m_id, gatewayInfo);
}

void ServerConfigManager::RemoveGatewayInfo(int id) {
    auto iter = m_gatewayInfoMap.Find(id);
    if (iter != m_gatewayInfoMap.End()) {
        m_gatewayInfoMap.Erase(iter);
    }
}

void ServerConfigManager::RemoveAllGatewayInfo() {
    m_gatewayInfoMap.Clear();
}

void ServerConfigManager::LoadLoginConfig() {
    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);

    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);

    rapidxml::file<> file("../Resources/Config/ServerConfig.xml");
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

    rapidxml::file<> file("../Resources/Config/ServerConfig.xml");
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

    rapidxml::file<> file("../Resources/Config/ServerConfig.xml");
    auto data = file.data();

    rapidxml::xml_document<> doc;
    doc.parse<0>(data);
    auto docName = doc.name();

    rapidxml::xml_node<>* root = doc.first_node();
    auto rootName = root->name();

    auto node = root->first_node("Gateway");
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

        m_gatewayConfig.m_id = id;
        m_gatewayConfig.m_privateAddress = privateHost.ToAddress();
        m_gatewayConfig.m_publicAddress = publicHost.ToAddress();
    }
}

void ServerConfigManager::LoadZoneConfig() {
    NS_MZ_NET::Host privateHost;
    privateHost.SetFamily(AF_INET);

    NS_MZ_NET::Host publicHost;
    publicHost.SetFamily(AF_INET);

    rapidxml::file<> file("../Resources/Config/ServerConfig.xml");
    auto data = file.data();

    rapidxml::xml_document<> doc;
    doc.parse<0>(data);
    auto docName = doc.name();

    rapidxml::xml_node<>* root = doc.first_node();
    auto rootName = root->name();

    auto node = root->first_node("Zone");
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

        m_zoneConfig.m_id = id;
        m_zoneConfig.m_privateAddress = privateHost.ToAddress();
        m_zoneConfig.m_publicAddress = publicHost.ToAddress();
    }
}

void ServerConfigManager::LoadGatewayList() {
    NS_MZ_NET::Host host;
    host.SetFamily(AF_INET);

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
        auto ipAttr = node->first_attribute("ip");
        auto portAttr = node->first_attribute("port");

        const auto szId = idAttr->value();
        const auto szIp = ipAttr->value();
        const auto szPort = portAttr->value();

        const auto id = atoi(szId);
        const auto port = atoi(szPort);

        host.SetIp(szIp);
        host.SetPort(port);

        ServerInfo serverInfo;
        serverInfo.m_id = id;
        serverInfo.m_address = host.ToAddress();
        AddGatewayInfo(serverInfo);
    }
}
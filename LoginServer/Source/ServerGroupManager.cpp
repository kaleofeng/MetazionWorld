#include "ServerGroupManager.hpp"

#include <Common/Xml/rapidxml.hpp>
#include <Common/Xml/rapidxml_utils.hpp>

ServerGroupManager::ServerGroupManager() {}

ServerGroupManager::~ServerGroupManager() {}

void ServerGroupManager::Initialize() {
    LoadAllServerGroup();
}

void ServerGroupManager::Finalize() {
    RemoveAllServerGroup();
}

int ServerGroupManager::GetServerGroupSize() const {
    return m_serverGroupMap.GetSize();
}

ServerGroup* ServerGroupManager::GetServerGroup(int id) {
    auto iter = m_serverGroupMap.Find(id);
    if (iter != m_serverGroupMap.End()) {
        return &iter->second;
    }
    return nullptr;
}

const ServerGroupManager::ServerGroupMap_t& ServerGroupManager::GetAllServerGroup() const {
    return m_serverGroupMap;
}

void ServerGroupManager::AddServerGroup(const ServerGroup& serverGroup) {
    m_serverGroupMap.Insert(serverGroup.GetId(), serverGroup);
}

void ServerGroupManager::RemoveServerGroup(int id) {
    auto iter = m_serverGroupMap.Find(id);
    if (iter != m_serverGroupMap.End()) {
        m_serverGroupMap.Erase(iter);
    }
}

void ServerGroupManager::RemoveAllServerGroup() {
    m_serverGroupMap.Clear();
}

void ServerGroupManager::LoadAllServerGroup() {
    NS_MZ_NET::Host host;
    host.SetFamily(AF_INET);

    rapidxml::file<> file("Resources/Config/ServerGroupList.xml");
    auto data = file.data();

    rapidxml::xml_document<> doc;
    doc.parse<0>(data);
    auto docName = doc.name();

    rapidxml::xml_node<>* root = doc.first_node();
    auto rootName = root->name();

    for (auto node = root->first_node("ServerGroup")
        ; !NS_MZ::IsNull(node); node = node->next_sibling()) {
        auto idAttr = node->first_attribute("id");
        auto nameAttr = node->first_attribute("name");
        auto ipAttr = node->first_attribute("ip");
        auto portAttr = node->first_attribute("port");
       
        const auto szId = idAttr->value();
        const auto szName = nameAttr->value();
        const auto szIp = ipAttr->value();
        const auto szPort = portAttr->value();

        const auto id = atoi(szId);
        const auto port = atoi(szPort);
        
        host.SetIp(szIp);
        host.SetPort(port);

        ServerGroup serverGroup;
        serverGroup.SetId(id);
        serverGroup.SetName(szName);
        serverGroup.SetPublicAddress(host.ToAddress());
        serverGroup.SetStatus(0);
        AddServerGroup(serverGroup);
    }
}
#include "UserGroup.h"
#include <iostream>

UserGroup::UserGroup(const std::string& groupName) : groupName(groupName) {}

void UserGroup::addUser(User* user) {
    members.push_back(user);
    std::cout << "User " << user->getName() << " has been added to group " << groupName << ".\n";
}

void UserGroup::removeUser(User* user) {
    auto it = std::remove(members.begin(), members.end(), user);
    if (it != members.end()) {
        members.erase(it, members.end());
        std::cout << "User " << user->getName() << " has been removed from group " << groupName << ".\n";
    }
}

void UserGroup::listMembers() const {
    std::cout << "Members of group " << groupName << ":\n";
    for (const auto& member : members) {
        std::cout << "- " << member->getName() << "\n";
    }
}

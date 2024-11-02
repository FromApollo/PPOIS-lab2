#include "SecuritySystem.h"
#include <iostream>

void SecuritySystem::addUser(User* user, const std::string& password) {
    passwords[user] = password;
    std::cout << "User " << user->getName() << " has been added to the security system.\n";
}

bool SecuritySystem::checkPassword(User* user, const std::string& password) const {
    auto it = passwords.find(user);
    if (it != passwords.end() && it->second == password) {
        return true;
    }
    return false;
}

void SecuritySystem::changePassword(User* user, const std::string& newPassword) {
    if (passwords.find(user) != passwords.end()) {
        passwords[user] = newPassword;
        std::cout << "Password for user " << user->getName() << " has been changed.\n";
    }
}

void SecuritySystem::setAccessRights(User* user, Document* document, const std::string& rights) {
    accessRights[user][document] = rights;
    std::cout << "Access rights for user " << user->getName() << " on document " << document->getTitle() << " set to "
        << rights << ".\n";
}

std::string SecuritySystem::getAccessRights(User* user, Document* document) const {
    auto userRights = accessRights.find(user);
    if (userRights != accessRights.end()) {
        auto docRights = userRights->second.find(document);
        if (docRights != userRights->second.end()) {
            return docRights->second;
        }
    }
    return "No access rights.";
}

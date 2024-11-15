#include "AccessRights.h"
#include <iostream>

AccessRights::AccessRights(User* user, Document* document, const std::string& accessLevel)
    : user(user), document(document), accessLevel(accessLevel) {}

bool AccessRights::checkAccess() const {
    if (accessLevel == "admin") {
        std::cout << "You are an admin, you can read, write, and perform administrative actions." << std::endl;
        return true;
    }
    else if (accessLevel == "write") {
        std::cout << "You are a writer, you can read and write." << std::endl;
        return true;
    }
    else if (accessLevel == "read") {
        std::cout << "You are a reader, you can only read." << std::endl;
        return true;
    }
    else {
        std::cout << "Access denied: you have no permissions." << std::endl;
        return false;
    }
}

void AccessRights::assignAccess(const std::string& newAccessLevel) {
    accessLevel = newAccessLevel;
    std::cout << "Access level for user " << user->getName() << " on document "
        << document->getTitle() << " has been changed to " << accessLevel << ".\n";
}

std::string AccessRights::getAccessLevel() const {
    return accessLevel;
}

User* AccessRights::getUser() const {
    return user;
}

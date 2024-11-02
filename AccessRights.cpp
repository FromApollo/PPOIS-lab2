#include "AccessRights.h"
#include <iostream>

AccessRights::AccessRights(User* user, Document* document, const std::string& accessLevel)
    : user(user), document(document), accessLevel(accessLevel) {}

bool AccessRights::checkAccess() const {

    if (accessLevel == "admin" || accessLevel == "write" || accessLevel == "read") {
        return true;
    }
    return false;
}

void AccessRights::assignAccess(const std::string& newAccessLevel) {
    accessLevel = newAccessLevel;
    std::cout << "Access level for user " << user->getName() << " on document "
        << document->getTitle() << " has been changed to " << accessLevel << ".\n";
}

std::string AccessRights::getAccessLevel() const {
    return accessLevel;
}

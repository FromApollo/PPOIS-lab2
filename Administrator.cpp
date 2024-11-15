#include "Administrator.h"
#include <iostream>
#include "AccessRights.h"

Administrator::Administrator(int id, const std::string& name, const std::string& email, const std::string& password,
    int accessLevel)
    : User(id, name, email, password), accessLevel(accessLevel) {}


void Administrator::changeUserPermissions(AccessRights& accessRights, const std::string& newAccessLevel) {
    std::string currentAccessLevel = accessRights.getAccessLevel();
    std::cout << "Current access level for user " << accessRights.getUser()->getName() << ": " << currentAccessLevel
        << std::endl;

    accessRights.assignAccess(newAccessLevel);
    std::cout << "Administrator " << name << " changed access level to " << newAccessLevel << ".\n";
}


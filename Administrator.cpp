#include "Administrator.h"
#include <iostream>

Administrator::Administrator(int id, const std::string& name, const std::string& email, const std::string& password, int accessLevel)
    : User(id, name, email, password), accessLevel(accessLevel) {}

void Administrator::addUser(const User& user) {
    std::cout << "User " << user.getName() << " has been added by administrator " << name << ".\n";
}

void Administrator::deleteUser(const User& user) {
    std::cout << "User " << user.getName() << " has been deleted by administrator " << name << ".\n";
}

void Administrator::changeUserPermissions(User& user, int newPermissions) {
    std::cout << "Administrator " << name << " changed permissions for user " << user.getName()
        << " to level " << newPermissions << ".\n";
}

#include "SecuritySystem.h"
#include "User.h"

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

bool SecuritySystem::login(User* user, const std::string& enteredPassword) const {
    if (checkPassword(user, enteredPassword)) {
        std::cout << "User " << user->getName() << " logged in successfully.\n";
        return true;
    }
    else {
        std::cout << "Incorrect password for user " << user->getName() << ".\n";
        return false;
    }
}

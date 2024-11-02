#include "User.h"
#include <iostream>

User::User(int id, const std::string& name, const std::string& email, const std::string& password)
    : id(id), name(name), email(email), password(password) {}

bool User::login(const std::string& enteredPassword) const {
    if (enteredPassword == password) {
        std::cout << "User " << name << " logged in successfully.\n";
        return true;
    }
    else {
        std::cout << "Incorrect password for user " << name << ".\n";
        return false;
    }
}

void User::logout() const {
    std::cout << "User " << name << " logged out.\n";
}

std::string User::getName() const {
    return name;
}

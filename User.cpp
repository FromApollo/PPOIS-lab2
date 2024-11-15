#include "User.h"
#include<iostream>

User::User(int id, const std::string& name, const std::string& email, const std::string& password)
    : id(id), name(name), email(email), password(password) {}

std::string User::getName() const {
    return name;
}

void User::displayInfo() const {
    std::cout << "User ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Email: " << email << std::endl;
}
#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "User.h"
#include "Document.h"
#include <map>
#include <string>
#include <iostream>

class SecuritySystem {
private:
    std::map<User*, std::string> passwords;
    std::map<User*, std::map<Document*, std::string>> accessRights;

public:
    void addUser(User* user, const std::string& password);

    bool checkPassword(User* user, const std::string& password) const;

    void changePassword(User* user, const std::string& newPassword);


    bool login(User* user, const std::string& enteredPassword) const;
};

#endif 
#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "User.h"
#include "Document.h"
#include <map>
#include <string>

class SecuritySystem {
private:
    std::map<User*, std::string> passwords;
    std::map<User*, std::map<Document*, std::string>> accessRights;

public:
    void addUser(User* user, const std::string& password);

    bool checkPassword(User* user, const std::string& password) const;

    void changePassword(User* user, const std::string& newPassword);

    void setAccessRights(User* user, Document* document, const std::string& rights);

    std::string getAccessRights(User* user, Document* document) const;
};

#endif 

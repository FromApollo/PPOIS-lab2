#ifndef ACCESSRIGHTS_H
#define ACCESSRIGHTS_H

#include "User.h"
#include "Document.h"
#include <string>

class AccessRights {
public:
    AccessRights(User* user, Document* document, const std::string& accessLevel);

    bool checkAccess() const;

    void assignAccess(const std::string& newAccessLevel);

    std::string getAccessLevel() const;

    User* getUser() const;

private:
    User* user;
    Document* document;
    std::string accessLevel;
};

#endif 
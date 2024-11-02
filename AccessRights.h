#ifndef ACCESSRIGHTS_H
#define ACCESSRIGHTS_H

#include "User.h"
#include "Document.h"

class AccessRights {
private:
    User* user;
    Document* document;
    std::string accessLevel;

public:
    AccessRights(User* user, Document* document, const std::string& accessLevel);

    bool checkAccess() const;

    void assignAccess(const std::string& newAccessLevel);

    std::string getAccessLevel() const;
};

#endif 

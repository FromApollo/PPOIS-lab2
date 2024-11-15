#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include "AccessRights.h"
#include <string>

class Administrator : public User {
public:
    Administrator(int id, const std::string& name, const std::string& email, const std::string& password,
        int accessLevel);


    void changeUserPermissions(AccessRights& accessRights, const std::string& newAccessLevel);

private:
    int accessLevel;
};

#endif 
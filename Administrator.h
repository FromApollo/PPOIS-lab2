#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include <string>

class Administrator : public User {
private:
    int accessLevel;

public:
    Administrator(int id, const std::string& name, const std::string& email, const std::string& password,
        int accessLevel);

    void addUser(const User& user);

    void deleteUser(const User& user);

    void changeUserPermissions(User& user, int newPermissions);
};

#endif 

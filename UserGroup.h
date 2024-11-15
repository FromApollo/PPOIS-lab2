#ifndef USERGROUP_H
#define USERGROUP_H

#include "User.h"
#include <string>
#include <vector>

class UserGroup {
private:
    std::string groupName;
    std::vector<User*> members;

public:
    UserGroup(const std::string& groupName);

    void addUser(User* user);

    void removeUser(User* user);

    void listMembers() const;
};

#endif 
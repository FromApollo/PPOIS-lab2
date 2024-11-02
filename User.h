#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    int id;
    std::string name;
    std::string email;
    std::string password;

public:
    User(int id, const std::string& name, const std::string& email, const std::string& password);

    virtual ~User() = default;

    bool login(const std::string& enteredPassword) const;

    void logout() const;

    std::string getName() const;
};

#endif 

#include "pch.h"
#include "D:/BSUIR/3 semester/PPOIS/lab2/Project1/Project1/Administrator.h"
#include "D:/BSUIR/3 semester/PPOIS/lab2/Project1/Project1/User.h"
#include "D:/BSUIR/3 semester/PPOIS/lab2/Project1/Project1/Document.h"
#include "D:/BSUIR/3 semester/PPOIS/lab2/Project1/Project1/AccessRights.h"

class MockUser : public User {
public:
    MockUser(int id, const std::string& name, const std::string& email, const std::string& password)
        : User(id, name, email, password) {}
};

class MockDocument : public Document {
public:
    MockDocument(int id, const std::string& title, const std::string& content, const std::string& creationDate)
        : Document(id, title, content, creationDate) {}
};

class AdministratorTest : public ::testing::Test {
protected:
    Administrator* admin;
    MockUser* user;
    MockDocument* document;
    AccessRights* accessRights;

    void SetUp() override {
        admin = new Administrator(1, "Admin", "admin@example.com", "admin123", 5);
        user = new MockUser(2, "Jane Smith", "jane@example.com", "password456");
        document = new MockDocument(2, "User Document", "User document content.", "2024-01-01");
        accessRights = new AccessRights(user, document, "read");
    }

    void TearDown() override {
        delete accessRights;
        delete document;
        delete user;
        delete admin;
    }
};

TEST_F(AdministratorTest, ChangeUserPermissionsSuccessfully) {
    std::string newAccessLevel = "write";
    EXPECT_NO_THROW(admin->changeUserPermissions(*accessRights, newAccessLevel));
    EXPECT_EQ(accessRights->getAccessLevel(), newAccessLevel);
}

TEST_F(AdministratorTest, ChangeUserPermissionsWithInvalidLevel) {
    std::string newAccessLevel = "";
    EXPECT_NO_THROW(admin->changeUserPermissions(*accessRights, newAccessLevel));
    EXPECT_EQ(accessRights->getAccessLevel(), newAccessLevel);
}

TEST_F(AdministratorTest, CheckUserNameAfterChange) {
    std::string newAccessLevel = "write";
    admin->changeUserPermissions(*accessRights, newAccessLevel);
    EXPECT_EQ(accessRights->getUser()->getName(), "Jane Smith");
}

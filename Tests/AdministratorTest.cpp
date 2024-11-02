#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Administrator.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"

class MockUser : public User {
public:
    MockUser(int id, const std::string& name, const std::string& email, const std::string& password)
        : User(id, name, email, password) {}
};

class AdministratorTest : public ::testing::Test {
protected:
    Administrator* admin;
    MockUser* user;

    void SetUp() override {
        admin = new Administrator(1, "Admin", "admin@example.com", "admin123", 5);
        user = new MockUser(2, "User", "user@example.com", "user123");
    }

    void TearDown() override {
        delete admin;
        delete user;
    }
};

TEST_F(AdministratorTest, ConstructorTest) {
    EXPECT_EQ(admin->getName(), "Admin");
}

TEST_F(AdministratorTest, AddUserTest) {
    testing::internal::CaptureStdout();
    admin->addUser(*user);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "User User has been added by administrator Admin.\n");
}

TEST_F(AdministratorTest, DeleteUserTest) {
    testing::internal::CaptureStdout();
    admin->deleteUser(*user);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "User User has been deleted by administrator Admin.\n");
}

TEST_F(AdministratorTest, ChangeUserPermissionsTest) {
    testing::internal::CaptureStdout();
    admin->changeUserPermissions(*user, 3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Administrator Admin changed permissions for user User to level 3.\n");
}

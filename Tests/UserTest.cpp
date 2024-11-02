#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"

class UserTest : public ::testing::Test {
protected:
    User* user;

    void SetUp() override {
        user = new User(1, "Alice", "alice@example.com", "password123");
    }

    void TearDown() override {
        delete user;
    }
};

TEST_F(UserTest, LoginWithCorrectPassword) {
    testing::internal::CaptureStdout();
    bool result = user->login("password123");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(result);
    EXPECT_EQ(output, "User Alice logged in successfully.\n");
}

TEST_F(UserTest, LoginWithIncorrectPassword) {
    testing::internal::CaptureStdout();
    bool result = user->login("wrongpassword");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(result);
    EXPECT_EQ(output, "Incorrect password for user Alice.\n");
}

TEST_F(UserTest, Logout) {
    testing::internal::CaptureStdout();
    user->logout();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "User Alice logged out.\n");
}

TEST_F(UserTest, GetName) {
    EXPECT_EQ(user->getName(), "Alice");
}

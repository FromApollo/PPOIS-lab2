#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\SecuritySystem.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"

class MockDocument : public Document {
public:
    MockDocument(int id, const std::string& title, const std::string& content, const std::string& creationDate)
        : Document(id, title, content, creationDate) {}

    void view() const override {
        std::cout << "Viewing document: " << title << std::endl;
    }
};

class SecuritySystemTest : public ::testing::Test {
protected:
    SecuritySystem securitySystem;
    User* user;
    MockDocument* doc;

    void SetUp() override {
        user = new User(1, "Alice", "alice@example.com", "password123");
        doc = new MockDocument(1, "Test Document", "This is a test document.", "2024-11-11");
        securitySystem.addUser(user, "password123");
    }

    void TearDown() override {
        delete user;
        delete doc;
    }
};

TEST_F(SecuritySystemTest, AddUserAndCheckPassword) {
    EXPECT_TRUE(securitySystem.checkPassword(user, "password123"));
    EXPECT_FALSE(securitySystem.checkPassword(user, "wrongpassword"));
}

TEST_F(SecuritySystemTest, ChangePassword) {
    securitySystem.changePassword(user, "newpassword456");
    EXPECT_TRUE(securitySystem.checkPassword(user, "newpassword456"));
    EXPECT_FALSE(securitySystem.checkPassword(user, "password123"));
}

TEST_F(SecuritySystemTest, Login) {
    EXPECT_TRUE(securitySystem.login(user, "password123"));
    EXPECT_FALSE(securitySystem.login(user, "wrongpassword"));
}

TEST_F(SecuritySystemTest, FailedLogin) {
    securitySystem.addUser(user, "password123");
    EXPECT_FALSE(securitySystem.login(user, "wrongpassword"));
}


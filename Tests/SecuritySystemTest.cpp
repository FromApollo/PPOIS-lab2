#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\SecuritySystem.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"

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

class SecuritySystemTest : public ::testing::Test {
protected:
    SecuritySystem* securitySystem;
    MockUser* user;
    MockDocument* document;

    void SetUp() override {
        securitySystem = new SecuritySystem();
        user = new MockUser(1, "John Doe", "john@example.com", "password123");
        document = new MockDocument(1, "Test Document", "This is the content.", "2024-11-02");
    }

    void TearDown() override {
        delete securitySystem;
        delete user;
        delete document;
    }
};

TEST_F(SecuritySystemTest, AddUserAndCheckPassword) {
    securitySystem->addUser(user, "password123");
    EXPECT_TRUE(securitySystem->checkPassword(user, "password123"));
    EXPECT_FALSE(securitySystem->checkPassword(user, "wrongpassword"));
}

TEST_F(SecuritySystemTest, ChangePassword) {
    securitySystem->addUser(user, "password123");
    securitySystem->changePassword(user, "newpassword");
    EXPECT_TRUE(securitySystem->checkPassword(user, "newpassword"));
    EXPECT_FALSE(securitySystem->checkPassword(user, "password123"));
}

TEST_F(SecuritySystemTest, SetAndGetAccessRights) {
    securitySystem->addUser(user, "password123");
    securitySystem->setAccessRights(user, document, "read");
    EXPECT_EQ(securitySystem->getAccessRights(user, document), "read");
}

TEST_F(SecuritySystemTest, GetAccessRightsForNonExistentDocument) {
    securitySystem->addUser(user, "password123");
    MockDocument* anotherDocument = new MockDocument(2, "Another Document", "Content", "2024-11-02");
    EXPECT_EQ(securitySystem->getAccessRights(user, anotherDocument), "No access rights.");
    delete anotherDocument;
}

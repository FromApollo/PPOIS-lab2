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

class AccessRightsTest : public ::testing::Test {
protected:
    MockUser* user;
    MockDocument* document;
    AccessRights* accessRights;

    void SetUp() override {
        user = new MockUser(1, "John Doe", "john@example.com", "password123");
        document = new MockDocument(1, "Test Document", "This is a test document.", "2024-01-01");
        accessRights = new AccessRights(user, document, "read");     }

    void TearDown() override {
        delete accessRights;
        delete document;
        delete user;
    }
};

TEST_F(AccessRightsTest, CheckAccessReturnsTrue) {
    EXPECT_TRUE(accessRights->checkAccess());
}

TEST_F(AccessRightsTest, AssignAccessChangesAccessLevel) {
    accessRights->assignAccess("write");
    EXPECT_EQ(accessRights->getAccessLevel(), "write");
}

TEST_F(AccessRightsTest, GetUserReturnsCorrectUser) {
    EXPECT_EQ(accessRights->getUser()->getName(), "John Doe");
}

TEST_F(AccessRightsTest, OutputMessageForAdminAccess) {
    accessRights->assignAccess("admin");

    testing::internal::CaptureStdout();
    accessRights->checkAccess();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "You are an admin, you can read, write, and perform administrative actions.\n");
}

TEST_F(AccessRightsTest, OutputMessageForWriterAccess) {
    accessRights->assignAccess("write");

    testing::internal::CaptureStdout();
    accessRights->checkAccess();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You are a writer, you can read and write.\n");
}

TEST_F(AccessRightsTest, OutputMessageForReaderAccess) {
    accessRights->assignAccess("read");
    testing::internal::CaptureStdout();
    accessRights->checkAccess();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "You are a reader, you can only read.\n");
}

TEST_F(AccessRightsTest, OutputMessageForAccessDenied) {
    accessRights->assignAccess("no_access"); 
    testing::internal::CaptureStdout();
    bool result = accessRights->checkAccess();     std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(result);     EXPECT_EQ(output, "Access denied: you have no permissions.\n"); 
}

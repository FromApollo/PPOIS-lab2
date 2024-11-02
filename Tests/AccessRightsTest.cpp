#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\AccessRights.h"
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

TEST(AccessRightsTest, CheckAccess_AdminLevel) {
    MockUser user(1, "Alice", "alice@example.com", "password123");
    MockDocument document(1, "Project Plan", "Content of the project plan.", "2024-11-02");
    AccessRights accessRights(&user, &document, "admin");

    EXPECT_TRUE(accessRights.checkAccess());
}

TEST(AccessRightsTest, CheckAccess_WriteLevel) {
    MockUser user(2, "Bob", "bob@example.com", "password456");
    MockDocument document(2, "Draft Document", "Draft content.", "2024-11-02");
    AccessRights accessRights(&user, &document, "write");

    EXPECT_TRUE(accessRights.checkAccess());
}

TEST(AccessRightsTest, CheckAccess_ReadLevel) {
    MockUser user(3, "Charlie", "charlie@example.com", "password789");
    MockDocument document(3, "Confidential Report", "Confidential content.", "2024-11-02");
    AccessRights accessRights(&user, &document, "read");

    EXPECT_TRUE(accessRights.checkAccess());
}

TEST(AccessRightsTest, CheckAccess_NoAccess) {
    MockUser user(4, "David", "david@example.com", "password000");
    MockDocument document(4, "Unpublished Paper", "Unpublished content.", "2024-11-02");
    AccessRights accessRights(&user, &document, "none");

    EXPECT_FALSE(accessRights.checkAccess());
}

TEST(AccessRightsTest, AssignAccess_ChangeAccessLevel) {
    MockUser user(5, "Eve", "eve@example.com", "password111");
    MockDocument document(5, "Final Version", "Final content.", "2024-11-02");
    AccessRights accessRights(&user, &document, "read");

    accessRights.assignAccess("write");

    EXPECT_EQ(accessRights.getAccessLevel(), "write");
}

TEST(AccessRightsTest, GetAccessLevel) {
    MockUser user(6, "Frank", "frank@example.com", "password222");
    MockDocument document(6, "Meeting Notes", "Notes from the meeting.", "2024-11-02");
    AccessRights accessRights(&user, &document, "admin");

    EXPECT_EQ(accessRights.getAccessLevel(), "admin");
}

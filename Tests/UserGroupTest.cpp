#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\UserGroup.h"

class TestUser : public User {
public:
    TestUser(int id, const std::string& name, const std::string& email, const std::string& password)
        : User(id, name, email, password) {}
};

class UserGroupTest : public ::testing::Test {
protected:
    UserGroup* group;
    User* user1;
    User* user2;

    void SetUp() override {
        group = new UserGroup("Developers");
        user1 = new TestUser(1, "Alice", "alice@example.com", "password123");
        user2 = new TestUser(2, "Bob", "bob@example.com", "password456");
    }

    void TearDown() override {
        delete group;
        delete user1;
        delete user2;
    }
};

TEST_F(UserGroupTest, AddUser) {
    testing::internal::CaptureStdout();
    group->addUser(user1);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "User Alice has been added to group Developers.\n");
}

TEST_F(UserGroupTest, RemoveUser) {
    group->addUser(user1);
    group->addUser(user2);

    testing::internal::CaptureStdout();
    group->removeUser(user1);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "User Alice has been removed from group Developers.\n");
}

TEST_F(UserGroupTest, ListMembers) {
    group->addUser(user1);
    group->addUser(user2);

    testing::internal::CaptureStdout();
    group->listMembers();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "Members of group Developers:\n- Alice\n- Bob\n";
    EXPECT_EQ(output, expectedOutput);
}

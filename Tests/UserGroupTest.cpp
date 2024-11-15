#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\UserGroup.h"

class UserGroupTest : public ::testing::Test {
protected:
    UserGroup* userGroup;
    User* user1;
    User* user2;

    void SetUp() override {
        userGroup = new UserGroup("Test Group");
        user1 = new User(1, "Alice", "alice@example.com", "password123");
        user2 = new User(2, "Bob", "bob@example.com", "password456");
    }

    void TearDown() override {
        delete userGroup;
        delete user1;
        delete user2;
    }
};

TEST_F(UserGroupTest, AddUserTest) {
    userGroup->addUser(user1);
    std::ostringstream output;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(output.rdbuf()); 

    userGroup->listMembers();

    std::cout.rdbuf(originalCoutBuffer);
    std::string expectedOutput = "Members of group Test Group:\n- Alice\n";
    EXPECT_EQ(output.str(), expectedOutput);
}

TEST_F(UserGroupTest, RemoveUserTest) {
    userGroup->addUser(user1);
    userGroup->addUser(user2);

    std::ostringstream output;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(output.rdbuf()); 

    userGroup->removeUser(user1); 
    userGroup->listMembers(); 

    std::cout.rdbuf(originalCoutBuffer); 
    std::string expectedOutput = "User Alice has been removed from group Test Group.\nMembers of group Test Group:\n- Bob\n";
    EXPECT_EQ(output.str(), expectedOutput);
}

TEST_F(UserGroupTest, ListMembersEmptyGroup) {
    std::ostringstream output;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(output.rdbuf()); 

    userGroup->listMembers(); 

    std::cout.rdbuf(originalCoutBuffer); 
    std::string expectedOutput = "Members of group Test Group:\n"; 
    EXPECT_EQ(output.str(), expectedOutput);
}


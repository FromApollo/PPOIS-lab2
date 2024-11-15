#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"

class UserTest : public ::testing::Test {
protected:
    User* user;

    void SetUp() override {
        user = new User(1, "John Doe", "john@example.com", "password123");
    }

    void TearDown() override {
        delete user;
    }
};

TEST_F(UserTest, ConstructorTest) {
    EXPECT_EQ(user->getName(), "John Doe");
}

TEST_F(UserTest, GetNameTest) {
    EXPECT_EQ(user->getName(), "John Doe");
}

TEST_F(UserTest, DisplayInfoTest) {
    std::ostringstream output;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(output.rdbuf()); 

    user->displayInfo();

    std::cout.rdbuf(originalCoutBuffer); 

    std::string expectedOutput = "User ID: 1\nName: John Doe\nEmail: john@example.com\n";
    EXPECT_EQ(output.str(), expectedOutput);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

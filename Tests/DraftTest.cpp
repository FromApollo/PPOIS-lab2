#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Draft.h"

class DraftTest : public ::testing::Test {
protected:
    Draft* draft;

    void SetUp() override {

        draft = new Draft(1, "Draft Title", "This is the content of the draft.", "2024-11-02", 1, "Alice");
    }

    void TearDown() override {
        delete draft;
    }
};

TEST_F(DraftTest, ConstructorTest) {
    EXPECT_EQ(draft->getTitle(), "Draft Title");
    EXPECT_NO_THROW(draft->view());
}

TEST_F(DraftTest, CreateNewVersionTest) {

    testing::internal::CaptureStdout();
    draft->createNewVersion();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "New version created. Current version: 2\n");
    EXPECT_NO_THROW(draft->view()); 
}

TEST_F(DraftTest, SubmitForReviewTest) {

    testing::internal::CaptureStdout();
    draft->submitForReview();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Draft submitted for review by editor: Alice\n");
}

TEST_F(DraftTest, ViewTest) {

    testing::internal::CaptureStdout();
    draft->view();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Draft ID: 1"), std::string::npos);
    EXPECT_NE(output.find("Title: Draft Title"), std::string::npos);
    EXPECT_NE(output.find("Content: This is the content of the draft."), std::string::npos);
    EXPECT_NE(output.find("Creation Date: 2024-11-02"), std::string::npos);
    EXPECT_NE(output.find("Version: 1"), std::string::npos);
    EXPECT_NE(output.find("Editor: Alice"), std::string::npos);
}

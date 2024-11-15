#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Draft.h"


class DraftTest : public ::testing::Test {
protected:
    Draft* draft;

    void SetUp() override {
        draft = new Draft(1, "Draft Title", "This is the content of the draft.", "2024-01-01", 1, "Editor Name");
    }

    void TearDown() override {
        delete draft;
    }
};

TEST_F(DraftTest, SubmitForReviewDisplaysCorrectMessage) {
    testing::internal::CaptureStdout(); 
    draft->submitForReview(); 
    std::string output = testing::internal::GetCapturedStdout(); 

    EXPECT_EQ(output, "Draft submitted for review by editor: Editor Name\n");
}

TEST_F(DraftTest, ViewDisplaysCorrectInformation) {
    testing::internal::CaptureStdout(); 
    draft->view(); 
    std::string output = testing::internal::GetCapturedStdout(); 

    EXPECT_EQ(output, "Draft ID: 1\nTitle: Draft Title\nContent: This is the content of the draft.\nCreation Date: 2024-01-01\nVersion: 1\nEditor: Editor Name\n");
}

TEST_F(DraftTest, CreateNewVersionIncrementsVersionAndDisplaysMessage) {
    testing::internal::CaptureStdout(); 
    draft->createNewVersion(); 
    std::string output = testing::internal::GetCapturedStdout(); 

    EXPECT_EQ(output, "New version created. Current version: 2\n"); 
    EXPECT_EQ(draft->getVersion(), 2); 
}





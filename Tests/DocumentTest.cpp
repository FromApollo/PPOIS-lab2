#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"

class DocumentTest : public ::testing::Test {
protected:
    Document* document;

    void SetUp() override {
        document = new Document(1, "Test Title", "This is test content.", "2024-01-01");
    }

    void TearDown() override {
        delete document;
    }
};

TEST_F(DocumentTest, ConstructorInitializesFieldsCorrectly) {
    EXPECT_EQ(document->getTitle(), "Test Title");
}

TEST_F(DocumentTest, ViewDisplaysCorrectInformation) {
    testing::internal::CaptureStdout();     document->view();     std::string output = testing::internal::GetCapturedStdout(); 
    EXPECT_EQ(output, "ID: 1\nTitle: Test Title\nContent: This is test content.\nCreation Date: 2024-01-01\n");
}

TEST_F(DocumentTest, EditUpdatesContentCorrectly) {
    document->edit("Updated content.");     
    testing::internal::CaptureStdout();     document->edit("New content again."); 
    std::string output = testing::internal::GetCapturedStdout(); 
    EXPECT_EQ(output, "Document content updated.\n");
}

TEST_F(DocumentTest, GetTitleReturnsCorrectTitle) {
    EXPECT_EQ(document->getTitle(), "Test Title"); 
}

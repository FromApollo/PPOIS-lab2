#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"

class DocumentTest : public ::testing::Test {
protected:
    Document* doc;

    void SetUp() override {

        doc = new Document(1, "Test Title", "This is the content.", "2024-11-02");
    }

    void TearDown() override {
        delete doc;
    }
};

TEST_F(DocumentTest, ConstructorTest) {
    EXPECT_EQ(doc->getTitle(), "Test Title");
    EXPECT_NO_THROW(doc->view());  
}

TEST_F(DocumentTest, GetTitleTest) {
    EXPECT_EQ(doc->getTitle(), "Test Title");
}

TEST_F(DocumentTest, EditTest) {
    std::string newContent = "Updated content.";

    testing::internal::CaptureStdout();
    doc->edit(newContent);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Document content updated.\n");
    EXPECT_NO_THROW(doc->view());  
}

TEST_F(DocumentTest, RemoveTest) {

    testing::internal::CaptureStdout();
    doc->remove();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Document 'Test Title' removed.\n");
}

TEST_F(DocumentTest, ViewTest) {

    testing::internal::CaptureStdout();
    doc->view();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("ID: 1"), std::string::npos);
    EXPECT_NE(output.find("Title: Test Title"), std::string::npos);
    EXPECT_NE(output.find("Content: This is the content."), std::string::npos);
    EXPECT_NE(output.find("Creation Date: 2024-11-02"), std::string::npos);
}

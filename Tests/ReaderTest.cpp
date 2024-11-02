#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Reader.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"

class MockDocument : public Document {
public:
    MockDocument(int id, const std::string& title, const std::string& content, const std::string& creationDate)
        : Document(id, title, content, creationDate) {}

    void view() const override {}
};

class ReaderTest : public ::testing::Test {
protected:
    Reader* reader;
    MockDocument* document;

    void SetUp() override {
        reader = new Reader(1, "John Doe", "john@example.com", "password123");
        document = new MockDocument(1, "Test Document", "This is the content.", "2024-11-02");
    }

    void TearDown() override {
        delete reader;
        delete document;
    }
};

TEST_F(ReaderTest, ViewDocument) {
    testing::internal::CaptureStdout(); 
    reader->viewDocument(*document);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Reader John Doe is viewing document: Test Document\n");
}

TEST_F(ReaderTest, AddToBookmarks) {
    testing::internal::CaptureStdout(); 
    reader->addToBookmarks(*document);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Document Test Document has been added to bookmarks by reader John Doe.\n");
}

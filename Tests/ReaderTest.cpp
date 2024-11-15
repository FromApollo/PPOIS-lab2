#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Reader.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"

class ReaderTest : public ::testing::Test {
protected:
    Reader* reader;
    Document* doc;

    void SetUp() override {

        reader = new Reader(1, "Alice", "alice@example.com", "password123");

        doc = new Document(1, "Test Document", "This is the content of the document.", "2024-11-11");
    }

    void TearDown() override {
        delete reader;
        delete doc;
    }
};

TEST_F(ReaderTest, ViewDocument) {

    testing::internal::CaptureStdout();
    reader->viewDocument(*doc);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Reader Alice is viewing document: Test Document\n");
}

TEST_F(ReaderTest, AddToBookmarksAndViewBookmarks) {
    reader->addToBookmarks(*doc);

    testing::internal::CaptureStdout();
    reader->viewBookmarks();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Bookmarks for reader Alice:\n- Test Document\n");
}

TEST_F(ReaderTest, ViewEmptyBookmarks) {
    testing::internal::CaptureStdout();
    reader->viewBookmarks();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Bookmarks for reader Alice:\nNo bookmarks available.\n");
}

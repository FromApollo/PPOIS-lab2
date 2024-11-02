#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Editor.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"

class EditorTest : public ::testing::Test {
protected:
    Editor* editor;
    Document* document;

    void SetUp() override {

        editor = new Editor(1, "Bob", "bob@example.com", "password123", "Science");
        document = new Document(1, "Test Document", "Initial content", "2024-11-02");
    }

    void TearDown() override {
        delete editor;
        delete document;
    }
};

TEST_F(EditorTest, ConstructorTest) {
    EXPECT_EQ(editor->getName(), "Bob");
    EXPECT_NO_THROW(editor->editDocument(*document, "Updated content"));
}

TEST_F(EditorTest, EditDocumentTest) {

    testing::internal::CaptureStdout();
    editor->editDocument(*document, "Updated content");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NO_THROW(document->view());
}

TEST_F(EditorTest, SuggestChangesTest) {

    testing::internal::CaptureStdout();
    editor->suggestChanges(*document, "Add more examples.");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Editor Bob suggested changes for document Test Document: Add more examples..\n");
}

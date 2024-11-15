#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Editor.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\User.h"

class FakeDocument : public Document {
public:
    FakeDocument(int id, const std::string& title, const std::string& content, const std::string& creationDate)
        : Document(id, title, content, creationDate) {}

    void edit(const std::string& newContent) {
        content = newContent;
    }
};

TEST(EditorTest, EditDocument) {

    FakeDocument doc(1, "Sample Document", "Old Content", "2024-11-11");
    Editor editor(1, "Editor Name", "editor@example.com", "password123", "Tech");

    editor.editDocument(doc, "New Content");

    EXPECT_EQ(doc.getTitle(), "Sample Document");
}

TEST(EditorTest, SuggestChanges) {

    FakeDocument doc(1, "Sample Document", "Content", "2024-11-11");
    Editor editor(1, "Editor Name", "editor@example.com", "password123", "Tech");


    testing::internal::CaptureStdout();
    editor.suggestChanges(doc, "Change the introduction.");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Editor Name suggested changes for document Sample Document"), std::string::npos);
}

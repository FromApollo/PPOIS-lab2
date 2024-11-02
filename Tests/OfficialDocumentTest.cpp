#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\OfficialDocument.h"

class OfficialDocumentTest : public ::testing::Test {
protected:
    OfficialDocument* doc;

    void SetUp() override {
        doc = new OfficialDocument(1, "Test Document", "This is the content.", "2024-11-02", 12345, "Report");
    }

    void TearDown() override {
        delete doc;
    }
};

TEST_F(OfficialDocumentTest, CreationTest) {
    EXPECT_EQ(doc->getTitle(), "Test Document");
}

TEST_F(OfficialDocumentTest, SignTest) {
    doc->sign();
}

TEST_F(OfficialDocumentTest, RevokeSignatureTest) {
    doc->sign(); 
    doc->revokeSignature();
}

TEST_F(OfficialDocumentTest, ViewTest) {
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    doc->view();

    std::cout.rdbuf(oldCout); 

    std::string expectedOutput =
        "ID: 1\n"
        "Title: Test Document\n"
        "Content: This is the content.\n"
        "Creation Date: 2024-11-02\n"
        "Document Number: 12345\n"
        "Type: Report\n"
        "Signed: No\n"; 

    EXPECT_EQ(output.str(), expectedOutput);
}




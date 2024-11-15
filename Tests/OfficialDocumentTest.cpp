#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Document.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\OfficialDocument.h"

class OfficialDocumentTest : public ::testing::Test {
protected:
    OfficialDocument* doc;

    void SetUp() override {

        doc = new OfficialDocument(1, "Official Document", "This is an official document.", "2024-11-11", 1001, "Contract");
    }

    void TearDown() override {
        delete doc;
    }
};

TEST_F(OfficialDocumentTest, SignDocument) {
    testing::internal::CaptureStdout();
    doc->sign();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Document Official Document has been signed.\n");
}

TEST_F(OfficialDocumentTest, RevokeSignature) {

    doc->sign();
    testing::internal::CaptureStdout();
    doc->revokeSignature();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Signature revoked for document Official Document.\n");

}

TEST_F(OfficialDocumentTest, ViewDocument) {
    testing::internal::CaptureStdout();
    doc->view();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Document Number: 1001"), std::string::npos);
    EXPECT_NE(output.find("Type: Contract"), std::string::npos);
    EXPECT_NE(output.find("Signed: No"), std::string::npos); 
}

TEST_F(OfficialDocumentTest, EditDocument) {
    doc->edit("This is the updated content of the document.");
    testing::internal::CaptureStdout();
    doc->view();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("This is the updated content of the document."), std::string::npos);
}
